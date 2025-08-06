//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <StrUtils.hpp>

#include "main.h"
#include "voxel.h"
#include "elemplano.h"
#include "plano.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormPpal *FormPpal;

//---------------------------------------------------------------------------
__fastcall TFormPpal::TFormPpal(TComponent* Owner)
        : TForm(Owner)
{
        DoubleBuffered=true;
}
//---------------------------------------------------------------------------
void __fastcall TFormPpal::Abrir1Click(TObject *Sender)
{
        //Abrir archivos
        OpenDialog1->DefaultExt = GraphicExtension(__classid(Graphics::TBitmap));
        OpenDialog1->FileName = GraphicFileMask(__classid(Graphics::TBitmap));
        OpenDialog1->Filter = GraphicFilter(__classid(Graphics::TBitmap));
        OpenDialog1->Options.Clear();
        OpenDialog1->Options << ofAllowMultiSelect << ofFileMustExist << ofHideReadOnly << ofNoChangeDir;
        OpenDialog1->InitialDir=ExtractFilePath(Application->ExeName);
        if (OpenDialog1->Execute())
        {
                Panel2->Show();
                FormPpal->Refresh();
                ChgStatus(false);
                //Habilito la listbox
                //Carga de nombre de archivos en la listbox
                NamesTs=OpenDialog1->Files;
                NamesAs=NamesTs->GetText();
                //Ubico el path
                Path=OpenDialog1->FileName;
                Path=Path.SubString(0,Path.LastDelimiter("\\"));
                NamesAs=AnsiReplaceText(NamesAs,Path,"");
                //Relleno la listbox
                NamesTs->SetText(NamesAs.c_str());
                ListBox1->Items->Assign(NamesTs);
                //Genero un array con los nombres de los archivos
                int posactual=0,posant=1, cantarch=0;      //Auxiliar para el explode de nombres
                NoFiles=OpenDialog1->Files->Count;
                Files=new AnsiString [NoFiles];
                NamesAs=AnsiReplaceText(NamesAs,"\r\n","*");
                while(posactual<NamesAs.Length())//Si son varios archivos
                {
                        if(NamesAs.IsDelimiter("*",posactual)==true)
                        {
                                Files[cantarch]=Path+NamesAs.SubString(posant,posactual-posant);
                                cantarch++;
                                posant=posactual+1;
                        }
                        posactual++;
                }
                //Agrego el ultimo archivo
                Files[cantarch]=Path+NamesAs.SubString(posant,NamesAs.Length()-posant);
                cantarch++;
                if(NoFiles==1)//Si es unico archivo
                {
                        Files[0]=Path+NamesAs.SubString(0,NamesAs.Length()-1);
                }
                //Almaceno Imagenes en una lista
                Bmp=new Graphics::TBitmap();
                Bmp->LoadFromFile(Files[0]);
                //Cargo la primer imagen para tener el tamano
                //Cargo el voxel
                Vox=new voxel (Bmp->Width,Bmp->Height,NoFiles);
                Vox->Cargar(Files,NoFiles);
                ChgStatus(true);
                Panel2->Hide();
                FormPpal->Refresh();
                ConfigImage(Image1,8,Bmp->Width,Bmp->Height);
                Image1->Enabled=true;
                Plano.VerPlano(Vox,0,90,0);
                Plano.Previa(Vox);
                Plano.Mostrar(Image1);
        }
        else
        {
                MessageBox(NULL, "Debe ingresar algun archivo!", "Warning!",MB_OK|MB_ICONWARNING)==IDNO;
        }

}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::BitBtn1Click(TObject *Sender)
{
        if( MessageBox(NULL, "Desea Salir?", "Salir",MB_YESNO|MB_ICONQUESTION) == IDNO)
		return;
        delete Bmp;
        delete Files;
        Close();        
}
//---------------------------------------------------------------------------

