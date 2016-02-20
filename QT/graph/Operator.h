#ifndef OPERATOR_H
#define OPERATOR_H

#include <string>
#include <vector>
#include <map>

#include "Element.h"
using namespace std;
struct Element;

struct Operator{
	static std::vector<vector<Operator>> operation;
	static map<string, double> constant;
	char c;
	string replace;
	double(*f)(double, double);
	double(*u)(double);

	static void add(unsigned int level, char c, double(*f)(double, double), string replace = "")
	{
		while (operation.size() <= level)
			operation.push_back(vector<Operator>());

		operation[level].push_back({ c, replace, f, nullptr });
	}

	static void add(unsigned int level, char c, double(*f)(double), string replace = "")
	{
		while (operation.size() <= level)
			operation.push_back(vector<Operator>());

		operation[level].push_back({ c, replace, nullptr, f });
	}

	static string format(string str)
	{
		for (unsigned int level = 0; level < operation.size(); level++) {
			for (unsigned int i = 0; i < operation[level].size(); i++) {
				string s = operation[level][i].replace;
				if (s != "") {
					int offest = 0;
					while ((offest = str.find(s, offest)) != std::string::npos) {
						str = str.replace(offest, s.length(), 1, operation[level][i].c);
						offest += s.length();
					}
				}
			}
		}
		return str;
	}
};
#endif OPERATOR_H
