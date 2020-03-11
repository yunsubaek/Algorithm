#include <stdio.h>
#include <string.h>
template<typename T>
class stack {
public:
	class Node {
	public:
		T data;
		Node *next;
		Node() {}
		Node(T data, Node *next) :data(data), next(next) {}
	};
	Node *tail = NULL;
	int _size = 0;
	void push(T data) {
		Node *temp = new Node();
		temp->data = data;
		_size++;
		if (tail == NULL) {
			tail = temp;
		}
		else {
			temp->next = tail;
			tail = temp;
		}
	}
	T top() {
		if (_size == 0)
			return -1;
		return tail->data;
	}
	bool empty() {
		return _size == 0;
	}
	void pop() {
		if (_size == 0)
			return;
		_size--;
		Node *temp = tail;
		tail = tail->next;
		delete temp;
	}
	int size() {
		return _size;
	}
	void clear() {
		while (_size) {
			Node *temp = tail;
			tail = tail->next;
			delete temp;
			_size--;
		}
		tail = NULL;
	}
};
int n;
char order[10];
int in;
int main() {
	scanf("%d", &n);
	stack<int> st;
	for (int i = 0; i<n; i++) {
		scanf("%s", order);
		if (strcmp(order, "push") == 0) {
			scanf("%d", &in);
			st.push(in);
		}
		else if (strcmp(order, "pop") == 0) {
			if (st.size() == 0)
				printf("-1\n");
			else {
				int now = st.top();
				printf("%d\n", now);
				st.pop();

			}
		}
		else if (strcmp(order, "size") == 0) {
			printf("%d\n", st.size());
		}
		else if (strcmp(order, "empty") == 0) {
			printf("%d\n", st.empty());
		}
		else if (strcmp(order, "top") == 0) {
			if (st.size() == 0)
				printf("-1\n");
			else
				printf("%d\n", st.top());
		}
	}
	return 0;
}
