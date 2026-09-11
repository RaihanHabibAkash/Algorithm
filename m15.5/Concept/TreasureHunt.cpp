#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int val[1005];
int weight[1005];

int treasure(int n, int mx_weight) {
    if(n < 0 || !mx_weight)
        return 0;
    if(dp[n][mx_weight] != -1)
        return dp[n][mx_weight];
    
    int option1 = -1;
    if(weight[n] <= mx_weight)
        option1 = treasure(n-1, mx_weight - weight[n]) + val[n];
    
    return dp[n][mx_weight] = max(option1, treasure(n-1, mx_weight));
}

int main() {
    int cs; cin >> cs;

    while(cs--) {
        int n, mx_weight; cin >> n >> mx_weight;
        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < n; i++)
            cin >> weight[i];
        for(int i = 0; i < n; i++)
            cin >> val[i];
        
        cout << treasure(n-1, mx_weight) << endl;
    }

    return 0;
}