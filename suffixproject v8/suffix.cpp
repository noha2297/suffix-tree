#include "suffix.h"
# include <iostream>
using namespace std;


suffix::suffix()
{
	str = "";

}
suffix::suffix(string s)
{
	str = s;
}
void suffix::insert()
{
	bool b = false;
	bool a[4444] = { 0 };

	for (int i = 0; i < str.length(); i++)
	{

		if (a[str[i]] == 0)

		{
			tree[{-1, -1}].push_back({ i ,str.size() - 1 });
			a[str[i]] = 1;
			//cout << " 2y 7aga" << endl;
		}
		else
		{
			vector<pair<int, int> > ::iterator it;
			for (it = tree[{ -1, -1 }].begin(); it != tree[{-1, -1}].end(); it++)
			{
				if (str[it->first] != str[i]) //str da el value bta3t el index ely by4awr 3leh it
				{

					continue;
				}
				else
				{
					b = true;
					int pos2 = i;
					int temp = it->second; // da tafkeer 2ni a5od 2l it-> second in tem to move el values bt4t el key el 2deem ll gded
										   //t3deel v2
					it->second = edit(it->first, pos2);

					if (tree[{it->first, temp}].size() == 0) // mmkn kman check if temp == str.size()-1;
					{
						tree[{it->first, it->second}].push_back({ it->second + 1,str.size() - 1 });
						tree[{it->first, it->second}].push_back({ pos2 + (it->second - it->first) + 1,str.size() - 1 });// error s3at bytl3 6:5
						tree.erase({ it->first,str.size() - 1 }); // dah 3lshan fe key zeyada bytl3 fady 
					}
					else if (temp - it->first == 0)
					{
						tree[{it->first, temp}].push_back({ pos2 + 1, str.size() - 1 });
					}
					else if (temp == it->second) // lw el key elgded hwa ns el key el2deem
					{
						tree[{it->first, it->second}].push_back({ pos2 + (it->second - it->first) + 1,str.size() - 1 });

					}
					else
					{
						                           
						int count;
						count = it->second - temp;
						//pair<int, int> v;
						vector<pair<int, int> > ::iterator it2;
						for (it2 = tree[{ it->first, temp }].begin(); it2 != tree[{it->first, temp}].end(); it2++)
						{
							//v.first = it2->first;
							//v.second = it2->second;
							tree[{it->first, it->second}].push_back({ it2->first + count ,str.size() - 1 });
						}
						tree.erase({ it->first,temp });
						tree[{it->first, it->second}].push_back({ pos2 + (it->second - it->first) + 1,str.size() - 1 });

					}

				}


			}
			//m4 m7taglha l2n el condition bta3 m3nah eh zbtha eno lw el7rf m4 mogod by create fe el node
			// 7b2a 2takd
			/*if (b == false)
			{
			tree[{-1, -1}].push_back({ i ,str.size() - 1 });
			cout << "2y 7aga" << endl;
			}*/



		}
	}
	//display();
	//update();
	display2();
	//cout << tree.size();
}





int suffix::edit(int pos1, int pos2)
{
	int counter = 0;
	for (int i = pos1 + 1, j = pos2 + 1; i < str.size(); i++, j++)
	{
		if (str[i] != str[j])
		{
			break;
		}
		counter++;
	}
	//t3deel v2 
	return (pos1 + counter);
}

void suffix::update()
{
	int c = 0;
	map<pair<int, int>, vector<pair<int, int> > > ::iterator it1;
	it1 = tree.begin();
	it1++;
	vector<pair<int, int> > ::iterator it2;
	vector<pair<int, int> > ::iterator it3;
	vector<pair<int, int> > ::iterator it4;
	vector<pair<int, int> > ::iterator it5;
	for (it1; it1 != tree.end(); it1++)
	{
		for (it2 = it1->second.begin(); it2 != it1->second.end(); it2++)
		{
			for (it3 = tree[{ -1, -1 }].begin(); it3 != tree[{-1, -1}].end(); it3++)
			{
				if ((str[it3->first] == str[it2->first]) && (it3->second != str.size() - 1) && (it1->first.first != it3->first))
				{
					/*for (it4 = tree[{it3->first, it3->second}].begin(); it4 != tree[{it3->first, it3->second}].end(); it4++)
					{
					for (it5 = it1->second.begin(); it5 != it1->second.end(); it5++)
					{
					if ((it4->first == it5->first + (it3->second - it3->first) + 1) && (it4->second == it5->second))
					{
					c++;
					break;
					}
					}
					}*/
					//	cout << c << "   " << tree[{it3->first, it3->second}].size() - 1 << endl;
					//if (c == tree[{it3->first, it3->second}].size() - 1)
					//{
					it2->first = it3->first;
					it2->second = it3->second;
					//}
				}
			}
		}
	}


}

