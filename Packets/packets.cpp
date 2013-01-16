/*Packets
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 17350		Accepted: 5675

Description
A factory produces products packed in square packets of the same height h and of the sizes 1*1, 2*2, 3*3, 4*4, 5*5, 6*6. These products are always delivered to customers in the square parcels of the same height h as the products have and of the size 6*6. Because of the expenses it is the interest of the factory as well as of the customer to minimize the number of parcels necessary to deliver the ordered products from the factory to the customer. A good program solving the problem of finding the minimal number of parcels necessary to deliver the given products according to an order would save a lot of money. You are asked to make such a program.

Input
The input file consists of several lines specifying orders. Each line specifies one order. Orders are described by six integers separated by one space representing successively the number of packets of individual size from the smallest size 1*1 to the biggest size 6*6. The end of the input file is indicated by the line containing six zeros.

Output
The output file contains one line for each line in the input file. This line contains the minimal number of parcels into which the order from the corresponding line of the input file can be packed. There is no line in the output file corresponding to the last ``null'' line of the input file.

Sample Input

0 0 4 0 0 1 
7 5 1 0 0 0 
0 0 0 0 0 0 

Sample Output

2 
1 
*/

//Find from the largest packets bewear that the edge of the packet can be less than the edge of some small ones
//AUTHOR: LIHAO
//DATE: Feb 17th 2009
//VENUE: DORMITORY

#include <iostream>
using namespace std;
bool is_empty(int a[])
{
	for(int i=1;i<=6;i++){
		if(a[i]){
			return false;
		}
	}
	return true;
}

int main()
{
	int a[7];
	while(cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]&&(a[1]||a[2]||a[3]||a[4]||a[5]||a[6])){
		int packets_num=0;
		while(!is_empty(a)){
			int volumn=36;
			int max_width;
			for(int i=6;i>0;i--){
				if(a[i]){
					max_width=i;
					volumn-=i*i;
					a[i]--;
					break;
				}
			}//notice that if the packets contain 3 then it can't contain too many 2, even the volumn is enough
			if(max_width==3){
				if(a[3]==0){
					if(a[2]>5){
						a[2]-=5;
						volumn-=20;
						for(int i=1;i>0;i--){
							while(volumn>=i*i&&a[i]){
								volumn-=i*i;
								a[i]--;
							}
						}
					}
					else{
						for(int i=3;i>0;i--){
							while(volumn>=i*i&&a[i]){
								volumn-=i*i;
								a[i]--;
							}
						}
					}
				}
				else if(a[3]==1){
					if(a[2]>3){
						a[2]-=3;
						a[3]--;
						volumn-=(9+12);
						for(int i=1;i>0;i--){
							while(volumn>=i*i&&a[i]){
								volumn-=i*i;
								a[i]--;
							}
						}
					}
				else{
						for(int i=3;i>0;i--){
							while(volumn>=i*i&&a[i]){
								volumn-=i*i;
								a[i]--;
							}
						}
					}
				}
				else if(a[3]==2){
					if(a[2]>1){
						a[2]--;
						a[3]-=2;
						volumn-=(18+4);
						for(int i=1;i>0;i--){
							while(volumn>=i*i&&a[i]){
								volumn-=i*i;
								a[i]--;
							}
						}
					}
					else{
						for(int i=3;i>0;i--){
							while(volumn>=i*i&&a[i]){
								volumn-=i*i;
								a[i]--;
							}
						}
					}
				}
				else{
					for(int i=3;i>0;i--){
						while(volumn>=i*i&&a[i]){
							volumn-=i*i;
							a[i]--;
						}
					}
				}
				
			}
			else{
			for(int i=6;i>0;i--){
				while(volumn>=i*i&&a[i]&&i+max_width<=6){
					volumn=volumn-i*i;
					a[i]--;
				}
			}
			}
			packets_num++;
		}
		cout<<packets_num<<endl;
	}
	return 0;
}
