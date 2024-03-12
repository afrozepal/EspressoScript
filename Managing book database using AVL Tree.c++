#include<iostream>
using namespace std;
template <class T>
class AVLTree
{
	class Node
	{
		friend class AVLTree;
		friend class List;
		friend class Nodem;
	private:
		int data;
		Node* left;
		Node* right;
		int height;
		Nodem* point;
	public:
		Node()
		{
			data = 0;
			left = right = NULL;
			height = 0;
			point = NULL;
		}
	};
	Node* root;
public:
	AVLTree()
	{
		root = NULL;
	}
	int getheight(Node* r)
	{
		if (r == 0)
			return -1;
		else
			return r->height;
	}
	List l;
	void insert(Node*& r, int data)
	{
		if (r == NULL)
		{
			r = new Node;
			r->data = data;
			r->point = l.insertatend(data);
			r->left = r->right = NULL;
		}
		else
		{
			if (data < r->data)
			{
				insert(r->left, data);
				if (getheight(r->left) - getheight(r->right) == 2)
				{
					if (data < r->left->data)
						rotateright(r);
					else
						doublerotateright(r);
				}
				r->height = 1 + max(getheight(r->left), getheight(r->right));
			}
			else if (data > r->data)
			{
				insert(r->right, data);
				if (getheight(r->left) - getheight(r->right) == -2)
				{
					if (data > r->right->data)
					{
						rotateleft(r);
					}
					else
						doublerotateleft(r);
				}
				r->height = 1 + max(getheight(r->left), getheight(r->right));
			}
		}
	}
	int max(int a, int b)
	{
		if (a > b)
			return a;
		else
			return b;
	}
	void rotateleft(Node*& x)
	{
		Node* y = x->right;
		x->right = y->left;
		y->left = x;
		x->height = 1 + max(getheight(x->left), getheight(x->right));
		y->height = 1 + max(x->height, getheight(y->right));
		x = y;
	}
	void rotateright(Node*& x)
	{
		Node* y = x->left;
		x->left = y->right;
		y->right = x;
		x->height = 1 + max(getheight(x->left), getheight(x->right));
		y->height = 1 + max(x->height, getheight(y->left));
	}

	void doublerotateright(Node*& x)
	{
		rotateleft(x->left);
		rotateright(x);
	}
	void doublerotateleft(Node*& x)
	{
		rotateright(x->right);
		rotateleft(x);
	}

	void preOrder(Node*& root)
	{
		if (root != NULL)
		{
			cout << root->data << " ";
			preOrder(root->left);
			preOrder(root->right);
		}
	}

	void postOrder(Node*& root)
	{
		if (root != NULL)
		{
			postOrder(root->left);
			postOrder(root->right);
			cout << root->data << " ";
		}
	}

	void inOrder(Node*& root)
	{
		if (root != NULL)
		{
			inOrder(root->left);
			cout << root->data << " ";
			inOrder(root->right);
		}
	}

	Node* deleteAVL(Node*& root, T d)
	{
		if (root == NULL)
			return root;

		if (d < root->data)
			root->left = deleteAVL(root->left, d);

		else if (d > root->data)
			root->right = deleteAVL(root->right, d);

		else
		{
			
			if ((root->left == NULL) || (root->right == NULL))
			{
				Node* temp = root->left ? root->left : root->right;

				if (temp == NULL)
				{
					temp = root;
					root = NULL;
				}
				else
					*root = *temp;
				free(temp);
			}
			else
			{
				Node* temp = minValueNode(root->right);

				root->data = temp->data;

				root->right = deleteAVL(root->right, temp->data);
			}
		}

		if (root == NULL)
			return root;

		root->height = 1 + max(getheight(root->left), getheight(root->right));

	
		int balance = getBalance(root);

		if (balance > 1 && getBalance(root->left) >= 0)
		{
			rotateright(root);
		}

		
		if (balance > 1 && getBalance(root->left) < 0)
		{
			rotateleft(root->left);
			rotateright(root);
		}

		if (balance < -1 && getBalance(root->right) <= 0)
		{
			rotateleft(root);
		}

		if (balance < -1 && getBalance(root->right) > 0)
		{
			rotateright(root->right);
			rotateleft(root);
		}

		return root;
	}

	Node* minValueNode(Node* node)
	{
		Node* current = node;

		while (current->left != NULL)
			current = current->left;

		return current;
	}

	int getBalance(Node*& n)
	{
		if (n == 0)
			return 0;
		return getheight(n->left) -
			getheight(n->right);
	}
	Node* AVLsearch(Node*& root, int key)
	{
		if (root == NULL)
		{
			Node* t = root;
			cout << "NO RECORD " << endl;
			return t;
		}

		else if (root->data == key)
		{
			Node* t = root;
			return t;
		}

		else if (root->data > key)
		{
			AVLsearch(root->left, key);
		}
		else if (root->data < key)
		{
			AVLsearch(root->right, key);
		}
	}

