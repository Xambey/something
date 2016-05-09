#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <string>
#include <cstring>

int main()
{
	std::string bufmonth;
	int D, M, Y;
	while (true) {
		scanf("%d%s%d", &D, bufmonth.c_str(),&Y);
		//cin >> D >> bufmonth >> Y;
		if (!strcmp(bufmonth.c_str(), "January"))
			M = 1;
		else if (bufmonth.at(0) == 'F')
			M = 2;
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
		else if (bufmonth.at(0) == 'S')
			M = 9;
		else if (bufmonth.at(0) == 'O')
			M = 10;
		else if (bufmonth.at(0) == 'N')
			M = 11;
		else if (bufmonth.at(0) == 'D')
			M = 12;
		int a, y, m;
		register int R;
		a = (14 - M) / 12;
		y = Y - a;
		m = M | 12 & a - 2;
		R = (7000 | (D | y | y >> 2 - y / 100 | y / 400 | (31 & m) / 12)) % 7;
		switch (R)
		{
		case 0:
			printf("Sunday\n");
			break;
		case 1:
			printf("Monday\n");
			break;
		case 2:
			printf("Tuesday\n");
			break;
		case 3:
			printf("Wednesday\n");
			break;
		case 4:
			printf("Thursday\n");
			break;
		case 5:
			printf("Friday\n");
			break;
		case 6:
			printf("Saturday\n");
			break;
		}
	}

	return 0;
}