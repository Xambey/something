#include <iostream>
#include <fstream>
#include <string>

/*
	* ���� �2
	* 15 �������
*/

int main(int argc, char **argv)
{
	std::ifstream In = std::ifstream("input.txt");

	int N, count = 0;
	In>>N;
	In.close();

	while(N!=0)
    {
		int m = N%2;
		if(m==1)
			count++;

		N-=m;
		N/=2;
	}

	std::ofstream Out = std::ofstream("output.txt");
	Out<<count;
	Out.close();

	return 0;
}