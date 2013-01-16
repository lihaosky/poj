/*Description

Standard web browsers contain features to move backward and forward among the pages recently visited. One way to implement these features is to use two stacks to keep track of the pages that can be reached by moving backward and forward. In this problem, you are asked to implement this.
The following commands need to be supported:
BACK: Push the current page on the top of the forward stack. Pop the page from the top of the backward stack, making it the new current page. If the backward stack is empty, the command is ignored.
FORWARD: Push the current page on the top of the backward stack. Pop the page from the top of the forward stack, making it the new current page. If the forward stack is empty, the command is ignored.
VISIT : Push the current page on the top of the backward stack, and make the URL specified the new current page. The forward stack is emptied.
QUIT: Quit the browser.
Assume that the browser initially loads the web page at the URL http://www.acm.org/
Input

Input is a sequence of commands. The command keywords BACK, FORWARD, VISIT, and QUIT are all in uppercase. URLs have no whitespace and have at most 70 characters. You may assume that no problem instance requires more than 100 elements in each stack at any time. The end of input is indicated by the QUIT command.
Output

For each command other than QUIT, print the URL of the current page after the command is executed if the command is not ignored. Otherwise, print "Ignored". The output for each command should be printed on its own line. No output is produced for the QUIT command.
*/
//AUTHOR:LIHAO
//DATE:Feb 7TH 2009
//VENUE: DORMITORY

#include <iostream>
#include <string>
using namespace std;
int main()
{
      string back[100];
      string forward[100];
      int back_c=0;
      int forward_c=0;
      string command;
      string url;
      back[0]="http://www.acm.org/";
      while(cin>>command&&command!="QUIT"){
            if(command=="VISIT"){
                  cin>>url;
                  forward_c=0;
                  back[++back_c]=url;
                  cout<<url<<endl;

            }
            else if(command=="BACK"){
                  if(back_c==0){
                        cout<<"Ignored"<<endl;
                  }
                  else{
                        forward[forward_c++]=back[back_c--];
                        cout<<back[back_c]<<endl;
                  }
            }
            else{
                  forward_c--;
                  if(forward_c<0){
                        cout<<"Ignored"<<endl;
                        forward_c=0;
                  }
                  else{
                        cout<<forward[forward_c]<<endl;
                        back[++back_c]=forward[forward_c];
                  }
            }
      }
      return 0;
}

