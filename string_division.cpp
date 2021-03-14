#include <bits/stdc++.h>
using namespace std;

string helper(string dividend, string divisor, string *s)
{
      stringstream ss;
      int o1, o2;
      string reminder;

      ss.clear();
      ss << divisor;
      ss >> o1;

      ss.clear();
      ss << dividend;
      ss >> o2;

      ss.clear();
      ss << (o2 / o1);
      ss >> *s;

      ss.clear();
      ss << (o2 % o1);
      ss >> reminder;

      return reminder;
}
int compare_helper(string s1, string s2)
{
      stringstream ss;
      int o1, o2;
      ss.clear();
      ss << s1;
      ss >> o1;
      ss.clear();
      ss << s2;
      ss >> o2;

      if (o1 > o2)
      {
            return 1;
      }
      else if (o1 == o2)
      {
            return 0;
      }
      else
      {
            return -1;
      }
}
int main()
{
      string number, divisor, output, quotient, rem, dividend;
      cin >> number >> divisor;

      dividend = output = quotient = rem = "";
      int count = 0;
      while (count < number.length())
      {
            dividend.push_back(number[count++]);
            while (compare_helper(divisor, dividend) > 0)
            {
                  cout << "div " << divisor << " dividend " << dividend << endl;
                  dividend.push_back(number[count]);
                  count++;
                  output.push_back('0');
            }
            quotient = "";
            rem = helper(dividend, divisor, &quotient);
            output.append(quotient);
            dividend = rem;
      }
      cout << "rem " << rem << endl;
      cout << "output " << 29019201292012 / 258 << endl;
      int pos = output.find_first_not_of('0');
      output = output.substr(pos);
      cout << "output " << output << endl;
}