#pragma once

#include <vector>
#include <string>
#include "resource.h"
#include <iostream>
#include <exception>
#include <fstream>
#include <iterator>

using namespace std;

template <typename Type>
class Matrix
{
	typedef vector<Type> MatrixRow;
	typedef vector<MatrixRow> matrix;
	matrix value;
public:
	Matrix();
	Matrix(int row, int col, const Type& val);
	void Clear();
	int GetColCount() const;
	int GetRowCount() const;
	Type GetValue(int row, int col) const;
	void PutValue(int row, int col, const Type& val);
	void SetValue(const Type& val);
	void Print() const;
	void Transform();
	//операции
	Matrix operator +(const Type& right);
	Matrix operator -(const Type& right);
	Matrix operator *(const Matrix& right);
	Matrix operator *(const Type& right);
	Matrix operator /(const Type& right);
	Matrix operator /(const Matrix& right);
	Matrix operator ^(const Type& right);
	Matrix operator =(const Matrix& right);
	Matrix operator +(const Matrix& right);
	Matrix operator -(const Matrix& right);
};

template<typename Type>
inline Matrix<Type>::Matrix():Matrix(1,1,0)
{
}

template<typename Type>
inline Matrix<Type>::Matrix(int row, int col, const Type& val)
{
	for (auto i = 0; i < row; i++) {
		auto string = MatrixRow(col);
		fill(string.begin(), string.end(), val);
		value.push_back(string);
	}
}

template<typename Type>
inline void Matrix<Type>::Clear()
{
	if (GetRowCount() > 0 && GetColCount() > 0) {
		for (auto i = 0; i < GetRowCount(); i++) {
			for (auto j = 0; j < GetColCount(); j++) {
				PutValue(i, j, 0);
			}
		}
	}
}

template<typename Type>
inline int Matrix<Type>::GetColCount() const
{
	if (value.empty()) return 0;
	return value[0].size();
}

template<typename Type>
inline int Matrix<Type>::GetRowCount() const
{
	if (value.empty()) return 0;
	return value.size();
}

template<typename Type>
inline Type Matrix<Type>::GetValue(int row, int col) const
{
	if ((unsigned int)row >= value.size()) return 0;
	auto line = value[row];
	if ((unsigned int)col >= line.size()) return 0;
	return line[col];
}

template<typename Type>
inline void Matrix<Type>::PutValue(int row, int col, const Type& val)
{
	if (row >= value.size()) return;//throw "Row > size of matrix";
	else {
		auto line = value[row];
		if (col >= line.size()) return;//throw "Col > size of matrix";
		else value[row][col] = val;
	}
}

template<typename Type>
inline void Matrix<Type>::SetValue(const Type& val)
{
	if (GetRowCount()  && GetColCount()) {
		for (auto i = 0; i < GetRowCount(); i++) {
			for (auto j = 0; j < GetColCount(); j++) {
				PutValue(i, j, val);
			}
		}
	}
}

template<typename Type>
inline void Matrix<Type>::Print() const
{
	for (int i = 0; i < GetRowCount(); i++) {
		for (int j = 0; j < GetColCount(); j++)
			cout << GetValue(i, j) << endl;
		cout << endl;
	}
}

template<typename Type>
inline void Matrix<Type>::Transform() //транспонирование матрицы, не требуещее создание доп. объектов :)
{
	const int row = GetRowCount();
	const int col = GetColCount();

	int i = 0;
	for (; i < col; i++) {
		auto string = MatrixRow(row);
		for (int j = 0; j < row; j++) {
			string[j] = GetValue(j, i);
		}
		value[i] = string;
	}
	value.erase(value.begin() + i);
}

template<typename Type>
inline Matrix<Type> Matrix<Type>::operator+(const Type& right)
{
	int row = GetRowCount();
	int col = GetColCount();

	if (row != right.GetRowCount() || col != right.GetColCount());
		return *this;
	Matrix <Type> obj(row, col, 0);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			obj.PutValue(i, j, GetValue(i, j) + right);
		}
	}
	return obj;
}