void suffix::display()
{
	map<pair<int, int>, vector<pair<int, int> > > ::iterator it1;
	vector<pair<int, int> > ::iterator it2;
	for (it1 = tree.begin(); it1 != tree.end(); it1++)
	{
		cout << it1->first.first << " : " << it1->first.second << endl;
		for (it2 = it1->second.begin(); it2 != it1->second.end(); it2++)
		{
			cout << it2->first << " :" << it2->second << "    ";
		}
		cout << endl;

	}


}

void suffix::display2()
{
	int x;
	map<pair<int, int>, vector<pair<int, int> > > ::iterator it1;
	vector<pair<int, int> > ::iterator it2;
	vector<pair<int, int> > ::iterator it3;
	cout << "the root is :" << endl;
	for (it3 = tree[{ -1, -1 }].begin(); it3 != tree[{-1, -1}].end(); it3++)
	{
		for (int i = it3->first; i <= it3->second; i++)
		{
			cout << str[i];
		}
		cout << endl;
	}
	it1 = tree.begin();
	it1++;
	for (it1; it1 != tree.end(); it1++)
	{
		for (int i = it1->first.first; i <= it1->first.second; i++)
		{
			cout << str[i];
		}
		cout << ">>>>>>>>>>" << endl;
		//cout << it1->first.first << " : " << it1->first.second << endl ;
		for (it2 = it1->second.begin(); it2 != it1->second.end(); it2++)
		{
			if (it2->first > str.size() - 1)
			{
				cout << "$";
				continue;
			}
			x = it2->first;
			for (it3 = tree[{ -1, -1 }].begin(); it3 != tree[{-1, -1}].end(); it3++)
			{
				if (str[it2->first] != str[it3->first])
				{
					continue;
				}
				else
				{
					for (int i = it3->first; i <= it3->second; i++)
					{
						cout << str[i];
						x++;
					}
				}
				cout << ">>>>>";
				for (int i = x; i <= it2->second; i++)
				{
					cout << str[i];
				}
				cout << endl;
				//cout << it2->first << " : " <<  it2->second<< "   ";
			}
		}
		cout << endl;
		cout << endl;

	}

}

bool suffix::search(string s, int x)
{
	int temp;
	bool b = false, c = true;
	map<pair<int, int>, vector<pair<int, int> > > ::iterator it1;
	it1 = tree.begin();
	it1++;
	//cout << s.size() << endl;
	vector<pair<int, int> > ::iterator it2;
	for (it1; it1 != tree.end(); it1++)
	{
		if (str[it1->first.first] == s[x])
		{

			if (s.size() == 1)
				return true;
			b = true;
			for (int i = it1->first.first; i <= it1->first.second; i++)
			{
				if (str[i] != s[x])
				{
					//cout << "2y 7aga" << endl;
					return false;
				}
				x++;
				//cout << "2y 7aga" << endl;
			}
			for (it2 = it1->second.begin(); it2 != it1->second.end(); it2++)
			{
				//cout << "2y 7aga" << endl;
				if (str[it2->first] == s[x])
				{
					/*if (it2->second != str.size() - 1)//|| bool=true;
					{
					//cout << "2y 7aga" << endl;
					search(s, x);
					}*/
					//else
					//{
					temp = x;
					for (int i = it2->first; i <= it2->second; i++)
					{
						//cout << "2y 7aga" << endl;
						//cout << it2->first << endl;
						if (str[i] != s[x])
						{
							//cout << "2y 7aga" << endl;
							//return false;
							c = false;
							break;
						}
						x++;
						//}
						//cout << "2y 7aga" << endl;
						if (c == true)
						{
							return true;
						}
						else
							return false;
					}
				}
			}
		}

	}
	vector<pair<int, int> > ::iterator it;
	for (it = tree[{ -1, -1 }].begin(); it != tree[{-1, -1}].end(); it++)
	{
		if (str[it->first] == s[x])
		{
			for (int i = it->first; i < str.size() - 1; i++)
			{
				if (str[i] != s[x])
					return false;
				x++;
			}
			return true;

		}
	}
	return false;
}

