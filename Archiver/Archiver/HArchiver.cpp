#include "HArchiver.h"

class HArchiver;
HArchiver::HArchiver()
{
	//just creating an object
}

HArchiver::HArchiver(string name)
{
	try {
		DateFile = "";
		EncryptDate = "";
		in.open(name, ios_base::binary);
		if (!in.is_open())
			throw "File " + name + " not found!";
		CreateTable();
		FillBuf();
		root = CreateTree();
		vector<bool> bvec;
		Encrypt(root,"", bvec);
		in.close();
		out.open("gav.bin", ios_base::binary);
		FillFileFromTree();
		out.close();
		in.open("gav.bin");
		Deencrypt();
	}
	catch (string n) {
		cerr << endl << "Error! <<" << n << endl;
		system("pause");
	}
	//catch (...) {
	//	cerr << endl << "Unknown error!";
	//	system("pause");
	//}
}

HArchiver::~HArchiver()
{
}

void HArchiver::CreateTable()
{
	if (in.eof())
		throw "File is empty, compression can not be!";
	FillVecFromFile();
}

HArchiver::Item *HArchiver::Find(char c, vector<Item*>& v)
{
	if (v.empty()) {
		//throw "Trying to find an empty vector!";
		return NULL;
	}
	for (auto it = v.begin(); it != v.end(); it++) {
		string s;
		s+=c;
		if ((*it)->symbol == s) return (*it);
	}
	return NULL;
}

void HArchiver::FillVecFromFile()
{
	in.seekg(0, in.end);
	int size = in.tellg();
	in.seekg(0, in.beg);
	char* s = new char[size + 1];
	in.read(s, size);
		for (int i = 0; i < size; i++) {
			DateFile += s[i];
			if (Find(s[i], vec)) {
				Find(s[i], vec)->value++;
			}
			else {
				Item* t = new Item(s[i], 1);
				vec.push_back(t);
			}
		}
}

void HArchiver::FillBuf()
{
	for (int i = 0; i < vec.size(); i++) {
		Item* s = new Item(vec.at(i)->symbol, 0);
		buf.push_back(s);
	}
}

void HArchiver::FillFileFromTree()
{
	AddDateInBuf(root);

	char b = 0;
	int count = 0;
	for (auto it = DateFile.begin(); it != DateFile.end(); it++) {
		EncryptDate += Find(*it, buf)->code;
	}

	char Si = (char)EncryptDate.size();
	out.write(&Si, sizeof(Si));

	for (auto it = DateFile.begin(); it != DateFile.end(); it++) {
		vector<bool> x = Find(*it, buf)->bool_code;
		for (int i = 0; i < x.size(); i++) {
			b = b | x[i] << (7 - count);
			count++;
			if (count == 8) {
				count = 0;
				out.write(&b, 1);
				b = 0;
			}
		} 
	}
	for (int i = 0; i < buf.size(); i++) {
		char c = buf.at(i)->symbol[0];
		vector<bool> x = buf.at(i)->bool_code;
		for (int i = 0; i < x.size(); i++) {
			b = b | x[i] << (7 - count);
			count++;
			if (count == 8) {
				count = 0;
				out.write(buf.at(i)->symbol.c_str(), 1);
				out.write(&b, 1);
				b = 0;
			}
		}
	}
}

void HArchiver::AddDateInBuf(Item* s)
{
	if (s->right) {
		AddDateInBuf(s->right);
	}
	if (s->left) {
		AddDateInBuf(s->left);
	}
	if (!(s->right && s->left)) {
		char c = s->symbol[0];
		Find(c, buf)->code = s->code;
		Find(c, buf)->bool_code = s->bool_code;
		return;
	}
}

void HArchiver::Encrypt(Item* t, string s, vector<bool> bvec)
{
	t->bool_code = bvec;
	t->code = s;
	if (t->right) {
		vector<bool> g = bvec;
		g.push_back(0);
		Encrypt(t->right, s + "0", g);
	} 
	if (t->left) {
		vector<bool> m = bvec;
		m.push_back(1);
		Encrypt(t->left, s + "1", m);
	}
	if (!(t->left && t->right))
		return;
}

void HArchiver::Deencrypt()
{
	string str;
	string size = "";
	int num;
	in >> num;
	getline(in, str);
	for (auto it = str.begin(); it != str.end(); it++) {
		if (Find(*it, vec)) {
			Find(*it, vec)->value++;
		}
		else {
			Item* t = new Item(*it, 1);
			vec.push_back(t);
		}
	}
}


HArchiver::Item * HArchiver::CreateTree()
{
	Item* root;
	Item* t;
	int first_size = vec.size();
	for (int i = 0; i < first_size - 1; i++) {
		if (vec.empty()) 
			throw "Trying to sort an empty vector!";
		sort(vec.begin(), vec.end(), [](Item* i, Item* j) -> bool {return (i->value > j->value);});

		//value1 - the penultimate element, value 2 - last element
		int value2 = vec.at(vec.size() - 1)->value;
		int value1 = vec.at(vec.size() - 2)->value;
		string s;
		s += vec.at(vec.size() - 2)->symbol + vec.at(vec.size() - 1)->symbol;
		
		t = new Item(s, value1 + value2);
		t->right = vec.at(vec.size() - 1);
		t->left = vec.at(vec.size() - 2);
		vec.erase(vec.end() - 1);
		vec.erase(vec.end() - 1);
		vec.push_back(t);
	}
	return vec.at(0);
}

HArchiver::Item *HArchiver::operator=(Item* t)
{
	Item temp(t->symbol, t->value);
	return &temp;
}
