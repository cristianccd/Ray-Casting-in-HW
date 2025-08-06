//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ImgList.hpp>
#include "voxel.h"
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFormPpal : public TForm
{
__published:	// IDE-managed Components
        TOpenDialog *OpenDialog1;
        TMainMenu *MainMenu1;
        TMenuItem *Archivo1;
        TMenuItem *Abrir1;
        TGroupBox *GroupBox1;
        TImage *Image1;
        TPanel *Panel1;
        TListBox *ListBox1;
        TBitBtn *BitBtn1;
        TPanel *Panel2;
        TStaticText *StaticText1;
        TStaticText *StaticText2;
        TComboBox *ComboBox1;
        void __fastcall Abrir1Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
private:	// User declarations
        int NoFiles;
        AnsiString *BmpFiles;
        AnsiString Path;
        AnsiString *Files;
        AnsiString NamesAs;
        TStrings *NamesTs;
        Graphics::TBitmap *Bmp;
public:		// User declarations
        voxel *Vox;
        __fastcall TFormPpal(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPpal *FormPpal;
//---------------------------------------------------------------------------
#endif
