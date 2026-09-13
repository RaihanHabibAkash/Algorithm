#include <bits/stdc++.h>
using namespace std;

int val[1005];

bool subSet_sum(int i, int sum) { // O(2^N)
    if(i < 0) { // Base case from phitron
        if(sum == 0)
            return true;
        else
            return false;
    }

    bool option1 = false;
    if(val[i] <= sum)
        option1 = subSet_sum(i-1, sum - val[i]);
    
    return option1 || subSet_sum(i-1, sum);
}

int main() {
    int n, sum; cin >> n >> sum;
    for(int i = 0; i < n; i++)
        cin >> val[i];

    cout << (subSet_sum(n-1, sum) ? "YES" : "NO") << endl;

    return 0;
}