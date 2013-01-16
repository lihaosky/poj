/****************************************************
*   compute C(n, m)
*   use array to store all the digits
*   n could be 100000(maybe larger), m could be 5000
*  
*****************************************************/

#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 1000000; //maximum digits of product of numerator
short num[SIZE];         //digits of product of numerator
int numSize = 0;         //current number of digits of numerator

//initialize num[SIZE]
void initialize()
{
	for (int i = 0; i < SIZE; i++){
		num[i] = 0;
	}
	num[0] = 1;
}


//compute numerator of C(n, m)
void multiply(int n, int m)
{
	int carry;
	while (n >= m){
		carry = 0;
		for (int i = 0; i <= numSize; i++){
			int product = num[i] * n + carry;
			num[i] = product % 10;
			carry = product / 10;
		}
		while (carry){
			num[++numSize] = carry % 10;
			carry /= 10;
		}
		n--;
	}
}

//divide the numerator by all the denominator
void divide(int m)
{
	int counter, dividend,pos;
	bool isEnd;
	while (m > 1){
		pos = numSize;
		counter = 0;
		dividend = num[numSize];
		isEnd = false;
		while (1){
			while (dividend < m){
				num[pos] = 0;
				pos--;
				if (pos < 0){
					isEnd = true;
					break;
				}
				dividend = dividend * 10 + num[pos];
			}
			if (isEnd){
				break;
			}
			num[pos] = dividend / m;
			if (counter == 0){
				numSize = pos;
			}
			pos--;
			if (pos < 0){
				break;
			}
			dividend = (dividend % m) * 10 + num[pos];
			counter++;
		}
		m--;
	}
}

//print the result
void print()
{
	for (int i = numSize; i >=0; i--){
		cout << num[i];
	}
	cout << endl;
}

int main()
{
	int m,n;
	cin >> n >> m; // C(n, m)
	if (m > n){
		cout << "m should be smaller than n" << endl;
		return 0;
	}
	if (m == 0 || m == n){
		cout << 1 << endl;
		return 0;
	}
	if (m > n/2){
		m = n - m;
	}
	initialize();
	multiply(n, n - m + 1);
	divide(m);
	print();
}

