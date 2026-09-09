/*
J. Factorial
time limit per test1 second
memory limit per test64 megabytes
Given a number N. Print factorial of N.

Note: Solve this problem using recursion.

Input
Only one line containing a number N (1 ≤ N ≤ 20).

Output
Print the factorial of the number N.

Example
InputCopy
5
OutputCopy
120
*/
// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/J
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll fact(int n) {
    if(n == 1)
        return 1;
    return n * fact(n - 1);
}

int main() {
    int n; cin >> n;
    cout << fact(n) << endl;

    return 0;
}