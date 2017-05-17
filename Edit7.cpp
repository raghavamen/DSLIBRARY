/* THE FINAL LIBRARY */

#include<iostream>
#include<cstdlib>
#include<queue>
#include<stack>
using namespace std;

// QUEUE has been used for LEVEL ORDER PRINTING OF BST //

class Stack
{
	public:
		int array[100];
		int size;
		int maximum;
		Stack(int a = 100)
		{
			maximum = a;
			size = 0;
		}
		void push(int a)
		{
			array[size++] = a;	
		}
		int pop(void)
		{
			size--;
			return array[size];
		}
		bool isEmpty(void)
		{
			if(size==0) return true;
			else return false;
		}
		bool isFull(void)
		{
			if(size == maximum) return true;
			return false;
		}
		int sizeOfStack(void)
		{
			return size;
		}
};

class Queue
{
	public:
		int array[100];
		int maximum;
		int size;
		int front = -1;
		int rear = -1;
		Queue(int a = 100)
		{
			size = 0;
			maximum = a;
		}
		bool isFull(void)
		{
			if(size == maximum) return true;
			return false;
		}
		void enqueue(int data)
		{
			if(isFull()) return ;
			if(front == -1)
			{
				front = front+1;
			}
			rear = (rear + 1)%maximum;
			array[rear] = data;
			size++;
		}
		bool isEmpty()
		{
			if(size==0) return true;
			return false;
		}
		int dequeue()
		{
			if(isEmpty()) return -1;
			int a = array[front];
			front = (front+1)%maximum;
			size--;
			return a;
		}
};


class Node
{
	public:
	int data;
	Node *next = {NULL};
	public:
		Node(int d)
		{
			data = d; 
		}
		Node()
		{
		}
		void setNext(Node * n)
		{
			next = n;
		}
		int getData(void)
		{
			return data;
		}
};

class List
{
	Node * head;
	public:
		List()
		{
			head = NULL;
		}
		void print()
		{
			Node * temp;
			temp = head;
			while(temp)
			{
				int a = temp->getData();
				cout << a << " ";
				temp = temp->next; 
			}
		}
		void addbegin(int data)
		{
			Node * temp = new Node;
			temp->data = data;
			temp->next = head;
			head = temp;
		}
		void addend(int data)
		{
			Node * temp = head;
			while(temp->next)
			{
				temp = temp->next;
			}
			temp->next = new Node;
			temp->next->data = data;
		}
		void deletelist(int data)
		{
			if(head->data == data) head = head->next;
			else
			{
				Node * temp = head;
				while(temp->next->data!= data)
				{
					temp = temp->next;
				}
				Node * k = temp->next;
				temp->next = k->next;
				free(k);
			}
		}
		int lengthOfList()
		{
			int count = 0;
			if(head == NULL) return count;
			Node * k = head;
			while(k)
			{
				count++;
				k = k->next;
			}
			return count;
		}
		bool cycleList()
		{
			Node *first = head;
			Node *second = head;
			while(first && second && second->next)
			{
				first = first->next;
				second = second->next->next;
				if(first == second)
				{
					return true;
				}
			}
			return false;
		}
		
		void reverseList()
		{
			Node * current = head;
			Node * prev = NULL;
			Node * nexts;
			while(current != NULL)
			{
				nexts = current->next;
				current->next = prev;
				prev = current;
				current = nexts;
			}
			head = prev;
		}
		bool searchList(int data)
		{
			Node * temp = head;
			while(temp)
			{
				if(temp->data == data) return true;
				temp = temp->next;
			}
			return false;
		}
		Node * getNth(int N)
		{
			Node * temp = head;
			for(int i = 1; i < N; i++)
			{
				temp = temp->next;
			}
			return temp;
		}
		Node * NthFromEnd(int N)
		{
			Node * temp = head;
			int len = 0;
			while(temp)
			{
				len++;
				temp = temp->next;	
			}
			temp = head;
			for(int i = 1; i < len - N + 1; i++)
			{
				temp = temp->next;
			}
			return temp;Add
		}
		bool Palindrome()
		{
			Node * temp = head;
			stack<Node *s> s;
			while(temp)
			{
				s.push(temp);
				temp = temp->next;
			}
			temp = head;
			while(temp)
			{
				Node * k = s.top();
				s.pop();
				if(temp->data != k->data) return false;
				temp = temp->next;
			}
			return true;
		}
};

