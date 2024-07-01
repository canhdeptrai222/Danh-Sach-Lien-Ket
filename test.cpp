#include <iostream>

using namespace std;

struct SinhVien {
	int id;
	string name;
};

ostream& operator << (ostream& out, const SinhVien sv) {
	out << "MSSV: " << sv.id << endl;
	out << "Ho va ten: " << sv.name << endl;

	return out;
}

template <typename T>
struct Node
{
	T value;
	// Node next; ??????
	Node* next;
};
template <typename T>
void init(Node<T>*& head)
{
	head = NULL;
}
template <typename T>
Node<T>* createNode(T x)
{
	Node<T>* p = new Node<T>;
	p->value = x;
	p->next = NULL;
	return p;
}
template <typename T>
void addFirst(Node<T>*& head, T x)
{
	Node<T>* p = createNode(x);
	p->next = head;
	head = p;
}
template <typename T>
void deleteFirst(Node<T>*& head)
{
	if (head != NULL)
	{
		Node<T>* p = head;
		head = p->next;
		p->next = NULL;
		delete (p);
	}
}
template <typename T>
void output(Node<T>* head)
{
	Node<T>* p = head;
	while (p != NULL)
	{
		cout << p->value;
		p = p->next;
	}
	cout << endl;
}
template <typename T>
void clean(Node<T>*& head)
{
	while (head != NULL)
	{
		deleteFirst(head);
	}
}
int main()
{
	Node<SinhVien>* head;
	init(head);
	SinhVien sv1;
	sv1.id = 123;
	sv1.name = "Canh";
	SinhVien sv2;
	sv2.id = 456;
	sv2.name = "Ronaldo";
	addFirst(head, sv1);
	addFirst(head, sv2);
	/*addFirst(head, 7);*/
	output(head);
	cout << "======CLEAN======\n";
	clean(head);
	output(head);
	return 0;
}