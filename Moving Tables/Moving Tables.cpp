/*
Moving Tables
Time Limit: 1000MS  Memory Limit: 10000K
Total Submissions: 8234  Accepted: 2687

Description

The famous ACM (Advanced Computer Maker) Company has rented a floor of a building whose shape is in the following figure.



The floor has 200 rooms each on the north side and south side along the corridor. Recently the Company made a plan to reform its system. The reform includes moving a lot of tables between rooms. Because the corridor is narrow and all the tables are big, only one table can pass through the corridor. Some plan is needed to make the moving efficient. The manager figured out the following plan: Moving a table from a room to another room can be done within 10 minutes. When moving a table from room i to room j, the part of the corridor between the front of room i and the front of room j is used. So, during each 10 minutes, several moving between two rooms not sharing the same part of the corridor will be done simultaneously. To make it clear the manager illustrated the possible cases and impossible cases of simultaneous moving.



For each room, at most one table will be either moved in or moved out. Now, the manager seeks out a method to minimize the time to move all the tables. Your job is to write a program to solve the manager's problem.
Input

The input consists of T test cases. The number of test cases ) (T is given in the first line of the input file. Each test case begins with a line containing an integer N , 1 <= N <= 200, that represents the number of tables to move.
Each of the following N lines contains two positive integers s and t, representing that a table is to move from room number s to room number t each room number appears at most once in the N lines). From the 3 + N -rd
line, the remaining test cases are listed in the same manner as above.
Output

The output should contain the minimum time in minutes to complete the moving, one per line.
Sample Input

3
4
10 20
30 40
50 60
70 80
2
1 3
2 200
3
10 100
20 80
30 50

Sample Output

10
20
30
Source

Taejon 2001
*/
//pitfall be careful
//AUTHOR: LIHAO
//VENUE: DORMITORY
//DATE: 7TH MAY 2009

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Table
{
      int s,t;
}table[205];

bool cmp(Table a,Table b)
{
      return a.s<b.s;
}
int check(bool used[],int size)
{
      for(int i=0;i<size;i++){
            if(used[i]==false){
                  return i;
            }
      }
      return size;
}

int main()
{
      int test,n,size,s,t,j,ans;
      bool used[205];
      cin>>test;
      while(test--){
            cin>>n;
            memset(used,0,n);
            size=0;
            ans=0;
            for(int i=0;i<n;i++){
                  cin>>s>>t;
                  if(s>t){
                        int tmp=t;
                        t=s;
                        s=tmp;
                  }
                  if(s&1==0){
                        s--;
                  }
                  if(t&1){
                        t++;
                  }
                  table[size].s=s;
                  table[size++].t=t;
            }
            sort(table,table+size,cmp);
            while(check(used,n)!=n){
                  int pre=check(used,n);
                  used[pre]=true;
                  for(int i=pre;i<n;i++){
                        if(!used[i]){
                              if(table[i].s>table[pre].t){
                                    used[i]=true;
                                    pre=i;
                              }
                        }
                  }
                  ans++;
            }
            cout<<ans*10<<endl;
      }
}
