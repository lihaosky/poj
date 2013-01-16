/*
Round and Round We Go
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 5366		Accepted: 2458

Description
A cyclic number is an integer n digits in length which, when multiplied by any integer from 1 to n, yields a"cycle"of the digits of the original number. That is, if you consider the number after the last digit to "wrap around"back to the first digit, the sequence of digits in both numbers will be the same, though they may start at different positions.For example, the number 142857 is cyclic, as illustrated by the following table:
142857 *1 = 142857
142857 *2 = 285714
142857 *3 = 428571
142857 *4 = 571428
142857 *5 = 714285
142857 *6 = 857142

Input
Write a program which will determine whether or not numbers are cyclic. The input file is a list of integers from 2 to 60 digits in length. (Note that preceding zeros should not be removed, they are considered part of the number and count in determining n. Thus, "01"is a two-digit number, distinct from "1" which is a one-digit number.)

Output
For each input integer, write a line in the output indicating whether or not it is cyclic.

Sample Input

142857
142856
142858
01
0588235294117647

Sample Output

142857 is cyclic
142856 is not cyclic
142858 is not cyclic
01 is not cyclic
0588235294117647 is cyclic

Source
Greater New York 2001
就是只要输入的数*(len+1)=9....9(共len个）
len=输入数的长度
*/

//AUTHOR: LIHAO
//DATE: MAR 8TH 2009
//VENUE: DORMITORY

#include <iostream>
#include <string>

using namespace std;
int main()
{
	string a;
	int len,carry,re,x;
	bool flag;
	while(cin>>a){
		len=a.length();
		carry=0;
		flag=true;
		for(int i=len-1;i>=0;i--){
			x=((a[i]-'0')*(len+1)+carry);
			carry=x/10;
			re=x%10;
			if(re!=9){
				cout<<a<<" is not cyclic"<<endl;
				flag=false;
				break;
			}
		}
		if(flag){
			cout<<a<<" is cyclic"<<endl;
		}
	}
	return 0;
}
