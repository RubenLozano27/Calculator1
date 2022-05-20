#include "Main.h"
wxBEGIN_EVENT_TABLE(Main, wxFrame)
EVT_BUTTON(10001, OnButtonClicked)
wxEND_EVENT_TABLE()
Main::Main() :wxFrame(nullptr, wxID_ANY, "DaCalculator", wxPoint(30, 30), wxSize(400, 600), wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX))
{
	wxBoxSizer* vrs = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* vrsPlusMinus = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* hrs = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* hrsRow2 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* hrsRow3 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* hrsRow4 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* hrsRow5 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* hrsRow6 = new wxBoxSizer(wxHORIZONTAL);
	calcDisplay = new wxTextCtrl(this,1000);
	calcDisplay->SetMinSize(wxSize(400, 100));
	hrs->Add(calcDisplay);
	vrs->Add(hrs);
	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	calcDisplay->SetFont(font);
	btn[10] = new wxButton(this, 110, "Bin");
	btn[11] = new wxButton(this, 111, "Hex");
	btn[12] = new wxButton(this, 112, "Dex");
	btn[13] = new wxButton(this, 113, "Mod");
	btn[14] = new wxButton(this, 114, "+");
	btn[15] = new wxButton(this, 115, "-");
	btn[16] = new wxButton(this, 116, "*");
	btn[17] = new wxButton(this, 117, "/");
	btn[18] = new wxButton(this, 118,"=");
	btn[19] = new wxButton(this, 119, "C");
	btn[20] = new wxButton(this, 120, ".");
	for (int i = 0; i < 10; i++)
	{
		if (i == 0)
			btn[i] = new wxButton(this, 100 + i, std::to_string(i));
		else
			btn[i] = new wxButton(this, 100 + i, std::to_string(i));
	}
	for (size_t i = 0; i < 21; i++)
	{
		btn[i]->SetMinSize(wxSize(100,100));
		btn[i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::OnButtonClicked, this);
	}
	btn[14]->SetMinSize(wxSize(100, 50));
	btn[15]->SetMinSize(wxSize(100, 50));
	hrsRow2->Add(btn[10]);
	hrsRow2->Add(btn[11]);
	hrsRow2->Add(btn[12]);
	hrsRow2->Add(btn[13]);
	vrs->Add(hrsRow2);
	hrsRow3->Add(btn[1]);
	hrsRow3->Add(btn[2]);
	hrsRow3->Add(btn[3]);
	vrsPlusMinus->Add(btn[14]);
	vrsPlusMinus->Add(btn[15]);
	hrsRow3->Add(vrsPlusMinus);
	vrs->Add(hrsRow3);
	hrsRow4->Add(btn[4]);
	hrsRow4->Add(btn[5]);
	hrsRow4->Add(btn[6]);
	hrsRow4->Add(btn[16]);
	vrs->Add(hrsRow4);
	hrsRow5->Add(btn[7]);
	hrsRow5->Add(btn[8]);
	hrsRow5->Add(btn[9]);
	hrsRow5->Add(btn[17]);
	vrs->Add(hrsRow5);
	hrsRow6->Add(btn[20]);
	hrsRow6->Add(btn[0]);
	hrsRow6->Add(btn[19]);
	hrsRow6->Add(btn[18]);
	vrs->Add(hrsRow6);
	SetSizer(vrs);
}
Main::~Main()
{

}
void Main::OnButtonClicked(wxCommandEvent& evt)
{
	btn[evt.GetId() - 100]->Enable(false);
	btn[evt.GetId() - 100]->Enable(true);
	if (btn[evt.GetId() - 100] == btn[20])
	{
		if (!decimalClick)
		{
			calcDisplay->AppendText(btn[evt.GetId() - 100]->GetLabelText());
		}
		decimalClick = true;
	}
	else if (evt.GetId() - 100 > 14 && evt.GetId() - 100 < 18)
	{
		decimalClick = false;
		calcDisplay->AppendText(btn[evt.GetId() - 100]->GetLabelText());
	}
	else if (evt.GetId() - 100 == 19)
	{
		calcDisplay->Clear();
	}
	else
	{
		calcDisplay->AppendText(btn[evt.GetId() - 100]->GetLabelText());
	}
}