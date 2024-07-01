#include <iostream>


using namespace std;


struct Node {
	int value;
	Node* next;
	Node* prev;
};
struct DSLienKetKep {
	Node* head;
	Node* tail;
};
void init(DSLienKetKep& lk) {
	lk.head = NULL;
	lk.tail = NULL;
}
Node* createNode(int x) {
	Node* p = new Node;
	p->value = x;
	p->next = NULL;
	p->prev = NULL;
	return p;
}
void addFirst(DSLienKetKep& lk, int x) {
	Node* p = createNode(x);
	if (lk.head == NULL) {
		lk.head = lk.tail = p;
	}
	else {
		p->next = lk.head;
		lk.head->prev = p;
		lk.head = p;
	}
}
void addLast(DSLienKetKep& lk, int x) {
	Node* p = createNode(x);
	if (lk.head == NULL) {
		lk.head = lk.tail = p;
	}
	else {
		lk.tail->next = p;
		p->prev = lk.tail;
		lk.tail = p;
	}
}
void addNodeAfter(DSLienKetKep& lk, int giatri, int x) {
	Node* q = lk.head;
	if (lk.head != NULL) {
		while (q != NULL && q->value != giatri) {
			q = q->next;
		}
		if (q != NULL) {// da tim thay node
			Node* p = createNode(x);
			if (q == lk.tail) {
				addLast(lk, x);
			}
			else {
				p->next = q->next;
				q->next->prev = p;
				q->next = p;
				p->prev = q;
			}
		}
	}
}
void deleteFirst(DSLienKetKep& lk) {
	if (lk.head != NULL) {
		Node* p = lk.head;
		lk.head = p->next;
		if (p->next != NULL) {
			lk.head->prev = NULL;
			p->next = NULL;
		}
		delete(p);
	}
}
void deleteLast(DSLienKetKep& lk) {
	if (lk.head != NULL) {
		Node* p = lk.tail;
		if (p->prev == NULL) {
			deleteFirst(lk);
			/*lk.head = NULL;
			lk.tail = NULL;*/
		}
		else {
			lk.tail = p->prev;
			lk.tail->next = NULL;
			p->prev = NULL;
			delete(p);
		}
		//delete(p);
	}
}
void deleteNode(DSLienKetKep& lk, int giatri) {
	if (lk.head != NULL) {
		Node* p = lk.head;
		Node* prevNode = NULL;
		
		while (p != NULL && p->value != giatri) {
			prevNode = p;
			p = p->next;
		}
		if (p != NULL) {// da tim thay
			if (prevNode == NULL) {
				deleteFirst(lk);
			}
			else if (p->next == NULL) {
				deleteLast(lk);
			}
			else {
				prevNode->next = p->next;
				p->prev = NULL;
				p->next->prev = prevNode;
				p->next = NULL;
				delete(p);
			}
		}
	}
}
Node* search(DSLienKetKep& lk, int giatri) {
	Node* p = lk.head;
	for (; p != NULL; p = p->next) {
		if (p->value == giatri)
			return p;
	}
	return NULL;
}
void outputLeftToRight(DSLienKetKep lk) {
	Node* p = lk.head;
	while (p != NULL) {
		cout << p->value << "\t";
		p = p->next;
	}cout << endl;
}
void outputRightToleft(DSLienKetKep lk) {
	Node* p = lk.tail;
	while (p != NULL) {
		cout << p->value << "\t";
		p = p->prev;
	}cout << endl;
}
void clean(DSLienKetKep& lk) {
	while (lk.head != NULL) {
		deleteFirst(lk);
	}
	cout << "Clean danh sach thanh cong!" << endl;
}
int main() {
	DSLienKetKep lk;
	init(lk);
	addFirst(lk, 1);
	addFirst(lk, 2);
	addFirst(lk, 9);
	addLast(lk, 10);
	addLast(lk, 100);
	addNodeAfter(lk, 10, 99);
	outputLeftToRight(lk);
	cout << "Tim node: ";
	int node; cin >> node;
	Node* q = search(lk, node);
	if (q == NULL)
		cout << "Khong tim thay" << endl;
	else {
		cout << "Dia chi cua node: " << q << endl;
		cout << "Gia tri cua node = " << q->value << endl;
	}
	//deleteFirst(lk);
	//deleteLast(lk);
	//outputLeftToRight(lk);
	//deleteNode(lk,1);
	//outputLeftToRight(lk);
	clean(lk);
	//outputRightToleft(lk);
	return 1;
}