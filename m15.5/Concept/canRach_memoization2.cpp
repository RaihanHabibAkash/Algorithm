#include <bits/stdc++.h>
using namespace std;

int dp[100000 + 5];

void can_reach(int i) {
    if(i > 100000)
        return;
    if(dp[i] != -1)
        return;
      
    dp[i] = true;
    can_reach(i + 5);
    can_reach(i * 4);
}

int main() {
    memset(dp, -1, sizeof(dp));
    can_reach(1);

    int cs; cin >> cs;
    while(cs--) {
        int n; cin >> n;
        if(dp[n] == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}