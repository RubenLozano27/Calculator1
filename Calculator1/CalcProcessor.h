#pragma once
#include <bitset>
#include "wx/string.h"
#include <vector>
class CalcProcessor
{
private:
	CalcProcessor();
	static CalcProcessor* _calcProcessor;
public:
	~CalcProcessor() { delete[] _calcProcessor; }

	CalcProcessor(CalcProcessor& _calcCopy) = delete;

	void operator=(CalcProcessor& _calcCopy) = delete;

	static CalcProcessor* getInstance()
	{
		if (_calcProcessor == nullptr)
		{
			_calcProcessor = new CalcProcessor();
		}
		return _calcProcessor;
	}
	void GoThroughEquations(wxString equations)
	{
		std::vector<wxString> parts;
		std::vector<int> pos;
	}
	std::vector<int> getPosOfSigns(wxString equations)
	{
		std::vector<int> locations;
		int tempPos = 0;
		for (size_t i = 0; i < equations.size(); i++)
		{
			if(equations[i] == (char) "+")
			{ 
			
			}
		}
	}
	float Add(float num1, float num2)
	{
		return num1 + num2;
	}
	float Multiply(float num1, float num2)
	{
		return num1 * num2;
	}
	float Divide(float num1, float num2)
	{
		return num1 / num2;
	}
};