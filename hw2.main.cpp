#include <iostream>
#include "hw2.biguint.h"

using namespace std;

int main() {
  cout << "Test b1 and b2 constructor" << endl;
  BigUInt b1(88408721);
  BigUInt b2(69606478);
  cout << "--------------------------------------" << endl;

  b1.Print();
  cout << "Correct if b1 equals to 88408721" << endl;
  b2.Print();
  cout << "Correct if b2 equals to 69606478" << endl;
  cout << "--------------------------------------" << endl;
  // Test += function
  b1 += b2;
  b1.Print();
  cout << "b1 += b2 should equal to 158015199" << endl;

  // New Testing Unit
  BigUInt b3(385);
  b3.Print();
  cout << "Correct if b4 equals to 385" << endl;
  cout << "--------------------------------------" << endl;

  b3.TimesTenPow(1);
  b3.Print();
  cout << "b3 x 10^1" << endl;
  b3.TimesTenPow(8);
  b3 += b1;
  b3.Print();
  cout << "--------------------------------------" << endl;
  
  b1.Print();
  b1.TimesTenPow(15);
  b1.TimesTenPow(15);
  cout << b1 << endl;
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
