//Assume each letter in the alphabets: 'a','b',бн,'z' or 'A','B',бн,'Z' has a value from 1 to 26
//respectively, complete the following program which calculates the sum of an word.

#include<iostream>
#include<string>
using namespace std;
int value(char);
int main()
{
    string word;
    int sum=0;
    cin>>word;
    for(int i=0;word[i];i++){
            sum+=value(word[i]);
            }
    cout<<sum<<endl;
    system("PAUSE");
}
    
int value(char a)
{
    return a>='a'?(a-'a'):(a-64);
}
