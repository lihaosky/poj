/*
P,MTHBGWB
Time Limit: 1000MS  Memory Limit: 10000K
Total Submissions: 3121  Accepted: 1778

Description

Morse code represents characters as variable length sequences of dots and dashes. In practice, characters in a message are delimited by short pauses. The following table shows the Morse code sequences:
A .- H .... O --- V ...-
B -... I .. P .--. W .--
C -.-. J .--- Q --.- X -..-
D -.. K -.- R .-. Y -.--
E . L .-.. S ... Z --..
F ..-. M -- T - �� ��
G --. N -. U ..- �� ��

Note that four dot-dash combinations are unassigned. For the purposes of this problem we will assign them as follows (these are not the assignments for actual Morse code):
underscore ..-- period ---.
comma .-.- question mark ----

Thus, the message "ACM_GREATER_NY_REGION" is encoded as:
.- -.-. -- ..-- --. .-. . .- - . .-. ..-- -. -.-- ..-- .-. . --. .. --- -.
M.E. Ohaver proposed an encryption scheme based on mutilating Morse code. Her scheme replaces the pauses between letters, necessary because Morse is a variable-length encoding that is not prefix-free, with a string that identifies the number of dots and dashes in each. For example, consider the message ".--.-.--". Without knowing where the pauses should be, this could be "ACM", "ANK", or several other possibilities. If we add length information, however, ".--.-.--242", then the code is unabiguous.
Ohaver's scheme has three steps, the same for encryption and decryption:
1. Convert the text to Morse code without pauses but with a string of numbers to indicate code lengths
2. Reverse the string of numbers
3. Convert the dots and dashes back into to text using the reversed string of numbers as code lengths
As an example, consider the encrypted message "AKADTOF_IBOETATUK_IJN". Converting to Morse code with a length string yields ".--.-.--..----..-...--..-...---.-.--..--.-..--...----.232313442431121334242". Reversing the numbers and decoding yields the original message "ACM_GREATER_NY_REGION".

Input

This problem requires that you implement Ohaver's encoding algorithm. The input will consist of several messages encoded with Ohaver's algorithm. The first line of the input is an integer n that specifies the number of test cases. The following n lines contain one message per line. Each message will use only the twenty-six capital letters, underscores, commas, periods, and question marks. Messages will not exceed 100 characters in length.
Output

For each message in the input, output the line number starting in column one, a colon, a space, and then the decoded message. The output format must be adhered to precisely.
Sample Input

5
AKADTOF_IBOETATUK_IJN
PUEL
QEWOISE.EIVCAEFNRXTBELYTGD.
?EJHUT.TSMYGW?EJHOT
DSU.XFNCJEVE.OE_UJDXNO_YHU?VIDWDHPDJIKXZT?E

Sample Output

1: ACM_GREATER_NY_REGION
2: PERL
3: QUOTH_THE_RAVEN,_NEVERMORE.
4: TO_BE_OR_NOT_TO_BE?
5: THE_QUICK_BROWN_FOX_JUMPS_OVER_THE_LAZY_DOG

Source

Greater New York 2001
*/

//AUTHOR: LIHAO
//DATE: MAR 2ND 2009
//VENUE: DORMITORY

#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
      map<char,string> index;
      index['A']=".-";
      index['B']="-...";
      index['C']="-.-.";
      index['D']="-..";
      index['E']=".";
      index['F']="..-.";
      index['G']="--.";
      index['H']="....";
      index['I']="..";
      index['J']=".---";
      index['K']="-.-";
      index['L']=".-..";
      index['M']="--";
      index['N']="-.";
      index['O']="---";
      index['P']=".--.";
      index['Q']="--.-";
      index['R']=".-.";
      index['S']="...";
      index['T']="-";
      index['U']="..-";
      index['V']="...-";
      index['W']=".--";
      index['X']="-..-";
      index['Y']="-.--";
      index['Z']="--..";
      index['_']="..--";
      index['.']="---.";
      index[',']=".-.-";
      index['?']="----";
      map<char,string>::iterator it;
      int case_num;
      int code[100],size,mark;
      cin>>case_num;
      for(int i=0;i<case_num;i++){
            mark=0;
            string str,code_seq,tmp;
            cin>>str;
            size=0;
            for(int i=0;i<str.length();i++){
                  code_seq+=index[str[i]];
                  code[size++]=index[str[i]].length();
            }
            cout<<i+1<<": ";
            for(int k=size-1;k>=0;k--){
                  tmp=code_seq.substr(mark,code[k]);
                  mark+=code[k];
                  for(it=index.begin();it!=index.end();it++){
                        if((*it).second==tmp){
                              cout<<(*it).first;
                              break;
                        }
                  }
            }
            cout<<endl;
      }
      return 0;
}
