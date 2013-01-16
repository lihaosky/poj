Travel Games
Time Limit: 3000MS  Memory Limit: 65536K 
Total Submissions: 1661  Accepted: 577 

Description

The cows are taking a trip to the lakes in Minnesota. Like everyone else, they are bored and are playing "travel games" to pass the time away. 

In this travel game, the first cow thinks of a three letter word from the Sacred Travel Game Dictionary (STGD). The next cow in line must add a letter to the word (at the beginning, between two letters, or at the end) to make another word in the STGD. The cows are curious as to just how big the final word can be. 

Given a dictionary of D (1 <= D <= 1000) words and a starting word, find any of the longest possible words that can be formed playing this travel game. 

Input

* Line 1: The integer D followed by a space followed by a legal three letter word. 

* Line 2 through D+1: Each line contains a legal word no longer than 80 characters, consisting only of lowercase letters, from the STGD. 

Output

A single line with the longest word that can be formed by extending the input seed. 
The input ensure the correct result will be unique.
Sample Input

9 cal
cal
calf
calfs
call
calls
choral
chorale
coal
coral

Sample Output

chorale

Hint

[From the sequence: cal, coal, coral, choral, chorale]
Source

USACO 2003 February Orange