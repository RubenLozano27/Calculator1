#pragma once
#include <bitset>
#include "IBaseCommand.h"
#include <vector>
class CalcProcessor : IBaseCommand
{
private:
	CalcProcessor() {};
	static CalcProcessor* _calcProcessor;
public:
	std::vector<> commands;
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
};