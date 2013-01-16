/********************************************************************
STAMPS
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 5983		Accepted: 1561

Description
Have you done any Philately lately?

You have been hired by the Ruritanian Postal Service (RPS) to design their new postage software. The software allocates stamps to customers based on customer needs and the denominations that are currently in stock.

Ruritania is filled with people who correspond with stamp collectors. As a service to these people, the RPS asks that all stamp allocations have the maximum number of different types of stamps in it. In fact, the RPS has been known to issue several stamps of the same denomination in order to please customers (these count as different types, even though they are the same denomination). The maximum number of different types of stamps issued at any time is twenty-five.

To save money, the RPS would like to issue as few duplicate stamps as possible (given the constraint that they want to issue as many different types). Further, the RPS won't sell more than four stamps at a time.

Input
The input for your program will be pairs of positive integer sequences, consisting of two lines, alternating until end-of-file. The first sequence are the available values of stamps, while the second sequence is a series of customer requests. For example:

1 2 3 0 ; three different stamp types
7 4 0 ; two customers
1 1 0 ; a new set of stamps (two of the same type)
6 2 3 0 ; three customers

Note: the comments in this example are *not* part of the data file; data files contain only integers.

Output
For each customer, you should print the "best" combination that is exactly equal to the customer's needs, with a maximum of four stamps. If no such combination exists, print "none".
The "best" combination is defined as the maximum number of different stamp types. In case of a tie, the combination with the fewest total stamps is best. If still tied, the set with the highest single-value stamp is best. If there is still a tie, print "tie".

For the sample input file, the output should be:

7 (3): 1 1 2 3
4 (2): 1 3
6 ---- none
2 (2): 1 1
3 (2): tie

That is, you should print the customer request, the number of types sold and the actual stamps. In case of no legal allocation, the line should look like it does in the example, with four hyphens after a space. In the case of a tie, still print the number of types but do not print the allocation (again, as in the example).Don't print extra blank at the end of each line.

Sample Input

1 2 3 0	; three different stamp types
7 4 0		; two customers
1 1 0		; a new set of stamps (two of the same type)
6 2 3 0	; three customers

Sample Output

7 (3): 1 1 2 3 
4 (2): 1 3 
6 ---- none
2 (2): 1 1
3 (2): tie
*******************************************************************************/
//understand what is back trace searching a little
//AUTHOR: LIHAO
//DATE: 23 MAR, 2009
//VENUE: DORMITORY

#include <iostream>
#include <algorithm>
using namespace std;

bool tie;
int type,num,tmp_num;
int result[4],tmp[4];

void find(int stamp[],int start,int size,int level,int tar)
{
	if(tmp_num==4){
		return;
	}
	for(int i=start;i<size;i++){
		if(stamp[i]>tar){
			return ;
		}
		else{
			for(int j=1;j<=4;j++){
				if(tmp_num+j>4||j*stamp[i]>tar){
					break;
				}
				for(int k=0;k<j;k++){
					tmp[tmp_num++]=stamp[i];
				}
				if(j*stamp[i]==tar){
					if(level>type){
						for(int p=0;p<tmp_num;p++){
							result[p]=tmp[p];
						}
						type=level;
						num=tmp_num;
						tie=false;
					}
		            else if(level==type){
		            	if(num>tmp_num){
		            		for(int p=0;p<tmp_num;p++){
		            			result[p]=tmp[p];
		            			num=tmp_num;
		            		}
		            		tie=false;
		            	}
		            	else if(num==tmp_num){
		            		if(result[num-1]<tmp[num-1]){
		            			for(int p=0;p<tmp_num;p++){
		            				result[p]=tmp[p];
		            			}
		            			tie=false;
		            		}
		            		else if(result[num-1]==tmp[num-1]){
		            			tie=true;
		            		}
		            		else{
		            	    }
		                 }
		                 else{
		                 }
		        }
		        else{
		        }
		         tmp_num-=j;
		         continue;
		       }
				find(stamp,i+1,size,level+1,tar-j*stamp[i]);
				tmp_num-=j;
			}
		}
	}
}

int main()
{
	int stamp[100],size=0,tar[100],tar_size=0;
	while(cin>>stamp[size++]){
		if(stamp[size-1]==0){
			size--;
			sort(stamp,stamp+size);
			while(cin>>tar[tar_size]&&tar[tar_size++]);
			tar_size--;
			for(int i=0;i<tar_size;i++){
				type=0;
				num=0;
				tmp_num=0;
				find(stamp,0,size,1,tar[i]);
				if(!num){
					cout<<tar[i]<<" ---- none"<<endl;
				}
				else{
					if(!tie){
						cout<<tar[i]<<" ("<<type<<"):";
						for(int j=0;j<num;j++){
							cout<<" "<<result[j];
						}
						cout<<endl;
					}
					else{
						cout<<tar[i]<<" ("<<type<<"):";
						cout<<" tie"<<endl;
					}
				}
			}
			size=0;
			tar_size=0;
			tie=false;
		}
	}
	return 0;
}
