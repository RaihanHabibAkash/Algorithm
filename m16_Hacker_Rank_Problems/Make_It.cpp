/*
You will be given a positive integer . You will start from  and do some steps (possibly zero).

In each step you can choose one of the following:

Add  with the current value
Multiply by  with the current value
Can you tell if you can reach  by using any number of steps you want.

Input Format

First line will contain , the number of test cases.
In each test case you will be given .
Constraints

Output Format

Print "YES" if you can reach , "NO" otherwise.
Sample Input 0

5
1
3
5
15
16
Sample Output 0

YES
NO
YES
NO
YES
*/
// https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-06/challenges/make-it-2/
#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 5;

bool dp[N];

void can_make(int i) {
    if(i >= N)
        return;

    if(dp[i])
        return;
    
    dp[i] = true;

    can_make(i + 3);
    can_make(i * 2);
}

int main() {
    memset(dp, false, sizeof(dp));
    can_make(1);

    int cs; cin >> cs;
    while(cs--) {
        int n; cin >> n;
        if(dp[n])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}