/*
The Tetranacci sequence is an extension of the well-known Fibonacci sequence, incorporating four previous terms instead of two.

The Tetranacci sequence Tn is defined as follows:

T0 = 0, T1 = 1, T2 = 1,T3 = 2
For  , Tn = Tn-1 + Tn-2 + Tn-3 + Tn-4
Given an integer 𝑛, return the value of Tn

Note : You must solve this problem using Recursion. (Top Down)

Input Format

A single integer n representing the position in the Tetranacci sequence.

Constraints

The result is guaranteed to fit within a 32-bit integer (  231-1 )
Output Format

Print a single integer, the value of Tn

Sample Input 0

4
Sample Output 0

4
Explanation 0

image

Sample Input 1

5
Sample Output 1

8
Explanation 1

image
*/
// https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-06/challenges/tetranacci-number-a-easy-version/
#include <bits/stdc++.h>
using namespace std;

int dp[35];

int tetra(int n) {
    if(n == 0)
        return 0;
    else if(n <= 2) // 1,2
        return 1;
    else if(n == 3)
        return 2;

    if(dp[n] != -1)
        return dp[n];

    return dp[n] = tetra(n-1) + tetra(n-2) + tetra(n-3) + tetra(n-4); 
}

int main() {
    memset(dp, -1, sizeof(dp));
    int n; cin >> n;
    cout << tetra(n) << endl;

    return 0;
}