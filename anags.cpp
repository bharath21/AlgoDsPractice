// CPP program to reverse a linked list
// in groups of given size
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node
{
public:
      int data;
      Node *next;
};

/* Function to print linked list */
void printList(Node *node)
{
      while (node != NULL)
      {
            cout << node->data << " ";
            node = node->next;
      }
      cout << endl;
}

/* Reverses the linked list in groups
of size k and returns the pointer
to the new head node. */
Node *reverse(Node *head, int k)
{
      printList(head);
      if (head == NULL)
      {
            return NULL;
      }
      Node *prev = NULL;
      // Node* it=head;
      Node *curr = head;
      Node *next;
      int count = k;
      while (count-- && curr != NULL)
      {
            cout << "a " << curr->data << endl;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            // count--;
      }

      head->next = reverse(curr, k);
      return prev;
}

/* Function to push a node */
void push(Node **head_ref, int new_data)
{
      /* allocate node */
      Node *new_node = new Node();

      /* put in the data */
      new_node->data = new_data;

      /* link the old list off the new node */
      new_node->next = (*head_ref);

      /* move the head to point to the new node */
      (*head_ref) = new_node;
}

/* Driver code*/
int main()
{
      /* Start with the empty list */
      Node *head = NULL;

      /* Created Linked list 
	is 1->2->3->4->5->6->7->8->9 */

      push(&head, 4);
      push(&head, 3);
      push(&head, 2);
      push(&head, 1);

      cout << "Given linked list \n";
      printList(head);
      head = reverse(head, 3);

      cout << "\nReversed Linked list \n";
      printList(head);

      return (0);
}

// This code is contributed by rathbhupendra
