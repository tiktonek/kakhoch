//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include<vector>
#include<string>
//---------------------------------------------------------------------------

class library{
	public:
		char name[100];
		char faculty[100];
		int year;
		int number;
		char email[100];
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
	TLabel *Label7;
	void __fastcall ShowRecord();
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ButtonLeftClick(TObject *Sender);
	void __fastcall ButtonRightClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
