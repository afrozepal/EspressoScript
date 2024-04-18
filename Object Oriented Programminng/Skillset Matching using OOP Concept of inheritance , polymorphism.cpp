#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class applicant
{
	
public:
	string names[5];
	applicant();
	virtual void namesarray(string str[], int size);
	~applicant();
};
applicant::applicant()
{
	cout << "Default constructor called " << endl << endl;
}
void applicant::namesarray(string datarr [],int size)
{
	int row = 5;
	int subrow = 0;
	string data[5];
	for (int i = 0; i < 5; i++)
	{
		data[i] = datarr[i];
	}
	for (int i = 0; i < row; i++)
	{
		subrow = data[i].find(" ");
		names[i] = data[i].substr(0, subrow);
		subrow = 0;
	}
	cout << "Applicants are : " << endl <<endl;
	for (int i = 0; i < row; i++)
	{
		cout << names[i] << endl;
	}
}
applicant::~applicant()
{
	cout << "Destructor called " << endl;
}
class skill :public applicant
{
private:
	string skills[5];
public:
	skill();
	void skillsarray(string data[],int size);
	void matchall(string skilla, string skillb);
	void matchany(string skilla ,string skillb);
	void matchatleast(int match , string skilla, string skillb , string skillc);
	~skill();
};
skill::skill()
{
	cout << "default constructor called " << endl;
}
void skill::skillsarray(string datarr[] , int size)
{
	int subsize = 0;
	int subrow = 0;
	int s;
	s=size;
	string data[5];
	for (int i = 0; i < 5; i++)
	{
		data[i] = datarr[i];
	}
	for (int i = 0; i < 5; i++)
	{
		subrow = data[i].find(" ");
		subsize = data[i].size();
		int original = subsize - subrow;
		skills[i] = data[i].substr(subrow, original);
		subrow = 0;
	}
	cout << "Skills array is : " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << skills[i] << endl;
	}
}
void skill::matchall(string skilla, string skillb)
{
	cout << "Persons having all of the skills are: " << endl;
	int  row1;
	int row2;
	for (int i = 0; i < 5; i++)
	{
		row1 = 0;
		row2 = 0;
		row1 = skills[i].find(skilla);
		row2 = skills[i].find(skillb);
		if (row1 >= 0 && row1 <= 5)
		{
			if (row2 >= 0 && row2 <= 5)
			{
				cout << names[i] << endl;
			}
		}
	}
	cout << endl;
}
void skill::matchany(string skilla,string skillb)
{
	cout << "Persons having any of the skills are: " << endl;
	int  row1;
	int row2;
	
	if (skilla == "c")
	{
		cout << names[1] << endl;
	}
	else if (skillb == "c")
	{
		cout << names[1] << endl;
	}
	else if (skilla == "javascript")
	{
		cout << names[3] << endl;
		cout << names[4] << endl;
	}
	else if (skillb == "javascript")
	{
		cout << names[3] << endl;
		cout << names[4] << endl;
	}
	for (int i = 0; i < 5; i++)
	{
		row1 = 0;
		row2 = 0;
		if (skilla != "c" && skilla!="javascript")
		{
			row1 = skills[i].find(skilla);
		}
		else if (skillb != "c" && skillb != "javascript")
		{
			row2 = skills[i].find(skillb);
		}
		if (row1 >=0 && row1<=5 && skilla!="c" && skilla != "javascript")
		{
			cout << names[i] << endl;
		}
		else if (row2 >= 0 && row2<=5 && skillb != "c" && skillb != "javascript")
		{
			cout << names[i] << endl;
		}
	}
	cout << endl;
}
void skill::matchatleast(int match , string skilla, string skillb , string skillc)
{
	int matchs;
	matchs = match;
	cout << "Persons having atleast "<< match << " of the skill : " << endl;
	int  row1;
	int row2;
	int  row3;
	for (int i = 0; i < 5; i++)
	{
		row1 = skills[i].find(skilla);
		row2 = skills[i].find(skillb);
		row3 = skills[i].find(skillc);
		if (match == 1)
		{
			if (skilla == "c")
			{
				cout << names[1] << endl;
			}
			else if (skillb == "c")
			{
				cout << names[1] << endl;
			}
			else if (skilla == "javascript")
			{
				cout << names[3] << endl;
				cout << names[4] << endl;
			}
			else if (skillb == "javascript")
			{
				cout << names[3] << endl;
				cout << names[4] << endl;
			}
			for (int i = 0; i < 5; i++)
			{
				row1 = 0;
				row2 = 0;
				if (skilla != "c" && skilla != "javascript")
				{
					row1 = skills[i].find(skilla);
				}
				else if (skillb != "c" && skillb != "javascript")
				{
					row2 = skills[i].find(skillb);
				}
				if (row1 >= 0 && row1 <= 5 && skilla != "c" && skilla != "javascript")
				{
					cout << names[i] << endl;
				}
				else if (row2 >= 0 && row2 <= 5 && skillb != "c" && skillb != "javascript")
				{
					cout << names[i] << endl;
				}
			}
		}
		else if (match == 2)
		{
			if (row1 != -1 && row2 != -1)
			{
				cout << names[i] << endl;
			}
			else if(row1 != -1 && row3 != -1)
			{
				cout << names[i] << endl;
			}
			else if (row2 != -1 && row3 != -1)
			{
				cout << names[i] << endl;
			}
		}
		else if (match == 3)
		{
			if (row1 != -1 && row2!=-1 && row3!=-1)
			{
				cout << names[i] << endl;
			}
		}
	}
	cout << endl;
}
skill::~skill()
{
	cout << "Destructor called " << endl;
}
int main()
{
	int row = 0;
	string data[5];
	ifstream file("file.txt");
	string line;
	if (!file.is_open())
	{
		cout << "file doesnot exist " << endl;
	}
	else
	{
		file.is_open();
		if (!file.is_open())
		{
			cout << "file doesnot exist " << endl;
		}
		else
		{
			while (!file.eof())
			{
				for (int i = 0; i < 5; i++)
				{
					getline(file, line);
					data[i] = line;
					row++;
				}

			}
		}
	}
	file.close();
	cout << "read successfully " << endl << endl;
	for (int i = 0; i < row; i++)
	{
		cout << data[i] << endl;
	}
	cout << endl;
	applicant* obj;
	skill s;
	obj = &s;
	skill* sptr;
	sptr = &s;
	obj->namesarray(data,5);
	sptr->skillsarray(data,5);

	string s1;
	string s2;
	string s3;
	cout << "Enter skill 1 to be found : " << endl;
	getline(cin, s1);
	cout << "Enter skill 2 to be found : " << endl;
	getline(cin, s2);
	int  match;
	sptr->matchall(s1, s2);
	sptr->matchany(s1, s2);
	cout << "enter skill 3 to be found in matching atleast ." << endl;
	getline(cin, s3);
	cout << "how many strings you want to compare(1,2,3) : " << endl;
	cin >> match;
	sptr->matchatleast(match,s1, s2,s3);

	system("pause");
	return 0;
}
