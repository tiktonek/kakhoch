//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int curr=-1, total=0;
std::vector <library> libdb;

void __fastcall TForm1::ShowRecord(){
	if (libdb.size()!=0) {
	EditName->Text=libdb[curr].name;
	EditFaculty->Text=libdb[curr].faculty;
	EditCourse->Text=IntToStr(libdb[curr].year);
	EditNumber->Text=IntToStr(libdb[curr].number);
    EditEmail->Text=libdb[curr].email;    
	}
	LabelCount->Caption = IntToStr(total);
	LabelCurrent->Caption = IntToStr(curr+1);
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonAddClick(TObject *Sender)
{
if (EditName->Text == ""|| EditFaculty->Text == ""|| EditCourse->Text == ""|| EditNumber->Text == ""|| EditEmail->Text == "") {
	MessageBox(0, L"��� ���������� ������ ���������� ��������� ��� ����!",L"������!", MB_OK + MB_ICONWARNING);
	}
	libdb.push_back(library());
	strcpy(libdb[total].name,AnsiString(EditName->Text).c_str());
	strcpy(libdb[total].faculty,AnsiString(EditFaculty->Text).c_str());
	libdb[total].year =  EditCourse->Text.ToInt();
    libdb[total].number =  EditNumber->Text.ToInt();
	strcpy(libdb[total].email,AnsiString(EditEmail->Text).c_str());
	curr=total;
	total++;
	ShowRecord();
}

//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonLeftClick(TObject *Sender)
{
	if (curr > 0) curr--;
	ShowRecord();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonRightClick(TObject *Sender)
{
	if (curr < total-1) curr++;
	ShowRecord();
}
//---------------------------------------------------------------------------

