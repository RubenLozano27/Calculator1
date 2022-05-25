#pragma once
#include <bitset>
class CalcProcessor
{
private:
	CalcProcessor() {};
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