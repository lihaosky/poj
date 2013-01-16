//recursively solve permutation n numbers
//permutate first n-1 numbers and append the last one at the end
//AUTHOR: LIHAO
//DATE: Jan 27 2009
//VENUE: Dormitory


#include <iostream>
#include <ctime>
using namespace std;

void swap(int& i,int& j)
{
      int temp=i;
      i=j;
      j=temp;
}
int counter=0;

void perm(int a[],int k,int n)
{
      if(!k){
            //output the permutation
            for(int i=0;i<n;i++){
                  cout<<a[i]<<" ";
            }
            cout << endl;
            counter++;
            return;
      }
      //change the last element and solve the first n-1 numbers
      for(int i=0;i<k;i++){
            swap(a[i],a[k-1]);

            //permutate the first n-1 numbers
            perm(a,k-1,n);

            //restore the preceding number sequence
            swap(a[i],a[k-1]);
      }
}

int main()
{
      int a[100];
      int n;
      cout << "how many numbers do you want to permutate:" << endl;
      cin>>n;
      cout << "The original numbers are: " << endl;
      for(int i=0;i<n;i++){
            a[i]=i+1;
            cout << a[i] <<" ";
      }
      cout << endl;
      cout << " numbers after permutation are: " << endl;
      perm(a,n,n);
      cout<<endl<<counter<<endl;
      return 0;
}
