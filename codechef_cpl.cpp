#include <iostream>
using namespace std;
struct node
{
      int height;
      bool isUsed;
};
int calculateBoxes(node *h, int i, int height, int size, bool used)
{
      if (i > size - 1)
      {
            return size;
      }

      if (height <= 0)
      {
            return 0;
      }
      return min(calculateBoxes(h, i + 1, height, size, false), 
      1 + calculateBoxes(h, i + 1, height - h[i].height, size, true));
}

int main()
{
      // your code goes here
      int t, n, k, i, j;
      node arr[4000];
      cin >> t;
      while (t--)
      {
            cin >> n >> k;
            for (i = 0; i < n; i++)
            {
                  cin >> arr[i].height;
                  arr[i].isUsed = false;
            }
            cout << calculateBoxes(arr, 0, k, n, false) << endl;
      }
      return 0;
}
