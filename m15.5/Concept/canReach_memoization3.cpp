#include <bits/stdc++.h>
using namespace std;

int dp[100000 + 5];

bool can_reach(int n) {
    if(n == 1)
        return true;
    else if(n < 1)
        return false;
    
    if(dp[n] != -1)
        return dp[n];

    bool option2 = false;
    if(!(n % 4))
        option2 = can_reach(n / 4);
    
    return dp[n] = can_reach(n - 5) || option2;
}

int main() {
    int n; cin >> n;
    memset(dp, -1, sizeof(dp));

    if(can_reach(n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
