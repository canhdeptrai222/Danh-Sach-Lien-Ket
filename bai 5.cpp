#include <iostream>


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

void addFirst(Node*& head, int x)
{
	Node* p = createNode(x);
	if (head == NULL)
	{
		head = p;
	}
	else
	{
		p->next = head;
		head = p;
	}
}



int main() {
	
	system("Color C");
	return 1;
}