object FormPpal: TFormPpal
  Left = 96
  Top = 31
  Width = 723
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
    Left = 320
    Top = 544
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
  object ComboBox1: TComboBox
    Left = 560
    Top = 544
    Width = 137
    Height = 21
    ItemHeight = 13
    TabOrder = 4
    OnChange = ComboBox1Change
    Items.Strings = (
      'Vista Superior'
      'Vista Inferior'
      'Vista Lateral Izquierda'
      'Vista Lateral Derecha')
  end
  object OpenDialog1: TOpenDialog
  end
  object MainMenu1: TMainMenu
    Left = 32
    object Archivo1: TMenuItem
      Caption = 'Archivo'
      object Abrir1: TMenuItem
        Caption = 'Abrir...'
        OnClick = Abrir1Click
      end
    end
  end
end
