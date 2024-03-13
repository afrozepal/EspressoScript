//ITERATIVE WAY
#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int r, c;
int sr, sc;
int check = 0;
void setup_arr(char** arr, int dr, int dc, string str);
void display(string str, int dr, int dc);
void disparr(char** arr);
int ending(char end, int dr, int dc, int room_num);
void fileread(string str);
int rand_num;
int total_rooms;
string r1;
string r2;
string r3;
template<class T>
class Stack
{
private:
	T* arr;
	int maxsize;
	int topp;
public:
	Stack(int s = 500)
	{
		topp = -1;
		arr = new T[s];
		maxsize = s;
	}
	bool  isempty()
	{
		return topp == -1;
	}
	bool isfull()
	{
		return topp == maxsize;
	}
	void push(T d)
	{
		if (topp == maxsize - 1)
		{
			cout << "stack is full " << endl;
			return;
		}
		else
			topp++;
		arr[topp] = d;
	}
	void pop()
	{
		if (topp == -1)
		{
			cout << "list becomes empty " << endl;
			return;
		}
		topp--;
	}
	T top()
	{
		if (topp == -1)
		{
			cout << " list is empty " << endl;
			return 0;
		}
		else
		{
			return arr[topp];
		}
	}
};
Stack<int>s;
Stack<int>print;
void fileread(string str)
{
	ifstream file(str);
	if (!file.is_open())
	{
		cout << "file doesnot exist " << endl;
	}
	else
	{
		file >> std::noskipws >> total_rooms;
		file.ignore();
		getline(file, r1);
		getline(file, r2);
		getline(file, r3);
	}
	cout << endl << endl << endl << endl;
	cout << "					";
	cout << "------WELCOME TO HAUNTED HOUSE------" << endl << endl;
	cout << "						";
	cout << "--IT HAS " << total_rooms << " ROOMS-- " << endl << endl;
	cout << "						   " << r1 << endl;
	cout << "						   " << r2 << endl;
	cout << "						   " << r3 << endl;
	cout << endl << endl << endl << endl;
	system("pause");
	display(r1, sr, sc);
}
void display(string str, int dr, int dc)
{
	ifstream file(str);
	if (!file.is_open())
	{
		cout << "file doesnot exist " << endl;
	}
	else
	{
		char values = '0';
		int rows, cols;
		while (values != '\n')
		{
			file >> std::noskipws >> rows;
			file >> std::noskipws >> values;
			file >> std::noskipws >> cols;
			file >> std::noskipws >> values;
		}
		values = '0';
		while (values != '\n')
		{
			file >> std::noskipws >> sr;
			file >> std::noskipws >> values;
			file >> std::noskipws >> sc;
			file >> std::noskipws >> values;
		}
		char** arr;
		arr = new char* [rows];
		for (int i = 0; i < rows; i++)
		{
			arr[i] = new char[cols];
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				file >> values;
				if (values != ' ' && values != '\n')
				{
					*(*(arr + i) + j) = values;
				}
				else
				{
					j--;
				}
			}
		}
		cout << endl;
		r = rows;
		c = cols;
		cout << "Room is  : " << str << endl;

		disparr(arr);
		if (check == 0)
		{
			if (arr[sr][sc] == '0')
			{
				arr[sr][sc] = '*';
			}
			system("cls");
			cout << "		WELCOME TO ROOM " << str << endl << endl;
			cout << "	The search for treasure is starting from row " << sr << " col " << sc << endl;
			disparr(arr);
			int dr = sr;
			int dc = sc;
			int room_num = 0;
			if (str == r1)
			{
				room_num = 1;
			}
			if (str == r2)
			{
				room_num = 2;
			}
			if (str == r3)
			{
				room_num = 3;
			}
			if (room_num == 1)
				s.push(123);
			else if (room_num == 2)
				s.push(456);
			else if (room_num == 3)
				s.push(789);
			setup_arr(arr, dr, dc, str);
		}
		else if (check == 1)
		{
			if (arr[dr][dc] == '0')
			{
				arr[dr][dc] = '*';
			}
			system("cls");
			cout << "the key is starting from row " << dr << " col " << dc << endl;
			disparr(arr);
			check = 0;
			setup_arr(arr, dr, dc, str);
		}
	}
}
void disparr(char** arr)
{
	cout << endl << endl;
	for (int i = 0; i < r; i++)
	{
		cout << "					";
		for (int j = 0; j < c; j++)
		{
			cout << *(*(arr + i) + j) << "   ";
		}
		cout << endl;
	}
}
int ending(char end, int dr, int dc, int room_num)
{
	if (end == 'T')
	{
		system("cls");
		cout << endl << endl << endl;
		cout << "					 ";
		cout << "CONGRATS YOU FOUND TREASURE " << endl;
		cout << "						";
		cout << "       ^^" << endl;
		cout << "						";
		cout << "       00 " << endl;
		cout << "						";
		cout << "     //  \\\\ " << endl;
		cout << "						";
		cout << "    //    \\\\" << endl;
		cout << "						";
		cout << " (==\\\\    //==)" << endl;
		cout << "						";
		cout << "     \\\\  // " << endl;
		cout << "						";
		cout << "       ||   " << endl;
		cout << "						";
		cout << "     //  \\\\ " << endl;
		cout << "						";
		cout << "    //    \\\\" << endl;
		cout << endl << endl << endl;
		cout << "TREASURE IS FOUND AT INDEX " << dr << "," << dc << " IN ROOM NUMBER " << room_num << endl;
		return 1;
	}
	else if (end == 'D')
	{
		system("cls");
		cout << endl << endl << endl;
		cout << "					 ";
		cout << "YOU ARE EATEN BY A DEVIL " << endl;
		cout << endl << endl;
		cout << "       * *         * * * * * *   * * * * *   * * * * * *   * * * * *   " << endl;
		cout << "       * *         * *     * *   * *         * *           * *    * *  " << endl;
		cout << "       * *         * *     * *   * * * * *   * * * * * *   * * * * * " << endl;
		cout << "       * *         * *     * *   * * * * *   * * * * * *   * *  * *    " << endl;
		cout << "       * *         * *     * *         * *   * *           * *   *  *       " << endl;
		cout << "       * * * * *   * * * * * *   * * * * *   * * * * * *   * *     *  *       " << endl;
		cout << endl << endl << endl;
		return 1;
	}
	else if (end == 'G')
	{
		system("cls");
		display(r2, sr, sc);
		return 1;
	}
	else if (end == 'P')
	{

		srand(time(0));
		rand_num = rand() % 2 + 1;

		if (rand_num == 1) // 1 for head
		{
			srand(time(0));
			rand_num = rand() % 3 + 1;
			cout << endl << endl;
			cout << "coin flips for head and now is moving to room # " << rand_num << endl;
			system("pause");
			system("cls");

			if (rand_num == 1)
			{
				s.push(123);
				display(r1, sr, sc);
			}
			else if (rand_num == 2)
			{
				s.push(456);
				display(r2, sr, sc);
			}
			else if (rand_num == 3)
			{
				s.push(789);
				display(r3, sr, sc);
			}
		}
		else // 2 for tail
		{
			cout << endl << endl;
			cout << "coin flips for tail and now is moving to same room that is room # " << room_num << " at cell next to portal;" << endl;
			cout << endl << endl;
			system("pause");
			check = 1;
			if (room_num == 1)
			{
				s.push(123);
				display(r1, dr - 1, dc);
			}
			if (room_num == 2)
			{
				s.push(456);
				display(r2, dr, dc - 1);
			}
			if (room_num == 3)
			{
				s.push(789);
				display(r3, dr, dc + 1);
			}
		}
		return 1;
	}
	else
		return 0;
}
void setup_arr(char** arr, int dr, int dc, string str)
{
	int room_num = 0;
	if (str == r1)
	{
		room_num = 1;
	}
	if (str == r2)
	{
		room_num = 2;
	}
	if (str == r3)
	{
		room_num = 3;
	}
	char key;
	key = 72;
	int loopcheck = 0;
	while (key == 72 || key == 80 || key == 75 || key == 77 || loopcheck >= 0)
	{
		cout << "enter key : ";
		key = _getch();
		if (key == 72)
		{
			////up
			if (dr > 0 && dr < r && arr[dr - 1][dc] == '0')
			{
				s.push(dr);
				s.push(dc);
				arr[dr - 1][dc] = '*';
				arr[dr][dc] = '0';
				system("cls");
				disparr(arr);
				dr--;
			}
			else
			{
				char e = arr[dr - 1][dc];
				if (e != 'X')
				{
					s.push(dr);
					s.push(dc);
					s.push(dr - 1);
					s.push(dc);
					system("cls");
					disparr(arr);
				}
				int x = ending(e, dr - 1, dc, room_num);
				if (x == 1)
					break;
			}
		}
		else if (key == 80)
		{
			////down
			if (dr >= 0 && dr < r - 1 && arr[dr + 1][dc] == '0')
			{
				s.push(dr);
				s.push(dc);
				arr[dr + 1][dc] = '*';
				arr[dr][dc] = '0';
				system("cls");
				disparr(arr);
				dr++;
			}
			else
			{
				char e = arr[dr + 1][dc];
				if (e != 'X')
				{
					s.push(dr);
					s.push(dc);
					s.push(dr + 1);
					s.push(dc);
					system("cls");
					disparr(arr);
				}
				int x = ending(e, dr + 1, dc, room_num);
				if (x == 1)
					break;
			}
		}
		else if (key == 77)
		{
		////	right
			if (dc < c - 1 && dc >= 0 && arr[dr][dc + 1] == '0')
			{
				s.push(dr);
				s.push(dc);
				arr[dr][dc + 1] = '*';
				arr[dr][dc] = '0';
				system("cls");
				disparr(arr);
				dc++;
			}
			else
			{
				char e = arr[dr][dc + 1];
				if (e != 'X')
				{
					s.push(dr);
					s.push(dc);
					s.push(dr);
					s.push(dc + 1);
					system("cls");
					disparr(arr);
				}
				int x = ending(e, dr, dc + 1, room_num);
				if (x == 1)
					break;
			}
		}
		else if (key == 75)
		{
			/////left
			if (dc > 0 && dc < c && arr[dr][dc - 1] == '0')
			{
				s.push(dr);
				s.push(dc);
				arr[dr][dc - 1] = '*';
				arr[dr][dc] = '0';
				system("cls");
				disparr(arr);
				dc--;
			}
			else
			{
				char e = arr[dr][dc - 1];
				if (e != 'X')
				{
					s.push(dr);
					s.push(dc);
					s.push(dr);
					s.push(dc - 1);
					system("cls");
					disparr(arr);
				}
				int x = ending(e, dr, dc - 1, room_num);
				if (x == 1)
					break;
			}
		}
		if (key == 'Q')
		{
			system("cls");
			cout << endl << endl << endl;
			cout << "					 ";
			cout << "GAME END";
			cout << endl << endl << endl;
			return;
		}
	}
	while (!s.isempty())
	{

		print.push(s.top());
		s.pop();
	}
	if (print.isempty())
	{
		return;
	}
		cout << "OBSERVED PATH IS : " << endl;
	int i = 0;
	while (!print.isempty())
	{
		if (print.top() == 123)
		{
			cout << endl;
			cout << "ROOM 1 : " << endl;
			print.pop();
			cout << endl;
		}
		if (print.top() == 456)
		{
			cout << endl;
			cout << "ROOM 2 : " << endl;
			print.pop();
			cout << endl;
		}
		if (print.top() == 789)
		{
			cout << endl;
			cout << "ROOM 3 : " << endl;
			print.pop();
			cout << endl;
		}
		if (print.top() == 123 || print.top() == 456 || print.top() == 789)
		{
			print.pop();
		}
		cout << print.top();
		print.pop();
		if (i % 2 == 0)
			cout << " , ";
		else
			cout << endl;
		i++;
	}
}
int main()
{
	fileread("hauntedhouse.txt");
	cout << "Game concluded" << endl;
	char d = 1;
	cout << "			" << d << "   " << d << "   " << d << endl;
	cout << endl << endl;

	system("pause");
	return 0;
}
