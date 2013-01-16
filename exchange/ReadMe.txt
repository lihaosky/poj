/*Exchange Rates
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 1457		Accepted: 465

Description

Now that the Loonie is hovering about par with the Greenback, you have decided to use your $1000 entrance scholarship to engage in currency speculation. So you gaze into a crystal ball which predicts the closing exchange rate between Canadian and U.S. dollars for each of the next several days. On any given day, you can switch all of your money from Canadian to U.S. dollars, or vice versa, at the prevailing exchange rate, less a 3% commission, less any fraction of a cent.

Assuming your crystal ball is correct, what's the maximum amount of money you can have, in Canadian dollars, when you're done?

Input

The input contains a number of test cases, followed by a line containing 0. Each test case begins with 0 < d ¡Ü 365, the number of days that your crystal ball can predict. d lines follow, giving the price of a U.S. dollar in Canadian dollars, as a real number.

Output
For each test case, output a line giving the maximum amount of money, in Canadian dollars and cents, that it is possible to have at the end of the last prediction, assuming you may exchange money on any subset of the predicted days, in order.

Sample Input

3
1.0500
0.9300
0.9900
2
1.0500
1.1000
0

Sample Output

1001.60
1000.00
*/
//using dp to solve it store dollar and canadian dollar respectively and 
//on a new day search for the largest amount of dollar previous, change it to 
//canadian dollar present and see if it is bigger than last day. In this way,
//we can guarantee that each day we have the largest amount of canadian dollar~~