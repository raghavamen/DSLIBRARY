/* THE FINAL LIBRARY */

#include<iostream>
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


int main()
{
	Queue q(20);
	q.enqueue(5);
	cout << q.array[0];
	q.enqueue(6);
	int a = q.dequeue();
	cout << a;
	a = q.dequeue();
	
	return 0;
}

