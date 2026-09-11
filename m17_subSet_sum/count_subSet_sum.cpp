#include <bits/stdc++.h>
using namespace std;

int val[1005];
int dp[1005][1005];

int subSet_sum(int i, int sum) {
    if(sum == 0)
        return 1;
    else if(i < 0)
        return 0;
    
    if(dp[i][sum] != -1)
        return dp[i][sum];

    int option1 = 0;
    if(val[i] <= sum)
        option1 = subSet_sum(i-1, sum - val[i]);

    return dp[i][sum] = option1 + subSet_sum(i-1, sum);
}

int main() {
    int n, sum; cin >> n >> sum;
    for(int i = 0; i < n; i++)
        cin >> val[i];

    // Setting value to -1 default
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= sum; j++)
            dp[i][j] = -1;

    cout << subSet_sum(n-1, sum) << endl;

    return 0;
}