#include <bits/stdc++.h>
using namespace std;

list<int> linkedlist;
class Node
{
public:
      int data;
      Node *next;
      Node(int data)
      {
            this->data = data;
            this->next = NULL;
      }
};
Node *head;
Node *head2;
Node *intersection(Node *head1, Node *head2)
{
      Node *result = NULL;
      Node *temp = result;
      while (head1 && head2)
      {
            if (head1->data > head2->data)
            {
                  head2 = head2->next;
            }
            else if (head1->data < head2->data)
            {
                  head1 = head1->next;
            }
            else
            {
                  if (temp == NULL)
                  {
                        //cout << head1->data << endl;
                        temp = new Node(head1->data);
                        // result = temp;
                  }
                  else
                  {
                        //cout << head1->data << endl;

                        temp->next = new Node(head1->data);
                        temp = temp->next;
                  }
                  head1 = head1->next;
                  head2 = head2->next;
            }
      }
      return result;
}
int main()
{
      int temp;
      for (int i = 0; i < 10; i++)
      {
            // cin >> temp;
            linkedlist.push_back(i + 1);
      }
      unordered_set<int> uset;
      // map<int, char *> m;
      uset.insert(1);
      uset.insert(2);
      uset.insert(1);
      auto it = uset.begin();
      // pair<int, string> s(1, "aa");
      // m.insert(make_pair(1, "aa"));
      for (auto i : uset)
      {
            cout << i << endl;
      }

      for (int i = 0; i < 10; i++)
      {
            // cin >> temp;
      }
      linkedlist.reverse();
      // for (auto i : linkedlist)
      // {
      //       cout << i << " ";
      // }
      // cout << endl;
      auto i = linkedlist.rbegin();
      advance(i, 2);
      // cout << *i << endl;
      Node *t = new Node(1);
      head = t;
      head->next = new Node(2);
      head->next->next = new Node(3);
      head->next->next->next = new Node(4);
      head->next->next->next->next = new Node(5);
      head->next->next->next->next->next = new Node(6);

      head2 = new Node(2);
      head2->next = new Node(4);
      head2->next->next = new Node(6);
      head2->next->next->next = new Node(8);

      Node *head3 = intersection(head, head2);
      while (head3)
      {
            //cout << head3->data << " ";
            head3 = head3->next;
      }
      cin >> temp;
}