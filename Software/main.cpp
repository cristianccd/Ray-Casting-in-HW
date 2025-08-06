//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <StrUtils.hpp>

#include "main.h"
#include "voxel.h"
#include "elemplano.h"
#include "plano.h"
#include <Printers.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormPpal *FormPpal;

//---------------------------------------------------------------------------
__fastcall TFormPpal::TFormPpal(TComponent* Owner)
        : TForm(Owner)
{
        DoubleBuffered=true;
        ScrollBar2->Enabled=false;
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
                Plano.VerPlano(Vox,0,0,0);
                Plano.Previa(Vox,Edit10->Text.ToInt());
                Plano.Mostrar(Image1);
                RadioButton1->Checked=true;
                CheckBox1->Checked=true;
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
        delete NamesTs;
        delete Vox;
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
        TMouseButton Button;
        Edit1->Text=X;
        Edit2->Text=Y;
        Edit3->Text=(int)Plano.GetElemPlano(X,Y).GetCoords(2);
        Edit4->Text=Plano.GetElemPlano(X,Y).GetValue();
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::Image1MouseMoveMouseWheel(TObject *Sender,
      TShiftState Shift, int X, int Y, int WheelDelta)
{
        TMouseButton Button;
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
        //previa=false;
        Panel2->Show();
        FormPpal->Refresh();
        Plano.Borrar();
        Plano.VerPlano(Vox,Azimuth,Elevacion,0);
        int Usup,Uinf;
        //Verifico Umbrales
        if(CheckBox4->Checked==true)
        {
                Usup=Edit11->Text.ToInt();
                Uinf=Edit7->Text.ToInt();
                if(Uinf>Usup)
                {
                        MessageBox(NULL, "Inferior>Superior!", "Warning!",MB_OK|MB_ICONWARNING)==IDNO;
                        if(NoFiles!=0)
                                ChgStatus(true);
                        Panel2->Hide();
                        FormPpal->Refresh();
                        return;
                }
        }
        else
        {
                Usup=255;
                Uinf=Edit10->Text.ToInt();
        }
        float Profmax=sqrt(pow(Vox->getTam(0),2)+pow(Vox->getTam(1),2)+pow(Vox->getTam(2),2));
        float Profmin=0;
        if(CheckBox5->Checked==false)
        {
                Profmax=Edit12->Text.ToInt();
                Profmin=Edit13->Text.ToInt();
        }
        //Verifico Minimo y Max
        if(Edit13->Text.ToInt()>Edit12->Text.ToInt())
        {
                MessageBox(NULL, "Minimo>Maximo!", "Warning!",MB_OK|MB_ICONWARNING)==IDNO;
                if(NoFiles!=0)
                        ChgStatus(true);
                Panel2->Hide();
                FormPpal->Refresh();
                return;
        }
        //Cargo la LUT
        SelectLUT();
        //Cargo el plano
        Plano.CargarPlano(Vox,ProgressBar1,RadioButton1->Checked,RadioButton2->Checked,RadioButton8->Checked,CheckBox1->Checked,Uinf,Usup,Profmax,Profmin);
        //Armo el histograma
        Plano.Histograma();
        if(CheckBox2->Checked==true)
        {
                Plano.Ecualizar();
        }
        if(CheckBox3->Checked==true)
        {
                float Umean=Plano.Isodata();
                Plano.UmbralFijo(Umean);
        }
        //Chart Histograma
        Series1->Clear();
        Plano.Histograma();
        for(int i=1;i<256;i++)
                Series1->AddXY(i,Plano.GetHistograma(i));
        BorrarImg(Image1);
        Plano.Mostrar(Image1);
        Panel2->Hide();
        FormPpal->Refresh();
        ChgStatus(true);
        if(RadioButton2->Checked==true||RadioButton8->Checked==true)
        {
                        CheckBox1->Checked=false;
                        CheckBox1->Enabled=false;
        }
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
                CheckBox4->Enabled=true;
                CheckBox5->Enabled=true;
                RadioButton1->Enabled=true;
                RadioButton2->Enabled=true;
                RadioButton3->Enabled=true;
                RadioButton4->Enabled=true;
                RadioButton5->Enabled=true;
                RadioButton6->Enabled=true;
                RadioButton7->Enabled=true;
                RadioButton8->Enabled=true;
                Edit8->Enabled=true;
                Edit9->Enabled=true;
                Edit10->Enabled=true;
                BitBtn1->Enabled=true;
                BitBtn2->Enabled=true;
                ScrollBar2->Enabled=true;
                ScrollBar1->Enabled=true;
                Button1->Enabled=true;
                Button2->Enabled=true;
        }
        else
        {
                ListBox1->Enabled=false;
                CheckBox1->Enabled=false;
                CheckBox2->Enabled=false;
                CheckBox3->Enabled=false;
                CheckBox4->Enabled=false;
                CheckBox5->Enabled=false;
                RadioButton1->Enabled=false;
                RadioButton2->Enabled=false;
                RadioButton3->Enabled=false;
                RadioButton4->Enabled=false;
                RadioButton5->Enabled=false;
                RadioButton6->Enabled=false;
                RadioButton7->Enabled=false;
                RadioButton8->Enabled=false;
                Edit8->Enabled=false;
                Edit9->Enabled=false;
                Edit10->Enabled=false;
                BitBtn1->Enabled=false;
                BitBtn2->Enabled=false;
                ScrollBar2->Enabled=false;
                ScrollBar1->Enabled=false;
                Button1->Enabled=false;
                Button2->Enabled=false;
        }
        FormPpal->Refresh();
}
void __fastcall TFormPpal::Guardar1Click(TObject *Sender)
{
        //GUARDAR
        SaveDialog1->Filter = "Bmp files (*.bmp)|*.BMP";
        if(SaveDialog1->Execute())
        {
                Image1->Picture->SaveToFile(SaveDialog1->FileName+".bmp");
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::Imprimir1Click(TObject *Sender)
{
        //IMPRIMIR

        TPrinter *Prntr = Printer();
        if(PrintDialog1->Execute())
        {
                TRect R=Rect(Prntr->PageWidth/2-256*4,Prntr->PageHeight/2-256*4,Prntr->PageWidth/2+256*4,Prntr->PageHeight/2+256*4);
                Image1->Transparent=true;
                Prntr->BeginDoc();
                Prntr->Canvas->StretchDraw(R,Image1->Picture->Graphic);
                Prntr->EndDoc();
                Image1->Transparent=false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::Salir1Click(TObject *Sender)
{
        if( MessageBox(NULL, "Desea Salir?", "Salir",MB_YESNO|MB_ICONQUESTION) == IDNO)
		return;
        delete Bmp;
        delete Files;
        delete NamesTs;
        delete Vox;
        Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::Ecualizacin1Click(TObject *Sender)
{
        Plano.Ecualizar();
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::Isodata1Click(TObject *Sender)
{
        Plano.Isodata();
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::PasaBajos1Click(TObject *Sender)
{
        float Mask[9]={(float)1/9,(float)1/9,(float)1/9,(float)1/9,(float)1/9,
                      (float)1/9,(float)1/9,(float)1/9,(float)1/9};
        Plano.SetMask(Mask);
        Plano.ApplyMask(Aux);
        Aux.Mostrar(Image1);
        Image1->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::PasaAltos1Click(TObject *Sender)
{
        float Mask[9]={(float)-1/9,(float)-1/9,(float)-1/9,(float)-1/9,(float)8/9,(float)-1/9,(float)-1/9,(float)-1/9,(float)-1/9};
        Plano.SetMask(Mask);
        Plano.ApplyMask(Aux);
        Aux.Mostrar(Image1);
        Image1->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::Zoom1Click(TObject *Sender)
{
        //ZOOM + Bilinear!
        AnsiString Texto = "1.5";
        bool SI = InputQuery("Ingrese el Zoom deseado:", "Zoom: ", Texto);
        if(!SI) return;
        double FE=AnsiReplaceText(Texto,".",",").ToDouble();
        Aux=Plano;
        Plano.Bilinear(Aux,FE,256,256);
        Aux.Mostrar(Image1);
        Image1->Refresh();
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
        if(Button==mbLeft)
        {
                Azimuth=X*360/512-180;
                Elevacion=Y*360/512-180;
                Edit5->Text=Azimuth;
                Edit6->Text=Elevacion;
                Plano.VerPlano(Vox,Azimuth,Elevacion,0);
                Plano.Previa(Vox,Edit10->Text.ToInt());
                Plano.Mostrar(Image1);
                Image1->Refresh();
        }
        if(Button==mbRight)
        {
                AnsiString Texto = "1.5";
                bool SI = InputQuery("Ingrese el Zoom deseado:", "Zoom: ", Texto);
                if(!SI) return;
                double FE=AnsiReplaceText(Texto,".",",").ToDouble();
                Aux=Plano;
                Plano.Bilinear(Aux,FE,X,Y);
                Aux.Mostrar(Image1);
                Image1->Refresh();
        }

}
//---------------------------------------------------------------------------


void __fastcall TFormPpal::CheckBox4Click(TObject *Sender)
{
        if(CheckBox4->Checked==true)
        {
                Edit7->Enabled=true;
                Edit11->Enabled=true;
                Edit10->Enabled=false;
        }
        else
        {
                Edit7->Enabled=false;
                Edit11->Enabled=false;
                Edit10->Enabled=true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::CheckBox5Click(TObject *Sender)
{
        if(CheckBox5->Checked==false)
        {
                Edit12->Enabled=true;
                Edit13->Enabled=true;
        }
        else
        {
                Edit12->Enabled=false;
                Edit13->Enabled=false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::Button1Click(TObject *Sender)
{
        ConfigImage(Image1,8,512,512);
        SelectLUT();
        Plano.IzqDer();
        Plano.Mostrar(Image1);
        Series1->Clear();
        Plano.Histograma();
        for(int i=1;i<256;i++)
                Series1->AddXY(i,Plano.GetHistograma(i));
        Plano.Borrar();
        FormPpal->Refresh();
}
//---------------------------------------------------------------------------

void TFormPpal::SelectLUT()
{
        float LUT[256];
        if(RadioButton3->Checked==true)
        {
                for(int i=0;i<256;i++)
                        LUT[i]=i;
        }
        if(RadioButton4->Checked==true)//Altos
        {
                for(int i=0;i<256;i++)
                        LUT[i]=255*exp(-pow(i-256,2)/(2*pow(20,2)));
        }
        if(RadioButton6->Checked==true)//Medios
        {
                for(int i=0;i<256;i++)
                        LUT[i]=255*exp(-pow(i-128,2)/(2*pow(20,2)));
        }
        if(RadioButton7->Checked==true)//Bajos
        {
                for(int i=0;i<256;i++)
                        LUT[i]=255*exp(-pow(i,2)/(2*pow(20,2)));
        }
        if(RadioButton5->Checked==true)//Log
        {
                for(int i=0;i<256;i++)
                        LUT[i]=255*exp(-i);
        }
        Plano.LoadLUT(LUT,256);
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::ScrollBar1Change(TObject *Sender)
{
        Edit8->Text=ScrollBar1->Position;
        Edit9->Text=ScrollBar2->Position-100;
        Aux=Plano;
        Aux.BrilloContr(ScrollBar1->Position,ScrollBar2->Position);
        Aux.ApplyLUT();
        Aux.Mostrar(Image1);
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::ScrollBar2Change(TObject *Sender)
{
        Edit8->Text=ScrollBar1->Position;
        Edit9->Text=ScrollBar2->Position-100;
        Aux=Plano;
        Aux.BrilloContr(ScrollBar1->Position,ScrollBar2->Position);
        Aux.ApplyLUT();
        Aux.Mostrar(Image1);
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::Bilinear1Click(TObject *Sender)
{
                AnsiString Texto = "1.5";
                bool SI = InputQuery("Ingrese el Zoom deseado:", "Zoom: ", Texto);
                if(!SI) return;
                double FE=AnsiReplaceText(Texto,".",",").ToDouble();
                Aux=Plano;
                Plano.Bilinear(Aux,FE,256,256);
                Aux.Mostrar(Image1);
                Image1->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::RadioButton8Click(TObject *Sender)
{
        CheckBox1->Checked=false;
        CheckBox1->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TFormPpal::Button2Click(TObject *Sender)
{
        Plano=Aux;        
}
//---------------------------------------------------------------------------

