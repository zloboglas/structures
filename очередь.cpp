#include <iostream>
using namespace std;

struct node_s {
	int data;
	node_s* next_ptr;
	node_s* previous_ptr;
};

// struct queue_descr {

node_s* top_ptr = NULL;
node_s* buttom_ptr = NULL;
int counter = 0;

// };

void push(int);
int pop();




int main() {
	char user_input;
	bool flag = 1;

	for (; flag;) {

		cin >> user_input;

		switch (user_input) {
			case('w'): {
				// write
				int var;
				cin >> var;
				push(var);
				break;
			}
			case('r'): {
				// read
				if (counter == 0) {
					cout << "sorry, but there isn't any elements in the queue" << endl;
				}
				else {
					cout << pop() << endl;
				}
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
	node_s* node_ptr = new node_s;

	node_ptr->data = value; // �������� ������

	node_ptr->previous_ptr = NULL; // ����������� ���

	node_ptr->next_ptr = top_ptr; // ��������� ��������

	top_ptr = node_ptr; // ������ ������� ��� ����

	if (counter == 0) { // �� � ������ ����
		buttom_ptr = node_ptr;
	}

	if (counter > 0) {
		node_ptr->next_ptr->previous_ptr = node_ptr; // ���������� ������������ ��� ����
	}
	counter++;
}

int pop() {
	int rec = buttom_ptr->data; // ��������� �-��� 
	node_s* tmp = buttom_ptr->previous_ptr;

	delete buttom_ptr;

	counter--;

	buttom_ptr = tmp;

	if (counter > 0) {
		buttom_ptr->next_ptr = NULL;
	}

	return rec;
}