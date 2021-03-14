#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
      int data;
      Node *next;
      Node *down;
      Node()
      {
            next = NULL;
            down = NULL;
      }
};

class LinkedList
{
public:
      Node *merge(Node *first, Node *second, Node *temp)
      {
            if (first == NULL)
            {
                  return second;
            }
            if (second == NULL)
            {
                  return first;
            }
            if (first->data <= second->data)
            {
                  temp = first;
                  temp->down = merge(first->down, second, temp);
            }
            else
            {
                  temp = second;
                  temp->down = merge(first, second->down, temp);
            }
            temp->next = NULL;
            return temp;
      }
      Node *flatten(Node *root)
      {
            if (root && root->next)
            {
                  root->next = flatten(root->next);
            }
            return merge(root, root->next, NULL);
      }
      Node *getNode(int data)
      {
            Node *temp = new Node();
            temp->data = data;
            return temp;
      }
      void printDown(Node *root)
      {
            while (root)
            {
                  cout << root->data << " ";
                  root = root->down;
            }
      }
};

int main()
{
      LinkedList ll;
      Node *root = ll.getNode(5);

      root->next = ll.getNode(10);
      root->next->next = ll.getNode(19);
      root->next->next->next = ll.getNode(28);

      root->down = ll.getNode(7);
      root->down->down = ll.getNode(8);
      root->down->down->down = ll.getNode(30);

      root->next->down = ll.getNode(20);
      root->next->down->down = ll.getNode(23);
      // root->next->down->down->down = ll.getNode(21);

      root->next->next->down = ll.getNode(22);
      root->next->next->down->down = ll.getNode(50);

      // Node *temp = ll.flatten(root);

      // ll.printDown(temp);

      string s = "a boy has a";
      stringstream ss(s);
      string word;
      while (ss << word)
      {
            cout << word << endl;
      }
}