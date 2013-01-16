/*
Chain
Time Limit: 1000MS  Memory Limit: 10000K
Total Submissions: 1691  Accepted: 576

Description

Byteland had not always been a democratic country. There were also black pages in its book of history. One lovely day general Bytel − commander of the junta which had power over Byteland −− decided to finish the long−lasting time of war and released imprisoned activists of the opposition. However, he had no intention to let the leader Bytesar free. He decided to chain him to the wall with the bytish chain. It consists of joined rings and the bar fixed to the wall. Although the rings are not joined with the bar, it is hard to take them off.
'General, why have you chained me to the prison walls and did not let rejoice at freedom!' cried Bytesar.
'But Bytesar, you are not chained at all, and I am certain you are able to take off the rings from the bar by yourself.' perfidiously answered general Bytel, and he added 'But deal with that before a clock strikes the cyber hour and do not make a noise at night, otherwise I will be forced to call Civil Cyber Police.'
Help Bytesar! Number the following rings of the chain with integers 1,2,...,n. We may put on and take off these rings according to the following rules:
.only one ring can be put on or taken off from the bar in one move,
.the ring number 1 can be always put on or taken off from the bar,
.if the rings with the numbers 1,...,k−1 (for 1<= k < n) are taken off from the bar and the ring number k is put on, we can put on or take off the ring number k+1.
Write a program which:
.reads from std input the description of the bytish chain,
.computes minimal number of moves necessary to take off all rings of the bytish chain from the bar,
.writes the result to std output.
Input

In the first line of the input there is written one integer n, 1 <= n <= 1000. In the second line there are written n integers o1,o2,...,on (each of them is either 0 or 1) separated by single spaces. If oi=1, then the i−th ring is put on the bar, and if oi=0, then the i−th ring is taken off the bar.
Output

The output should contain exactly one integer equal to the minimal number of moves necessary to take off all the rings of the bytish chain from the bar.
Sample Input

4
1 0 1 0
Sample Output

6
Source

POI 2001
*/

//using recursion to solve, however, the size can't be larger than 30, otherwise it would be slow

//AUTHOR: LIHAO
//VENUE: DORMITORY
//DATE: 17 MAY 2009
#include <iostream>
using namespace std;

__int64 moves = 0;
bool chain[1010];
int size;
void compute_move(int chain_num, bool status)
{
	if (chain_num < 0){
		return;
	}

	if (status == 0){
		if (chain_num == 0){
			if (chain[chain_num] == 0){
				return;
			}
			else{
				chain[chain_num] = 0;
				moves++;
				return;
			}
		}
		else{
			if (chain[chain_num] == 0){
				compute_move(chain_num - 1, 0);
			}
			else{
				compute_move(chain_num - 1, 1);
				compute_move(chain_num - 2, 0);
				chain[chain_num] = 0;
				moves++;
				compute_move(chain_num - 1, 0);
			}
		}
	}
	else{
		if (chain_num == 0){
			if (chain[chain_num] == 1){
				return;
			}
			else{
				chain[chain_num] = 1;
				moves++;
				return;
			}
		}
		else{
			if (chain[chain_num] == 1){
				return;
			}
			else{
				compute_move(chain_num - 1, 1);
				compute_move(chain_num - 2, 0);
				chain[chain_num] = 1;
				moves++;
			}
		}
	}
}

int main()
{
	cin >> size;
	for (int i = 0; i < size; i++){
		chain[i] = rand() % 2;
//		cin >> chain[i];
	}
	compute_move(size - 1, 0);
	cout << moves << endl;
}
