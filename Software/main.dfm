object FormPpal: TFormPpal
  Left = 343
  Top = 169
  Width = 1097
  Height = 619
  AlphaBlend = True
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
    Left = 904
    Top = 0
    Width = 177
    Height = 185
    TabOrder = 1
    object ListBox1: TListBox
      Left = 8
      Top = 8
      Width = 161
      Height = 169
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
    Top = 192
    Width = 177
    Height = 369
    Caption = 'Panel de Control'
    TabOrder = 4
    object Bevel3: TBevel
      Left = 8
      Top = 168
      Width = 161
      Height = 57
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
      Height = 84
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
      Top = 112
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
      Top = 336
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
      Top = 312
      Width = 161
      Height = 17
      Min = 0
      Max = 1000
      Smooth = True
      TabOrder = 6
    end
    object StaticText7: TStaticText
      Left = 32
      Top = 176
      Width = 50
      Height = 17
      Caption = 'Azimuth= '
      TabOrder = 7
    end
    object StaticText8: TStaticText
      Left = 24
      Top = 200
      Width = 60
      Height = 17
      Caption = 'Elevacion= '
      TabOrder = 8
    end
    object Edit5: TEdit
      Left = 80
      Top = 174
      Width = 41
      Height = 21
      Enabled = False
      TabOrder = 9
      Text = '0'
    end
    object Edit6: TEdit
      Left = 80
      Top = 198
      Width = 41
      Height = 21
      Enabled = False
      TabOrder = 10
      Text = '0'
    end
    object GroupBox7: TGroupBox
      Left = 8
      Top = 248
      Width = 161
      Height = 41
      Caption = 'Filtros'
      TabOrder = 11
      object Button2: TButton
        Left = 40
        Top = 16
        Width = 81
        Height = 17
        Caption = 'CON&FIRMAR'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        OnClick = Button2Click
      end
    end
    object RadioButton8: TRadioButton
      Left = 16
      Top = 136
      Width = 113
      Height = 17
      Caption = 'Transparencias'
      TabOrder = 12
      OnClick = RadioButton8Click
    end
  end
  object Salir: TGroupBox
    Left = 720
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
    Left = 904
    Top = 336
    Width = 177
    Height = 145
    TabOrder = 6
    object Label4: TLabel
      Left = 68
      Top = 17
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
      Left = 48
      Top = 77
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
    object Edit9: TEdit
      Left = 136
      Top = 76
      Width = 33
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -4
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      Text = '0'
    end
    object Edit8: TEdit
      Left = 136
      Top = 16
      Width = 33
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -4
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      Text = '0'
    end
    object ScrollBar1: TScrollBar
      Left = 8
      Top = 40
      Width = 161
      Height = 25
      Enabled = False
      Max = 255
      PageSize = 0
      TabOrder = 2
      OnChange = ScrollBar1Change
    end
    object ScrollBar2: TScrollBar
      Left = 8
      Top = 104
      Width = 161
      Height = 25
      Max = 150
      PageSize = 0
      Position = 100
      TabOrder = 3
      OnChange = ScrollBar1Change
    end
  end
  object GroupBox4: TGroupBox
    Left = 904
    Top = 192
    Width = 177
    Height = 137
    Caption = 'Umbrales'
    TabOrder = 7
    object Bevel4: TBevel
      Left = 8
      Top = 16
      Width = 161
      Height = 105
    end
    object StaticText9: TStaticText
      Left = 32
      Top = 48
      Width = 42
      Height = 17
      Caption = 'Inferior='
      TabOrder = 0
    end
    object StaticText10: TStaticText
      Left = 36
      Top = 24
      Width = 38
      Height = 17
      Caption = 'Ruido='
      TabOrder = 1
    end
    object Edit7: TEdit
      Left = 80
      Top = 44
      Width = 41
      Height = 21
      Enabled = False
      TabOrder = 2
      Text = '200'
    end
    object Edit10: TEdit
      Left = 80
      Top = 20
      Width = 41
      Height = 21
      TabOrder = 3
      Text = '50'
    end
    object CheckBox4: TCheckBox
      Left = 40
      Top = 96
      Width = 97
      Height = 17
      Caption = 'Segmentacion'
      TabOrder = 4
      OnClick = CheckBox4Click
    end
    object Edit11: TEdit
      Left = 80
      Top = 68
      Width = 41
      Height = 21
      Enabled = False
      TabOrder = 5
      Text = '250'
    end
    object StaticText11: TStaticText
      Left = 24
      Top = 72
      Width = 49
      Height = 17
      Caption = 'Superior='
      TabOrder = 6
    end
  end
  object GroupBox5: TGroupBox
    Left = 720
    Top = 192
    Width = 177
    Height = 137
    Caption = 'Profundidad Ray Casting'
    TabOrder = 8
    object Bevel5: TBevel
      Left = 8
      Top = 24
      Width = 161
      Height = 97
    end
    object StaticText12: TStaticText
      Left = 32
      Top = 56
      Width = 4
      Height = 4
      TabOrder = 0
    end
    object StaticText13: TStaticText
      Left = 35
      Top = 40
      Width = 45
      Height = 17
      Caption = 'M'#237'nima='
      TabOrder = 1
    end
    object Edit13: TEdit
      Left = 88
      Top = 36
      Width = 41
      Height = 21
      Enabled = False
      TabOrder = 2
      Text = '0'
    end
    object CheckBox5: TCheckBox
      Left = 48
      Top = 96
      Width = 97
      Height = 17
      Caption = 'Autom'#225'tico'
      Checked = True
      State = cbChecked
      TabOrder = 3
      OnClick = CheckBox5Click
    end
    object StaticText14: TStaticText
      Left = 35
      Top = 72
      Width = 46
      Height = 17
      Caption = 'M'#225'xima='
      TabOrder = 4
    end
    object Edit12: TEdit
      Left = 88
      Top = 68
      Width = 41
      Height = 21
      Enabled = False
      TabOrder = 5
      Text = '0'
    end
  end
  object GroupBox6: TGroupBox
    Left = 720
    Top = 336
    Width = 177
    Height = 145
    Caption = 'LUT'
    TabOrder = 9
    object Bevel6: TBevel
      Left = 8
      Top = 16
      Width = 161
      Height = 97
    end
    object RadioButton7: TRadioButton
      Left = 32
      Top = 88
      Width = 113
      Height = 17
      Caption = 'Exponencial'
      TabOrder = 0
    end
    object RadioButton5: TRadioButton
      Left = 32
      Top = 72
      Width = 113
      Height = 17
      Caption = 'Bajos'
      TabOrder = 1
    end
    object RadioButton6: TRadioButton
      Left = 32
      Top = 56
      Width = 113
      Height = 17
      Caption = 'Medios'
      TabOrder = 2
    end
    object RadioButton4: TRadioButton
      Left = 32
      Top = 40
      Width = 113
      Height = 17
      Caption = 'Altos'
      TabOrder = 3
    end
    object RadioButton3: TRadioButton
      Left = 32
      Top = 24
      Width = 113
      Height = 17
      Caption = 'Ninguna'
      Checked = True
      TabOrder = 4
      TabStop = True
    end
    object Button1: TButton
      Left = 64
      Top = 120
      Width = 57
      Height = 17
      Caption = 'PRE&VIA'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 5
      OnClick = Button1Click
    end
  end
  object Chart1: TChart
    Left = 536
    Top = 0
    Width = 361
    Height = 185
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    Title.Text.Strings = (
      'Histograma')
    BottomAxis.Automatic = False
    BottomAxis.AutomaticMaximum = False
    BottomAxis.AutomaticMinimum = False
    BottomAxis.Maximum = 256
    BottomAxis.Title.Caption = 'Intensidad'
    LeftAxis.Title.Caption = 'Apariciones'
    Legend.Visible = False
    View3D = False
    TabOrder = 10
    object Series1: TAreaSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clRed
      AreaLinesPen.Visible = False
      DrawArea = True
      LinePen.Color = clRed
      LinePen.Visible = False
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
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
        ShortCut = 16463
        OnClick = Abrir1Click
      end
      object Guardar1: TMenuItem
        Caption = 'Guardar...'
        ShortCut = 16467
        OnClick = Guardar1Click
      end
      object Imprimir1: TMenuItem
        Caption = 'Imprimir'
        ShortCut = 16464
        OnClick = Imprimir1Click
      end
      object Salir1: TMenuItem
        Caption = 'Salir'
        OnClick = Salir1Click
      end
    end
    object E1: TMenuItem
      Caption = '&Edici'#243'n'
      object Bilinear1: TMenuItem
        Caption = 'Bilinear'
        OnClick = Bilinear1Click
      end
      object Ecualizacin1: TMenuItem
        Caption = 'Ecualizaci'#243'n'
        OnClick = Ecualizacin1Click
      end
      object Isodata1: TMenuItem
        Caption = 'Isodata'
        OnClick = Isodata1Click
      end
    end
    object Filtros1: TMenuItem
      Caption = '&Filtros'
      object PasaAltos1: TMenuItem
        Caption = 'Pasa Altos'
        OnClick = PasaAltos1Click
      end
      object PasaBajos1: TMenuItem
        Caption = 'Pasa Bajos'
        OnClick = PasaBajos1Click
      end
    end
    object Ver1: TMenuItem
      Caption = '&Ver'
      object Zoom1: TMenuItem
        Caption = 'Zoom'
        OnClick = Zoom1Click
      end
    end
  end
  object SaveDialog1: TSaveDialog
    Left = 64
  end
  object PrintDialog1: TPrintDialog
    Left = 96
  end
end
