#include "Main.h"
wxBEGIN_EVENT_TABLE(Main, wxFrame)
EVT_BUTTON(10001, OnButtonClicked)
wxEND_EVENT_TABLE()
CalcProcessor* CalcProcessor::_calcProcessor = nullptr;
Main::Main() :wxFrame(nullptr, wxID_ANY, "DaCalculator", wxPoint(30, 30), wxSize(400, 600), wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX))
{
	wxBoxSizer* vrs = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* vrsPlusMinus = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* vrsMultyDivide = new wxBoxSizer(wxVERTICAL);
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
	for (size_t i = 0; i < 22; i++)
	{
		btn[i] = buttonbuilder.BuildButton(this, titles[i], 100 + i);
	}
	for (size_t i = 0; i < 22; i++)
	{
		btn[i]->SetMinSize(wxSize(100,100));
		btn[i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::OnButtonClicked, this);
	}
	btn[14]->SetMinSize(wxSize(100, 50));
	btn[15]->SetMinSize(wxSize(100, 50));
	btn[16]->SetMinSize(wxSize(100, 50));
	btn[17]->SetMinSize(wxSize(100, 50));
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
	vrsMultyDivide->Add(btn[16]);
	vrsMultyDivide->Add(btn[17]);
	hrsRow4->Add(vrsMultyDivide);
	vrs->Add(hrsRow4);
	hrsRow5->Add(btn[7]);
	hrsRow5->Add(btn[8]);
	hrsRow5->Add(btn[9]);
	hrsRow5->Add(btn[19]);
	vrs->Add(hrsRow5);
	hrsRow6->Add(btn[21]);
	hrsRow6->Add(btn[0]);
	hrsRow6->Add(btn[20]);
	hrsRow6->Add(btn[18]);
	vrs->Add(hrsRow6);
	SetSizer(vrs);
}
Main::~Main()
{

}
void Main::OnButtonClicked(wxCommandEvent& evt)
{
	CalcProcessor* processor = processor->getInstance();
	btn[evt.GetId() - 100]->Enable(false);
	btn[evt.GetId() - 100]->Enable(true);
	if (!firstInput)
	{
		if (btn[evt.GetId() - 100] == btn[21])
		{
			if (!decimalClick && !firstInput && !numLock)
			{
				calcDisplay->AppendText(btn[evt.GetId() - 100]->GetLabelText());
				decimalClick = true;
			}
		}
		if (evt.GetId() - 100 > 13 && evt.GetId() - 100 < 18 && !decimalClick)
		{
			firstInput = true;
			negateClick = false;
			if (inputNum != "" && !numLock)
			{
				listOfNums.push_back(inputNum);
			}
			numLock = false;
			inputNum.clear();
			listOfNums.push_back(btn[evt.GetId() - 100]->GetLabelText());
			calcDisplay->AppendText(btn[evt.GetId() - 100]->GetLabelText());
		}
		if (evt.GetId()-100 == 18)
		{
			if (listOfNums.size() > 1)
			{
				if (inputNum != "")
				{
					listOfNums.push_back(inputNum);
				}
				numLock = true;
				inputNum.clear();
				float sum;
				wxString sumString;
				for (size_t i = 0; i < listOfNums.size(); i++)
				{
					/*union { float fval; std::uint32_t ival; };
					fval = sum;*/
					if (listOfNums[i] == "*")
					{
						sum = processor->Multiply(wxAtof(listOfNums[i - 1]), wxAtof(listOfNums[i + 1]));
						listOfNums.erase(listOfNums.begin() + (i - 1), listOfNums.begin() + (i + 2));
						sumString = wxString::Format(wxT("%.2f"), sum);
						listOfNums.insert(listOfNums.begin() + (i - 1), sumString);
						i--;
					}
					if (listOfNums[i] == "/")
					{
						sum = processor->Divide(wxAtof(listOfNums[i - 1]), wxAtof(listOfNums[i + 1]));
						listOfNums.erase(listOfNums.begin() + (i - 1), listOfNums.begin() + (i + 2));
						sumString = wxString::Format(wxT("%.2f"), sum);
						listOfNums.insert(listOfNums.begin() + (i - 1), sumString);
						i--;
					}
				}
				for (size_t i = 0; i < listOfNums.size(); i++)
				{
					if (listOfNums[i] == "+")
					{
						sum = processor->Add(wxAtof(listOfNums[i - 1]), wxAtof(listOfNums[i + 1]));
						listOfNums.erase(listOfNums.begin() + (i - 1), listOfNums.begin() + (i + 2));
						sumString = wxString::Format(wxT("%.2f"), sum);
						listOfNums.insert(listOfNums.begin() + (i - 1), sumString);
						i--;
					}
					if (listOfNums[i] == "-")
					{
						sum = processor->Subtract(wxAtof(listOfNums[i - 1]), wxAtof(listOfNums[i + 1]));
						listOfNums.erase(listOfNums.begin() + (i - 1), listOfNums.begin() + (i + 2));
						sumString = wxString::Format(wxT("%.2f"), sum);
						listOfNums.insert(listOfNums.begin() + (i - 1), sumString);
					}
				}
				if (listOfNums[0][0] != (char) "-")
				{
					negateClick = false;
				}
				calcDisplay->Clear();
				calcDisplay->AppendText(sumString);
			}
		}
		if (evt.GetId()-100 == 19)
		{
			if (inputNum != "")
			{
				listOfNums.push_back(inputNum);
			}
			wxString minus = "-";
			if (listOfNums.size() > 0 && listOfNums.size() < 2 && !negateClick)
			{
				negateClick = true;
				numLock = true;
				listOfNums[0].Prepend(minus);
				calcDisplay->Clear();
				calcDisplay->AppendText(listOfNums[0]);
			}
		}
	}
	if (evt.GetId() - 100 == 20)
	{
		calcDisplay->Clear();
		listOfNums.clear();
		inputNum.clear();
		numLock = false;
		firstInput = true;
	}
	if (evt.GetId() - 100 < 10 && !numLock)
	{
		inputNum += btn[evt.GetId() - 100]->GetLabelText();
		calcDisplay->AppendText(btn[evt.GetId() - 100]->GetLabelText());
		firstInput = false;
		decimalClick = false;
	}
	evt.Skip();
}