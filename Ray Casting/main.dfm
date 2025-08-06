object FormPpal: TFormPpal
  Left = 301
  Top = 26
  Width = 817
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
    Items.Strings = (
      'Vista Superior'
      'Vista Inferior'
      'Vista Lateral Izquierda'
      'Vista Lateral Derecha')
  end
  object Button1: TButton
    Left = 224
    Top = 544
    Width = 73
    Height = 33
    Caption = 'BORRAR'
    TabOrder = 5
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 424
    Top = 544
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 6
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 424
    Top = 584
    Width = 75
    Height = 25
    Caption = 'Button3'
    TabOrder = 7
    OnClick = Button3Click
  end
  object Edit1: TEdit
    Left = 736
    Top = 16
    Width = 49
    Height = 21
    TabOrder = 8
  end
  object Edit2: TEdit
    Left = 736
    Top = 40
    Width = 49
    Height = 21
    TabOrder = 9
  end
  object Edit3: TEdit
    Left = 736
    Top = 64
    Width = 49
    Height = 21
    TabOrder = 10
  end
  object Edit4: TEdit
    Left = 736
    Top = 112
    Width = 49
    Height = 21
    TabOrder = 11
  end
  object Edit5: TEdit
    Left = 736
    Top = 136
    Width = 49
    Height = 21
    TabOrder = 12
  end
  object Edit6: TEdit
    Left = 736
    Top = 160
    Width = 49
    Height = 21
    TabOrder = 13
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
