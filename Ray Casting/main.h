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
#include "elemplano.h"
#include "normal.h"
#include "plano.h"
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
        TGroupBox *GroupBox2;
        TEdit *Edit7;
        TEdit *Edit8;
        TEdit *Edit9;
        TEdit *Edit10;
        TStaticText *StaticText3;
        TStaticText *StaticText4;
        TStaticText *StaticText5;
        TStaticText *StaticText6;
        TLabel *Label13;
        TEdit *Edit17;
        TEdit *Edit18;
        TLabel *Label14;
        TLabel *Label15;
        TEdit *Edit19;
        TButton *Button11;
        void __fastcall Abrir1Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall ListBox1Click(TObject *Sender);
private:	// User declarations
        int NoFiles;
        AnsiString *BmpFiles;
        AnsiString Path;
        AnsiString *Files;
        AnsiString NamesAs;
        TStrings *NamesTs;
        Graphics::TBitmap *Bmp;
public:		// User declarations
        voxel *Vox,*VoxR;
        plano Plano;
        normal Vect;
        __fastcall TFormPpal(TComponent* Owner);
        void ConfigImage(TImage * Image, int NBits, int X, int Y);
        void BorrarImg(TImage *);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPpal *FormPpal;
//---------------------------------------------------------------------------
#endif