	int minValue()
	{
		Node* current = root;

		while (current->left != NULL) {
			current = current->left;
		}
		return (current->data);
	}
	int maxValue()
	{
		Node* current = root;

		while (current->right != NULL) {
			current = current->right;
		}
		return (current->data);
	}
	void INSERT(T d)
	{
		insert(root, d);
	}
	void deletingAVL(T d)
	{
		Node* tr = AVLsearch(root, d);
		Nodem* tm = tr->point;
		l.deletinglist(tm);
		deleteAVL(root, d);
	}
	void Review(T d)
	{
		Node* t = AVLsearch(root, d);
		if (t != NULL)
		{
			Nodem* tm = t->point;
			l.printingrecord(tm);
		}
		else
		{
			return;
		}
	}
	void Update(T d)
	{
		Node* t = AVLsearch(root, d);
		if (t != NULL)
		{
			Nodem* tm = t->point;
			l.updaterecord(tm);
		}
		else
		{
			return;
		}
	}
	void print()
	{
		cout << "AVL tree is :" << endl;
		preOrder(root);
		cout << endl << endl;
	}
};
class Nodem
{
private:
	int ISSN;
	string title;
	string author;
	int ref_num;
	int iss_num;
	Nodem* next;
	Nodem* prev;
	friend class List;
	friend class AVLTree<int>;
public:
	Nodem()
	{
		next = prev = NULL;
		ISSN = 0;
		ref_num = iss_num = 0;
	}
};
class List
{
private:
	Nodem* head;
	Nodem* tail;
	friend class AVLTree<int>;
public:
	List()
	{
		tail = head = NULL;
	}
	Nodem* insertatend(int d)
	{
		if (head == NULL)
		{
			Nodem* t = new Nodem;
			cout << "NO RECORD FOUND , CREATING A NEW RECORD " << endl;
			cout << "ENTER BOOK NAME :   ";
			cin >> t->title;
			cout << "ENTER AUTHOR NAME :  ";
			cin >> t->author;
			cout << "ENTER REFERENCE NUM :  ";
			cin >> t->ref_num;
			cout << "ENTER ISSUANCE NUM :   ";
			cin >> t->iss_num;
			t->ISSN = d;
			head = t;
			tail = t;
			head->next = tail->next = NULL;
			head->prev = tail->prev = NULL;
			return t;
		}
		else
		{
			int check = 0;
			Nodem* t = head;
			while (t != NULL)
			{
				if (t->ISSN == d)
				{
					cout << "Record already present on this ISSN number " << endl;
					check = 1;
					break;
				}
				t = t->next;
			}
			if (check == 0)
			{
				Nodem* te = new Nodem;
				cout << "NO RECORD FOUND , CREATING A NEW RECORD " << endl;
				cout << "ENTER BOOK NAME :   ";
				cin >> te->title;
				cout << "ENTER AUTHOR NAME :  ";
				cin >> te->author;
				cout << "ENTER REFERENCE NUM :  ";
				cin >> te->ref_num;
				cout << "ENTER ISSUANCE NUM :   ";
				cin >> te->iss_num;
				te->ISSN = d;
				tail->next = te;
				te->prev = tail;
				tail = te;
				tail->next = NULL;
				return te;
			}
		}
	}
	void printingrecord(Nodem*& r)
	{
		Nodem* temp = r;
		cout << "ISSN :   " << temp->ISSN << endl;
		cout << "TITLE :   " << temp->title << endl;
		cout << "AUTHOR :   " << temp->author << endl;
		cout << "REFERENCE NUMBER :   " << temp->ref_num << endl;
		cout << "ISSUANCE UMBER :    " << temp->iss_num << endl;
	}
	void updaterecord(Nodem*& r)
	{
		Nodem* t = r;
		int n;
		cout << "Click on the Corresponding number to update data " << endl;
		cout << "Press 1 for ISSN number " << endl;
		cout << "Press 2 for title " << endl;
		cout << "Press 3 for author " << endl;
		cout << "Press 4 for reference number" << endl;
		cout << "Press 5 for issuance number" << endl;
		cin >> n;
		if (n == 1)
		{
			cout << "Enter updated ISSN number ";
			cin >> t->ISSN;
		}
		else if (n == 2)
		{
			cout << "Enter updated title ";
			cin >> t->title;
		}
		else if (n == 3)
		{
			cout << "Enter updated author name ";
			cin >> t->author;
		}
		else if (n == 4)
		{
			cout << "Enter updated reference number ";
			cin >> t->ref_num;
		}
		else if (n == 5)
		{
			cout << "Enter updated issuance number ";
			cin >> t->iss_num;
		}
		cout << "UPDATED RECORD IS " << endl;
		printingrecord(t);
	}
	void printlist()
	{
		Nodem* r = head;
		while (r != NULL)
		{
			cout << r->ISSN << endl;
			r = r->next;
		}
	}
	void deletinglist(Nodem*& t)
	{
		if (t == head)
		{
			t->next->prev = NULL;
			head = t->next;
			delete t;
		}
		else if (t == tail)
		{
			t->prev->next = NULL;
			tail = t->prev;
			delete t;
		}
		else
		{
			t->prev->next = t->next;
			t->next->prev = t->prev;
			delete t;
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
	cout << "Press 5 to view your AVL Tree" << endl;
}
int main()
{
	AVLTree<int>a;
	int x = 1;
	int d = 0;
	while (x != 0)
	{
		input();
		cin >> x;
		if (x == 1 || x == 2 || x == 3 || x == 4)
		{
			cout << "Enter ISSN number of book record :   ";
			cin >> d;
		}
		if (x == 1)
		{
			a.INSERT(d);
			cout << endl << endl;
		}
		if (x == 2)
		{
			a.Review(d);
			cout << endl << endl;
		}
		if (x == 3)
		{
			a.Update(d);
			cout << endl << endl;
		}
		if (x == 4)
		{
			a.deletingAVL(d);
			cout << endl << endl;
		}
		if (x == 5)
		{
			a.print();
			cout << endl << endl;
		}
	}
	system("pause");
	return 0;
}