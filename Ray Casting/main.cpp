//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <StrUtils.hpp>

#include "main.h"
#include "voxel.h"
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
                Panel2->Show();
                FormPpal->Refresh();
                Vox->Cargar(Files,NoFiles);
                Panel2->Hide();
                FormPpal->Refresh();
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

void __fastcall TFormPpal::ComboBox1Change(TObject *Sender)
{
        if(ComboBox1->ItemIndex==3)
                Vox->Vista(Image1,0,0);
}
//---------------------------------------------------------------------------

