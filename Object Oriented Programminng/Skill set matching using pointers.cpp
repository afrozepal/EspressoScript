#include <iostream>
#include <fstream>
using namespace std;




int main()
{
	//opening the file to read from it
	int i = 0;
	int rows=1 , cols=100;
	char value;
	int space = 0;
	char ** ptr;
	int row=10  , col=10;
	char arr[row][cols];
	int r=0 , c=-1;
	int r1;
	int c1;
	ptr = new char *[cols];
	for (int i = 0; i < row ; i++)
	{
		ptr[i] = new char [cols];
	}
	char **namesptr ;
	namesptr = new char *[cols];
	for (int i = 0; i < row; i++)
	{
		namesptr[i] = new char [cols];
	}
	int n=0;
	int count=0;
	ifstream file("file.txt");
	if (!file.is_open())
	{
		cout << "file doesnot exist " << endl;
	}
	else
	{
		file.is_open();
		int loop=0;
		while (!file.eof())
		{	
			file >> std::noskipws >> value;
					if (file.eof())
					{
						break;
					}
			cout << value ;
			
			c++;
			if (value!=' ' && space<1)
			{
				*(*(namesptr + (rows-1)) + count) = value ;
				count ++;
			}
			
			for ( r1 = r ; r1 < r+1 ; r1++)
			{
				for (c1 = c ; c1 < c+1 ; c1++)
				{
					*(*(ptr + r1) + c1) = value;
				}
			}		
			if (value ==' ')
			{
				space++;
			}
			else if (value == '\n')
			{
				rows++;
				count=0;
				space=0;
				r++;
				c=-1;
			}
			loop++;
			
			
		}
		cout << endl <<endl << "========== names array ======== " << endl << endl;
			for (int k=0 ; k< rows ; k++)
			{
				for (int l=0 ; *(*(namesptr + k) + l)!='\0' && (*(*(namesptr + k) + l)>='A' && *(*(namesptr + k) + l)<='z') ; l++)
				{
					cout << *(*(namesptr + k) + l);
				}
				cout << endl;
			}
			
	}
	
	cout << endl;
	char skill[12];
	int k , l;
	cout << "enter the skill to be found " << endl;
	cin >> skill ;
	cout << "skill to be found in :: " <<endl;
			for (int i=0 ; i<rows ; i++)
			{
				for (int j=0 ; *(*(ptr + i) + j)!='\0' ; j++)
				{
					if (*(*(ptr + i) + j) == skill[i] && *(*(ptr + i) + j+1) == skill[i+1] && skill[i+1]!=' ')
					{
							for (int k=0 ; *(*(ptr + i) + k)!=' ' ; k++)
							{
								cout << *(*(namesptr + i) + k) ;
							}
							cout << endl;
							break;
					}
				}
			}
			
	return 0;

}