void TFormPpal::ConfigImage(TImage * Image, int NBits, int X, int Y)
{
        if(NBits==8)
        {
                typedef struct
                {
                        TLogPalette lpal;
                        TPaletteEntry dummy[256];
                } LogPal;
                Image->Picture->Bitmap->PixelFormat=pf8bit;
                Image->Picture->Bitmap->Width=X;
                Image->Picture->Bitmap->Height=Y;
                LogPal SysPal;
                SysPal.lpal.palVersion = 0x300;
                SysPal.lpal.palNumEntries = 256;
                for (int i=0;i<SysPal.lpal.palNumEntries;i++)
                {
                        SysPal.lpal.palPalEntry[i].peRed = i;
                        SysPal.lpal.palPalEntry[i].peGreen = i;
                        SysPal.lpal.palPalEntry[i].peBlue = i;
                        SysPal.lpal.palPalEntry[i].peFlags = 0;
                }
                Image->Picture->Bitmap->Palette = CreatePalette(&SysPal.lpal);
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::Image1MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
        Edit1->Text=X;
        Edit2->Text=Y;
        Edit3->Text=(int)Plano.GetElemPlano(X,Y).GetCoords(2);
        Edit4->Text=Plano.GetElemPlano(X,Y).GetValue();
}
//---------------------------------------------------------------------------

void TFormPpal::BorrarImg(TImage *Image1)
{
        BYTE *LinePtr;
        for (int j=0;j<Image1->Height;j++)
        {
                LinePtr=(BYTE *) Image1->Picture->Bitmap->ScanLine[j];
                for (int i=0;i<Image1->Width;i++)
                        LinePtr[i]=0;
        }
        Image1->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::ListBox1Click(TObject *Sender)
{
        int index=ListBox1->ItemIndex;
        Vox->Mostrar(Image1,index);
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::BitBtn2Click(TObject *Sender)
{
        ChgStatus(false);
        Panel2->Show();
        FormPpal->Refresh();
        Plano.Borrar();
        BorrarImg(Image1);
        Plano.VerPlano(Vox,Azimuth,Elevacion,0);
        Plano.CargarPlano(Vox,ProgressBar1,RadioButton1->Checked,RadioButton2->Checked,CheckBox1->Checked);
        if(CheckBox2->Checked==true)
        {
                //Ecualizar
        }
        if(CheckBox3->Checked==true)
        {
                //Isodata
        }
        Plano.Mostrar(Image1);
        Panel2->Hide();
        FormPpal->Refresh();
        ChgStatus(true);
}
//---------------------------------------------------------------------------

void TFormPpal::ChgStatus(bool status)
{
        if(status==true)
        {
                ListBox1->Enabled=true;
                CheckBox1->Enabled=true;
                CheckBox2->Enabled=true;
                CheckBox3->Enabled=true;
                RadioButton1->Enabled=true;
                RadioButton2->Enabled=true;
                Edit8->Enabled=true;
                Edit9->Enabled=true;
                BitBtn1->Enabled=true;
                BitBtn2->Enabled=true;
                UpDown1->Enabled=true;
                UpDown2->Enabled=true;
        }
        else
        {
                ListBox1->Enabled=false;
                CheckBox1->Enabled=false;
                CheckBox2->Enabled=false;
                CheckBox3->Enabled=false;
                RadioButton1->Enabled=false;
                RadioButton2->Enabled=false;
                Edit8->Enabled=false;
                Edit9->Enabled=false;
                BitBtn1->Enabled=false;
                BitBtn2->Enabled=false;
                UpDown1->Enabled=false;
                UpDown2->Enabled=false;
        }
        FormPpal->Refresh();
}
void __fastcall TFormPpal::Guardar1Click(TObject *Sender)
{
        //GUARDAR        
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::Salir1Click(TObject *Sender)
{
        //SALIR        
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::Ecualizacin1Click(TObject *Sender)
{
        //ECUALIZAR PLANO        
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::Isodata1Click(TObject *Sender)
{
        //ISODATA PLANO        
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::Umbralizacin1Click(TObject *Sender)
{
        //UMBRALIZACION PLANO        
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::PasaBajos1Click(TObject *Sender)
{
        //PASA BAJOS
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::PasaAltos1Click(TObject *Sender)
{
        //PASA ALTOS        
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::Rotar1Click(TObject *Sender)
{
        //ROTAR PLANO        
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::Zoom1Click(TObject *Sender)
{
        //ZOOM + Bilinear!        
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::RadioButton2Click(TObject *Sender)
{
        CheckBox1->Checked=false;
        CheckBox1->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::RadioButton1Click(TObject *Sender)
{
        CheckBox1->Checked=true;
        CheckBox1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        Azimuth=X*180/512-180;
        Elevacion=180-Y*180/512;
        Edit5->Text=Azimuth;
        Edit6->Text=Elevacion;
        Plano.VerPlano(Vox,Azimuth,Elevacion,0);
        Plano.Previa(Vox);
        Plano.Mostrar(Image1);
}
//---------------------------------------------------------------------------

