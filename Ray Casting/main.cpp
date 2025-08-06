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
                VoxR=new voxel (Bmp->Width,Bmp->Height,NoFiles);
                FormPpal->Refresh();
                Vox->Cargar(Files,NoFiles);
                Panel2->Hide();
                FormPpal->Refresh();
                ConfigImage(Image1,8,Bmp->Width,Bmp->Height);
                Vox->Mostrar(Image1,0);
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

void __fastcall TFormPpal::ListBox1Click(TObject *Sender)
{
        int index=ListBox1->ItemIndex;
        Vox->Mostrar(Image1,index);
}
//---------------------------------------------------------------------------

void TFormPpal::ConfigImage(TImage * Image, int NBits, int X, int Y)
{
        //TODO: Add your source code here
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

void __fastcall TFormPpal::Button1Click(TObject *Sender)
{
        BorrarImg(Image1);
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::Button2Click(TObject *Sender)
{
        float X,Y,Z,PX,PY,PZ;
        X=Plano.GetNormal().GetCoords(0);
        Y=Plano.GetNormal().GetCoords(1);
        Z=Plano.GetNormal().GetCoords(2);
        PX=Plano.GetNormal().GetPto(0);
        PY=Plano.GetNormal().GetPto(1);
        PZ=Plano.GetNormal().GetPto(2);
        Edit1->Text=PX;
        Edit2->Text=PY;
        Edit3->Text=PZ;
        Edit4->Text=X;
        Edit5->Text=Y;
        Edit6->Text=Z;
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::Image1MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
        Edit7->Text=X;
        Edit8->Text=Y;
        Edit9->Text=Plano.GetElemPlano(X,Y).GetCoords(2);
        Edit10->Text=Plano.GetElemPlano(X,Y).GetValue();
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::Button4Click(TObject *Sender)
{
        Panel2->Show();
        FormPpal->Refresh();
        Plano.Borrar();
        Plano.CargarPlano(Vox);
        BorrarImg(Image1);
        Plano.Mostrar(Image1);
        Panel2->Hide();
        FormPpal->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::Button5Click(TObject *Sender)
{
        AnsiString Texto = "90";
        bool SI = InputQuery("Ingrese el angulo deseado", "Angulo:", Texto);
        if(!SI) return;
        int Ang=Texto.ToInt();
        Vect.SetPto(0,0,0); //debe ser el origen para el vector de rotacion
        Vect.SetCoords(0,1,0);
        Plano.Rotar(Vect,Ang);        
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::Button6Click(TObject *Sender)
{
        AnsiString Texto = "90";
        bool SI = InputQuery("Ingrese el angulo deseado", "Angulo:", Texto);
        if(!SI) return;
        int Ang=Texto.ToInt();
        Vect.SetPto(0,0,0); //debe ser el origen para el vector de rotacion
        Vect.SetCoords(0,0,1);
        Plano.Rotar(Vect,Ang);
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::Button3Click(TObject *Sender)
{
        AnsiString Texto = "90";
        bool SI = InputQuery("Ingrese el angulo deseado", "Angulo:", Texto);
        if(!SI) return;
        int Ang=Texto.ToInt();
        Vect.SetPto(0,0,0); //debe ser el origen para el vector de rotacion
        Vect.SetCoords(1,0,0);
        Plano.Rotar(Vect,Ang);
}
//---------------------------------------------------------------------------


void __fastcall TFormPpal::Button7Click(TObject *Sender)
{
        AnsiString Texto = "90";
        bool SI = InputQuery("Ingrese el angulo deseado", "Azimuth:", Texto);
        if(!SI) return;
        float Azi=Texto.ToDouble();
        SI = InputQuery("Ingrese el angulo deseado", "Elevacion:", Texto);
        if(!SI) return;
        float Elev=Texto.ToDouble();
        SI = InputQuery("Ingrese el angulo deseado", "Tilt:", Texto);
        if(!SI) return;
        float Tilt=Texto.ToDouble();
        Plano.Rotar(Azi,Elev,Tilt);
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::Button8Click(TObject *Sender)
{
        int TX,TY,TZ;
        TX=AnsiReplaceText(Edit11->Text,".",",").ToInt();
        TY=AnsiReplaceText(Edit12->Text,".",",").ToInt();
        TZ=AnsiReplaceText(Edit13->Text,".",",").ToInt();
        Plano.Trasladar(TX,TY,TZ);
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

void __fastcall TFormPpal::Button9Click(TObject *Sender)
{
        Plano.Restore();
}
//---------------------------------------------------------------------------

