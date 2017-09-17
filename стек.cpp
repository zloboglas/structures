#include <iostream>
using namespace std;


struct node_s {
	int data;
	node_s* prev;
};

void push(int);

int pop();

// struct stack_descr {}
node_s* top_ptr;
int counter = 0;


int main() {
	char c;
	bool flag = 1;
	for (; flag;) {
		cin >> c;

		switch (c) {
		case('w'): {
			int var;
			cin >> var;
			push(var);
			break;
		}
		case('r'): {
			cout << endl << pop() << endl;
			break;
		}
		default: {
			flag = 0;
		}
		}

	}

	return 0;
}

void push(int value) {
	node_s* node_ptr;
	node_ptr = new node_s;

	node_ptr->data = value;

	if (counter == 0)
		node_ptr->prev = NULL;
	else
		node_ptr->prev = top_ptr;

	counter++;
	top_ptr = node_ptr;
}

int pop() {
	if (counter > 0) {
		int ret = top_ptr->data;
		node_s* it = top_ptr->prev; //tmp

		delete top_ptr;

		counter--;

		top_ptr = it;
		return ret;
	}
	else {
		return -42757;
	}
}
