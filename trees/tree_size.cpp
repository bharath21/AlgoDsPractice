#include <bits/stdc++.h>
using namespace std;

#define null nullptr

class Node
{
public:
      int data;
      Node *left;
      Node *right;

      Node(int data)
      {
            this->data = data;
            this->left = this->right = nullptr;
      }
};

class Tree
{
      Node *root;

public:
      Tree()
      {
            root = nullptr;
      }
      Node *findNode(Node *temp)
      {
            if (temp->left == nullptr)
            {
                  temp->left = new Node(0);
                  return temp->left;
            }
            if (temp->right == nullptr)
            {
                  temp->right = new Node(0);
                  return temp->right;
            }
            return findNode(temp->left);
            return findNode(temp->right);
      }
      void addNode(int value)
      {
            Node *new_node = new Node(value);
            if (root == nullptr)
            {
                  root = new_node;
                  // cout << root->data << endl;
            }
            else
            {
                  Node *temp = root;
                  Node *src = findNode(temp);
                  src->data = value;
            }
      }
      void in_order(Node *root2)
      {
            if (root2 == null)
            {
                  return;
            }
            in_order(root2->left);
            cout << root2->data << " ";
            in_order(root2->right);
      }
      void print_tree()
      {
            in_order(root);
      }
      Node *get_root()
      {
            return root;
      }
      int getSize(Node *root)
      {
            if (root == null)
            {
                  return 0;
            }
            return getSize(root->left) + 1 + getSize(root->right);
      }
      void level_order(Node *root)
      {
            list<Node *> q;
            q.push_back(root);
            while (!q.empty())
            {
                  cout << q.front()->data << " ";
                  if (q.front()->left)
                  {
                        q.push_back(q.front()->left);
                  }
                  if (q.front()->right)
                  {
                        q.push_back(q.front()->right);
                  }
                  q.pop_front();
            }
      }
      int get_height(Node *root)
      {
            if (root == null)
            {
                  return 0;
            }
            return 1 + max(get_height(root->left), get_height(root->right));
      }
      int getDiameter(Node *root)
      {
            if (root == null)
            {
                  return 0;
            }
            return max(max(getDiameter(root->left), get_height(root->left) + 1 + get_height(root->right)), getDiameter(root->right));
      }
};

int main()
{
      Tree *t = new Tree();
      // Node *r = t->get_root();
      // r = new Node(9);
      // cout << r->data << endl;
      // r->left = new Node(8);
      // r->right = new Node(10);
      t->addNode(10);
      t->addNode(1);
      t->addNode(2);
      t->addNode(3);
      t->addNode(4);
      t->addNode(5);

      t->print_tree();
      cout << endl;
      cout << endl
           << t->getSize(t->get_root());
      cout << endl;
      t->level_order(t->get_root());
      cout << endl
           << t->get_height(t->get_root());
      cout << endl
           << t->getDiameter(t->get_root());
}