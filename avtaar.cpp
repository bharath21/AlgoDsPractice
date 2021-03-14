//find sqrt without any helper functions
#include <bits/stdc++.h>
using namespace std;
int findNearestSquare(int number)
{
      for (int i = 0; i < number; i++)
      {
            if (i * i == number)
            {
                  return i;
            }
            if (i * i < number && (i + 1) * (i + 1) > number)
            {
                  return i;
            }
      }
}

double binarySearch(double start, double end, int number)
{
      double mid = (start + end) / 2;
      if (abs(mid * mid - number) < 1)
      {
            return mid;
      }
      if (number < mid * mid)
      {
            return binarySearch(start, mid, number);
      }
      else
      {
            return binarySearch(mid, end, number);
      }
}
double findSqrt(int number)
{
      int nearestSquare = findNearestSquare(number);
      if (nearestSquare * nearestSquare == number)
      {
            return nearestSquare;
      }
      double arr[10];
      // for(int i=0;i<9;i++) {
      //       arr[i]=nearestSquare+0.1;
      // }
      return binarySearch(nearestSquare, nearestSquare + 1, number);
}