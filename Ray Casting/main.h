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
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFormPpal : public TForm
{
__published:	// IDE-managed Components
        TOpenDialog *OpenDialog1;
        TMainMenu *MainMenu1;
        TGroupBox *GroupBox1;
        TImage *Image1;
        TPanel *Panel1;
        TListBox *ListBox1;
        TPanel *Panel2;
        TStaticText *StaticText1;
        TStaticText *StaticText2;
        TGroupBox *GroupBox2;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TEdit *Edit4;
        TStaticText *StaticText3;
        TStaticText *StaticText4;
        TStaticText *StaticText5;
        TStaticText *StaticText6;
        TMenuItem *Filtros1;
        TMenuItem *PasaBajos1;
        TMenuItem *PasaAltos1;
        TMenuItem *Ver1;
        TMenuItem *Rotar1;
        TMenuItem *Zoom1;
        TMenuItem *E1;
        TMenuItem *Isodata1;
        TMenuItem *Umbralizacin1;
        TMenuItem *Ecualizacin1;
        TGroupBox *GroupBox3;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *Edit5;
        TEdit *Edit6;
        TCheckBox *CheckBox1;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TMenuItem *Archivo1;
        TMenuItem *Abrir1;
        TMenuItem *Guardar1;
        TMenuItem *Salir1;
        TCheckBox *CheckBox2;
        TCheckBox *CheckBox3;
        TBevel *Bevel1;
        TBevel *Bevel2;
        TBevel *Bevel3;
        TBitBtn *BitBtn1;
        TLabel *Label3;
        TEdit *Edit7;
        TGroupBox *ByC;
        TGroupBox *Salir;
        TUpDown *UpDown1;
        TUpDown *UpDown2;
        TLabel *Label4;
        TLabel *Label5;
        TEdit *Edit8;
        TEdit *Edit9;
        TBitBtn *BitBtn2;
        TProgressBar *ProgressBar1;
        void __fastcall Abrir1Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall Guardar1Click(TObject *Sender);
        void __fastcall Salir1Click(TObject *Sender);
        void __fastcall Ecualizacin1Click(TObject *Sender);
        void __fastcall Isodata1Click(TObject *Sender);
        void __fastcall Umbralizacin1Click(TObject *Sender);
        void __fastcall PasaBajos1Click(TObject *Sender);
        void __fastcall PasaAltos1Click(TObject *Sender);
        void __fastcall Rotar1Click(TObject *Sender);
        void __fastcall Zoom1Click(TObject *Sender);
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
        plano Plano;
        normal Vect;
        __fastcall TFormPpal(TComponent* Owner);
        void ConfigImage(TImage * Image, int NBits, int X, int Y);
        void BorrarImg(TImage *);
        void ChgStatus(bool status);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPpal *FormPpal;
//---------------------------------------------------------------------------
#endif
