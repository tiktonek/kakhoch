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
	: TForm(Owner)  {

	ButtonAdd->Hint= "�������� ������";
	ButtonSave->Hint= "��������� ������";
	ButtonOpen->Hint= "������� ����";
	ButtonDelete->Hint= "�������";
	ButtonSearch->Hint= "�����";
	ButtonConfirm->Hint= "�����������";
	ButtonCancel->Hint= "������";

}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonAddClick(TObject *Sender)
{
	EditName->Enabled= true;
	EditFaculty->Enabled= true;
	EditCourse->Enabled= true;
	EditNumber->Enabled= true;
	EditEmail->Enabled= true;
	ButtonDelete->Visible= true;
	ButtonSave->Visible= true;
	ButtonSearch->Visible= true;
	EditSearch->Visible= true;
	ButtonConfirm->Visible= true;
	ButtonCancel->Visible= true;
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
void __fastcall TForm1::ButtonSaveClick(TObject *Sender)
{
	if(SaveDialog1->Execute()){
		FILE * f = fopen(AnsiString(SaveDialog1->FileName).c_str(),"wb");
		fwrite(&libdb[0],sizeof(library),total,f);
		fclose(f);
	}
}

//---------------------------------------------------------------------------


void __fastcall TForm1::ButtonOpenClick(TObject *Sender)
{
	if(OpenDialog1->Execute()){
	FILE * f = fopen(AnsiString(OpenDialog1->FileName).c_str(),"rb");
	libdb.clear();
		do{
				library s;
				fread(&s,sizeof(library),1,f);
				if(feof(f)) break;
				libdb.push_back(s);
		}  while (!feof(f));
		total=libdb.size();
		curr=0;
		ShowRecord();
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N2Click(TObject *Sender)
{
      if(SaveDialog1->Execute()){
		FILE * f = fopen(AnsiString(SaveDialog1->FileName).c_str(),"wb");
		fwrite(&libdb[0],sizeof(library),total,f);
		fclose(f);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N3Click(TObject *Sender)
{
 if(OpenDialog1->Execute()){
	FILE * f = fopen(AnsiString(OpenDialog1->FileName).c_str(),"rb");
	libdb.clear();
		do{
				library s;
				fread(&s,sizeof(library),1,f);
				if(feof(f)) break;
				libdb.push_back(s);
		}  while (!feof(f));
		total=libdb.size();
		curr=0;
		ShowRecord();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonDeleteClick(TObject *Sender)
{
	if(total>0){
		libdb.erase(libdb.begin()+curr);
		total--;
		curr--;
		ShowRecord();
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::ButtonSearchClick(TObject *Sender)
{
	library s;
	std::vector<library>::iterator p;
	if (CheckBox1->Checked == true) {
	   strcpy(s.name,AnsiString(EditSearch->Text).c_str());
	}
	if (CheckBox2->Checked == true) {
	   strcpy(s.faculty,AnsiString(EditSearch->Text).c_str());
	}
	if (CheckBox3->Checked == true) {
	   s.year = EditSearch->Text.ToInt();
	}
	if (CheckBox4->Checked == true) {
	   s.number = EditSearch->Text.ToInt();
	}
	if (CheckBox5->Checked == true) {
	   strcpy(s.email,AnsiString(EditSearch->Text).c_str());
	}

	p=std::find(libdb.begin(),libdb.end(),s);
	curr=p-libdb.begin();
	if(curr<total) ShowRecord();
}
//---------------------------------------------------------------------------




void __fastcall TForm1::ButtonConfirmClick(TObject *Sender)
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

