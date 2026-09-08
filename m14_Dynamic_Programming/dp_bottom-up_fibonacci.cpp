#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n; cin >> n;
    ll dp[n+1]; // O theke shuru

    // Default value set
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2]; // memoization

    cout << dp[n] << endl;

    return 0;
}
