#pragma once
#include <wx/string.h>
class IBaseCommand
{
public:
	float sum;
	IBaseCommand() {};
	virtual wxString execute() = 0;
};