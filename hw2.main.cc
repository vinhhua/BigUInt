#include <iostream>
#include "hw2.biguint.h"

using namespace std;

int main() {

  BigUInt b1(88408721);
  BigUInt b2(69606478);
  //BigUInt b3;

  b1.Print();
  cout << "Correct if b1 equals to 88408721" << endl;
  b2.Print();
  cout << "Correct if b2 equals to 69606478" << endl;
  //b3.Print();

  // New Testing Unit
  BigUInt b4(385);
  b4.Print();
  cout << "Correct if b4 equals to 358" << endl;

  b4.TimesTenPow(6);
  b4.Print();
  b4.TimesTenPow(8);
  cout << b4;
  //b1 += b2;
  //b1.Print();

  b1.TimesTenPow(15);
  b1.Print();
  cout << "Correct if b1 equals to 88408721 x 10^15" << endl;
  cout << b1 << endl;
  //b1 += b2;
  //b1.Print();

  //cout << b1;
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
