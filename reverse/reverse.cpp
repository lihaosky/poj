//funtion::input a string then input the number i, then the first i numbers will be push to the back
//LIHAO 18/NOV/2008


#include<iostream>
using namespace std;
int main()
{
    string word;
    cin>>word;
    int i;
    cin>>i;
    for(int j=0;j<i/2;j++){
            int temp=word[j];
            word[j]=word[i-1-j];
            word[i-1-j]=temp;
            }
    int k=i-1+word.length();
    for(int j=i;j<(word.length()+i)/2;j++){
            int temp=word[j];
            word[j]=word[k-j];
            word[k-j]=temp;
    }
    for(int j=0;j<word.length()/2;j++){
            int temp;
            temp=word[j];
            word[j]=word[word.length()-1-j];
            word[word.length()-1-j]=temp;
    }
    cout<<word<<endl;
    system("PAUSE");
    return 0;
}
            
