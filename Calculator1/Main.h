#pragma once
#include"wx/wx.h"
#include "ButtonFactory.h"
#include "CalcProcessor.h"
#include <vector>
class Main :public wxFrame
{
public:
	Main();
	~Main();
public:
	ButtonFactory buttonbuilder;
	wxButton* btn[22];
	bool negateClick = false;
	bool decimalClick = false;
	bool firstInput = true;
	bool numLock = false;
	wxString inputNum;
	std::vector<wxString> listOfNums;
	wxString titles[22] = { "0","1","2","3","4","5","6","7","8","9","Bin","Hex","Dex","Mod","+","-","*","/","=","+/-","C","."};
	wxTextCtrl* calcDisplay;
	void OnButtonClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

