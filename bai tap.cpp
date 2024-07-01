#include <iostream>
#include <ctime>

using namespace std;

struct Node {
	int value;
	Node* next;
};

void init(Node*& head) {
	head = NULL;
}

Node* createNode(int x) {
	Node* p = new Node;
	p->value = x;
	p->next = NULL;
	return p;
}

void addFirst(Node*& head, int x) {
	Node* p = createNode(x);
	p->next = head;
	head = p;
}
void addLast(Node*& head, int x) {
	Node* p = createNode(x);
	if (head == NULL) {
		head = p;
	}
	else {
		Node* last = head;
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = p;
	}
}
void addNode(Node*& head,int giatri ,int x) {
	Node* p = createNode(x);
	if (head != NULL) {
		Node* find = head;
		while (find != NULL && find->value != giatri) {
			find = find->next;
		}
		if (find != NULL) {
			p->next = find->next;
			find->next = p;
		}
	}
}
void deleteFirst(Node*& head) {
	if (head != NULL) {
		Node* p = head;
		head = head->next;
		p->next = NULL;
		delete(p);
	}
}
void deleteLast(Node*& head) {
	if (head != NULL) {
		Node* last = head;
		Node* prev = NULL;
		while (last->next != NULL) {
			prev = last;
			last = last->next;
		}
		if (prev == NULL) {
			deleteFirst(head);
		}
		else {
			prev->next = NULL;
			delete(last);
		}
	}
}
void deleteNode(Node*& head, int x) {
	if (head != NULL) {
		Node* p = head;
		Node* prev = NULL;
		while (p != NULL && p->value != x) {
			prev = p;
			p = p->next;
		}
		if (p != NULL) {
			if (prev == NULL) {
				deleteFirst(head);
			}
			else {
				prev->next = p->next;
				p->next = NULL;
				delete(p);
			}
		}
	}
}
void randomDS(Node*& head) {
	for (int i = 0; i < 5; i++) {
		addFirst(head, rand() % 100 + 1);
	}
	cout << "Rand thanh cong!" << endl;
}
Node* maxElement(Node* head) {
	int max = INT_MIN;
	Node* p = head;
	Node* res = NULL;
	while (p != NULL) {
		if (p->value > max) {
			max = p->value;
			res = p;
		}
		p = p->next;
	}
	return res;
}
int tong(Node* head) {
	int sum = 0;
	Node* p = head;
	while (p != NULL) {
		sum += p->value;
		p = p->next;
	}
	return sum;
}
bool SNT(int x) {
	if (x < 2)
		return false;
	else {
		for (int i = 2; i <= sqrt(x); i++) {
			if (x % i == 0) {
				return false;
			}
		}
	}
	return true;
}
int countSNT(Node* head) {
	int count = 0;
	for (Node* p = head; p != NULL; p = p->next) {
		if (SNT(p->value))
			count++;
	}
	return count;
}
void xuatSNT(Node* head) {
	for (Node* p = head; p != NULL; p = p->next) {
		if (SNT(p->value))
			cout << p->value << "\t";
	}cout << endl;
}

Node* gopDS(Node* head1, Node* head2) {
	Node* tmp = head1;
	Node* combine = tmp;
	if (head1 != NULL && head2 != NULL) {
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = head2;
	}
	return combine;
}
Node* reserve(Node*& head) {
	Node* current = head;
	Node* prev = NULL;
	Node* next = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}
void output(Node* head) {
	Node* p = head;
	while (p != NULL) {
		cout << p->value << "\t";
		p = p->next;
	}cout << endl;
}
int main() {
	srand((int)time(NULL));
	Node* head;
	init(head);
	randomDS(head);
	output(head);
	/*cout << "Max = " << maxElement(head)->value << endl;
	cout << "Tong = " << tong(head) << endl; 
	cout << "So luong so nguyen to = " << countSNT(head) << endl;
	cout << "Them 1 phan tu vao cuoi: " << endl;
	addLast(head, -1);
	output(head);
	cout << "Xoa phan tu dau: " << endl;
	deleteFirst(head);
	output(head);
	cout << "Xoa phan tu cuoi: " << endl;
	deleteLast(head);
	output(head);
	cout << "Xoa phan tu bat ki: " << endl;
	cout << "Nhap phan tu can xoa: ";
	int x;
	cin >> x;
	deleteNode(head, x);
	output(head);
	cout << "Them phan tu bat ki: " << endl;
	int tmp;
	cout << "Nhap vi tri can them sau so ?: ";
	cin >> tmp;
	addNode(head, tmp, 10);
	output(head);*/
	cout << "dao nguoc danh sach: ";
	Node* res = reserve(head);
	output(res);
	/*Node* head1;
	init(head1);
	randomDS(head1);
	cout << "Danh sach lien ket head1: ";
	output(head1);
	Node* head2;
	init(head2);
	randomDS(head2);
	cout << "Danh sach lien ket head2: ";
	output(head2);
	cout << "Danh sach sau khi noi: \t";
	output(gopDS(head1, head2));*/
	return 1;
}