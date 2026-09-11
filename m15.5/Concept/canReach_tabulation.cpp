#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 5;

bool dp[N];

int main() {
    memset(dp, false, sizeof(dp));

    dp[1] = true;
    for(int i = 1; i < N; i++) { // N index a gele somossa 0->N-1
        if(dp[i] && i+5 < N)
            dp[i+5] = true;
        if(dp[i] && i*4 < N)
            dp[i*4] = true;
    }

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