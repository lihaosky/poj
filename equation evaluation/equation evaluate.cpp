//this can solve some equation but the equation can only have the same number of viariables and equations
//LIHAO 2008/11/11

#include<iostream>
using namespace std;
int tall(int a[],int);
void generate(int,int);
bool finish(int,int);
double det(double a[][10],int);
void inverse(double a[][10],int,double b[][10]);
void multyple(double a[][10],double b[],double c[],int n)
{
     for(int i=1;i<=n;i++){c[i]=0;}
     for(int i=1;i<=n;i++){
             for(int j=1;j<=n;j++){
                     c[i]+=a[i][j]*b[j];
                     }
             }
}
int main()
{
    double  coefficient[10][10];
    double temp[10][10];
    double c[10],d[10];
    int n;
    cout<<"input dimension of coefficient"<<endl;
    cin>>n;
    cout<<"input coefficient, row then column:"<<endl;
    for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                    cin>>coefficient[i][j];
                    }
    }
    cout<<"input the constant value:"<<endl;
    for(int i=1;i<=n;i++){
            cin>>c[i];
    }
    cout<<"The equation is:"<<endl;
    for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                    if(j==n){cout<<coefficient[i][j];continue;}
                    cout<<coefficient[i][j]<<"X"<<j<<"+";
                    }
                    cout<<"="<<c[i]<<endl;
    }
    inverse(coefficient,n,temp);
    multyple(temp,c,d,n);
    cout<<"The root is:"<<endl;
    for(int i=1;i<=n;i++){
            cout<<"X"<<i<<"="<<d[i]<<endl;
    }
    system("PAUSE");
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
	if(tall_num%2){
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

double det(double a[][10],int n)
{
     int b[10];
     double subtotal=0;
     double product=1;
     for(int i=1;i<=n;i++){b[i]=i;}
     for(int i=1;i<=n;i++){product*=a[i][b[i]];}
     subtotal+=product;
     while(!finish(b,n)){
             product=1; 
             generate(b,n);
             for(int i=1;i<=n;i++){
                   product*=a[i][b[i]];
             }
             subtotal+=(tall(b,n))*product;
     }
     return subtotal;
}  

void inverse(double a[][10],int n,double b[][10])
{
     double c[10][10];
     double temp[10][10];
     for(int i=1;i<=n;i++){
             for(int j=1;j<=n;j++){
                     int col=1,row=1;
                     for(int k=1;k<=n-1;k++){
                             for(int l=1;l<=n-1;l++){
                                     if(row==i){row++;col=1;}
                                     if(col==j){
                                                if(col==n&&(row+1==i)){row+=2;col=1;}
                                                else{if(col==n){col=1;row++;}else{col=col+1;}}
                                     }
                                     c[k][l]=a[row][col];
                                     col==n?row++,col=1:col++;
                                     }
                             }
                             if((i+j)%2){
                             b[j][i]=det(c,n-1)*(-1)/det(a,n);
                             }
                             else{b[j][i]=det(c,n-1)/det(a,n);}
                     }
             }
             for(int i=1;i<=n;i++){
                     for(int j=1;j<=n;j++){
                             cout<<b[i][j]<<" ";
                             }
                             cout<<endl;
             }
}
                             

                             
                                     
                                     
                     
                     
                     
     
     
