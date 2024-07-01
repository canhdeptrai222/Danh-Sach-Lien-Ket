#include <iostream>

using namespace std;
// khai bao cau truc
struct Node {
	int value;
	Node* next;
	Node* prev;
};

struct DoubleLinkedList {
	Node* head;
	Node* tail;
};
// khai bao danh sach rong
void init(DoubleLinkedList& ls) {
	ls.head = ls.tail = NULL;
}

Node* createNode(int x) {
	Node* p = new Node;
	p->value = x;
	p->next = NULL;
	p->prev = NULL;
	return p;
}
//add first
void addFirst(DoubleLinkedList& ls, int x) {
	Node* p = createNode(x);
	if (ls.head == NULL) {
		ls.head = ls.tail = p;
	}
	else {
		p->next = ls.head;
		ls.head->prev = p;
		ls.head = p;
	}
}
//add last
void addLast(DoubleLinkedList& ls, int x) {
	Node* p = createNode(x);
	if (ls.head == NULL) {
		ls.head = ls.tail = p;
	}
	else {
		ls.tail->next = p;
		p->prev = ls.tail;
		ls.tail = p;
	}
}
//delete first
void delFirst(DoubleLinkedList& ls) {
	if (ls.head != NULL) {
		Node* p = ls.head;
		if (p->next == NULL)
			ls.head = ls.tail = NULL;
		else {
			ls.head = ls.head->next;
			p->next = NULL;
			ls.head->prev = NULL;
		}
		delete(p);
	}
}
//delete last
void delLast(DoubleLinkedList& ls) {
	if (ls.head != NULL) {
		Node* p = ls.tail;
		if (p->prev == NULL) {
			ls.head = ls.tail = NULL;
		}
		else {
			ls.tail = ls.tail->prev;
			ls.tail->next = NULL;
			p->prev = NULL;
		}
		delete(p);
	}
}
//find and delete
void deleteNode(DoubleLinkedList& ls, int x) {
	if (ls.head != NULL) {
		Node* p = ls.head;
		Node* prev = NULL;
		while (p != NULL && p->value != x) {
			prev = p;
			p = p->next;
		}
		if (p != NULL) {
			if (prev == NULL) {
				delFirst(ls);
				return;
			}
			else if (p->next == NULL) {
				delLast(ls);
				return;
			}
			else {
				prev->next = p->next;
				p->next->prev = prev;
				p->next = NULL;
				p->prev = NULL;
				delete(p);
			}
		}

	}
}
//hehe
Node* searchExact(DoubleLinkedList& ls, int x) {
	if (ls.head != NULL) {
		Node* p = ls.head;
		while (p != NULL && p->value <= x) {
			p = p->next;
		}return p;
	}
}
//search and add 
void addNode(DoubleLinkedList ls, int prev, int x) {
	if (ls.head != NULL) {
		Node* p = searchExact(ls, prev);
		Node* add = createNode(x);
		if (p != NULL) {
			if (p->next == NULL) {
				addLast(ls, x);
			}
			else {
				add->next = p->next;
				p->next->prev = add;
				add->prev = p;
				p->next = add;
			}
		}
		system("Color C");
	}
}
//xuat danh sach
void output(DoubleLinkedList ls) {
	Node* p = ls.head;
	while (p != NULL) {
		cout << p->value << "\t";
		p = p->next;
	}cout << endl;
	system("Color B");
}
//giai phong phan tu khoi heappp
void clearNode(DoubleLinkedList& ls)
{
	while (ls.head != NULL)
	{
		delFirst(ls);
	};
	cout << "CLEAR!\n";
}
int main() {
	DoubleLinkedList ls;
	init(ls);
	addLast(ls, 80);
	addFirst(ls, 55);
	addFirst(ls, 16);
	addLast(ls, 90);
	output(ls);
	/*delFirst(ls);
	delLast(ls);*/
	//16 55 80 3
	/*Node* res = searchExact(ls, 17);
	cout << res << endl;
	cout << res->value << endl;*/
	addNode(ls, 81, 10);
	output(ls);
	return 1;
}