#include <bits/stdc++.h>
using namespace std;

int dp[100000 + 5];

bool can_reach(int steps, int target) {
    if(steps == target)
        return true;
    else if(steps > target)
        return false;

    if(dp[steps] != -1)
        return dp[steps];
      
    return dp[steps] = can_reach(steps + 5, target) || can_reach(steps  * 4, target);
}

int main() {
    memset(dp, -1, sizeof(dp));

    int n; cin >> n;
    if(can_reach(1, n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
