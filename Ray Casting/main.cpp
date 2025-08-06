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
        OpenDialog1->Execute();
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
        for(int i=0;i<NoFiles;i++)
        {
                Bmp->LoadFromFile(Files[i]);
                ImageList1->Add(Bmp,Bmp);
        }
        //Cargo el voxel
        voxel Vox(Bmp->Width,Bmp->Height,NoFiles);
        Vox.Cargar(Files,NoFiles);
        delete Bmp;
        delete Files;
}
//---------------------------------------------------------------------------


