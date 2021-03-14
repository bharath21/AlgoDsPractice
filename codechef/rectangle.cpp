#include <bits/stdc++.h>
using namespace std;

int main()
{
      // your code goes here
      int test_cases, rows, columns;
      cin >> test_cases;
      vector<string> row_strings;
      while (test_cases--)
      {
            cin >> rows >> columns;
            string row_string;
            row_strings.clear();
            for (int i = 0; i < rows; i++)
            {
                  cin >> row_string;
                  row_strings.push_back(row_string);
            }
            int start_column = -1, end_column = -1;
            int start_row = -1, end_row = -1;
            bool result = true;
            for (int i = 0; i < rows; i++)
            {
                  row_string = row_strings[i];
                  for (int j = 0; j < columns; j++)
                  {
                        if (row_string[j] == '1')
                        {
                              start_row = i;
                              int k;
                              for (k = start_row; k < rows; k++)
                              {
                                    string str = row_strings[k];
                                    // cout << "k " << k << endl;
                                    if (str[j] == '0')
                                    {
                                          break;
                                    }
                              }
                              end_row = k - 1;
                              break;
                        }
                  }
                  if (start_row != -1)
                  {
                        break;
                  }
            }
            // cout << "start row " << start_row << " " << end_row << endl;
            for (int i = 0; i < rows; i++)
            {
                  row_string = row_strings[i];
                  for (int j = 0; j < columns; j++)
                  {
                        if (row_string[j] == '1')
                        {
                              if (start_column == -1)
                              {
                                    start_column = j;
                                    // j+;
                                    while (row_string[j] == '1' && j < columns)
                                    {
                                          j++;
                                    }
                                    end_column = j - 1;

                                    // cout << "sc " << start_column << " " << end_column << endl;
                              }
                              else
                              {
                                    if (j < start_column || j > end_column)
                                    {
                                          result = false;
                                          break;
                                    }
                              }
                        }
                        else
                        {
                              if (start_row != -1)
                              {
                                    if (j >= start_column && j <= end_column && i >= start_row && i <= end_row)
                                    {
                                          result = false;
                                          break;
                                    }
                              }
                        }
                  }
                  if (result == false)
                  {
                        break;
                  }
            }
            cout << endl
                 << (result ? "YES" : "NO") << endl;
      }
      return 0;
}
