#include <iostream>


using namespace std;

struct Node {
	int value;
	Node* next;
};

struct CircleLinkedList {
	Node* head;
	Node* tail;
};

void init(CircleLinkedList& l) {
	l.head = l.tail = NULL;
}

Node* createNode(int x) {
	Node* p = new Node;
	p->value = x;
	p->next = NULL;
	return p;
}

void addFirst(CircleLinkedList& l, int x) {
	Node* p = createNode(x);
	if (l.head == NULL) {
		l.head = l.tail = p;
		l.tail->next = l.head;
	}
	else {
		l.tail->next = p;
		p->next = l.head;
		l.head = p;
	}
}

void addLast(CircleLinkedList &l, int x) {
	Node* p = createNode(x);
	if (l.head == NULL) {
		l.head = l.tail = p;
		l.tail->next = l.head;
	}
	else {
		l.tail->next = p;
		p->next = l.head;
		l.tail = p;
	}
}
Node* search(CircleLinkedList l, int x) {
	Node* q = l.head;
	do {
		if (q->value == x)
			return q;
		q = q->next;
	} while (q != l.tail->next);
	return NULL;
}

void addNodeAfter(CircleLinkedList &l, int find, int x) {
	if (l.head != NULL) {
		Node* q = search(l, find);
		if (q != NULL) {
			Node* p = createNode(x);
			if (q->next == l.head)
				addLast(l, p->value);
			else {
				p->next = q->next;
				q->next = p;
			}
		}
	}
}
void addNodeBefore(CircleLinkedList& l, int find, int x) {
	if (l.head != NULL) {
		Node* q = search(l, find);
		if (q != NULL) {
			Node* p = createNode(x);
			if (q->next == l.head)
				addFirst(l, p->value);
			else {
				p->next = q->next;
				q->next = p;
			}
		}
	}
}
void delFirst(CircleLinkedList& l) {
	if (l.head != NULL) {
		Node* p = l.head;
		if (l.head == l.tail) {
			l.head = l.tail = NULL;
			p->next = NULL;
		}
		else {
			l.tail->next = l.head->next;
			l.head = l.head->next;
			p->next = NULL;
		}
		delete p;
	}
}
void delLast(CircleLinkedList &l) {
	if (l.head != NULL) {
		Node* p = l.tail;
		if (l.head == l.tail) {
			l.head = l.tail = NULL;
			p->next = NULL;
		}
		else {
			Node* prevTail = l.head;
			while (prevTail->next != l.tail)
				prevTail = prevTail->next;
			prevTail->next = l.head;
			l.tail = prevTail;
			p->next = NULL;
		}
		delete p;
	}
}
void delNode(CircleLinkedList&l, int x) {
	Node * q = search(l, x);
	if (q != NULL) {
		Node* prevQ = l.head;
		while (prevQ->next != q)
			prevQ = prevQ->next;
		if (q == l.head)
			delFirst(l);
		else if (prevQ->next == l.tail)
			delLast(l);
		else {
			prevQ->next = q->next;
			q->next = NULL;
			delete q;
		}
	}
}

void swap(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}

void sort(CircleLinkedList& l) {
	Node* p = l.head;
	do {
		Node* q = p->next;
		do {
			if (p->value > q->value)
				swap(p->value, q->value);
			q = q->next;
		} while (q != l.tail->next);
		p = p->next;
	} while (p != l.tail);
}

void addNodeSpecial(CircleLinkedList& l, int x) {
	if (l.head != NULL) {
		Node* p = createNode(x);
		Node* q = l.head;
		while (q->next != l.head && x > q->value) {
			q = q->next;
		}
		addNodeAfter(l, q->value, x);
	}
}

void output(CircleLinkedList l) {
	if (l.head != NULL) {
		Node* p = l.head;
		do {
			cout << p->value << " ";
			p = p->next;
		} while (p != l.tail->next);
		cout << endl;
	}
}

void clean(CircleLinkedList &l) {
	if (l.head != NULL) {
		do {
			delFirst(l);
		} while (l.head != l.tail);
	}
}

int main() {
	CircleLinkedList l;
	init(l);
	addFirst(l, 5);
	addFirst(l, 4);
	addFirst(l, 2);
	addFirst(l, 1);
	output(l);
	/*cout << "=============SAU KHI XOA============\n";
	delFirst(l);
	delLast(l);
	output(l);*/
	/*delNode(l,120);*/
	//sort(l);
	addNodeSpecial(l, 3);
	output(l);
	/*cout << "==============SEARCH===============\n";
	cout << search(l, 11)->value << endl;*/
	cout << "=============CLEAN=============\n";
	clean(l);


	return 1;
}
