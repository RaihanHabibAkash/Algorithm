#include <bits/stdc++.h>
using namespace std;

int val[1005];
int dp[1005][1005];

bool subSet_sum(int i, int sum) {
    if(sum == 0) // Base case added by me
        return true;
    else if(i < 0)
        return false;

    if(dp[i][sum] != -1)
        return dp[i][sum];

    bool option1 = false;
    if(val[i] <= sum)
        option1 = subSet_sum(i-1, sum - val[i]);

    return dp[i][sum] = option1 || subSet_sum(i-1, sum);
}

int main() {
    int n, sum; cin >> n >> sum;
    for(int i = 0; i < n; i++)
        cin >> val[i];

    // Setting value to -1 default
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= sum; j++)
            dp[i][j] = -1;

    cout << (subSet_sum(n-1, sum) ? "YES" : "NO") << endl;

    return 0;
}