#include <bits/stdc++.h>
using namespace std;

bool dp[100000 + 5];

void can_reach(int i) {
    if(i > 100000)
        return;
    if(dp[i])
        return;
      
    dp[i] = true;
    can_reach(i + 5);
    can_reach(i * 4);
}

int main() {
    memset(dp, false, sizeof(dp));
    can_reach(1);

    int cs; cin >> cs;
    while(cs--) {
        int n; cin >> n;
        if(dp[n])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}