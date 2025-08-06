object FormPpal: TFormPpal
  Left = 233
  Top = 67
  Width = 729
  Height = 619
  AutoSize = True
  BorderIcons = [biSystemMenu, biMinimize, biMaximize, biHelp]
  Caption = '::: MIP y Volume Rendering ::: Cristian D'#39'Alessandro :::'
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
    Left = 0
    Top = 0
    Width = 529
    Height = 529
    TabOrder = 0
    object Image1: TImage
      Left = 9
      Top = 8
      Width = 512
      Height = 512
      Cursor = crCross
      Enabled = False
      OnMouseDown = Image1MouseDown
      OnMouseMove = Image1MouseMove
    end
  end
  object Panel1: TPanel
    Left = 536
    Top = 0
    Width = 177
    Height = 129
    TabOrder = 1
    object ListBox1: TListBox
      Left = 8
      Top = 8
      Width = 161
      Height = 113
      ItemHeight = 13
      TabOrder = 0
      OnClick = ListBox1Click
    end
  end
  object Panel2: TPanel
    Left = 160
    Top = 232
    Width = 225
    Height = 73
    Color = clInactiveCaption
    TabOrder = 2
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
    Left = 0
    Top = 528
    Width = 529
    Height = 33
    TabOrder = 3
    object Edit1: TEdit
      Left = 48
      Top = 8
      Width = 41
      Height = 21
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 136
      Top = 8
      Width = 41
      Height = 21
      TabOrder = 1
    end
    object Edit3: TEdit
      Left = 232
      Top = 8
      Width = 41
      Height = 21
      TabOrder = 2
    end
    object Edit4: TEdit
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
      Left = 208
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
  object GroupBox3: TGroupBox
    Left = 536
    Top = 136
    Width = 177
    Height = 289
    Caption = 'Panel de Control'
    TabOrder = 4
    object Bevel3: TBevel
      Left = 8
      Top = 141
      Width = 161
      Height = 84
    end
    object Bevel1: TBevel
      Left = 8
      Top = 13
      Width = 161
      Height = 57
    end
    object Bevel2: TBevel
      Left = 8
      Top = 77
      Width = 161
      Height = 57
    end
    object CheckBox1: TCheckBox
      Left = 16
      Top = 16
      Width = 97
      Height = 17
      Caption = 'Filtrado Trilinear'
      Checked = True
      State = cbChecked
      TabOrder = 0
    end
    object RadioButton1: TRadioButton
      Left = 16
      Top = 88
      Width = 113
      Height = 17
      Caption = 'Volume Rendering'
      Checked = True
      TabOrder = 3
      TabStop = True
      OnClick = RadioButton1Click
    end
    object RadioButton2: TRadioButton
      Left = 16
      Top = 104
      Width = 113
      Height = 17
      Caption = 'MIP'
      TabOrder = 4
      OnClick = RadioButton2Click
    end
    object CheckBox2: TCheckBox
      Left = 16
      Top = 32
      Width = 97
      Height = 17
      Caption = 'Ecualizaci'#243'n'
      TabOrder = 1
    end
    object CheckBox3: TCheckBox
      Left = 16
      Top = 48
      Width = 97
      Height = 17
      Caption = 'Isodata'
      TabOrder = 2
    end
    object BitBtn2: TBitBtn
      Left = 40
      Top = 256
      Width = 89
      Height = 25
      Caption = 'A&PLICAR'
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 5
      OnClick = BitBtn2Click
      Kind = bkOK
    end
    object ProgressBar1: TProgressBar
      Left = 8
      Top = 232
      Width = 161
      Height = 17
      Min = 0
      Max = 1000
      Smooth = True
      TabOrder = 6
    end
    object StaticText7: TStaticText
      Left = 32
      Top = 160
      Width = 50
      Height = 17
      Caption = 'Azimuth= '
      TabOrder = 7
    end
    object StaticText8: TStaticText
      Left = 24
      Top = 184
      Width = 60
      Height = 17
      Caption = 'Elevacion= '
      TabOrder = 8
    end
    object Edit5: TEdit
      Left = 80
      Top = 158
      Width = 41
      Height = 21
      Enabled = False
      TabOrder = 9
      Text = '0'
    end
    object Edit6: TEdit
      Left = 80
      Top = 182
      Width = 41
      Height = 21
      Enabled = False
      TabOrder = 10
      Text = '0'
    end
  end
  object Salir: TGroupBox
    Left = 536
    Top = 520
    Width = 177
    Height = 41
    TabOrder = 5
    object BitBtn1: TBitBtn
      Left = 40
      Top = 10
      Width = 97
      Height = 25
      Caption = '&SALIR'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = BitBtn1Click
      Kind = bkClose
    end
  end
  object ByC: TGroupBox
    Left = 536
    Top = 432
    Width = 177
    Height = 89
    TabOrder = 6
    object Label4: TLabel
      Left = 68
      Top = 9
      Width = 45
      Height = 13
      Caption = 'BRILLO'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label5: TLabel
      Left = 56
      Top = 45
      Width = 76
      Height = 13
      Caption = 'CONTRASTE'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object UpDown1: TUpDown
      Left = 8
      Top = 24
      Width = 161
      Height = 17
      Min = 0
      Orientation = udHorizontal
      Position = 0
      TabOrder = 0
      Wrap = False
    end
    object UpDown2: TUpDown
      Left = 8
      Top = 60
      Width = 161
      Height = 17
      Min = 0
      Orientation = udHorizontal
      Position = 0
      TabOrder = 1
      Wrap = False
    end
    object Edit8: TEdit
      Left = 136
      Top = 8
      Width = 33
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -8
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      Text = '0'
    end
    object Edit9: TEdit
      Left = 136
      Top = 44
      Width = 33
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -8
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      Text = '0'
    end
  end
  object OpenDialog1: TOpenDialog
  end
  object MainMenu1: TMainMenu
    Left = 32
    object Archivo1: TMenuItem
      Caption = '&Archivo'
      object Abrir1: TMenuItem
        Caption = 'Abrir...'
        OnClick = Abrir1Click
      end
      object Guardar1: TMenuItem
        Caption = 'Guardar...'
        OnClick = Guardar1Click
      end
      object Salir1: TMenuItem
        Caption = 'Salir'
        OnClick = Salir1Click
      end
    end
    object E1: TMenuItem
      Caption = '&Edici'#243'n'
      object Ecualizacin1: TMenuItem
        Caption = 'Ecualizaci'#243'n'
        OnClick = Ecualizacin1Click
      end
      object Isodata1: TMenuItem
        Caption = 'Isodata'
        OnClick = Isodata1Click
      end
      object Umbralizacin1: TMenuItem
        Caption = 'Umbralizaci'#243'n'
        OnClick = Umbralizacin1Click
      end
    end
    object Filtros1: TMenuItem
      Caption = '&Filtros'
      object PasaBajos1: TMenuItem
        Caption = 'Pasa Bajos'
        OnClick = PasaBajos1Click
      end
      object PasaAltos1: TMenuItem
        Caption = 'Pasa Altos'
        OnClick = PasaAltos1Click
      end
    end
    object Ver1: TMenuItem
      Caption = '&Ver'
      object Rotar1: TMenuItem
        Caption = 'Rotar'
        OnClick = Rotar1Click
      end
      object Zoom1: TMenuItem
        Caption = 'Zoom'
        OnClick = Zoom1Click
      end
    end
  end
end
