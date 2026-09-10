#include <bits/stdc++.h>
using namespace std;

int val[1005], weight[1005];
int dp[1005][1005];

int knap_sack(int i, int max_weight) { // O(Max_Index * Max Weight)
    if(i < 0 || !max_weight)
        return 0;
    if(dp[i][max_weight] != -1)
        return dp[i][max_weight];

    int option1 = -1, option2;

    if(max_weight >= weight[i])
        option1 = knap_sack(i - 1, max_weight - weight[i]) + val[i];
    option2 = knap_sack(i - 1, max_weight);

    return dp[i][max_weight] = max(option1, option2);
}

int main() {
    int n, max_weight; cin >> n;

    for(int i = 0; i < n; i++)
        cin >> val[i];
    for(int i = 0; i < n; i++)
        cin >> weight[i];

    cin >> max_weight;

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= max_weight; j++)
            dp[i][j] = -1;

    cout << knap_sack(n - 1, max_weight) << endl;

    return 0;
}