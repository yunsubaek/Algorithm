#include <stdio.h>
#include <string.h>
template <typename T>
class queue {
public:
	class Node {
	public:
		T data;
		Node *next;
	};
	Node *head = 0, *tail = 0;
	int _size = 0;
	void push(T data) {
		_size++;
		Node *temp = new Node();
		temp->data = data;
		if (head == 0) {
			head = tail = temp;
		}
		else {
			tail->next = temp;
			tail = tail->next;
		}
	}
	T front() {
		if (_size == 0)
			return -1;
		return head->data;
	}
	bool empty() {
		return _size == 0;
	}
	void pop() {
		if (_size == 0)
			return;
		_size--;
		Node *temp = head;
		head = head->next;
		delete temp;
	}
	int size() {
		return _size;
	}
	void clear() {
		while (_size) {
			Node *temp = head;
			head = head->next;
			_size--;
			delete temp;
		}
	}
	T back() {
		if (_size == 0)
			return -1;
		return tail->data;
	}
};
int n;
char order[10];
int main() {
	scanf("%d", &n);
	queue<int> q;
	for (int i = 0; i<n; i++) {
		scanf("%s", order);
		if (strcmp(order, "push") == 0) {
			int in;
			scanf("%d", &in);
			q.push(in);
		}
		else if (strcmp(order, "pop") == 0) {
			if (q.size() == 0)
				printf("-1\n");
			else {
				printf("%d\n", q.front());
				q.pop();
			}
		}
		else if (strcmp(order, "size") == 0) {
			printf("%d\n", q.size());
		}
		else if (strcmp(order, "empty") == 0) {
			printf("%d\n", q.empty());
		}
		else if (strcmp(order, "front") == 0) {
			if (q.size() == 0)
				printf("-1\n");
			else
				printf("%d\n", q.front());
		}
		else if (strcmp(order, "back") == 0) {
			if (q.size() == 0)
				printf("-1\n");
			else
				printf("%d\n", q.back());
		}
	}
	return 0;
}
