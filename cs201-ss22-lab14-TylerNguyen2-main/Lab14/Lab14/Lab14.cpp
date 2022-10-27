

#include <iostream>
#include <fstream>
#include <list>
#include <iterator>
#include <string>

using namespace std;


void fillList(list<char>& l1, string line)
{
	for (int i = 0; line[i]; i++)
	{
		l1.push_back(line[i]);
	}
}


void printList(ostream& out, list<char>& l1)
{
	list<char>::iterator it;
	for (it = l1.begin(); it != l1.end(); it++)
	{

		if (*it != ' ')
		{
			out << "[" << *it << "] -> ";
		}
		else
		{
			out << "[] -> ";
		}
	}
	out << "0\n";
}


void removeCharacter(list<char>& l1, char ch)
{
	list<char>::iterator it;
	for (it = l1.begin(); it != l1.end();)
	{
		if (tolower(*it) == ch)
		{
			it = l1.erase(it);
		}
		else
		{
			it++;
		}
	}
}


int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	string s;


	while (getline(fin, s) && s != "END")
	{
		list<char> L;
		fillList(L, s);
		removeCharacter(L, 'a');

		removeCharacter(L, 'e');

		removeCharacter(L, 'i');

		removeCharacter(L, 'o');

		removeCharacter(L, 'u');

		printList(fout, L);

	}
	fin.close();
	fout.close();
	return 0;
}