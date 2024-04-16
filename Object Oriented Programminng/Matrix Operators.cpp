#include<iostream>
using namespace std;
class matrices
{
private:
	int** matrix;
	int rows, cols;
public:
	void getsize(int a, int b);
	void input();
	void display();
	//operator overloading
	void operator + (matrices m);
	void operator - (matrices m);
	void operator * (matrices m);
	void operator == (matrices m);
	//deleting dynamic arrays
	void deletem();
	//destructor
	~matrices();
};
void matrices :: operator + (matrices m)
{
	int** sum;
	sum = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		sum[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			sum[i][j] = matrix[i][j] + m.matrix[i][j];
		}
	}
	cout << endl << "ADDITION OF TWO MATRICES IS : " << endl << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(sum + i) + j) << "	";
		}
		cout << endl;
	}
	for (int i = 0; i < rows; i++)
	{
		delete[] sum[i];
	}
	delete[] sum;
}
void matrices :: operator - (matrices m)
{
	int** sub;
	sub = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		sub[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			sub[i][j] = matrix[i][j] - m.matrix[i][j];
		}
	}
	cout << endl << "SUBTRACION OF TWO MATRICES IS " << endl << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(sub + i) + j) << "	";
		}
		cout << endl;
	}
	for (int i = 0; i < rows; i++)
	{
		delete[] sub[i];
	}
	delete[] sub;
}
void matrices :: operator * (matrices m)
{
	int sum;
	int** mul;
	mul = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		mul[i] = new int[cols];
	}
	if (rows == cols)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				sum = 0;
				for (int k = 0; k < 2; k++)
				{
					sum = sum + (matrix[i][k] * m.matrix[k][j]);
				}
				mul[i][j] = sum;
			}
		}
		cout << endl << "MULTIPLICATION OF TWO MATRICES IS : " << endl << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << mul[i][j] << "	";
			}
			cout << endl;
		}
	}
	else
	{
		cout << endl << "Multiplication is not possible as the number of columns of the 1st matrix are not equal to the number of rows of the 2nd one" << endl;
	}
	for (int i = 0; i < rows; i++)
	{
		delete[] mul[i];
	}
	delete[] mul;
}
void matrices :: operator == (matrices m)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j] == m.matrix[i][j])
			{
				if (i == rows - 1 && j == cols - 1)
					cout << endl << "----- MATRICES ARE EQUAL -----" << endl;
			}
			else
			{
				cout << endl << "----- MATRICES ARE NOT EQUAL -----" << endl;
				i = rows;
				break;
			}
		}
	}
}
void matrices::getsize(int r, int c)
{
	rows = r;
	cols = c;
	matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
	}
}
void matrices::input()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin >> *(*(matrix + i) + j);
		}
	}
	cout << endl;
}
void matrices::display()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(matrix + i) + j) << "	";
		}
		cout << endl;
	}
}
void matrices::deletem()
{
	for (int i = 0; i < rows ; i++)
	{
		delete matrix[i];
	}
	delete [] matrix;
}
matrices::~matrices()
{
	cout << endl;
}
int main()
{
	int r, c;
	cout << "Enter order of matrix: " << endl;
	cout << "ROWS : ";
	cin >> r;
	cout << "COLOMNS : ";
	cin >> c;
	matrices m1, m2;
	m1.getsize(r, c);
	m2.getsize(r, c);
	cout << "INPUT ELEMENT OF MATRIX 1 : " << endl;
	m1.input();
	cout << "INPUT ELEMENT OF MATRIX 2 : " << endl;
	m2.input();
	cout << endl << "-----  MATRIX 1  ----- " << endl;
	m1.display();
	cout << "-----  MATRIX 2  -----" << endl;
	m2.display();
	//calling operators
	m1 + m2;
	m1 - m2;
	m1 * m2;
	m1 == m2;
	//calling delete function
	m1.deletem();
	m2.deletem();
	return 0;
}
