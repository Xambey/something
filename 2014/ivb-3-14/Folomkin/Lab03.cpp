#include <iostream>
#include <fstream>
#include <string>

/*
	* ���� �3
	* 15 �������
		�������� ������, ���������� ��������� �����, ���������� �����������, ����
		��� ����� ��������� �������� ��� ����� �������, ��� � ������ ������. �����
		���� ������, � ������� �������� ����� s, ��������� �� n ��������� ����
		���������� ��������. ������������� �� ����� ����� ���������� ������ ��������
		����� �������� ������, ������� ����� �����������. ��������� ����� ����������
		�������� ������������ �� ������� ����� ���������� (��������, �������)
		������ ����� ��������, ��� ���������� � ���������� ������ �������� �����������.
		�������, ������������� ������ �������� ������������ ��������, ���������
		�����������.
*/

bool isPal(char * sub, int offest, int len)
{
	for(int i = 0; i< len/2; i++)
		if(sub[offest+i]!=sub[offest+len-1-i])
			return false;

	return true;
}

char * GetSub(char * sub, int offest, int len)
{
	char * phrase = new char[len+1];

	for(int m=0 ; m<len; m++)
		phrase[m] = sub[offest+m];

	phrase[len] = 0;
	return phrase;
}

int main(int argc, char **argv)
{
	setlocale(0, "");

	char * phrase = strdup("testset");
	int len = strlen(phrase),
		count = 0;

	for (int i = 0; i < len; i++)
	{
		for (int n = 1; n <= len - i; n++)
		{
			if(isPal(phrase, i, n))
			{
				printf("%s\n", GetSub(phrase, i, n));
				count++;
			}
		}
	}

	printf("���������� %i ��������� �������� �������� �� ������ \"%s\" ���������.\n", count, phrase);
	return 0;
}