template<typename Type>
inline Matrix<Type> Matrix<Type>::operator-(const Type & right)
{
	int row = GetRowCount();
	int col = GetColCount();

	if ((row != right.GetRowCount()) || (col != right.GetColCount()))
		return *this;
	Matrix <Type> obj(row, col, 0);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			obj.PutValue(i, j, GetValue(i, j) - right);
		}
	}
	return obj;
}

template<typename Type>
inline Matrix<Type> Matrix<Type>::operator*(const Matrix & right)
{
	int row = GetRowCount();
	int col = GetColCount();
	double sum = 0;
	Matrix <Type> obj(row, right.GetColCount(), 0);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < right.GetColCount(); j++) {
			for (int k = 0; k < col; k++) {
				sum += GetValue(i, k) * right.GetValue(k, j);
				obj.PutValue(i, j, sum);
			}
			sum = 0;
		}
	}
	return obj;
}

template<typename Type>
inline Matrix<Type> Matrix<Type>::operator*(const Type& number)
{
	int row = GetRowCount();
	int col = GetColCount();
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			PutValue(i, j, GetValue(i, j) * number);
		}
	}
	return *this;
}

template<typename Type>
inline Matrix<Type> Matrix<Type>::operator/(const Matrix & right)
{
	int row = GetRowCount();
	int col = GetColCount();
	double sum = 0;
	Matrix <Type> obj(row, right.GetColCount(), 0);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < right.GetColCount(); j++) {
			for (int k = 0; k < col; k++) {
				if (!right.GetValue(k, j)) {
					obj.PutValue(i, j, 0);
					continue;
				}
				if (GetValue(i, k) % right.GetValue(k, j) == 0) {
					sum += (double)GetValue(i, k) / (double)right.GetValue(k, j);
					obj.PutValue(i, j, sum);
				}
			}
			sum = 0;
		}
	}
	return obj;
}

template<typename Type>
inline Matrix<Type> Matrix<Type>::operator/(const Type & number)
{
	int row = GetRowCount();
	int col = GetColCount();
	if (!right) return *this;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			PutValue(i, j, GetValue(i, j) / number);
		}
	}
	return *this;
}

template<typename Type>
inline Matrix<Type> Matrix<Type>::operator^(const Type& number)
{
	const int row = GetRowCount();
	const int col = GetColCount();
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			const int value = GetValue(i, j);
			int k = 0, sum = 1;
			while (k < (int)number) {
				sum *= value;
				k++;
			}
			PutValue(i, j, sum);
		}
	}
	return *this;
}

template<typename Type>
inline Matrix<Type> Matrix<Type>::operator=(const Matrix & right)
{
	const int row = GetRowCount();
	const int col = GetColCount();
	if ((row != right.GetRowCount()) || (col != right.GetColCount()))
		return *this;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			PutValue(i, j, right.GetValue(i, j));
		}
	}
	return *this;
}

template<typename Type>
inline Matrix<Type> Matrix<Type>::operator+(const Matrix & right)
{
	const int row = GetRowCount();
	const int col = GetColCount();
	if ((row != right.GetRowCount()) || (col != right.GetColCount()))
		return *this;
	Matrix <Type> obj(row, col, 0);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			obj.PutValue(i, j, GetValue(i,j) + right.GetValue(i, j));
		}
	}
	return obj;
}

template<typename Type>
inline Matrix<Type> Matrix<Type>::operator-(const Matrix & right)
{
	const int row = GetRowCount();
	const int col = GetColCount();
	if ((row != right.GetRowCount()) || (col != right.GetColCount()))
		return *this;
	Matrix <Type> obj(row, col, 0);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			obj.PutValue(i, j, GetValue(i, j) - right.GetValue(i, j));
		}
	}
	return obj;
}





