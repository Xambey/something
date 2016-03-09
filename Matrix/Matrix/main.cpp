#include <iostream>
#include <string>
#include <ctime>
#include <cstring>
#include "matrix.cpp"
using namespace std;

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

void //���������������� �������
__test_transposition()
{
    Matrix <int> a(8, 4, 1);
    a.put(5, 1, 2);
    a.put(2, 3, 1);
    a.put(2, 2, 2);
    std::cout << "�������: " << std::endl << a << std::endl;
    std::cout << "Transp.: " << std::endl << a.transponse() << std::endl;
}



void //������������ ������
__test_operatorUMN()
{
    Matrix<int> a(3, 3, 2);
    Matrix<int> b(2, 2, 3);
    std::cout << "������� A:" << std::endl << a;
    std::cout << "������� B:" << std::endl << b;
    std::cout << "������� A*B:" << std::endl << a*b << std::endl;
}


void //�������� ������� �� ������
__test_LoadByFile()
{
    Matrix <int> m(3, 3, 0);
    m.loadFromFile("matrix2.txt");
}

void //������ ������� � ����
__test_SaveFile()
{
    Matrix <int> m(3, 3, 0);
    m.saveToFile("matrix2.txt");
}

void // � �������, ��������� �� ����� � ������, ������� ������� (���������� ����������) ����������� �������, ��������� ������ �� �����.
__test_podmatrix()
{
    Matrix<int> m(8, 8, 1);
    for (int i = 1; i < m.getRowCount() - 1; i++)
    {
        for (int j = 1; j < m.getColCount() - 1; j++)
        {
            m.put(i, j, 0);
        }
    }
    m.put(3, 2, 1);
    cout << "�������������� ������� (������� �13):" << endl << "�������� �������: " << endl;
    for (int i = 0; i < m.getRowCount(); i++)
    {
        for (int j = 0; j < m.getColCount(); j++)
        {
            cout << m.get(i, j) << " ";
        }
        cout << endl;
    }
    int col = 0;

    col = m.individualFind();
    cout << endl << "����������. ������ ���������� = " << col << " x " << col << endl;;
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "0" << " ";
        }
        cout << endl;
    }
}

int //������� �-��� (����)
main(int argc, char **argv)
{
	setlocale(LC_ALL, "Russian");
    char key;
    cout << "\t����:\n1)���� ������� � ����������\n2)�������� ������\n3)��������� ������\n4)��������� ������\n5)���������������� �������\n6)�������������� �������(������� �13):\n'q' ��� ������\n";
    cin >> key;
    Matrix <int> m(3, 3, 0);
    while (key != 'q')
    {
        switch (key)
        {
        case '1':
			cout << "\n���� �������: \n" << endl;
			m.readFromKeyboard();
            //m.loadFromFile("matrix2.txt");
            //cout << m;
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
            __test_podmatrix();
            break;
        }
        cout << "\n\n\t����:\n1)���� ������� � ����������\n2)�������� ������\n3)��������� ������\n4)��������� ������\n5)���������������� �������\n6)�������������� �������(������� �13):\n'q' ��� ������\n";
        cin >> key;
    }
    return EXIT_SUCCESS;
}