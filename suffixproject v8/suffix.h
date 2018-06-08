#pragma once
#include <string>
#include <vector>
#include<map>
#include<algorithm>
using namespace std;
class suffix
{
	map<pair<int, int>, vector<pair<int, int> > >tree;
	string str;


public:

	suffix();
	suffix(string);
	void insert();
	int edit(int, int);
	void update();
	void display();
	void display2();
	bool search(string, int);
	bool search(string);
	//bool searchsub(string, int);
	void searchsimilar(string);
	~suffix();
};
