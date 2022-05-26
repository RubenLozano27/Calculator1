#pragma once
#include <wx/string.h>
struct  Commands
{
	
};
class IBaseCommand
{
	wxString inputNum;
public:
	virtual void execute() = 0;
};

