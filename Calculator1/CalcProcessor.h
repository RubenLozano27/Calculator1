#pragma once
#include <bitset>
#include "IBaseCommand.h"
#include <functional>
#include"wx\string.h"
#include <vector>
class CalcProcessor 
{
private:
	CalcProcessor() {};
	static CalcProcessor* _calcProcessor;

public:
	std::vector<std::function<float (float,float)>> commands;
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
	void execute()
	{
	
	}
	float Add(float num1, float num2)
	{
		return num1 + num2;
	}
	float Subtract(float num1, float num2)
	{
		return num1 - num2;
	}
	float Multiply(float num1, float num2)
	{
		return num1 * num2;
	}
	float Divide(float num1, float num2)
	{
		return num1 / num2;
	}
	wxString binary(float num)
	{
		wxString binary;
		char* bits = reinterpret_cast<char*>(&num);
		binary = bits;
		return binary;
	}
	wxString Hex(float input)
	{
		wxString output;
		output.Format("%X", input);
		
		return output;
	}
};