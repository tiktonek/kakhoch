object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1047#1072#1087#1080#1089#1100
  ClientHeight = 474
  ClientWidth = 635
  Color = clInactiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 215
    Top = 37
    Width = 23
    Height = 13
    Caption = #1060#1048#1054
  end
  object Label2: TLabel
    Left = 216
    Top = 99
    Width = 56
    Height = 13
    Caption = #1060#1072#1082#1091#1083#1100#1090#1077#1090
  end
  object Label3: TLabel
    Left = 216
    Top = 161
    Width = 24
    Height = 13
    Caption = #1050#1091#1088#1089
  end
  object Label4: TLabel
    Left = 216
    Top = 223
    Width = 131
    Height = 13
    Caption = #8470' '#1089#1090#1091#1076#1077#1085#1095#1077#1089#1082#1086#1075#1086' '#1073#1080#1083#1077#1090#1072
  end
  object Label5: TLabel
    Left = 216
    Top = 285
    Width = 28
    Height = 13
    Caption = 'e-mail'
  end
  object LabelCurrent: TLabel
    Left = 321
    Top = 365
    Width = 11
    Height = 13
    Caption = '0'
  end
  object Label6: TLabel
    Left = 472
    Top = 365
    Width = 89
    Height = 13
    Caption = #1050#1086#1083'-'#1074#1086' '#1079#1072#1087#1080#1089#1077#1081':'
  end
  object LabelCount: TLabel
    Left = 567
    Top = 365
    Width = 3
    Height = 13
  end
  object Label7: TLabel
    Left = 176
    Top = 8
    Width = 293
    Height = 13
    Caption = #1056#1077#1075#1080#1089#1090#1088#1072#1094#1080#1086#1085#1085#1072#1103' '#1092#1086#1088#1084#1072' '#1076#1083#1103' '#1086#1085#1083#1072#1081#1085' '#1079#1072#1087#1080#1089#1080' '#1074' '#1073#1080#1073#1083#1080#1086#1090#1077#1082#1091
  end
  object EditName: TEdit
    Left = 216
    Top = 56
    Width = 209
    Height = 21
    TabOrder = 0
  end
  object EditFaculty: TEdit
    Left = 216
    Top = 118
    Width = 209
    Height = 21
    TabOrder = 1
  end
  object EditCourse: TEdit
    Left = 216
    Top = 180
    Width = 209
    Height = 21
    TabOrder = 2
  end
  object EditNumber: TEdit
    Left = 216
    Top = 242
    Width = 209
    Height = 21
    TabOrder = 3
  end
  object EditEmail: TEdit
    Left = 216
    Top = 304
    Width = 209
    Height = 21
    TabOrder = 4
  end
  object ButtonAdd: TButton
    Left = 465
    Top = 404
    Width = 121
    Height = 33
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 5
    OnClick = ButtonAddClick
  end
  object ButtonLeft: TButton
    Left = 239
    Top = 352
    Width = 57
    Height = 42
    Caption = '<-'
    TabOrder = 6
    OnClick = ButtonLeftClick
  end
  object ButtonRight: TButton
    Left = 347
    Top = 352
    Width = 57
    Height = 42
    Caption = '->'
    TabOrder = 7
    OnClick = ButtonRightClick
  end
end
