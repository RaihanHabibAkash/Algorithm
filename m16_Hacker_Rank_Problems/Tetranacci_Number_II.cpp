/*
The Tetranacci sequence is an extension of the well-known Fibonacci sequence, incorporating four previous terms instead of two.

The Tetranacci sequence Tn is defined as follows:

T0 = 0, T1 = 1, T2 = 1,T3 = 2
For  , Tn = Tn-1 + Tn-2 + Tn-3 + Tn-4
Given an integer 𝑛, return the value of Tn

Note : You must solve this problem using Loop. (Bottom up)

Input Format

A single integer n representing the position in the Tetranacci sequence.

Constraints

The result is guaranteed to fit within a 64-bit integer (  263-1 )
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
// https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-06/challenges/tetranacci-number/
#include <bits/stdc++.h>
using namespace std;

long long dp[65];

int main() {
    int n; cin >> n;

    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;

    for(int i = 4; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4];

    cout << dp[n] << endl;

    return 0;
}