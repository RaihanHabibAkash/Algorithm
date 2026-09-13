#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int val[1005];
int weight[1005];

int unbounded_knapSack(int i, int mx_weight) {
    if(i < 0 || !mx_weight) return 0;
    
    if(dp[i][mx_weight] != -1) return dp[i][mx_weight];

    int option1 = -1;
    if(weight[i] <= mx_weight)
        option1 = unbounded_knapSack(i, mx_weight - weight[i]) + val[i];
        
    return dp[i][mx_weight] = max(option1, unbounded_knapSack(i-1, mx_weight));
}

int main() {
    int n, mx_weight; cin >> n >> mx_weight;
    memset(dp, -1, sizeof(dp));

    for(int i = 0; i < n; i++)
        cin >> val[i];
    for(int i = 0; i < n; i++)
        cin >> weight[i];

    cout << unbounded_knapSack(n-1, mx_weight) << endl;

    return 0;
}