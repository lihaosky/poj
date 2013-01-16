/*
Chain
Time Limit: 1000MS  Memory Limit: 10000K
Total Submissions: 1691  Accepted: 576

Description

Byteland had not always been a democratic country. There were also black pages in its book of history. One lovely day general Bytel − commander of the junta which had power over Byteland −− decided to finish the long−lasting time of war and released imprisoned activists of the opposition. However, he had no intention to let the leader Bytesar free. He decided to chain him to the wall with the bytish chain. It consists of joined rings and the bar fixed to the wall. Although the rings are not joined with the bar, it is hard to take them off.
'General, why have you chained me to the prison walls and did not let rejoice at freedom!' cried Bytesar.
'But Bytesar, you are not chained at all, and I am certain you are able to take off the rings from the bar by yourself.' perfidiously answered general Bytel, and he added 'But deal with that before a clock strikes the cyber hour and do not make a noise at night, otherwise I will be forced to call Civil Cyber Police.'
Help Bytesar! Number the following rings of the chain with integers 1,2,...,n. We may put on and take off these rings according to the following rules:
.only one ring can be put on or taken off from the bar in one move,
.the ring number 1 can be always put on or taken off from the bar,
.if the rings with the numbers 1,...,k−1 (for 1<= k < n) are taken off from the bar and the ring number k is put on, we can put on or take off the ring number k+1.
Write a program which:
.reads from std input the description of the bytish chain,
.computes minimal number of moves necessary to take off all rings of the bytish chain from the bar,
.writes the result to std output.
Input

In the first line of the input there is written one integer n, 1 <= n <= 1000. In the second line there are written n integers o1,o2,...,on (each of them is either 0 or 1) separated by single spaces. If oi=1, then the i−th ring is put on the bar, and if oi=0, then the i−th ring is taken off the bar.
Output

The output should contain exactly one integer equal to the minimal number of moves necessary to take off all the rings of the bytish chain from the bar.
Sample Input

4
1 0 1 0
Sample Output

6
Source

POI 2001
*/

//Need to think about it
//nice problem
//without recursion
//you've got to use array to compute the power of 2 and store the result since the number could be too large
//AUTHOR: LIHAO
//VENUE: DORMITORY
//DATE: 17 MAY 2009

#include <iostream>
#include <cstring>
using namespace std;

bool chain[1010];

int size;
int ans[350];
int a[350];
int powerSize = 0;
int ansSize = 0;

void pow(int n)
{
	int carry = 0;
	for (int i = 0; i < n; i++){
		carry = 0;
		for( int j = 0; j <= powerSize; j++){
			int tmp = a[j] * 2 + carry;
			a[j] = tmp % 10;
			carry = tmp / 10;
		}
		if (carry){
			a[++powerSize] = carry;
		}
	}
}

void print(int i)
{
	cout << "i: "<< i << endl;
	for (int j = powerSize; j >=0; j--){
		cout << a[j] ;
	}
	cout << endl;
	for (int j = ansSize; j >= 0; j--){
		cout << ans[j];
	}
	cout << endl;
}

void add()
{
	int carray = 0;
	int i;
	for (i = 0; i <= powerSize || i <= ansSize; i++){
		int tmp = ans[i] + a[i] + carray;
		ans[i] = tmp % 10;
		carray = tmp / 10;
	}
	if (carray){
		ans[i] = carray;
		if (i > ansSize){
			ansSize = i;
		}
	}
	else{
		if (i - 1 > ansSize){
			ansSize = i - 1;
		}
	}
}


int main()
{
	for (int i = 0; i < 350; i++){
		ans[i] = 0;
	}
	cin >> size;
	bool status = 0;
	for (int i = 0; i < size; i++){
		cin >> chain[i];
	}
	for (int i = size - 1; i >= 0; i--){
		for (int j = 0; j < 350; j++){
			a[j] = 0;
		}
		a[0] = 1;
		powerSize = 0;
		if (status == 0){
			if (chain[i] == 0){
				continue;
			}
			else{
				pow(i);
				add();
				status = 1;
				print(i);
			}
		}
		else{
			if (chain[i] == 1){
				status = 0;
				continue;
			}
			else{
				pow(i);
				add();
				print(i);
			}
		}
	}
	for (int i = ansSize; i >= 0; i--){
		cout << ans[i];
	}
	cout << endl;
}
