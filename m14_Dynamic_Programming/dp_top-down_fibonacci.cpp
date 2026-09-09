#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[1005];

ll fibo(int n) { // O(N)
    if(n < 2)
        return n; // always return 0 or 1

    if(dp[n] != -1)
        return dp[n];

    return dp[n] = fibo(n-1) + fibo(n-2); // memoization
}

int main() {
    int n; cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << fibo(n) << endl;

    return 0;
}
