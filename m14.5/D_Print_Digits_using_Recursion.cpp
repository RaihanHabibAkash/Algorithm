/*
D. Print Digits using Recursion
time limit per test1 second
memory limit per test256 megabytes
Given a number N. Print the digits of N separated by a space.

Note: Solve this problem using recursion.

Input
First line contains a number T (1 ≤ T ≤ 10) number of test cases.

Next T lines will contain a number N (0 ≤ N ≤ 109).

Output
For each test case print a single line contains the digits of the number separated by space.

Example
InputCopy
3
121
39
123456
OutputCopy
1 2 1 
3 9 
1 2 3 4 5 6 
*/
// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/D
#include <bits/stdc++.h>
using namespace std;

void prin(int n) {
    if(n == 0)
        return;
    
    prin(n / 10);

    cout << n % 10 << " ";
}

int main() {
    int cs; cin >> cs;
    while(cs--) {
        int n; cin >> n;
        if(!n)
            cout << 0;
        else
            prin(n);
        cout << endl;
    }

    return 0;
}