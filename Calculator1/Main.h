#pragma once
#include"wx/wx.h"

class Main :public wxFrame
{
public:
	Main();
	~Main();

public:
	wxButton* btn[21];
	bool decimalClick = false;
	wxTextCtrl* calcDisplay;
	void OnButtonClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

