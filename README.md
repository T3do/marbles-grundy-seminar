# Seminar Imaprtial Game Theory

## Problem
B. Marbles
time limit per test0.5 seconds
memory limit per test1024 megabytes
Using marbles as a currency didn't go so well in Cubicônia. In an attempt to make it up to his friends after stealing their marbles, the Emperor decided to invite them to a game night in his palace.

Of course, the game uses marbles, since the Emperor needs to find some use for so many of them. N
 marbles are scattered in a board whose lines are numbered from 0
 through L
 and the columns numbered from 0
 through C
. Players alternate turns. In his turn, a player must choose one of the marbles and move it. The first player to move a marble to position (0,0)
 is the winner. The movements are limited so the game could be more interesting; otherwise, the first player could just move a marble to position (0,0)
 and win. A movement consists in choosing an integer u
 greater than 0
 and a ball, whose location is denoted by (l,c)
, and move it to one of the following positions, as long as it is inside the board:

(l−u,c)
 or;
(l,c−u)
 or;
(l−u,c−u)
.
Note that more than one marble can occupy the same position on the board.

As the Emperor doesn't like to lose, you should help him determine which games he should attend. Also, as expected, the Emperor always take the first turn when playing. Assuming both players act optimally, you are given the initial distribution of the marbles, and should find if it is possible for the Emperor to win if he chooses to play.

Input
The first line contains an integer N (1≤N≤1000). 
Each of the following N rows contains two integers li and ci indicating on which row and column the i-th marble is in (1≤li,ci≤100).

Output
Your program should print a single line containing the character Y if it is possible for the Emperor to win the game or N otherwise.

Examples
E1
2
1 3
2 3

Y

E2
1
1 2

N

## Idea
- Model as impartial game
- Compute Grundy numbers / mex using DP
- XOR to decide winner