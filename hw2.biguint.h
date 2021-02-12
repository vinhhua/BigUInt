#ifndef HW2_BIGUINT_H
#define HW2_BIGUINT_H

#include <iostream>
// FIX THE TimesTenPow()
using namespace std;

class BigUInt {
private:
	// Pointer to array. Each element of array contains a digit.
	// Array length is equal to the number of digits of the BigUInt.
	// data[0] contains the least significant digit.
	// For example, if the BigUInt represents the number 385,
	// then data[0] is 5, data[1] is 8, data[2] is 3, and length is 3.
	unsigned char *data;
	// The length of the array data.
	int length;

public:
	// 1. (1 point) Initializes the BigUInt to 0.
	BigUInt() {
		length = 1;
		data = new unsigned char[length];
		data[0] = 0;
	};

	// Helper method to get the number of digits in an int to allocate space accordingly
	int CountDigit(unsigned int n) {
		int count = 0;
		while (n > 0) {
			n /= 10;
			++count;
		}
		return count;
	};

	// 2. (5 points) Initializes the BigUInt to n.
	// Allocate data to an array the number of digits.
	BigUInt(unsigned int n) {
		length = CountDigit(n);
		data = new unsigned char[length];
		int index = 0;
		while (n > 0) {
			int digit = n % 10;
			data[index++] = (unsigned char)digit;
			n = n / 10;
		}
	};

	// 3. (1 point) Frees space in data.
	~BigUInt() {
		cout << "BigUInt destructor called." << endl;
		delete[] data;
	};

	// 4. (1 point) Print the number represented by this BigUInt.
	void Print() {
		for (int i = length - 1; i >= 0; i--) {
			cout << (int)data[i] << "";
		}
		cout << endl;
	};

	// 5. (4 points) Set this BigUInt to original value times 10^p.
	// Allocate space as neccessary.
	void TimesTenPow(unsigned int p) {
		unsigned char *oldData = data;
		int initialLength = length - 1;
		length = length + p;
		data = new unsigned char[length];
		int index = length - 1;

		// Transfer the old data into the new unsigned char array first up to old length (reverse order)
		while (initialLength >= 0) {
			data[index--] = oldData[initialLength--];
		}

		// Then fill in the rest with 0's (reverse order)
		while (index >= 0) {
			data[index--] = 0;
		}
		delete[] oldData;
	};

	// 6. (6 points) Set this BigUInt to original value plus rhs.
	// Allocate space as necessary.
	BigUInt &operator+=(const BigUInt &rhs) {
		if (length < rhs.length) length = rhs.length;
		int carry = 0;
		int index = 0;
		while (index < rhs.length) {
			int sum = data[index] + rhs.data[index];
			data[index] = (sum % 10) + carry;
			carry = 1 ? sum > 9 : 0;
			index++;
		}

		// Add left most siginificant digit (or carry)
		if (carry != 0) {
			unsigned char* oldData = data;
			data = new unsigned char[length++];
			for (int i=0; i < length; i++) {
				data[i] = oldData[i];
			}
			data[length - 1] = carry;
			delete[] oldData;
		}

		return *this;
	};

	// 7. (2 points) Print the number represented by this BigUInt.
	friend ostream &operator<<(ostream &os, const BigUInt &b);
};

ostream &operator<<(ostream &os, const BigUInt &b) {
	for (int i = b.length - 1; i >= 0; i--) {
		cout << (int)b.data[i] << "";
	}
	cout << endl;
	return os;
}

#endif // HW2_BIGUINT_H
