//quicksort from programming pearls
//author:...
//venue: home
//date: Dec 25 2008

#include <iostream>
#include <ctime>
using namespace std;
void quicksort(int *x,int n)
{
	if(n<=1){
		return;
	}
	int *p=x;
	int m=0;
	for(int i=1;i<n;i++){
		if(*x>*(x+i)){
			p++;
			int temp=*p;
			*p=*(x+i);
			*(x+i)=temp;
			m++;
		}
	}
	int temp=*p;
	*p=*x;
	*x=temp;
	p++;
	quicksort(x,m);
	quicksort(p,n-1-m);
}

int main()
{
	int a[100];
	srand(time(NULL));
	for(int i=0;i<20;i++){
		a[i]=rand()%50;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	quicksort(a,20);
	for(int i=0;i<20;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	system("PAUSE");
	return 0;
}
