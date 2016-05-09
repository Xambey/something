#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <string>
#include <cstring>
#include <fstream>

int main()
{
	std::string bufmonth;
	int D, M, Y;
	std::ifstream op("input.txt");
	while (!op.eof()) {
		op >> D >> bufmonth >> Y;
		//scanf("%d%s%d", &D, bufmonth.c_str(), &Y);
		//cin >> D >> bufmonth >> Y;
		if (!strcmp(bufmonth.c_str(), "January"))
			M = 1;
		else if (!strcmp(bufmonth.c_str(), "March"))
			M = 3;
		else if (!strcmp(bufmonth.c_str(), "April"))
			M = 4;
		else if (!strcmp(bufmonth.c_str(), "May"))
			M = 5;
		else if (!strcmp(bufmonth.c_str(), "June"))
			M = 6;
		else if (!strcmp(bufmonth.c_str(), "July"))
			M = 7;
		else if (!strcmp(bufmonth.c_str(), "August"))
			M = 8;
		else if (bufmonth[0] == 'F')
			M = 2;
		else if (bufmonth[0] == 'S')
			M = 9;
		else if (bufmonth[0] == 'O')
			M = 10;
		else if (bufmonth[0] == 'N')
			M = 11;
		else if (bufmonth[0] == 'D')
			M = 12;
		int a, y, m;
		register int R;
		a = (14 - M) / 12;
		y = Y - a;
		m = M | 12 & a - 2;
		std::string S[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
		R = (7000 | (D | y | y >> 2 - y / 100 | y / 400 | (31 & m) / 12)) % 7;
		printf("%s\n", S[R].c_str());
	}
	op.close();
	return 0;
}