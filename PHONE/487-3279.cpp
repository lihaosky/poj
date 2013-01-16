#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
      int n;
      map<string,int> a;
      string tmp;
      bool flag=false;
      cin>>n;
      for(int k=0;k<n;k++){
            cin>>tmp;
            for(int j=0;j<tmp.length();j++){
                  if(tmp[j]=='-'){
                        tmp.erase(j,1);
                        j--;
                  }
            }
            tmp.insert(3,"-");
            for(int i=0;i<tmp.length();i++){
                  if(tmp[i]>='A'&&tmp[i]<='C'){
                        tmp[i]='2';
                  }
                  else if(tmp[i]>='D'&&tmp[i]<='F'){
                        tmp[i]='3';
                  }
                  else if(tmp[i]>='G'&&tmp[i]<='I'){
                        tmp[i]='4';
                  }
                  else if(tmp[i]>='J'&&tmp[i]<='L'){
                        tmp[i]='5';
                  }
                  else if(tmp[i]>='M'&&tmp[i]<='O'){
                        tmp[i]='6';
                  }
                  else if(tmp[i]>='P'&&tmp[i]<='S'){
                        tmp[i]='7';
                  }
                  else if(tmp[i]>='T'&&tmp[i]<='V'){
                        tmp[i]='8';
                  }
                  else if(tmp[i]>='W'&&tmp[i]<='Y'){
                        tmp[i]='9';
                  }
                  else{
                        continue;
                  }
            }
            a[tmp]++;
      }
      map<string,int>::iterator i;
      for(i=a.begin();i!=a.end();i++){
            if((*i).second!=1){
            cout<<(*i).first<<" "<<(*i).second<<endl;
            flag=true;
            }
      }
      if(!flag){
            cout<<"No duplicates."<<endl;
      }
      return 0;
}
