#include <iostream>
#include "hw2.biguint.h"

using namespace std;

int main() {
  cout << " Unit Testing " << endl;
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
  cout << b3;
  cout << "Correct if b4 equals to 385" << endl;
  cout << "--------------------------------------" << endl;

  b3.TimesTenPow(1);
  cout << b3;
  cout << "b3 x 10^1" << endl;
  b3.TimesTenPow(8);
  b3 += b1;
  b3.Print();
  cout << "--------------------------------------" << endl;
  
  b1.Print();
  b1.TimesTenPow(15);
  cout << b1 << endl;
  b1 += b2;
  b1.Print();
  cout << "--------------------------------------" << endl;
  

  cout << b1;

  cout << "Another block of test" << endl;
  BigUInt b4;
  cout << b4;
  cout << "Correct if b4 = 0" << endl;
  cout << "--------------------------------------" << endl;
  

  BigUInt b5(12345);
  cout << b5;
  cout << "Correct if b4 = 12345" << endl;
  cout << "Correct if b5 = 12345 x 10^5" << endl;
  b5 += b5;
  cout << "Correct if b5 + b5 = 24690" << endl;
  b5.TimesTenPow(20);
  cout << b5;
  cout << "Correct if b5 x 10^20 = 24690 x 10^20" << endl;
  cout << "--------------------------------------" << endl;
  
  
  BigUInt b6(6789);
  b6.TimesTenPow(100);
  cout << b6;
  cout << "--------------------------------------" << endl;
  

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
