/*Cipher
Time Limit: 1000MS  Memory Limit: 10000K
Total Submissions: 8632  Accepted: 1991

Description

Bob and Alice started to use a brand-new encoding scheme. Surprisingly it is not a Public Key Cryptosystem, but their encoding and decoding is based on secret keys. They chose the secret key at their last meeting in Philadelphia on February 16th, 1996. They chose as a secret key a sequence of n distinct integers, a1 ; . . .; an, greater than zero and less or equal to n. The encoding is based on the following principle. The message is written down below the key, so that characters in the message and numbers in the key are correspondingly aligned. Character in the message at the position i is written in the encoded message at the position ai, where ai is the corresponding number in the key. And then the encoded message is encoded in the same way. This process is repeated k times. After kth encoding they exchange their message.

The length of the message is always less or equal than n. If the message is shorter than n, then spaces are added to the end of the message to get the message with the length n.

Help Alice and Bob and write program which reads the key and then a sequence of pairs consisting of k and message to be encoded k times and produces a list of encoded messages.

Input

The input file consists of several blocks. Each block has a number 0 < n <= 200 in the first line. The next line contains a sequence of n numbers pairwise distinct and each greater than zero and less or equal than n. Next lines contain integer number k and one message of ascii characters separated by one space. The lines are ended with eol, this eol does not belong to the message. The block ends with the separate line with the number 0. After the last block there is in separate line the number 0.
Output

Output is divided into blocks corresponding to the input blocks. Each block contains the encoded input messages in the same order as in input file. Each encoded message in the output file has the lenght n. After each block there is one empty line.
Sample Input

10
4 5 3 7 2 8 1 6 10 9
1 Hello Bob
1995 CERC
0
0

Sample Output

BolHeol  b
C RCE
*/

//easy method, to avoid TLE, I get the repeat time and path of each position and take modular of k
//take 188ms and 400kb of memory
//AUTHOR: LIHAO
//VENUE: DORMITORY
//DATE: Mar 1st 2009


#include <iostream>
#include <cstring>
using namespace std;

struct trace
{
      int size;
      int way[201];
};

void get_trace(trace road[],int a[],int n)
{
      int key;
      for(int i=1;i<=n;i++){
            if(a[i]==i){
                  road[i].way[road[i].size++]=i;
            }
            else{
            key=a[i];
            road[i].way[road[i].size++]=a[i];
            while(a[key]!=i){
                  road[i].way[road[i].size++]=a[key];
                  key=a[key];
            }
            road[i].way[road[i].size++]=i;
            }
      }
}
void man(int k,int n,char str[],trace road[])
{
      char b[201];
      for(int i=1;i<=n;i++){
            int key;
            if(k%road[i].size==0){
                  key=road[i].size-1;
            }
            else{
                  key=k%road[i].size-1;
            }
            b[road[i].way[key]]=str[i];
      }
      for(int i=1;i<=n;i++){
            str[i]=b[i];
      }
}

int main()
{
      trace road[201];
      int n,k,a[201];
      while(cin>>n&&n){
            for(int i=1;i<=n;i++){
                  cin>>a[i];
            }
            for(int s=1;s<=n;s++){
                        road[s].size=0;
            }
            get_trace(road,a,n);
            while(1){
                  cin>>k;
                  if(!k){
                        break;
                  }
                  char str[203];
                  gets(str);
                  for(int j=strlen(str);j<=n+1;j++){
                        str[j]=' ';
                  }
                        man(k,n,str,road);
                        for(int j=1;j<=n;j++){
                           cout<<str[j];
                       }
                       cout<<endl;
            }
            cout<<endl;
      }
      return 0;
}
