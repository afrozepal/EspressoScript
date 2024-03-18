#include<iostream>
#include<vector>
#include<string>
#include<List>
using namespace std;
class listdata
{
private:
	friend class HashTable;
	friend class List;
	int ISSN;
	string title;
	string author;
	int ref_num;
	int iss_num;
public:
	listdata()
	{
		ISSN = 0;
		title = author = '\0';
		ref_num = iss_num = 0;
	}
	void insertlistdata(int issn)
	{
		cout << "CREATING A NEW RECORD " << endl;
		ISSN = issn;
		cout << "ENTER BOOK NAME :   ";
		cin >> title;
		cout << "ENTER AUTHOR NAME :  ";
		cin >> author;
		cout << "ENTER REFERENCE NUM :  ";
		cin >> ref_num;
		cout << "ENTER ISSUANCE NUM :   ";
		cin >> iss_num;
	}
	void display()
	{
		cout << "ISSN :   " << ISSN << endl;
		cout << "TITLE :   " << title << endl;
		cout << "AUTHOR :   " << author << endl;
		cout << "REFERENCE NUMBER :   " << ref_num << endl;
		cout << "ISSUANCE UMBER :    " << iss_num << endl;
	}
};
list<listdata>::iterator it;
class HashTable
{
private:
	int capacity;
	int key_index;
	vector<list<listdata>>v;
	friend class listdata;
public:
	HashTable()
	{
		capacity = 20;
		key_index = 0;
	}
	int getindex(int key)
	{
		return key % capacity;
	}
	void vectordata()
	{
		list<listdata>lu;
		for (int i = 0; i < capacity; i++)
		{
			v.push_back(lu);
		}
	}
	int checking(int issn)
	{
		int index = getindex(issn);
		for (it = v[index].begin(); it != v[index].end(); it++)
		{
			if (it->ISSN == issn)
			{
				return 1;
			}
		}
		return 0;
	}
	listdata ld;
	void insertviachaining(int key)
	{
		list<listdata>l;
		int index = getindex(key);
		int check = checking(key);
		if (check == 0)
		{
			cout << "key is going at index " << index << endl;
			if (v[index].empty() == true)
			{
				cout << "The first elements inserting in list , vector pointing for head of list " << endl;
				ld.insertlistdata(key);
				l.push_back(ld);
				v[index] = l;
				return;
			}
			ld.insertlistdata(key);
			v[index].push_back(ld);
		}
		cout << "Record already present on this ISSN number " << endl;
	}
	void review(int issn)
	{
		int index = getindex(issn);
		for (it = v[index].begin() ; it!=v[index].end() ; it++)
		{
			if (it->ISSN == issn)
			{
				it->display();
				return;
			}
		}
		cout << "No record found on this ISSN number " << endl;
	}
	void update(int issn)
	{
		int index = getindex(issn);
		int check = checking(issn);
		int n = 0;
		if (check == 1)
		{
			cout << "Click on the Corresponding number to update data " << endl;
			cout << "Press 1 for title " << endl;
			cout << "Press 2 for author " << endl;
			cout << "Press 3 for reference number" << endl;
			cout << "Press 4 for issuance number" << endl;
			cin >> n;
			if (n == 1)
			{
				cout << "Enter updated title ";
				cin >> it->title;
			}
			else if (n == 2)
			{
				cout << "Enter updated author name ";
				cin >> it->author;
			}
			else if (n == 3)
			{
				cout << "Enter updated reference number ";
				cin >> it->ref_num;
			}
			else if (n == 4)
			{
				cout << "Enter updated issuance number ";
				cin >> it->iss_num;
			}
			cout << "UPDATED RECORD IS " << endl;
			it->display();
		}
		else
		{
			cout << "NO record to be updated on this ISSN number " << endl;
		}
	}
	void deletehash(int issn)
	{
		int index = getindex(issn);
		int check = checking(issn);
		if (check == 1)
		{
			cout << "Record deleted of ISSN " << issn << endl;
			v[index].erase(it);
		}
		else
		{
			cout << "NO record on this ISSN number to be deleted " << endl;
		}
	}
};
void input()
{
	cout << "Press 0 to exit " << endl;
	cout << "Press 1 to create new record " << endl;
	cout << "Press 2 to review a book record " << endl;
	cout << "Press 3 to update a book record " << endl;
	cout << "Press 4 to delete a book record " << endl;
}
int main()
{
	HashTable h;
	int issn = 0;
	int x = 1;
	h.vectordata();
	while (x != 0)
	{
		input();
		cin >> x;
		if (x == 1 || x == 2 || x == 3 || x == 4)
		{
			cout << "Enter ISSN number of book record :   ";
			cin >> issn;
		}
		if (x == 1)
		{
			h.insertviachaining(issn);
			cout << endl << endl;
		}
		if (x == 2)
		{
			h.review(issn);
			cout << endl << endl;
		}
		if (x == 3)
		{
			h.update(issn);
			cout << endl << endl;
		}
		if (x == 4)
		{
			h.deletehash(issn);
			cout << endl << endl;
		}
	}
	cout << endl << endl;
	system("pause");
	return 0;
}