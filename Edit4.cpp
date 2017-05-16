/* THE FINAL LIBRARY */

#include<iostream>
#include<cstdlib>
using namespace std;


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
};



int main()
{
	List l;
	l.addbegin(5);
	l.addbegin(6);
	l.addend(7);
	l.print();
	l.deletelist(5);
	l.print();
	cout << l.lengthOfList() << " is the length of the list";
	if(l.cycleList()) cout << "There is a loop";
	else cout << "No loop";
	l.reverseList();
	l.print();
	return 0;
}

