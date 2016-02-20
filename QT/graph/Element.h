#ifndef ELEMENT_H
#define ELEMENT_H
//#include "Operator.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <Operator.h>

struct Element {
	static vector<vector<Operator>> operation;
	string data;
	bool isX;
	double value;
	Operator * operaror = nullptr;
	Element *A = nullptr, *B = nullptr;

	Element(string data)
	{
		isX = false;
		this->data = data;
		bool flag = true;

		int sp;
		while (flag && data[0] == '(' && data[data.length() - 1] == ')')
		{
			sp = 0;
			for (unsigned int i = 1; i < data.length() - 2; i++)
			{
				if (data[i] == ')')
					sp--;
				else if (data[i] == '(')
					sp++;

				if (sp == -1) {
					flag = false;
					break;
				}
			}
			if (flag)
				data = data.substr(1, data.length() - 2);
		}

		if (data == "x")
		{
			isX = true;
			return;
		}

		for (unsigned int level = 0; level < Operator::operation.size(); level++) {
			sp = 0;
			for (int i = data.length() - 1; i >= 0; i--) {
				if (data[i] == ')')
					sp--;
				else if (data[i] == '(')
					sp++;
				else if (sp == 0) {
					auto list = &Operator::operation[level];
					for (auto op = list->begin(); op != list->end(); op++) {
						if (op->c == data[i]) {
							operaror = &(*op);
							if (operaror->f != nullptr)
								A = new Element(data.substr(0, i));
							B = new Element(data.substr(i + 1, data.length() - i - 1));
							return;
						}
					}
				}
			}
		}

		for (auto i = Operator::constant.begin(); i != Operator::constant.end(); i++) {
			if (data == i->first){
				value = i->second;
				return;
			}
		}

		value = atof(data.c_str());
	}

	double operator()(double x)
	{
		if (operaror != nullptr){
			if (operaror->f != nullptr)
				return operaror->f((*A)(x), (*B)(x));
			return operaror->u((*B)(x));
		}
		if (isX)
			return x;
		return value;
	}

	~Element()
	{
		if (A != nullptr)
			delete A;
		if (B != nullptr)
			delete B;
	}
};
#endif ELEMENT_H
