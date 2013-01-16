/*********************************************************
Dead Fraction
Time Limit: 1000MS		Memory Limit: 30000K
Total Submissions: 1103		Accepted: 319

Description
Mike is frantically scrambling to finish his thesis at the last minute. He needs to assemble all his research notes into vaguely coherent form in the next 3 days. Unfortunately, he notices that he had been extremely sloppy in his calculations. Whenever he needed to perform arithmetic, he just plugged it into a calculator and scribbled down as much of the answer as he felt was relevant. Whenever a repeating fraction was displayed, Mike simply reccorded the first few digits followed by "...". For instance, instead of "1/3" he might have written down "0.3333...". Unfortunately, his results require exact fractions! He doesn't have time to redo every calculation, so he needs you to write a program (and FAST!) to automatically deduce the original fractions.
To make this tenable, he assumes that the original fraction is always the simplest one that produces the given sequence of digits; by simplest, he means the the one with smallest denominator. Also, he assumes that he did not neglect to write down important digits; no digit from the repeating portion of the decimal expansion was left unrecorded (even if this repeating portion was all zeroes).

Input
There are several test cases. For each test case there is one line of input of the form "0.dddd..." where dddd is a string of 1 to 9 digits, not all zero. A line containing 0 follows the last case.

Output
For each case, output the original fraction.

Sample Input

0.2...
0.20...
0.474612399...
0

Sample Output

2/9
1/5
1186531/2500000

Hint
Note that an exact decimal fraction has two repeating expansions (e.g. 1/5 = 0.2000... = 0.19999...).

Source
Waterloo local 2003.09.27
*******************************************************************/
//read the description caarrefully -_- find minimum denominator
//AUTHOR: LIHAO
//VENUE: DORMITORY
//DATE: 17 APRILT 2009
#include <iostream>
#include <string>
using namespace std;
long long gcd(long long a,long long b)
{
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}

int main()
{
	long long fno,sno,eno,g,con,no,min_de,con2;
	string n;
	while(cin>>n&&n!="0"){
		con=1;
		con2=0;
		for(int i=2;i<=n.length()-4;i++){
			con*=10;
		}
		min_de=9999999999999999;
		for(int i=n.length()-4;i>=2;i--){
			con2=con2*10+9;
			sno=0;
			eno=0;
			con/=10;
			int j=2;
			for(j=2;j<i;j++){
				sno=sno*10+n[j]-48;
			}
			for(;j<=n.length()-4;j++){
				eno=eno*10+n[j]-48;
			}
			fno=eno+con2*sno;
			g=gcd(fno,con2*con);
			if(con2*con/g<min_de){
				min_de=con2*con/g;
				no=fno/g;
			}
		}
		cout<<no<<"/"<<min_de<<endl;
	}
}
