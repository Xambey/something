#include <iostream>
#include <string>
#include <ctime>
#include <cstring>
#include "matrix.h"
using namespace std;

void  // �������� �� ��������������
__test_isSymmetric()
{
	Matrix<int> m(4, 4, 0);

	std::cout << "�������: " << std::endl << m;
	std::cout << "�����������: " << (m.isSymmetric() ? "���" : "��") << std::endl << std::endl;
}

void //�������� ������
__test_operatorPlus()
{
	Matrix<int> a(3, 3, 2);
	Matrix<int> b(3, 3, 3);
	std::cout << "������� A:" << std::endl << a;
	std::cout << "������� B:" << std::endl << b;
	std::cout << "������� A+B:" << std::endl << a + b << std::endl;
}

void // ��������� ������
__test_operatorMinus()
{
	Matrix<int> a(3, 3, 2);
	Matrix<int> b(3, 3, 3);
	std::cout << "������� A:" << std::endl << a;
	std::cout << "������� B:" << std::endl << b;
	std::cout << "������� A-B:" << std::endl << a - b << std::endl;
}
void //�������� �������
__test_invert()
{
	Matrix <int> m(3, 3, 0);
	m.put(0, 0, 5);
	m.put(1, 1, 3);
	m.put(2, 2, 2);
	std::cout << m.invert() << std::endl;

}
void //���������������� �������
__test_transposition()
{
	Matrix <int> a(8, 4, 1);
	a.put(5, 1, 2);
	a.put(2, 3, 1);
	a.put(2, 2, 2);
	std::cout << "�������: " << std::endl << a << std::endl;
	std::cout << "Transp.: " << std::endl << a.transposition() << std::endl;
}

void //������������ �������
__test_determinant()
{
	Matrix <int> a(3, 3, 0);
	a.put(0, 0, 5);
	a.put(1, 1, 3);
	a.put(2, 2, 2);
	std::cout << "������� A:" << std::endl << a;
	std::cout << "det(A)=" << a.determinant() << std::endl;
}

void //����� �������
__test_isMinor()
{
	Matrix <int> m(4, 4, 0);
	for (int i = 0, i2 = 0; i < m.getRowCount(); i++, i2++) {
		for (int j = 0, j2 = 0; j < m.getColCount(); j++, j2++) {
			m.put(i2, j2, m.get(i, j));
		}
	}

	int row = 3, col = 3;
	std::cout << "�������: " << std::endl << m;
	std::cout << "����� (" << row << "," << col << ") = " << m.minor(row, col) << std::endl << std::endl;
}

void //������������� ������
__test_operatorUMN()
{
	Matrix<int> a(3, 3, 2);
	Matrix<int> b(2, 2, 3);
	std::cout << "������� A:" << std::endl << a;
	std::cout << "������� B:" << std::endl << b;
	std::cout << "������� A*B:" << std::endl << a*b << std::endl;
}

void //��������� ������
__test_equality()
{
	Matrix<int> a(3, 3, 3);
	Matrix<int> b(3, 3, 2);
	std::cout << "������� A:" << std::endl << a;
	std::cout << "������� B:" << std::endl << b << std::endl;
	std::cout << "A=B ?  " << (a == b ? "��" : "���") << std::endl;
	std::cout << "A!=B ?  " << (a != b ? "��" : "���") << std::endl;
	std::cout << "A>=B ?  " << (a >= b ? "��" : "���") << std::endl;
	std::cout << "A<=B ?  " << (a <= b ? "��" : "���") << std::endl << std::endl;
}
void //�������� ������� �� ������
__test_LoadByFile()
{
	Matrix <int> m(3, 3, 0);
	m.LoadByFile("matrix2.txt");
}

void //������ ������� � ����
__test_SaveFile()
{
	Matrix <int> m(3, 3, 0);
	m.SaveFile("matrix2.txt");
}

void // ���� ������� �������� n*m. ����� ������ ������� � ����������� ��������� � ������������� ������ ������� �� ���������� �������� ��������� ���������� �������.
__test_minCol()
{
	Matrix<int> m(5, 4, 0);
	cout << "�������������� ������� (������� �14):" << endl;
	for (int i = 0; i < m.getRowCount(); i++) {
		for (int j = 0; j < m.getColCount(); j++) {
			m.put(i, j, rand() % 100 - 50);
		}
	}
	cout << m << endl << "---" << endl << m.minCol() << endl;
}

int //������� �-��� (����)
main(int argc, char **argv)
{
	setlocale(0, "Russian");
	char key;
	cout << "����:\n1)���� ������� � ����������\n2)�������� ������\n3)��������� ������\n4)��������� ������\n5)���������������� �������\n6)�������������� �������(������� �14):\n'q' ��� ������\n";
	cin >> key;
	while (key != 'q')
	{
		switch (key)
		{
		case '1':
			cout << "\n���� �������: \n" << Matrix<int>::ReadKeyboard() << endl;
			break;
		case '2':
			cout << "\n���� ������� �� �����..." << endl;
			cout << "����� ������ � ����..." << endl;
			__test_operatorPlus();
			break;
		case '3':
			cout << "\n���� ������� �� �����..." << endl;
			cout << "����� ������ � ����..." << endl;
			__test_operatorMinus();
			break;
		case '4':
			cout << "\n���� ������� �� �����..." << endl;
			cout << "����� ������ � ����..." << endl;
			__test_operatorUMN();
			break;
		case '5':
			cout << "\n���� ������� �� �����..." << endl;
			cout << "����� ������ � ����..." << endl;
			__test_transposition();
			break;
		case '6':
			cout << "\n���� ������� �� �����..." << endl;
			cout << "����� ������ � ����..." << endl;
			__test_minCol();
			break;
		}
		system("pause");
		system("cls");
		cout << "����:\n1)���� ������� � ����������\n2)�������� ������\n3)��������� ������\n4)��������� ������\n5)���������������� �������\n6)�������������� �������(������� �14):\n'q' ��� ������\n";
		cin >> key;
	}

	//__test_isSymmetric();
	//__test_operatorPlus();
	//__test_operatorMinus();
	//__test_determinant();
	//__test_isMinor();
	//__test_operatorUMN();
	//__test_equality();
	//__test_transposition();
	//__test_minCol();
	//__test_LoadByFile();
	//__test_SaveFile();
	system("pause");
	return EXIT_SUCCESS;
}