bool suffix::search(string s)
{
	bool b = false;
	int x, y;
	vector<pair<int, int> > ::iterator it;
	for (it = tree[{ -1, -1 }].begin(); it != tree[{-1, -1}].end(); it++)
	{

		if (str[it->first] == s[0])
		{
			b = true;
			x = it->first; //3mlahom e7tyaty 3lshan m4 3rfa ntham el interator lma b3nl break ..tgnbn ll errors delw2ty
			y = it->second;
			break;
		}
	}
	if (b == true)
	{

		if (y == str.size() - 1) // m3naha 2no lh branch wahed mn el root bs
		{
			// hna 3za amshy 3la el string w el substring w 2shofhom zy b3d wla la
			for (int i = x, j = 0; i <= str.size() - 1, j<s.size(); i++, j++)
			{
				if (str[i] != s[j])
				{
					return false;
				}
			}
			return true;
		}
		else // m3naha 2no leh el kema 2le fe el root 3bara an key lmkan
		{
			int j = 1;
			for (int i = x + 1; i <= y; i++, j++) // 3lshan yt check rang el key ely fe el root mougood fe substring wla la
			{

				if (str[i] != s[j])
				{
					return false;
				}
			}
			//cout << j << endl;
			bool check = false;
			vector<pair<int, int> > ::iterator it2;
			for (it2 = tree[{ x, y }].begin(); it2 != tree[{x, y}].end(); it2++)
			{
				if (str[it2->first] == s[j])
				{
					for (int i = it2->first + 1; i <= it2->second; i++, j++)
					{
						if (str[i] == s[j + 1])
						{
							check = true;
							continue;
						}
						else
						{
							check = false;
							break;
						}
					}
					if (check == true)
					{
						return true;
					}
				}
			}

		}
	}

	return false;
}

/*

bool suffix::searchsub(string s, int x)
{
	bool b = false;
	int x, y;
	vector<pair<int, int> > ::iterator it;
	for (it = tree[{ -1, -1 }].begin(); it != tree[{-1, -1}].end(); it++)
	{

		if (str[it->first] == s[0])
		{
			b = true;
			x = it->first; //3mlahom e7tyaty 3lshan m4 3rfa ntham el interator lma b3nl break ..tgnbn ll errors delw2ty
			y = it->second;
			break;
		}
	}
	if (b == true)
	{

		if (y == str.size() - 1) // m3naha 2no lh branch wahed mn el root bs
		{
			// hna 3za amshy 3la el string w el substring w 2shofhom zy b3d wla la
			for (int i = x, j = 0; i <= str.size() - 1, j<s.size(); i++, j++)
			{
				if (str[i] != s[j])
				{
					return false;
				}
			}
			return true;
		}
		else // m3naha 2no leh el kema 2le fe el root 3bara an key lmkan
		{
			int j = 1;
			for (int i = x + 1; i <= y; i++, j++) // 3lshan yt check rang el key ely fe el root mougood fe substring wla la
			{

				if (str[i] != s[j])
				{
					return false;
				}
			}
			//cout << j << endl;
			bool check = false;
			vector<pair<int, int> > ::iterator it2;
			for (it2 = tree[{ x, y }].begin(); it2 != tree[{x, y}].end(); it2++)
			{
				if (str[it2->first] == s[j])
				{
					for (int i = it2->first + 1; i <= it2->second; i++, j++)
					{
						if (str[i] == s[j + 1])
						{
							check = true;
							continue;
						}
						else
						{
							check = false;
							break;
						}
					}
					if (check == true)
					{
						return true;
					}
				}
			}

		}
	}

	return false;

	}
	vector<pair<int, int> > ::iterator it;
	for (it = tree[{ -1, -1 }].begin(); it != tree[{-1, -1}].end(); it++)
	{
		if (str[it->first] == s[x])
		{
			for (int i = it->first, j = x; i < str.size() - 1, j <= s.size() - 1; i++, j++)
			{
				//cout << "2y 7aga" << endl;
				if (str[i] != s[x])
				{
					y = 0;
					return;
				}
				x++;
			}
			y++;
			return;

		}
	}
}
*/
void suffix::searchsimilar(string s)
{
	int count = 0, c = 0;
	for (int i = 0; i < str.length(); i++)
	{
		for (int j = i, k = 0; j < str.size() && k < s.size(); j++, k++)
		{
			if (str[j] != s[k])
				count++;
			c++;
		}
		//cout << c;
		if (count <= 1)
		{
			if ((c == 2) && (count == 1))
			{
				cout << "i dont know" << endl;
			}
			 if (c > 1)
			{
				for (int j = i, k = 0; j < str.size() && k < s.size(); j++, k++)
				{
					cout << str[j];
				}
			}
		}
		count = 0;
		c = 0;
		cout << endl;
	}

}


suffix::~suffix()
{
}