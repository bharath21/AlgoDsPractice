#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
      vector<vector<int>> m;
      int rows, cols, t;

      int findRow(int start, int end, int target)
      {
            if (start > end)
            {
                  return -1;
            }
            int mid = (end + start) / 2;
            if (target == m[mid][0] || target == m[mid][cols - 1])
            {
                  return mid;
            }
            if (target > m[mid][0] && target < m[mid][cols - 1])
            {
                  return mid;
            }
            if (target < m[mid][0])
            {
                  return findRow(start, mid - 1, target);
            }
            return findRow(mid + 1, end, target);
      }

      bool findElement(vector<int> arr, int start, int end)
      {
            cout << start << " " << end << endl;
            if (start > end)
            {
                  return false;
            }
            int mid = (end + start) / 2;
            if (arr[mid] == t)
            {
                  return true;
            }
            if (t < arr[mid])
            {
                  return findElement(arr, start, mid - 1);
            }
            return findElement(arr, mid + 1, end);
      }

      bool searchMatrix(vector<vector<int>> &matrix, int target)
      {
            m = matrix;
            t = target;
            rows = matrix.size();
            cols = matrix[0].size();
            int targetRow = findRow(0, matrix.size() - 1, target);
            cout << "targetRow " << targetRow << endl;
            bool result = false;
            if (targetRow != -1)
            {
                  result = findElement(matrix[targetRow], 0, matrix[targetRow].size() - 1);
            }
            return result;
      }
};

int main()
{
      Solution s;
      int m, n, target;
      vector<vector<int>> matrix;
      cin >> m >> n;
      for (int i = 0; i < m; i++)
      {
            for (int j = 0; j < n; j++)
            {
                  cin >> matrix[i][j];
            }
      }
      cin >> target;
      cout << s.searchMatrix(matrix, target);
      return 0;
}