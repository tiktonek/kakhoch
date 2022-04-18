//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
#include<vector>
#include<string>
#include<algorithm>
//---------------------------------------------------------------------------

class library{
	public:
		char name[100];
		char faculty[100];
		int year;
		int number;
		char email[100];

		bool friend operator==(const library &a, const library &b){
			return(
			strcmp(a.name,b.name)==0 ||
			strcmp(a.faculty,b.faculty)==0 ||
			strcmp(a.email,b.email)==0 ||
			a.year==b.year ||
			a.number==b.number
			);
		}
};



extern int curr, total;
extern std::vector <library> libdb;



class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *EditName;
	TEdit *EditFaculty;
	TEdit *EditCourse;
	TEdit *EditNumber;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *EditEmail;
	TLabel *Label5;
	TButton *ButtonAdd;
	TButton *ButtonLeft;
	TButton *ButtonRight;
	TLabel *LabelCurrent;
	TLabel *Label6;
	TLabel *LabelCount;
	TImageList *ImageList1;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TButton *ButtonSave;
	TButton *ButtonOpen;
	TLabel *Label7;
	TButton *ButtonDelete;
	TButton *ButtonSearch;
	TEdit *EditSearch;
	TButton *ButtonConfirm;
	TButton *ButtonCancel;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TCheckBox *CheckBox4;
	TCheckBox *CheckBox5;
	void __fastcall ShowRecord();
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ButtonLeftClick(TObject *Sender);
	void __fastcall ButtonRightClick(TObject *Sender);
	void __fastcall ButtonOpenClick(TObject *Sender);
	void __fastcall ButtonSaveClick(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall ButtonDeleteClick(TObject *Sender);
	void __fastcall ButtonSearchClick(TObject *Sender);
	void __fastcall ButtonConfirmClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
