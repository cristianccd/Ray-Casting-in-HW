object FormPpal: TFormPpal
  Left = 257
  Top = 205
  Width = 928
  Height = 480
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
  object Image1: TImage
    Left = 392
    Top = 8
    Width = 256
    Height = 256
  end
  object Label1: TLabel
    Left = 656
    Top = 288
    Width = 217
    Height = 33
    Caption = 'Label1'
  end
  object Image2: TImage
    Left = 120
    Top = 8
    Width = 256
    Height = 256
  end
  object ListBox1: TListBox
    Left = 656
    Top = 8
    Width = 121
    Height = 257
    ItemHeight = 13
    TabOrder = 0
  end
  object OpenDialog1: TOpenDialog
    Left = 8
    Top = 32
  end
  object MainMenu1: TMainMenu
    Left = 40
    Top = 32
    object Archivo1: TMenuItem
      Caption = 'Archivo'
      object Abrir1: TMenuItem
        Caption = 'Abrir...'
        OnClick = Abrir1Click
      end
    end
  end
  object ImageList1: TImageList
    Left = 72
    Top = 32
  end
end
