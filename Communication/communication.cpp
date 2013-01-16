/*Communication System
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 7515		Accepted: 2681

Description
We have received an order from Pizoor Communications Inc. for a special communication system. The system consists of several devices. For each device, we are free to choose from several manufacturers. Same devices from two manufacturers differ in their maximum bandwidths and prices.
By overall bandwidth (B) we mean the minimum of the bandwidths of the chosen devices in the communication system and the total price (P) is the sum of the prices of all chosen devices. Our goal is to choose a manufacturer for each device to maximize B/P.

Input
The first line of the input file contains a single integer t (1 ≤ t ≤ 10), the number of test cases, followed by the input data for each test case. Each test case starts with a line containing a single integer n (1 ≤ n ≤ 100), the number of devices in the communication system, followed by n lines in the following format: the i-th line (1 ≤ i ≤ n) starts with mi (1 ≤ mi ≤ 100), the number of manufacturers for the i-th device, followed by mi pairs of positive integers in the same line, each indicating the bandwidth and the price of the device respectively, corresponding to a manufacturer.

Output
Your program should produce a single line for each test case containing a single number which is the maximum possible B/P for the test case. Round the numbers in the output to 3 digits after decimal point.

Sample Input

1 3
3 100 25 150 35 80 25
2 120 80 155 40
2 100 100 120 110

Sample Output

0.649
*/

//sort all the values by its bandwidth, observe that once a minimum bandwidth is fixed
//we just need to take the bigger bandwidth and among which the smallest price
//if reach high bandwidth that in a group no one is bigger no need to consider it


//AUTHOR: LIHAO
//DATE: Feb 18th 2009
//VENUE: DORMITORY
// 464 K	829MS	C++	1528B
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
struct device
{
	int bandwidth;
	int price;
};

struct order
{
	int bandwidth;
	int price;
	int row_num;
};

bool cmp(order a,order b)
{
	return a.bandwidth<b.bandwidth;
}

double get_max(order now,int a[],int size,device all[][100])
{
	double total_price=now.price;
	double tmp_price;
	for(int i=0;i<size;i++){
	    if(i==now.row_num){
	    	continue;
	    }
		tmp_price=999999999;
		for(int j=0;j<a[i];j++){
			if(all[i][j].bandwidth>=now.bandwidth&&all[i][j].price<tmp_price){
				tmp_price=all[i][j].price;
			}
		}
		if(tmp_price==999999999){
			return -1;
		}
		else{
			total_price+=tmp_price;
		}
	}
	double x=(double)now.bandwidth/total_price;
	return x;
}

int main()
{
	device all[100][100];
	order mine[10000];
	int a[100],case_num,line_num,row_num;
	double max;
	int size=0;
	cin>>case_num;
	
	for(int i=0;i<case_num;i++){
		cin>>line_num;
		size=0;
		max=0.0;
		for(int j=0;j<line_num;j++){
			cin>>row_num;
			a[j]=row_num;
			for(int k=0;k<row_num;k++){
				cin >> all[j][k].bandwidth >> all[j][k].price;
				mine[size].bandwidth = all[j][k].bandwidth;
				mine[size].price = all[j][k].price;
				mine[size++].row_num = j;
			}
		}
		sort(mine,mine+size,cmp);
		for(int n=0;n<size;n++){
			double tmp=get_max(mine[n],a,line_num,all);
			if(tmp>max){
				max=tmp;
			}
		}
		cout<<setiosflags(ios::fixed)<<setprecision(3)<<max<<endl;
	}
	return 0;
}
	
