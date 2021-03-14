#include <bits/stdc++.h>
using namespace std;

int powerOfNumber(int number, int power)
{
      if (power == 0)
      {
            return 1;
      }
      if (number == 1)
      {
            return 1;
      }
      if (number == 0)
      {
            return 0;
      }
      if (power == 1)
      {
            return number;
      }
      int product = 1;
      if (power % 2 == 0)
      {
            product = powerOfNumber(number, power / 2);
            return product * product;
      }
      else
      {

            product = powerOfNumber(number, power / 2);
            return product * product * number;
      }
}

int main()
{
      int number, power;
      cin >> number >> power;
      if (power < 0)
      {
            cout << float(1.0 / float(powerOfNumber(number, abs(power)))) << endl;
      }
      else
      {
            cout << powerOfNumber(number, (power)) << endl;
      }
}