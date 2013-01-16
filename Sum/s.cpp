//given a array of numbers
//given a number
//decide if the number is the sum from the numbers in the array
//author: LIHAO
//VENUE:home
//date: Dec 23 2008

#include<iostream>
#include<ctime>
using namespace std;

struct element
{
	int value;
	int status;
};

bool is_finish(element a[],int up)
{
	for(int i=0;i<up;i++){
		if(a[i].status!=2){
			return false;}
	}
	return true;
}

void get_factor(int sum,int factor[],int& factor_size)
{
      for(int i=1;i<=sum;i++){
            if(sum%i==0){
                  factor[factor_size++]=i;
            }
      }
}

bool find(element a[],int low,int up,int x)
{
	while(low<up){
		if(a[low].status==2){
			low++;
			continue;
		}
		if(a[low].value==x){a[low].status=1;return true;}
		else if(a[low].value<x){
			if(find(a,low+1,up,x-a[low].value)){
			a[low].status=1;
			return true;
			}
			else{
				low++;
				return find(a,low,up,x);
			}
		}
		else{return false;}
	}
	return false;
}


int main()
{
      int n;
	while(cin>>n&&n){
	      srand(time(NULL));
	element a[65];
	int factor[100];
	int factor_size=0;
	int sum=0;
	for(int i=0;i<n;i++){
		a[i].value=rand()%50;
		sum+=a[i].value;
		a[i].status=0;
	}
	for(int i=0;i<n;i++){
	      cout<<a[i].value<<" ";
	}
	cout<<endl;
	get_factor(sum,factor,factor_size);
	int k;
	for( k=0;k<factor_size;k++){
	while(find(a,0,n,factor[k])){
		for(int i=0;i<n;i++){
			if(a[i].status){
				a[i].status=2;
			}
		}
	}
		if(is_finish(a,n)){
		      break;
		}
		else{
		      for(int j=0;j<n;j++){
		            a[j].status=0;
		      }
		}
	}
	if(k==factor_size){
	      cout<<"no answer"<<endl;
	}
	else{
	cout<<factor[k]<<endl;
	}
	}
	return 0;
}
