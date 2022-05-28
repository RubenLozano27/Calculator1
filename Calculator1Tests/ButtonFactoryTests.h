#pragma once
#pragma warning(disable: 4996)
#include "wx/testing.h"
#include"wx/string.h"
#include"..\Calculator1\ButtonFactory.h"
#include"..\Calculator1\ButtonFactory.cpp"
class ButtonFactoryTests
{
public:
	ButtonFactoryTests() {};
	~ButtonFactoryTests() {};
public:
	wxButton* testbutton;
	ButtonFactory* factory = new ButtonFactory();
	void TestButtonFactoryButtonCreation()
	{
		testbutton = factory->BuildButton(NULL, "test", wxID_ANY);
		if (testbutton != nullptr)
			std::cout << "Pass" << std::endl;
		else
			std::cout << "Fail" << std::endl;
	}
	void TestButtonText()
	{
		wxString text = testbutton->GetLabelText();
		std::cout << text;
	}
};

