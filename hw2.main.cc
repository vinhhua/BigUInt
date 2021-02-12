#include <iostream>
#include "hw2.biguint.h"

using namespace std;

int main() {

  BigUInt b1(88408721);
  BigUInt b2(69606478);

  b1.Print();
  b2.Print();

  cout << "b1 + b2 should equal to 158015199" << endl;
  b1 += b2;
  b1.Print();

  b1.TimesTenPow(15);
  b1.Print();

  b1 += b2;
  b1.Print();

  cout << b1;

  return 0;
}

/*
Results:
88408721
158015199
158015199000000000000000
158015199000000069606478
158015199000000069606478
*/