/* THE FINAL LIBRARY */

#include<iostream>
using namespace std;


class Stack
{
	public:
		int array[100];
		int size;
		int maximum;
		Stack(int a)
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
			return arr[size];
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

int main()
{
	Stack s(20);
	s.push(5);
	cout << s.array[0];
	return 0;
}

