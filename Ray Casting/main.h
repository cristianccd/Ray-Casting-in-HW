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
#include <ExtDlgs.hpp>
#include <Chart.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
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
        TMenuItem *Ecualizacin1;
        TGroupBox *GroupBox3;
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
        TGroupBox *ByC;
        TGroupBox *Salir;
        TLabel *Label4;
        TLabel *Label5;
        TEdit *Edit9;
        TBitBtn *BitBtn2;
        TProgressBar *ProgressBar1;
        TStaticText *StaticText7;
        TStaticText *StaticText8;
        TEdit *Edit5;
        TEdit *Edit6;
        TGroupBox *GroupBox4;
        TBevel *Bevel4;
        TStaticText *StaticText9;
        TStaticText *StaticText10;
        TEdit *Edit7;
        TEdit *Edit10;
        TCheckBox *CheckBox4;
        TEdit *Edit8;
        TGroupBox *GroupBox5;
        TBevel *Bevel5;
        TStaticText *StaticText12;
        TStaticText *StaticText13;
        TEdit *Edit13;
        TCheckBox *CheckBox5;
        TGroupBox *GroupBox6;
        TSaveDialog *SaveDialog1;
        TPrintDialog *PrintDialog1;
        TMenuItem *Imprimir1;
        TBevel *Bevel6;
        TChart *Chart1;
        TEdit *Edit11;
        TStaticText *StaticText11;
        TStaticText *StaticText14;
        TEdit *Edit12;
        TAreaSeries *Series1;
        TMenuItem *Bilinear1;
        TRadioButton *RadioButton7;
        TRadioButton *RadioButton5;
        TRadioButton *RadioButton6;
        TRadioButton *RadioButton4;
        TRadioButton *RadioButton3;
        TButton *Button1;
        TScrollBar *ScrollBar1;
        TScrollBar *ScrollBar2;
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
        void __fastcall PasaBajos1Click(TObject *Sender);
        void __fastcall PasaAltos1Click(TObject *Sender);
        void __fastcall Rotar1Click(TObject *Sender);
        void __fastcall Zoom1Click(TObject *Sender);
        void __fastcall RadioButton2Click(TObject *Sender);
        void __fastcall RadioButton1Click(TObject *Sender);
        void __fastcall Image1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall CheckBox4Click(TObject *Sender);
        void __fastcall Imprimir1Click(TObject *Sender);
        void __fastcall CheckBox5Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall ScrollBar1Change(TObject *Sender);
        void __fastcall ScrollBar2Change(TObject *Sender);
        void __fastcall Image1MouseMoveMouseWheel(TObject *Sender,
      TShiftState Shift, int X, int Y, int WheelDelta);
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
        plano Plano,Aux;
        normal Vect;
        __fastcall TFormPpal(TComponent* Owner);
        void ConfigImage(TImage * Image, int NBits, int X, int Y);
        void BorrarImg(TImage *);
        void ChgStatus(bool status);
        int Azimuth,Elevacion;
        void SelectLUT();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPpal *FormPpal;
//---------------------------------------------------------------------------
#endif
