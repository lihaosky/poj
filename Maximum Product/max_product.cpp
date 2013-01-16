/****************************************************************
* find the maximum product in array                             *    
* the numbers are consecutive                                   *  
* DP--store every state's maximum positive and negtive value    *
* according to the input update the maximum value               *
****************************************************************/
//AUTHOR: LIHAO
//VENUE: DORMITORY
//DATE: 2 APRIL 2009
//

#include <iostream>
using namespace std;
int main()
{
	int size;
	double a,tmp,tmp_max;
	double max=-9999999;
	double negtive_max=1;
	cin>>size;
	cin>>a;
	tmp_max=a;
	negtive_max=tmp_max;
	
	//input and update the value
	for(int i=1;i<size;i++){
		cin>>a;
		if(a>0){
			if(tmp_max>0){
				tmp_max*=a;
			}
			else{
				tmp_max=a;
			}
			negtive_max*=a;
		}
		else if(a<0){
			if(negtive_max>0){
				negtive_max*=a;
			}
			else{
				if(tmp_max>0){
					tmp=tmp_max;
					tmp_max=negtive_max*a;
					negtive_max=tmp*a;
				}
				else{
					tmp_max*=a;
					if(a<negtive_max){
						negtive_max=a;
					}
				}
			}
		}
		else{
			if(tmp_max<0){
				tmp_max=0;
			}
			else{
				max=tmp_max;
				tmp_max=0;
			}
			negtive_max=1;
		}
		if(tmp_max>max){
			max=tmp_max;
		}
		cout<<"max"<<max<<" negtive_max"<<negtive_max<<endl;
	}
	cout<<max<<endl;
}
