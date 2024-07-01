#include <iostream>

using namespace std;

struct Node
{
	int value;
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
void delFirst(Node *&head)
{
	if (head != NULL)
	{
		Node *p = head;
		head = head->next;
		p->next = NULL;
		delete (p);
	}
}

Node* search(Node* head, int x) {
	Node* p = head;
	while (p != NULL && p->value != x) {
		p = p->next;
	}return p;
}

void output(Node *head)
{
	if (head != NULL)
	{
		Node *p = head;
		while (p != NULL)
		{
			cout << p->value << "\t";
			p = p->next;
		}
		cout << endl;
	}
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
		Node *q = head;
		while (q->next != NULL)
		{
			q = q->next;
		}
		q->next = p;
	}
}

void delLast(Node *&head)
{
	if (head != NULL)
	{
		Node *p = head;
		Node *prev = NULL;
		while (p->next != NULL)
		{
			prev = p;
			p = p->next;
		}
		if (prev == NULL)
		{
			head = NULL;
		}
		else
		{
			prev->next = NULL;
		}
		delete (p);
	}
}

// This function searches for a node with a given value in a linked list
// and deletes it if found.
void searchAndDel(Node *&head, int x)
{
	// If the list is not empty
	if (head != NULL)
	{
		// Initialize a pointer to the current node as the head of the list
		Node *p = head;
		// Initialize a pointer to the previous node as NULL
		Node *prev = NULL;

		// Search for the node with the given value
		while (p != NULL && p->value != x)
		{
			// If the node is not the one we're looking for, move to the next node
			prev = p;	 // Update the previous node
			p = p->next; // Move to the next node
		}

		// If the node is found
		if (p != NULL)
		{ // da tim thay
			// If the node is at the head of the list
			if (prev == NULL)
			{
				// Delete the node at the head of the list
				delFirst(head);
			}
			else
			{
				// If the node is not at the head of the list

				// Update the previous node's next pointer to skip the current node
				prev->next = p->next;

				// Set the current node's next pointer to NULL
				p->next = NULL;

				// Delete the current node
				delete (p);
			}
		}

		// Print "DONE!" to indicate the operation is complete
		cout << "DONE!\n";
	}
}
void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}
/*
 * This function takes a pointer to the head of a linked list as input and
 * performs an in-place interchange sort on the linked list.
 *
 * The function iterates through each node in the list and compares it with
 * the nodes after it. If the current node's value is greater than the next
 * node's value, it swaps their values using the swap function.
 *
 * The complexity of this function is O(n^2), where n is the number of nodes
 * in the list.
 */
void interChangeSort(Node *head)
{
	// Iterate through each node in the list
	for (Node *p = head; p != NULL; p = p->next)
	{
		// Iterate through the nodes after the current node
		for (Node *q = p->next; q != NULL; q = q->next)
		{
			// Check if the current node's value is greater than the next node's value
			if (p->value > q->value)
			{
				// Swap the values of the current node and the next node
				swap(p->value, q->value);
			}
		}
	}
}
void clearNode(Node *head)
{
	while (head != NULL)
	{
		delFirst(head);
	};
	cout << "CLEAR!\n";
}
int main()
{
	Node *head;
	init(head);
	addLast(head, 1);
	addFirst(head, 10);
	addFirst(head, 9);
	addFirst(head, 100);
	addLast(head, 1000);
	////delFirst(head);
	// output(head);
	////delLast(head);
	// cout << "======FIND AND DELETE====\n";
	// searchAndDel(head, 9);
	output(head);
	/*cout << "======SORT TANG DAN=====\n";
	interChangeSort(head);
	output(head);*/
	cout << "=========SEARCH=========\n";
	Node* res = search(head, 11);
	cout << res << endl;
	clearNode(head);

	return 1;
}