#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* next;
};

struct DSLienKetVong {
	Node* head;
	Node* tail;
};

void init(DSLienKetVong& lk) {
	lk.head = lk.tail = NULL;
}

Node* createNode(int x) {
	Node* p = new Node;
	p->value = x;
	p->next = NULL;
	return p;
}

void addFirst(DSLienKetVong& lk, int x) {
	Node* p = createNode(x);
	if (lk.head == NULL) {
		lk.head = lk.tail = p;
		lk.tail->next = lk.head;
	}
	else {
		p->next = lk.head;
		lk.head = p;
		lk.tail->next = lk.head;
	}
}
void output(DSLienKetVong lk) {
	Node* p = lk.head;
	do {
		cout << p->value << "\t";
		p = p->next;
	} while (p != lk.tail->next);
}
int main() {
	DSLienKetVong lk;
	init(lk);
	addFirst(lk, 10);
	addFirst(lk, 9);
	addFirst(lk, 2);
	output(lk);
	return 1;
}