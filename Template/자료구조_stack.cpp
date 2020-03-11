#include<iostream>
using namespace std;
template<typename T>

struct StackNode{
	T value;
	StackNode *next;
	StackNode(T value,StackNode* next)
		:value(value),next(next){}
};

template<typename T>
class Stack {
	int StackSize;
	StackNode<T>* top;
public:
	Stack() : top(NULL),StackSize(0) {}
	void push(T value) {
		top = new StackNode<T>(value, top);
		StackSize++;
	}
	T &peek() {
		return top->value;
	}
	void pop() {
		StackNode<T>* remove = top;
		top = top->next;
		delete remove;
		StackSize--;
	}
	int size() {
		return StackSize;
	}
	bool empty() {
		return StackSize == 0;
	}
};

struct Position {
	int x, y;
};

int main()
{
	Stack<Position> s;
	Position p;
	p.x = 3;
	p.y = 4;
	s.push(p);
	p.x = 1;
	p.y = 2;
	s.push(p);
	while(s.empty()==false)
	{
		Position&a = s.peek();
		cout << a.x << '/' << a.y;
		s.pop();
	}
}