//given a array of numbers
//given a number
//decide if the number is the sum from the numbers in the array
//author: LIHAO
//VENUE:home
//date: Dec 23 2008

#include<iostream>
#include<ctime>
#include <algorithm>
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
bool cmp(element a,element b)
{
      return a.value>b.value;
}

int main()
{
	element a[10000];
	int n;
	cout<<"input size of the array:"<<endl;
	cin>>n;
	srand(time(NULL));
	cout<<"input element of the array:"<<endl;
	for(int i=0;i<n;i++){
		//a[i].value=rand()%100;
		//cout<<a[i].value<<" ";
		cin>>a[i].value;
		a[i].status=0;
	}
	int x;
	cout<<endl<<"input the number you want to find:"<<endl;
	cin>>x;
	clock_t start=clock();
	stable_sort(a,a+n,cmp);
	if(find(a,0,n,x)){
		for(int i=0;i<n;i++){
			if(a[i].status){
				cout<<a[i].value<<" ";
				a[i].status=2;
			}
		}
		cout<<endl;
		while(!is_finish(a,n)&&find(a,0,n,x)){
		for(int i=0;i<n;i++){
			if(a[i].status==1){
				cout<<a[i].value<<" ";
				a[i].status=2;
			}
		}
		cout<<endl;
	}
	}
	else{
		cout<<"Doesn't exist!"<<endl;
	}
	clock_t end=clock();
	double t=(end-start)/CLOCKS_PER_SEC;
	cout<<t<<endl;
	system("PAUSE");
	return 0;
}
