#include <iostream>

using namespace std;
struct Node
{
	int value;
	// Node next; ??????
	Node *next;
};
void init(Node *&head)
{
	head = NULL;
}
Node *createNode(int x)
{
	Node *p = new Node;
	p->value = x;
	p->next = NULL;
	return p;
}
void addFirst(Node *&head, int x)
{
	Node *p = createNode(x);
	p->next = head;
	head = p;
}
void addLast(Node *&head, int x)
{
	Node *p = createNode(x);
	if (head == NULL)
	{
		head = p;
	}
	else
	{
		Node *last = head;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = p;
	}
}
void output(Node *head)
{
	Node *p = head;
	while (p != NULL)
	{
		cout << p->value << "\t";
		p = p->next;
	}
	cout << endl;
}
void addNode(Node *head, int findNode, int giatri)
{
	Node *p = createNode(giatri);
	// tim node
	Node *q = head;
	while (q != NULL && q->value != findNode)
	{
		q = q->next;
	}
	if (q != NULL)
	{
		p->next = q->next;
		q->next = p;
	}
}
Node *search(Node *head, int giatri)
{
	Node *p = head;
	while (p != NULL && p->value != giatri)
	{
		p = p->next;
	}
	return p;
}
void deleteFirst(Node *&head)
{
	if (head != NULL)
	{
		Node *p = head;
		head = p->next;
		p->next = NULL;
		delete (p);
	}
}
void deleteLast(Node *&head)
{
	if (head != NULL)
	{
		Node *last = head;
		Node *prev = NULL;
		while (last->next != NULL)
		{
			prev = last;
			last = last->next;
		}
		if (prev == NULL)
		{
			deleteFirst(head);
		}
		else
		{
			prev->next = NULL;
			delete (last);
		}
	}
}
void deleteNode(Node *&head, int giatri)
{
	if (head != NULL)
	{
		Node *p = head;
		Node *prev = NULL;
		while (p != NULL && p->value != giatri)
		{
			prev = p;
			p = p->next;
		}
		if (p != NULL)
		{ // da tim thay
			if (prev == NULL)
			{
				deleteFirst(head);
			}
			else
			{
				prev->next = p->next;
				p->next = NULL;
				delete (p);
			}
		}
	}
}
Node *maxElement(Node *head)
{
	int max = INT_MIN;
	Node *kq = NULL;
	Node *p = head;
	while (p != NULL)
	{
		if (max < p->value)
		{
			max = p->value;
			kq = p;
		}
		p = p->next;
	}
	return kq;
}
void swapNode(int &a, int &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}
void swap(Node *&a, Node *&b)
{
	Node *tmp = a;
	a = b;
	b = tmp;
}
void interchangeSort(Node *head)
{
	for (Node *i = head; i != NULL; i = i->next)
	{
		for (Node *j = i->next; j != NULL; j = j->next)
		{
			if (i->value > j->value)
			{
				swapNode(i->value, j->value);
			}
		}
	}
}
// void selectionSort(Node* head) {
//	Node* prev = NULL;
//	Node* next = head;
//	while (next != NULL) {
//
//
//
//	}
//
// }
void clean(Node *&head)
{
	while (head != NULL)
	{
		deleteFirst(head);
	}
}
int main()
{
	Node *head;
	init(head);
	/*addLast(head, 100);
	addFirst(head, 1);
	addFirst(head, 10);
	addLast(head, 99);
	addFirst(head, 5);
	addLast(head, 1);*/
	addFirst(head, 6);
	addFirst(head, 8);
	addFirst(head, 7);
	addNode(head, 8, 10);
	output(head);
	deleteNode(head, 7);
	// deleteFirst(head);
	// deleteLast(head);

	output(head);
	// cout << "Max = " << maxElement(head)->value;
	// clean(head);
	// interchangeSort(head);
	// output(head);
	return 1;
}