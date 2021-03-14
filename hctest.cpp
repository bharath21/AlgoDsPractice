#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
      int val;
      ListNode *next;
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
      void printLista(ListNode *temp)
      {
            while (temp)
            {

                  cout << temp->val << " ";
                  temp = temp->next;
            }
      }
      ListNode *oddEvenList(ListNode *head)
      {
            ListNode *oddPtr;
            ListNode *evenPtr, *evenList;
            if (head == nullptr)
            {
                  return head;
            }
            if (head->next == nullptr)
            {
                  return head;
            }
            if (head->next->next == nullptr)
            {
                  return head;
            }
            oddPtr = head;
            evenPtr = head->next;
            evenList = evenPtr;
            while (1)
            {
                  oddPtr->next = evenPtr->next;
                  oddPtr = evenPtr->next;

                  if (oddPtr->next == nullptr)
                  {
                        evenPtr->next = nullptr;
                        oddPtr->next = evenList;
                        break;
                  }

                  evenPtr->next = oddPtr->next;
                  evenPtr = oddPtr->next;

                  if (evenPtr->next == nullptr)
                  {
                        evenPtr->next = nullptr;
                        oddPtr->next = evenList;
                        break;
                  }
            }
            return head;
      }
      void findMiddleE(ListNode *head, ListNode **a, ListNode **b)
      {

            ListNode *x = head->next;
            ListNode *y = head;
            while (x != nullptr)
            {
                  x = x->next;
                  if (x != nullptr)
                  {
                        x = x->next;
                        y = y->next;
                  }
            }
            *a = head;
            *b = y->next;
            y->next = nullptr;
      }
      ListNode *mergeLists(ListNode *a, ListNode *b)
      {
            ListNode *result = nullptr;
            if (a == nullptr)
            {
                  return b;
            }
            else if (b == nullptr)
            {
                  return a;
            }
            if (a->val <= b->val)
            {
                  result = a;
                  result->next = mergeLists(a->next, b);
            }
            else
            {
                  result = b;
                  result->next = mergeLists(a, b->next);
            }
            return result;
      }
      void mergeSort(ListNode **headref)
      {
            // cout << "head ref value " << headref << endl;
            // cout << "star head ref value " << *headref << endl;
            // cout << "a" << endl;
            ListNode *head = *headref;
            ListNode *c;
            ListNode *d;
            if (head == nullptr || head->next == nullptr)
            {
                  return;
            }

            findMiddleE(head, &c, &d);
            mergeSort(&c);
            mergeSort(&d);
            *headref = mergeLists(c, d);
      }
      ListNode *sortList(ListNode *head)
      {
            cout << "star head addr " << head->val << endl;
            // printLista(head);
            mergeSort(&head);
            printLista(head);
            return head;
      }
};
void foo(ListNode *r)
{
      r->val = 0;
}

int main()
{
      Solution s;
      ListNode *root;
      root = new ListNode(4, nullptr);

      root->next = new ListNode(7, nullptr);
      root->next->next = new ListNode(1, nullptr);

      root->next->next->next = new ListNode(2, nullptr);

      s.sortList(root);
      // s.printLista(root);

      return 0;
}