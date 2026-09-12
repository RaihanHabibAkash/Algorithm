#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int val[1005];

bool equal_sum(int i, int sum) {
    if(sum == 0)
        return true;
    else if(i < 0)
        return false;

    if(dp[i][sum] != -1)
        return dp[i][sum];
    
    bool option1 = false;
    if(val[i] <= sum)
        option1 = equal_sum(i-1, sum - val[i]);

    return dp[i][sum] = option1 || equal_sum(i-1, sum);
}

int main() {
    int n, sum = 0; cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> val[i];
        sum += val[i];    
    }

    if(sum % 2)
        cout << "NO" << endl;
    else {
        memset(dp, -1, sizeof(dp));
        cout << (equal_sum(n-1, sum/2) ? "YES" : "NO") << endl;
    }

    return 0;
}