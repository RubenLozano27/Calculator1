#pragma once
#include"wx/wx.h"
#include "ButtonFactory.h"
class Main :public wxFrame
{
public:
	Main();
	~Main();

public:
	ButtonFactory buttonbuilder;
	wxButton* btn[21];
	bool decimalClick = false;
	wxString titles[21] = { "0","1","2","3","4","5","6","7","8","9","Bin","Hex","Dex","Mod","+","-","*","/","=","C","."};
	wxTextCtrl* calcDisplay;
	void OnButtonClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

