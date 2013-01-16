//user input the comlumn and row number of matrix 
//output the determinant of the matrix
//LIHAO 
#include<iostream>
using namespace std;

void input(int b[][10],int m)
{
	int i,j;
	for(i=1;i<=m;i++){
		for(j=1;j<=m;j++){
            cout<<"b["<<i<<"]"<<"["<<j<<"]: ";
			cin>>b[i][j];
		}
	}
}

void output(int b[][10],int m)
{
	int i,j;
	for(i=1;i<=m;i++){
		for(j=1;j<=m;j++){
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
}
int tall(int a[],int m)
{
	int tall_num=0;
	for(int i=1;i<m;i++){
		for(int j=i+1;j<=m;j++){
			if(a[j]<a[i]){
				tall_num++;
			}
		}
	}
	if(tall_num%2==1){
		return -1;
	}
	return 1;
}

bool finish(int a[],int m)
{
	int j=m;
	for(j=m;j>0;j--){
		if(a[j]>a[j-1]){
			return false;
		}
	}
	return true;
}

void generate(int a[],int m)
{
	int j=m;
	for(j=m;j>0;j--){
		if(a[j]>a[j-1]){
			break;
		}
	}
	if(j==0){
		return;
	}
	int i,temp;
	for(i=m;i>=j;i--){
		if(a[i]>a[j-1]){
			temp=a[i];
			a[i]=a[j-1];
			a[j-1]=temp;
			break;
		}
	}
	for(int k=m;k>j;k--){
            for(int n=j;n<k;n++){
                    if(a[n]>a[n+1]){
                    temp=a[n];
                    a[n]=a[n+1];
                    a[n+1]=temp;
                    }
            }
}
}


	



int main()
{
	int b[10][10],m, a[20],outcome=0,subtotal;
	cout<<"Enter the row number and the colunm number of the matrix"<<endl;
	cin>>m;
	for(int i=1;i<=m;i++){
		a[i]=i;
	}
	cout<<"Input number of every component"<<endl;
	input(b,m);
	cout<<"the matrix is:"<<endl;
	output(b,m);
	subtotal=1;
		for(int  i=1;i<=m;i++){
			subtotal=subtotal*b[i][a[i]];
		}
		outcome+=(tall(a,m))*subtotal;
	while(!finish(a,m)){
        generate(a,m);
		subtotal=1;
		for(int  i=1;i<=m;i++){
			subtotal=subtotal*b[i][a[i]];
		}
		outcome+=(tall(a,m))*subtotal;
		
	}
	cout<<"the determinent of the matrix is"<<endl;
	cout<<outcome<<endl;
	system("PAUSE");
}