class bnode
{
	public:
	bnode *left = NULL;
	int data;
	bnode *right = NULL;
	bnode()
	{
		left = NULL;
		data;
		right = NULL;
	}
	bnode(int value)
	{
		left = NULL;
		data = value;
		right = NULL;
	}
};

class BST
{
	public:
		bnode * p;
	BST()
	{
		p = NULL;
	}
	void insertBST(int data)
	{
		if(p == NULL)
		{
			p = new bnode;
			p->data = data;
			p->left = NULL;
			p->right = NULL;
			return ;
		}
		else
		{
			bnode *t = p;
			while(1)
			{
				if(data < t->data && t->left)
				{
					t = t->left;
				}
				else
				if(data < t->data)
				{
					t->left = new bnode;
					t->left->data = data;
					return ;
				}
				else
				if(data > t->data && t->right)
				{
					t = t->right;
				}
				else
				if(data > t->data)
				{
					t->right = new bnode;
					t->right->data = data;
					return ;
				}
				else
				{
					return ;
				}
			}
		}
		// Finish of Insert function :D 
	}
	void inorder()
	{
		inorders(p);
	}
	private: void inorders(bnode * b)
	{
		if(b == NULL) return ;
		inorders(b->left);
		cout << b->data << " ";
		inorders(b->right);
	}
	public: void postorder()
	{
		postorders(p);
	}
	private: void postorders(bnode * b)
	{
		if(b == NULL) return ;
		postorders(b->left);
		postorders(b->right);
		cout << b->data << " ";
	}
	public: void preorder()
	{
		preorders(p);
	}
	private: void preorders(bnode * b)
	{
		if(b == NULL)
		return;
		cout << b->data << " ";
		postorders(b->left);
		postorders(b->right);
	}
	public: int height()
	{
		return heights(p);
	}
	private : int heights(bnode * b)
	{
		if(b == NULL) return -1;
		return 1 + max(heights(b->left),heights(b->right));
	}
	public : void levelorder()
	{
		queue<bnode *> q;
		bnode * temp = p;
		while(temp)
		{
			cout << temp->data << " ";
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
			if(q.size()==0) return ;
			temp = q.front();
			q.pop();
			if(!temp) return ;
		}
		
	}
	bool searchBST(int data)
	{
		return searchingBST(p, data);
	}
	private : bool searchingBST(bnode * a, int d)
	{
		if(a == NULL) return false;
		if(a->data == d) return true;
		if(d < a->data) return searchingBST(a->left,d);
		else return searchingBST(a->right, d);
	}
	public : int maxWidth()
	{
		return maxWidthBST(p);
	}
	private : int maxWidthBST(bnode * a)
	{
		if(a==NULL) return 0;
		int result = 0;
		queue<bnode *> q;
		q.push(a);
		while(!q.empty())
		{
			int count = q.size();
			result = max(count, result);
			while(count--)
			{
				bnode * temp = q.front();
				q.pop();
				if(temp->left) q.push(temp->left);
				if(temp->right) q.push(temp->right);
			}
		}
		return result;
	}
};


int main()
{
	BST B;
	B.insertBST(23);
	B.inorder();
	cout << endl << endl;
	B.insertBST(20);
	B.insertBST(26);
	B.insertBST(15);
	B.insertBST(21);
	B.insertBST(24);
	B.insertBST(27);
	cout << "The maximum width of the BST is " << B.maxWidth();
	return 0;
}

