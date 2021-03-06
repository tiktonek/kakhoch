//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int curr=-1, total=0,y=-1,k=-1;
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

	ButtonAdd->Hint= "???????? ????? ??????";
	ButtonSave->Hint= "????????? ??????";
	ButtonOpen->Hint= "??????? ????";
	ButtonDelete->Hint= "???????";
	ButtonSearch->Hint= "?????";
	ButtonConfirm->Hint= "???????????";
	ButtonCancel->Hint= "??????";
	ButtonEdit->Hint= "?????????????";

	if(total>1 && curr==1){
	ButtonRight->Visible = true;
	}
	if(total>1 && curr==total){
		ButtonRight->Visible = false;
		ButtonLeft->Visible = true;
	}
	if(total>1 && curr!=total){
		ButtonRight->Visible = true;
		ButtonLeft->Visible = true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonAddClick(TObject *Sender)
{
	EditName->Enabled= true;
	EditFaculty->Enabled= true;
	EditCourse->Enabled= true;
	EditNumber->Enabled= true;
	EditEmail->Enabled= true;
	
	ButtonAdd->Enabled= false;
	ButtonSearch->Enabled= false;
	ButtonEdit->Enabled= false;
	ButtonOpen->Enabled= false;
	ButtonSave->Enabled= false;
	ButtonDelete->Enabled= false;


	ButtonConfirm->Visible= true;
	ButtonCancel1->Visible= true;
	ButtonCancel->Visible= false;
	EditName->Text= "";
	EditFaculty->Text= "";
	EditCourse->Text= "";
	EditNumber->Text= "";
	EditEmail->Text= "";
	curr=total;
	total++;
	LabelCount->Caption= total;
	LabelCurrent->Caption= curr+1;



//	k+=1;
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
	ButtonDelete->Visible= true;
	ButtonSave->Visible= true;
	ButtonSearch->Visible= true;
	ButtonEdit->Visible= true;
	EditSearch->Visible= false;
	ButtonSearch->Enabled= true;
	ButtonEdit->Enabled= true;
	ButtonDelete->Enabled= true;
	ButtonSave->Enabled= true;
	Button1->Visible= false;
	CheckBox1->Visible= false;
	CheckBox2->Visible= false;
	CheckBox3->Visible= false;
	CheckBox4->Visible= false;
	CheckBox5->Visible= false;
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
		if((curr>0) || (curr==total)){
		curr--;
		}
		if(total==0){
		EditName->Text= "";
		EditFaculty->Text= "";
		EditCourse->Text= "";
		EditNumber->Text= "";
		EditEmail->Text= "";
		ButtonSearch->Enabled= false;
		ButtonEdit->Enabled= false;
		ButtonSave->Enabled= false;
		ButtonDelete->Enabled= false;
		}
	}
	ShowRecord();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::ButtonSearchClick(TObject *Sender)
{
	library s;
	int i=0;
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

	search:
	p=std::find(libdb.begin()+i,libdb.end(),s);
	if(curr== p - libdb.begin()){
i++;
goto search;
}
curr=p-libdb.begin();
if(curr<total){
ShowRecord();
LabelCurrent->Caption = curr+1;
}else{
curr=0;
LabelCurrent->Caption = 1;
ShowRecord();
}
//	curr=p-libdb.begin();
//	if(curr<total) ShowRecord();

	EditSearch->Visible= true;
	Button1->Visible= true;
    ButtonAdd->Enabled= false;
	ButtonConfirm->Visible= false;
	ButtonCancel->Visible= false;
	ButtonCancel1->Visible= false;
	ButtonDelete->Enabled= false;
	ButtonEdit->Enabled= false;
	EditName->Enabled= false;
	EditFaculty->Enabled= false;
	EditCourse->Enabled= false;
	EditNumber->Enabled= false;
	EditEmail->Enabled= false;
}
//---------------------------------------------------------------------------




void __fastcall TForm1::ButtonConfirmClick(TObject *Sender)
{
if (EditName->Text == ""|| EditFaculty->Text == ""|| EditCourse->Text == ""|| EditNumber->Text == ""|| EditEmail->Text == "") {
	MessageBox(0, L"??? ?????????? ?????? ?????????? ????????? ??? ????!",L"??????!", MB_OK + MB_ICONWARNING);
	}
////	if (k % 2 == 0) {
	libdb.push_back(library());
//	strcpy(libdb[total-1].name,AnsiString(EditName->Text).c_str());
//	strcpy(libdb[total-1].faculty,AnsiString(EditFaculty->Text).c_str());
//	libdb[total-1].year =  EditCourse->Text.ToInt();
//	libdb[total-1].number =  EditNumber->Text.ToInt();
//	strcpy(libdb[total-1].email,AnsiString(EditEmail->Text).c_str());
////	k+=1;
//	}

//	if(y%2==0){
	strcpy(libdb[curr].name,AnsiString(EditName->Text).c_str());
	strcpy(libdb[curr].faculty,AnsiString(EditFaculty->Text).c_str());
	libdb[curr].year = EditCourse->Text.ToInt();
	libdb[curr].number = EditNumber->Text.ToInt();
	strcpy(libdb[curr].email,AnsiString(EditEmail->Text).c_str());
//	y+=1;
//	}
//	ShowRecord();

    ButtonDelete->Visible= true;
	ButtonSave->Visible= true;
	ButtonSearch->Visible= true;
	ButtonEdit->Visible= true;
	EditName->Enabled= false;
	EditFaculty->Enabled= false;
	EditCourse->Enabled= false;
	EditNumber->Enabled= false;
	EditEmail->Enabled= false;
	ButtonSearch->Enabled= true;
	ButtonEdit->Enabled= true;
	ButtonCancel1->Visible= false;
	ButtonCancel->Visible= false;
	ButtonConfirm->Visible= false;
	ButtonAdd->Enabled= true;
	ButtonDelete->Enabled= true;
	ButtonOpen->Enabled= true;
	ButtonSave->Enabled= true;
	ButtonSearch->Enabled= true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditSearchChange(TObject *Sender)
{
	CheckBox1->Visible= true;
	CheckBox2->Visible= true;
	CheckBox3->Visible= true;
	CheckBox4->Visible= true;
	CheckBox5->Visible= true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonCancelClick(TObject *Sender)
{
	EditName->Enabled= false;
	EditFaculty->Enabled= false;
	EditCourse->Enabled= false;
	EditNumber->Enabled= false;
	EditEmail->Enabled= false;
	ButtonConfirm->Visible= false;
	ButtonCancel->Visible= false;
	EditSearch->Visible= false;
	ButtonAdd->Enabled= true;
	ButtonSearch->Enabled= true;
	ButtonDelete->Enabled= true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonEditClick(TObject *Sender)
{
//	y+=1;
	EditName->Enabled= true;
	EditFaculty->Enabled= true;
	EditCourse->Enabled= true;
	EditNumber->Enabled= true;
	EditEmail->Enabled= true;
	ButtonDelete->Visible= true;
	ButtonSave->Visible= true;
	ButtonSearch->Visible= true;
	ButtonDelete->Enabled= true;
	ButtonSearch->Enabled= false;
	ButtonDelete->Enabled= false;

	ButtonConfirm->Visible= true;
	ButtonCancel->Visible= true;
	ButtonAdd->Enabled= false;
	CheckBox1->Visible= false;
	CheckBox2->Visible= false;
	CheckBox3->Visible= false;
	CheckBox4->Visible= false;
	CheckBox5->Visible= false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	EditSearch->Visible= false;
	Button1->Visible= false;
	CheckBox1->Visible= false;
	CheckBox2->Visible= false;
	CheckBox3->Visible= false;
	CheckBox4->Visible= false;
	CheckBox5->Visible= false;
	ButtonAdd->Enabled= true;
	ButtonDelete->Enabled= true;
	ButtonEdit->Enabled= true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ButtonCancel1Click(TObject *Sender)
{
	if(total==1){
	total=0;
	curr=0;
	ShowRecord();
	EditName->Enabled= false;
	EditFaculty->Enabled= false;
	EditCourse->Enabled= false;
	EditNumber->Enabled= false;
	EditEmail->Enabled= false;
//	ButtonDelete->Visible= true;
//	ButtonSave->Visible= true;
//	ButtonSearch->Visible= true;
//	ButtonEdit->Visible= true;



	EditName->Text= "";
	EditFaculty->Text= "";
	EditCourse->Text= "";
	EditNumber->Text= "";
	EditEmail->Text= "";

	}

	if(total>1){
	total--;
	curr--;
	ShowRecord();

	EditName->Enabled= false;
	EditFaculty->Enabled= false;
	EditCourse->Enabled= false;
	EditNumber->Enabled= false;
	EditEmail->Enabled= false;
	ButtonSearch->Enabled= true;
	ButtonEdit->Enabled= true;
	ButtonDelete->Enabled= true;
	ButtonSave->Enabled= true;
	ButtonDelete->Visible= true;
	ButtonSave->Visible= true;
	ButtonSearch->Visible= true;
	ButtonEdit->Visible= true;
	}
	ButtonConfirm->Visible= false;
	ButtonCancel1->Visible= false;
	ButtonAdd->Enabled= true;
	ButtonOpen->Enabled= true;

}
//---------------------------------------------------------------------------


