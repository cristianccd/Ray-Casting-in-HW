object FormPpal: TFormPpal
  Left = 361
  Top = 15
  Width = 722
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
  object Label13: TLabel
    Left = 24
    Top = 578
    Width = 23
    Height = 13
    Caption = 'AZI='
  end
  object Label14: TLabel
    Left = 96
    Top = 578
    Width = 33
    Height = 13
    Caption = 'ELEV='
  end
  object Label15: TLabel
    Left = 176
    Top = 578
    Width = 29
    Height = 13
    Caption = 'TILT='
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
    Left = 592
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
  object GroupBox2: TGroupBox
    Left = 24
    Top = 536
    Width = 529
    Height = 33
    TabOrder = 4
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
  object Edit17: TEdit
    Left = 48
    Top = 576
    Width = 49
    Height = 21
    TabOrder = 5
    Text = '0'
  end
  object Edit18: TEdit
    Left = 128
    Top = 576
    Width = 49
    Height = 21
    TabOrder = 6
    Text = '0'
  end
  object Edit19: TEdit
    Left = 208
    Top = 576
    Width = 49
    Height = 21
    TabOrder = 7
    Text = '0'
  end
  object Button11: TButton
    Left = 128
    Top = 608
    Width = 49
    Height = 17
    Caption = 'Ver'
    TabOrder = 8
    OnClick = Button11Click
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
