#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <exception>
#include <map>
#include <vector>
#include <list>
#include <algorithm> 


using namespace std;

class HArchiver
{
	//this is sheet
	struct Item
	{
		Item() {};
		Item(char s, int val) { value = val; symbol = string(&s); right = NULL; left = NULL; code = ""; }
		Item(const char *s, int val) { value = val; symbol = string(s); right = NULL; left = NULL; code = "";}
		Item(string s, int val) { value = val; symbol = s; right = NULL; left = NULL; code = "";}
		double value;
		string symbol;
		Item* right;
		Item* left;
		string code;
		vector<bool> bool_code;
	};
	//this vector items, have symbols and values
	vector<Item*> vec;
	vector<Item*> buf;
	//root tree
	Item* root;
	//streams
	ifstream in; ofstream out;
	//calculating of occurrences
	void CreateTable();
	//find symbol in vector, if the symbol is found, it returns a pointer to a structure, else NULL
	Item *Find(char c, vector<Item*> &v);
	void FillVecFromFile();
	void FillBuf();
	void FillFileFromTree();
	void AddDateInBuf(Item* s);
	void Encrypt(Item* t, string s,vector<bool> bvec);
	void Deencrypt();
	Item *CreateTree();
	Item*operator=(Item*t);
	string DateFile;
	string EncryptDate;
public:
	HArchiver();
	HArchiver(string name);
	~HArchiver();
};

