#include <iostream>
#include <Windows.h>
using namespace std;
//khai bao cau truc
struct Node {
	int value;
	Node* next;
};

struct DSLienKetVong {
	Node* head;
	Node* tail;
};

//khoi tao danh sach rong
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
void addLast(DSLienKetVong& lk, int x) {
	Node* p = createNode(x);
	if (lk.head == NULL) {
		addFirst(lk, p->value);
	}
	else {
		lk.tail->next = p;
		p->next = lk.head;
		lk.tail = p;
	}

}
void delFirst(DSLienKetVong& lk) {
	if (lk.head != NULL) {
		Node* p = lk.head;
		if (lk.tail == lk.head) {
			lk.head = lk.tail = NULL;
			p->next = NULL;
		}
		else {
			lk.head = lk.head->next;
			lk.tail->next = lk.head;
			p->next = NULL;
		}
		delete(p);
	}
}
void delLast(DSLienKetVong& lk) {
	if (lk.head != NULL) {
		Node* pPrev = lk.head;
		Node* p = lk.tail;
		if (p == pPrev) {
			lk.head = lk.tail = NULL;
			p->next = NULL;
			pPrev->next = NULL;
		}
		else {
			while (pPrev->next != lk.tail) {
				pPrev = pPrev->next;
			}
			pPrev->next = lk.head;
			p->next = NULL;
			lk.tail = pPrev;
		}
		delete(p);
	}
}
Node* search(DSLienKetVong lk, int x) {
	if (lk.head != NULL) {
		Node* p = lk.head;
		do {
			if (p->value != x) {
				p = p->next;
			}
			else
				return p;
		} while (p != lk.tail->next);
	}
	return NULL;
}
void delNode(DSLienKetVong& lk, int x) {
	if (lk.head != NULL) {
		Node* p = search(lk, x);
		if (p != NULL) {
			Node* q = lk.head;
			while (q->next != p) {
				q = q->next;
			}
			if (p->next == q) {
				delFirst(lk);
			}
			else if (q->next == lk.tail) {
				delLast(lk);
			}
			else {
				q->next = p->next;
				p->next = NULL;
				delete(p);
			}
		}
	}
}

//xuat phan tu
void output(DSLienKetVong lk) {
	Node* p = lk.head;
	if (lk.head != NULL) {
		do {
			cout << p->value << "\t";
			p = p->next;
		} while (p != lk.tail->next);
		cout << "Done!!!!!!!!" << endl;
		return;
	}
	cout << "No ELEMENT!" << endl;
}


void clearNode(DSLienKetVong& lk) {
	if (lk.head != NULL) {
		while (lk.head != NULL) {
			delFirst(lk);
		}
	}
}
int main() {
	DSLienKetVong lk;
	init(lk);
	addLast(lk, 100);
	addFirst(lk, 10);
	addFirst(lk, 9);
	addLast(lk, 8);
	output(lk);
	/*delFirst(lk);*/
	//delLast(lk);
	delNode(lk, 100);
	output(lk);
	clearNode(lk);
	cout << "=======CLEAR======\n";
	output(lk);
	return 1;
}