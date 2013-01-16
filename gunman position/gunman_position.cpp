//suppose we have a nXn square
//there are certain blocks in the square and some gunmen
//suppose gunmen can only shoot vertically or horizontally and they can shoot each other through blocks
//now input n and the blocks use 'x' and blank place use '.'
//find the maximum gunmen such that it's safe(they can shoot each other
//
//AUTHOR: LIHAO
//DATE:Feb 4 2009
//VENUE: DORMITORY
//find a solution and using backwarding to find all solution and maximum number

#include <iostream>
using namespace std;

bool check(int i,int a[],int n)
{
	//check if this place can stand a gunman(suppose places after this didn't have gunman

	//this is a block
	if(a[i]==1){
		return false;
	}

	int j;
	//find the row of the place
	for(j=1;j<=n;j++){
		if(i<=j*n){
			break;
		}
	}

	//decide if in this row there are gunmen before exposed without blocks
	for(int k=i-1;k>=(j-1)*n+1;k--){
		//first encounter a block
		if(a[k]==1){
			break;
		}
		//first encounter another gunmen
		if(a[k]==2){
			return false;
		}
	}

	//decide if in this column there are gunmen before exposed without blocks
	for(int k=i-n;k>0;k-=n){
		if(a[k]==1){
			break;
		}
		if(a[k]==2){
			return false;
		}
	}
	return true;
}

int main()
{
	int a[100];//store the square
	int b[100];//store the position of gunmen
	char c;    //for input usage
	int n;     //dimesion of the square
	int d[100];//store the best position
	cout<<"input the dimention of the square:(0 to end)"<<endl;
	while(cin>>n&&n){
	int counter=0;
	int max=0;
	cout<<"input the blocks'x':"<<endl;
	//input data
	for(int i=1;i<=n*n;i++){
		    cin>>c;
		    if(c=='.'){
		    	a[i]=0;
		    }
		    else{
		        a[i]=1;
		    }
	}

	//find the first solution
	for(int i=1;i<=n*n;i++){
		if(check(i,a,n)){
			a[i]=2;
			b[++counter]=i;
		}
	}
	for(int i=1;i<=n*n;i++){
		d[i]=a[i];
	}
	max=counter;

	//回溯to find all the position
	while(b[1]<=n*n){
		//expel last gunman and move it forward
		a[b[counter]]=0;
		b[counter]++;

		//decide if this gunman can find a position
		while(!check(b[counter],a,n)&&b[counter]<=n*n){
			b[counter]++;
		}

		//if can't find eliminate this gunman and consider gunman before
		if(b[counter]>n*n){
			counter--;
			continue;
		}
		//if can the decide the position and find positions for more gunmen if there are
		else{
			a[b[counter]]=2;
			for(int i=b[counter]+1;i<=n*n;i++){
				if(check(i,a,n)){
					a[i]=2;
					b[++counter]=i;
				}
			}
			//if more gunmen stand modify the maximum number of gunmen
			if(counter>max){
				max=counter;
				for(int i=1;i<=n*n;i++){
					d[i]=a[i];
				}
			}
/*			for(int i=1;i<=n*n;i++){
				cout<<a[i]<<" ";
				if(i%n==0){
					cout<<endl;
				}
			}
			cout<<endl<<endl;*/
		}
	}
	cout<<"max number of gunmen are "<<max<<endl<<"the position is"<<endl;
	for(int i=1;i<=n*n;i++){
		cout<<d[i]<<" ";
		if(i%n==0){
			cout<<endl;
		}
	}
	cout<<"input the dimention of the square:(0 to end)"<<endl;
	}
	return 0;

}
