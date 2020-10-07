/* AUTHOR - Nymika Pasnoori (2018BCS-032)*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

int detectLoop(Node* root)
{
	Node *slow = root, *fast = root;

	while (slow && fast && fast->next) 
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return 1;
	}
	return 0;
}

void MiddleElement(Node* root)
{
	Node *slow = root, *fast = root;

	while (slow && fast && fast->next) 
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	cout<<"The middle node is "<<slow->data<<endl;
}

int main()
{
	Node* head = NULL;

	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 5);
	push(&head, 10);

	MiddleElement(head);

	/* Create a loop for testing */
	head->next->next->next->next->next = head;
	if (detectLoop(head))
		cout << "Loop found"<<endl;
	else
		cout << "No Loop"<<endl;
	return 0;
}
