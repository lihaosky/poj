//////the number can't be to big////////


#include<iostream>
using namespace std;
void binary(int a[],int *digit,int power)
{
	int i=0;
	while(power){
		a[i++]=power%2;
		power/=2;
	}
	*digit=i;
}
int main()
{
	int a[20];
	int digit=0;
	unsigned long n;
	long power;
	unsigned long divisor;
	unsigned long remainder;
	while(1){
	cout<<"Input the number,power,divisor:"<<endl;
	cin>>n>>power>>divisor;
	binary(a,&digit,power);
    remainder=(n*n)%divisor;
	for(int i=digit-2;i>=0;i--){
        if(i==0&&a[i]==0){
                          break;
                          }
		if(i==0&&a[0]==1){
			remainder=((remainder*n)%divisor);
			break;
		}
		if(a[i]==0){
			remainder=((remainder*remainder)%divisor);
		}
		else{
			remainder=(((remainder*n)%divisor)*((remainder*n)%divisor))%divisor;
		}
	}
	
	cout<<"The answer is "<<remainder<<endl;
}
	system("PAUSE");
}

