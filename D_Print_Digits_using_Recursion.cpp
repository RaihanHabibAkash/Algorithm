#include <bits/stdc++.h>
using namespace std;

void prin(int n) {
    if(n == 0)
        return;
    
    prin(n / 10);

    cout << n % 10 << " ";
}

int main() {
    int cs; cin >> cs;
    while(cs--) {
        int n; cin >> n;
        if(!n)
            cout << 0;
        else
            prin(n);
        cout << endl;
    }

    return 0;
}