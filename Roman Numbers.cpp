#include<iostream>
using namespace std;
class roman
{
private:
	char* n;
	int no;
	int sumi, subi, muli, divi;
public:
	void input();
	void conversion();
	void output();
	void display(int n);
	//operator overloading
	void operator + (roman m);
	void operator - (roman m);
	void operator * (roman m);
	void operator / (roman m);
	void operator ==(roman m);
	void operator !=(roman m);
	void operator > (roman m);
	void operator < (roman m);
	void operator ++();
	void operator --();
	roman operator++(int);
	roman operator--(int);
	//deleting dynamic array
	void deletem();
	//destructor
	~roman();
};
void roman::input()
{
	n = new char[8];
	cout << "Enter roman number : ";
	cin >> n;
}
void roman::output()
{
	cout << "Numbers is : " << no << endl;
	cout << endl;
}
void roman::conversion()
{
	no = 0;
	for (int i = 0; n[i] != '\0'; i++)
	{
		if (n[i] == 'N')
		{
			no = 0;
		}
		if (n[i] == 'I')
		{
			no = no + 1;
		}
		if (n[i] == 'V')
		{
			no = no + 5;
		}
		if (n[i] == 'X')
		{
			no = no + 10;
		}
		if (n[i] == 'L')
		{
			no = no + 50;
		}
		if (n[i] == 'C')
		{
			no = no + 100;
		}
		if (n[i] == 'D')
		{
			no = no + 500;
		}
		if (n[i] == 'M')
		{
			no = no + 1000;
		}
		if (n[i] == 'X' && n[i - 1] == 'I')
		{
			no = no - 2;
		}
		if (n[i] == 'V' && n[i - 1] == 'I')
		{
			no = no - 2;
		}
		if (n[i] == 'L' && n[i - 1] == 'X')
		{
			no = no - 20;
		}
		if (n[i] == 'C' && n[i - 1] == 'X')
		{
			no = no - 20;
		}
		if (n[i] == 'C' && n[i - 1] == 'L')
		{
			no = no - 20;
		}
		if (n[i] == 'D' && n[i - 1] == 'X')
		{
			no = no - 20;
		}
		if (n[i] == 'D' && n[i - 1] == 'L')
		{
			no = no - 20;
		}
		if (n[i] == 'D' && n[i - 1] == 'C')
		{
			no = no - 200;
		}
		if (n[i] == 'M' && n[i - 1] == 'X')
		{
			no = no - 20;
		}
		if (n[i] == 'M' && n[i - 1] == 'L')
		{
			no = no - 20;
		}
		if (n[i] == 'M' && n[i - 1] == 'C')
		{
			no = no - 200;
		}
		if (n[i] == 'M' && n[i - 1] == 'D')
		{
			no = no - 200;
		}
	}
}
void roman :: operator + (roman m)
{
	sumi = no + m.no;
	cout << "sum in int is " << sumi << endl;
	//again to roman conversion
	cout << "SUM IN ROMAN IS : ";
	display(sumi);
	cout << endl << endl;
}
void roman :: operator - (roman m)
{
	subi = no - m.no;
	cout << "difference in int is " << subi << endl;
	//again to roman conversion
	if (subi > 0)
	{
		cout << "DIFFERENCE IN ROMAN IS : ";
		display(subi);
	}
	else
	{
		cout << "difference is not compatible :	";
		display(0);
	}
	cout << endl;
}
void roman :: operator * (roman m)
{
	muli = no * m.no;
	cout << "multiplication in int is " << muli << endl;
	cout << "MULTIPLICATION IN ROMAN IS : ";
	display(muli);
	cout << endl;
}
void roman :: operator / (roman m)
{
	divi = no / m.no;
	cout << "division in int is " << divi << endl;
	//again to roman conversion
	if (divi > 0)
	{
		cout << "DIVISION IN ROMAN IS : ";
		display(divi);
		cout << endl;
	}
	else
	{
		cout << "division results in zero as it might be in decimal value :	";
		display(0);
	}
}
void roman :: operator == (roman m)
{
	if (no == m.no)
	{
		cout << "Both numbers are equal" << endl;
	}
}
void roman :: operator !=(roman m)
{
	if (no != m.no)
	{
		cout << "Both numbers are not equal" << endl;
	}
}
void roman :: operator > (roman m)
{
	if (no > m.no)
	{
		cout << "greater number is ";
		display(no);
	}
	else if (m.no > no)
	{
		cout << "greater number is ";
		display(m.no);
	}
}
void roman :: operator < (roman m)
{
	if (no < m.no)
	{
		cout << "smaller number is ";
		display(no);
	}
	else if (m.no < no)
	{
		cout << "smaller number is ";
		display(m.no);
	}
	cout << endl;
}
void roman :: operator ++ ()
{
	++no;
	display(no);
	--no;
	cout << endl;
}
void roman :: operator--()
{
	--no;
	display(no);
	++no;
	cout << endl;
}
roman roman :: operator++(int)
{
	roman temp;
	temp.no = no++;
	display(no);
	no--;
	return temp;
}
roman roman :: operator--(int)
{
	roman temp;
	temp.no = no--;
	display(no);
	no++;
	return temp;
}
void roman::deletem()
{
	for (int i = 0; i < n[i] != '\0'; i++)
	{
		delete[] n;
	}
}
roman :: ~roman()
{
	cout << endl;
}
void roman::display(int n)
{
	int numi = n;
	char* num;
	num = new char[10];
	*num = NULL;
	if (numi == 0)
	{
		num[0] = 'N';
	}
	if (numi <= -1)
	{
		cout << numi << " is negative number " << endl;
	}
	if (numi >= 1)
	{
		for (int i = 0; numi != 0; i++)
	{
		if ((numi >= 1 && numi <= 3))
		{
			for (int j = i; numi != 0; j++)
			{
				num[j] = 'I';
				numi = numi - 1;
				i++;
			}
		}
		else if (numi % 5 >= 0 && numi % 5 <= 3 && numi >= 5 && numi < 9)
		{
			num[i] = 'V';
			numi = numi - 5;
		}
		else if (numi == 4)
		{
			num[i] = 'I';
			i++;
			num[i] = 'V';
			numi = numi - 4;
		}
		else if (numi == 9)
		{
			num[i] = 'I';
			i++;
			num[i] = 'X';
			numi = numi - 9;
		}
		else if (numi >= 9)
		{
			if (numi % 1000 >= 0 && numi % 1000 <= 999 && numi >= 1000)
			{
				num[i] = 'M';
				numi = numi - 1000;
				i++;
			}
			else if (numi >= 900 && numi <= 999)
			{
				num[i] = 'C';
				i++;
				num[i] = 'M';
				numi = numi - 900;
				i++;
			}
			if (numi % 500 >= 0 && numi % 500 <= 499 && numi >= 500 && numi <= 899)
			{
				num[i] = 'D';
				numi = numi - 500;
				i++;
			}
			else if (numi >= 400 && numi <= 499)
			{
				num[i] = 'C';
				i++;
				num[i] = 'D';
				numi = numi - 400;
				i++;
			}
			if (numi % 100 >= 0 && numi % 100 <= 99 && numi >= 100 && numi <= 399)
			{
				num[i] = 'C';
				numi = numi - 100;
				i++;
			}
			else if (numi >= 90 && numi <= 99)
			{
				num[i] = 'X';
				i++;
				num[i] = 'C';
				numi = numi - 90;
				i++;
			}
			else if (numi % 50 >= 0 && numi % 50 <= 49 && numi >= 50 && numi <= 99)
			{
				num[i] = 'L';
				numi = numi - 50;
				i++;
			}
			else if (numi >= 40 && numi <= 49)
			{
				num[i] = 'X';
				i++;
				num[i] = 'L';
				numi = numi - 40;
				i++;
			}
			else if (numi % 10 >= 0 && numi % 10 <= 9 && numi >= 10 && numi <= 39)
			{
				num[i] = 'X';
				numi = numi - 10;
				i++;
			}
			i--;
		}
	}
	}
	for (int i = 0; num[i] != '\0' && num[i] >= 'A' && num[i] <= 'Z'; i++)
	{
		cout << num[i];
	}
}
int main()
{
	roman n1, n2;
	n1.input();
	n1.conversion();
	n1.output();
	n2.input();
	n2.conversion();
	n2.output();
	//calling operators
	n1 + n2;
	n1 - n2;
	n1* n2;
	n1 / n2;
	n1 == n2;
	n1 != n2;
	n1 > n2;
	n1 < n2;
	cout << "operator of prefix increment makes FIRST roman number : ";
	++n1;
	cout << endl;
	cout << "operator of prefix increment makes SECOND roman number : ";
	++n2;
	cout << endl;
	cout << "operator of prefix decrement makes FIRST roman number : ";
	--n1;
	cout << endl;
	cout << "operator of prefix decrement makes SECOND roman number : ";
	--n2;
	cout << endl;
	cout << "operator of postfix increment makes FIRST roman number : ";
	n1++;
	cout << "operator of postfix increment makes SECOND roman number : ";
	n2++;
	cout << "operator of postfix decrement makes FIRST roman number : ";
	n1--;
	cout << "operator of postfix decrement makes SECOND roman number : ";
	n2--;
	//calling delete function
	n1.deletem();
	n2.deletem();
	return 0;
}
