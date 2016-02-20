/*

10 ���� ������, ��������� �� ����, ����������� ���������. ������������ �����
������ �� ���������� ����������:
�) ��� ����� � ������ ��������, ����� ������ ����� ������� �����;
*/

#include <cstdio>
#include <ctype.h>
#include <cstring>

static void
MakeNewString(char * oldStr, char * newStr, int len)
{
	char ch;
	bool first = false;
	for (int i = 0; i < len; ++i) {
		ch = oldStr[i];
		if (isalpha(ch)) {
			if (isupper(ch) && first == false) {
				newStr[i] = ch;
				first = true;
			}
			else {
				newStr[i] = tolower(ch);
			}
		}
		else {
			newStr[i] = ch;
		}
	}
}

int
main()
{
	char str[] = "This Is a test.\n";
	char newStr[sizeof(str)];
	int sz = sizeof(str);
	memset(newStr, 0, sizeof(newStr));
	MakeNewString(str, newStr, sz);
	return 0;
}