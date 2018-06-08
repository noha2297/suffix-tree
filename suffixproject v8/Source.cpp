#include<iostream>
# include <string>
#include"suffix.h"
using namespace std;
void main()
{

	string str = "TAGATGCG", substring,suffixsubstring;
	bool b,bb;
	//cin >> str;
	suffix s = (str);
	s.insert();
	cout << endl;

	//cout << "please , enter the substring " << endl;
	//cin >> substring;
	substring = "GGG";
	b = s.search(substring, 0);
	if (b == true)
		cout <<"the substring found" << endl;
	else
	{
		cout << "the substring not found" << endl;
		cout << "there is found " << endl;
		s.searchsimilar( str);
	}

	suffixsubstring = "GCG ";
	bb = s.search(suffixsubstring);

	if (bb == true)
		cout << "the suffix found" << endl;
	else
	{
		cout << "the suffix not found" << endl;
	}




	//cout << b << endl;*/
	
	//int y = 0;
	//s.searchsub(substring, 0, y);
	//if (y == 0)
	//{
	//cout << "not found" << endl;
	//s.searchsimilar(substring);
	//}
	//	else
	//cout << "found" << y<< endl;
}