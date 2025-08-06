object FormPpal: TFormPpal
  Left = 262
  Top = 41
  Width = 967
  Height = 704
  Caption = 'Ray Casting'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 712
    Top = 18
    Width = 20
    Height = 13
    Caption = 'PX='
  end
  object Label2: TLabel
    Left = 712
    Top = 42
    Width = 20
    Height = 13
    Caption = 'PY='
  end
  object Label3: TLabel
    Left = 712
    Top = 66
    Width = 20
    Height = 13
    Caption = 'PZ='
  end
  object Label4: TLabel
    Left = 712
    Top = 114
    Width = 21
    Height = 13
    Caption = 'NX='
  end
  object Label5: TLabel
    Left = 712
    Top = 138
    Width = 21
    Height = 13
    Caption = 'NY='
  end
  object Label6: TLabel
    Left = 712
    Top = 162
    Width = 21
    Height = 13
    Caption = 'NZ='
  end
  object Label7: TLabel
    Left = 712
    Top = 290
    Width = 13
    Height = 13
    Caption = 'X='
  end
  object Label8: TLabel
    Left = 792
    Top = 290
    Width = 13
    Height = 13
    Caption = 'Y='
  end
  object Label9: TLabel
    Left = 872
    Top = 290
    Width = 13
    Height = 13
    Caption = 'Z='
  end
  object GroupBox1: TGroupBox
    Left = 24
    Top = 8
    Width = 529
    Height = 529
    TabOrder = 0
    object Image1: TImage
      Left = 9
      Top = 8
      Width = 512
      Height = 512
      Cursor = crCross
      OnMouseMove = Image1MouseMove
    end
  end
  object Panel1: TPanel
    Left = 560
    Top = 8
    Width = 137
    Height = 529
    TabOrder = 1
    object ListBox1: TListBox
      Left = 8
      Top = 8
      Width = 121
      Height = 513
      ItemHeight = 13
      TabOrder = 0
      OnClick = ListBox1Click
    end
  end
  object BitBtn1: TBitBtn
    Left = 288
    Top = 592
    Width = 81
    Height = 33
    Caption = 'SALIR'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnClick = BitBtn1Click
    Kind = bkClose
  end
  object Panel2: TPanel
    Left = 176
    Top = 264
    Width = 225
    Height = 73
    Color = clInactiveCaption
    TabOrder = 3
    Visible = False
    object StaticText1: TStaticText
      Left = 56
      Top = 8
      Width = 127
      Height = 28
      Caption = 'CARGANDO...'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object StaticText2: TStaticText
      Left = 8
      Top = 40
      Width = 212
      Height = 28
      Caption = 'ESPERE POR FAVOR'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
    end
  end
  object Button1: TButton
    Left = 208
    Top = 592
    Width = 73
    Height = 33
    Caption = 'BORRAR'
    TabOrder = 4
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 736
    Top = 16
    Width = 185
    Height = 21
    TabOrder = 5
  end
  object Edit2: TEdit
    Left = 736
    Top = 40
    Width = 185
    Height = 21
    TabOrder = 6
  end
  object Edit3: TEdit
    Left = 736
    Top = 64
    Width = 185
    Height = 21
    TabOrder = 7
  end
  object Edit4: TEdit
    Left = 736
    Top = 112
    Width = 185
    Height = 21
    TabOrder = 8
  end
  object Edit5: TEdit
    Left = 736
    Top = 136
    Width = 185
    Height = 21
    TabOrder = 9
  end
  object Edit6: TEdit
    Left = 736
    Top = 160
    Width = 185
    Height = 21
    TabOrder = 10
  end
  object Button2: TButton
    Left = 776
    Top = 192
    Width = 97
    Height = 17
    Caption = 'Mostrar Datos'
    TabOrder = 11
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 712
    Top = 216
    Width = 73
    Height = 17
    Caption = 'Rotar X'
    TabOrder = 12
    OnClick = Button3Click
  end
  object GroupBox2: TGroupBox
    Left = 24
    Top = 536
    Width = 529
    Height = 33
    TabOrder = 13
    object Edit7: TEdit
      Left = 48
      Top = 8
      Width = 41
      Height = 21
      TabOrder = 0
    end
    object Edit8: TEdit
      Left = 136
      Top = 8
      Width = 41
      Height = 21
      TabOrder = 1
    end
    object Edit9: TEdit
      Left = 240
      Top = 8
      Width = 41
      Height = 21
      TabOrder = 2
    end
    object Edit10: TEdit
      Left = 456
      Top = 8
      Width = 41
      Height = 21
      TabOrder = 3
    end
    object StaticText3: TStaticText
      Left = 24
      Top = 9
      Width = 21
      Height = 20
      Caption = 'X='
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
    end
    object StaticText4: TStaticText
      Left = 112
      Top = 9
      Width = 22
      Height = 20
      Caption = 'Y='
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 5
    end
    object StaticText5: TStaticText
      Left = 216
      Top = 9
      Width = 21
      Height = 20
      Caption = 'Z='
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 6
    end
    object StaticText6: TStaticText
      Left = 368
      Top = 9
      Width = 84
      Height = 20
      Caption = 'Intensidad='
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 7
    end
  end
  object Button4: TButton
    Left = 776
    Top = 264
    Width = 97
    Height = 17
    Caption = 'Mostrar Plano'
    TabOrder = 14
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 792
    Top = 216
    Width = 73
    Height = 17
    Caption = 'Rotar Y'
    TabOrder = 15
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 872
    Top = 216
    Width = 73
    Height = 17
    Caption = 'Rotar Z'
    TabOrder = 16
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 776
    Top = 240
    Width = 97
    Height = 17
    Caption = 'Rotar Angulo'
    TabOrder = 17
    OnClick = Button7Click
  end
  object Edit11: TEdit
    Left = 728
    Top = 288
    Width = 49
    Height = 21
    TabOrder = 18
    Text = '0'
  end
  object Edit12: TEdit
    Left = 808
    Top = 288
    Width = 49
    Height = 21
    TabOrder = 19
    Text = '0'
  end
  object Edit13: TEdit
    Left = 888
    Top = 288
    Width = 49
    Height = 21
    TabOrder = 20
    Text = '0'
  end
  object Button8: TButton
    Left = 776
    Top = 312
    Width = 97
    Height = 17
    Caption = 'Trasladar'
    TabOrder = 21
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 776
    Top = 336
    Width = 97
    Height = 17
    Caption = 'Restaurar'
    TabOrder = 22
    OnClick = Button9Click
  end
  object OpenDialog1: TOpenDialog
  end
  object MainMenu1: TMainMenu
    Left = 32
    object Archivo1: TMenuItem
      Caption = 'Archivo'
      object Abrir1: TMenuItem
        Caption = '&Abrir...'
        OnClick = Abrir1Click
      end
    end
  end
end
