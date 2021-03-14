#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
      int data;
      Node *left;
      Node *right;
      Node(int v)
      {
            this->left = nullptr;
            this->right = nullptr;
            this->data = v;
      }
      Node()
      {
            this->left = nullptr;
            this->right = nullptr;
      }
};
Node *constructTreeHelper(Node *root, Node *node)
{
      if (root == nullptr)
      {
            return node;
      }
      if (node->data > root->data)
      {
            root->right = constructTreeHelper(root->right, node);
      }
      else
      {
            root->left = constructTreeHelper(root->left, node);
      }
      return root;
}
Node *constructTree(Node *root, int n)
{
      int *arr;
      arr = new int[n];
      cout << "enter elements " << endl;
      for (int i = 0; i < n; i++)
      {
            cin >> arr[i];
      }
      for (int i = 0; i < n; i++)
      {
            Node *temp = new Node(arr[i]);
            root = constructTreeHelper(root, temp);
      }
      return root;
}
void printInOrder(Node *root)
{
      if (root)
      {
            printInOrder(root->left);
            cout << root->data << " ";
            printInOrder(root->right);
      }
}
int evenGPSHelper(Node *root, bool *even)
{
      queue<Node *> q;
      q.push(root);
      int res = 0;
      bool isEvenParent;
      int counter = 0, parentCounter = -1;
      while (!q.empty())
      {
            Node *front = q.front();
            q.pop();
            isEvenParent = false;
            parentCounter++;
            if (front->data % 2 == 0)
            {
                  isEvenParent = true;
            }
            if (front->left)
            {
                  counter++;
                  q.push(front->left);
                  if (even[parentCounter])
                  {
                        res += front->left->data;
                  }
                  if (isEvenParent)
                  {
                        even[counter] = true;
                  }
            }
            if (front->right)
            {
                  counter++;
                  q.push(front->right);
                  if (even[parentCounter])
                  {
                        res += front->right->data;
                  }
                  if (isEvenParent)
                  {
                        even[counter] = true;
                  }
            }
      }
      return res;
}
int evenGPS(Node *root, int n)
{
      bool even[n] = {false};
      return evenGPSHelper(root, even);
}
int main()
{
      Node *root = nullptr;
      int n;
      cin >> n;
      root = constructTree(root, n);
      printInOrder(root);
      cout << endl
           << evenGPS(root, n);
}