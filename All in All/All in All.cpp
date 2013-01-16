/**********************************************
All in All
Time Limit: 1000MS  Memory Limit: 30000K
Total Submissions: 11106  Accepted: 4359

Description

You have devised a new encryption technique which encodes a message by inserting between its characters randomly generated strings in a clever way. Because of pending patent issues we will not discuss in detail how the strings are generated and inserted into the original message. To validate your method, however, it is necessary to write a program that checks if the message is really encoded in the final string.

Given two strings s and t, you have to decide whether s is a subsequence of t, i.e. if you can remove characters from t such that the concatenation of the remaining characters is s.

Input

The input contains several testcases. Each is specified by two strings s, t of alphanumeric ASCII characters separated by whitespace.The length of s and t will no more than 100000.
Output

For each test case output "Yes", if s is a subsequence of t,otherwise output "No".
Sample Input

sequence subsequence
person compression
VERDI vivaVittorioEmanueleReDiItalia
caseDoesMatter CaseDoesMatter

Sample Output

Yes
No
Yes
No

Source

Ulm Local 2002
***************************************************************/
//AUTHOR: LIHAO
//DATE: 27 MAR, 2009
//VENUE: DORMITORY
#include <iostream>
#include <string>
using namespace std;
bool check(string a,string b)
{
      int pos=0;
      for(int i=0;i<a.length();i++){
            while(pos<b.length()&&a[i]!=b[pos]){
                  pos++;
            }
            if(pos==b.length()){
                  return false;
            }
            else{
                  pos++;
            }
      }
      return true;
}

int main()
{
      string a,b;
      while(cin>>a>>b){
            if(check(a,b)){
                  cout<<"Yes"<<endl;
            }
            else{
                  cout<<"No"<<endl;
            }
      }
}
