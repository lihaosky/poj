[25%] Coin game: Alice and Bob are playing a game using a bunch of coins. The players
pick several coins out of the bunch in turn. Each time a player is allowed to pick 1, 2 or 4
coins, and the player that gets the last coin is the winner. Assume that both players are
very smart and he/she will try his/her best to work out a strategy to win the game. For
example, if there are 2 coins and Alice is the rst player to pick, she will denitely pick 2
coins and win. If there are 3 coins and Alice is still the rst player to pick, no matter she
picks 1 or 2 coins, Bob will get the last coin and win the game.
Given the number of coins and the order of players (which means the rst and the second
players to pick the coins), you are required to write a program pickcoin.cpp to calculate
the winner of the game, and calculate how many dierent strategies there are for he/she
to win the game. You should use recursion to solve the problem, and the parameters are
read from the command line. You can assume that there are no more than 30 coins.
1
Here are some sample runs of the program:
[tmchan@localhost ~/c1122/a2]$./pickcoin 1 alice bob
alice 1
[tmchan@localhost ~/c1122/a2]$./pickcoin 2 bob alice
bob 1
[tmchan@localhost ~/c1122/a2]$./pickcoin 3 alice bob
bob 2
[tmchan@localhost ~/c1122/a2]$./pickcoin 10 alice bob
alice 22
[tmchan@localhost ~/c1122/a2]$./pickcoin 25 alice bob
alice 3344
[tmchan@localhost ~/c1122/a2]$./pickcoin 30 alice bob
bob 18272
