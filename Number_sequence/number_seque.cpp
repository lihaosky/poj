/*Number Sequence
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 13244		Accepted: 3382

Description
A single positive integer i is given. Write a program to find the digit located in the position i in the sequence of number groups S1S2...Sk. Each group Sk consists of a sequence of positive integer numbers ranging from 1 to k, written one after another.
For example, the first 80 digits of the sequence are as follows:
11212312341234512345612345671234567812345678912345678910123456789101112345678910

Input
The first line of the input file contains a single integer t (1 ≤ t ≤ 10), the number of test cases, followed by one line for each test case. The line for a test case contains the single integer i (1 ≤ i ≤ 2147483647)

Output
There should be one output line per test case containing the digit located in the position i.

Sample Input

2
8
3

Sample Output

2
2
*/

//compute and find the range
//AUTHOR: LIHAO
//DATE: Feb 18th 2009
//VENUE: DORMITORY

#include <iostream>
using namespace std;

int get_digit(unsigned long n,unsigned long num)
{
	int a[6];
	int size=0;
	while(num){
		a[size++]=num%10;
		num/=10;
	}
	return a[size-n];
}

int main()
{
	unsigned long num,a,j,now,pre,k,tmp,i;
	cin>>num;
	for(i=0;i<num;i++){
		cin>>a;
		//find the range
		for(j=1;;j++){
			if(j<10){
				now=((1+j)*j)/2;
			}
			if(j>=10&&j<100){
				now=(((1+j)*j)/2+(j-8)*(j-9)/2);
			}
			if(j>=100&&j<1000){
				now=(((1+j)*j)/2+4095+90*(j-99)+(j-98)*(j-99));
			}
			if(j>=1000&&j<10000){
				now=(((1+j)*j)/2+4095+81000+90*(j-999)+810900+1800*(j-999)+3*(j-998)*(j-999)/2);
			}
			if(j>=10000&&j<100000){
		now=(((1+j)*j)/2+4095+81000+810000+90*(j-9999)+810900+16200000+1800*(j-9999)+121513500+27000*(j-9999)+2*(j-9998)*(j-9999));
			}
			if(now>=a){
				break;
			}
		}
		   //find the previous range
		    k=j-1;
		    if(k<10){
				pre=(1+k)*k/2;
			}
			if(k>=10&&k<100){
				pre=((1+k)*k/2+(k-8)*(k-9)/2);
			}
			if(k>=100&&k<1000){
				pre=((1+k)*k/2+4095+90*(k-99)+(k-98)*(k-99));
			}
			if(k>=1000&&k<10000){
				pre=((1+k)*k/2+4095+81000+90*(k-999)+810900+1800*(k-999)+3*(k-998)*(k-999)/2);
			}
			if(k>=10000&&k<100000){
		pre=(((1+k)*k)/2+4095+81000+810000+90*(k-9999)+810900+16200000+1800*(k-9999)+121513500+27000*(k-9999)+2*(k-9998)*(k-9999));
			}
			//a is the tmpth digit in the current range
		    tmp=a-pre;
		    //find range in the current domain
		 for(j=1;;j++){
			if(j<10){
				now=j;
			}
			if(j>=10&&j<100){
				now=(j+j-9);
			}
			if(j>=100&&j<1000){
				now=(j+90+(j-99)*2);
			}
			if(j>=1000&&j<10000){
				now=(j+90+1800+(j-999)*3);
			}
			if(j>=10000&&j<100000){
		        now=(j+90+1800+27000+(j-9999)*4);
			}
			if(now>=tmp){
				break;
			}
		}
		j=j-1;
		//compute the exact position
		   if(j<10){
				now=j;
			}
			if(j>=10&&j<100){
				now=(j+j-9);
			}
			if(j>=100&&j<1000){
				now=(j+90+(j-99)*2);
			}
			if(j>=1000&&j<10000){
				now=(j+90+1800+(j-999)*3);
			}
			if(j>=10000&&j<100000){
		        now=(j+90+1800+27000+(j-9999)*4);
			}
		//get it
		cout<<get_digit(tmp-now,j+1)<<endl;
	}
	return 0;
}
