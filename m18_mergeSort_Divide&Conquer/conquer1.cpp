#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int a[n], b[m], c[n+m];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    // Main part
    int l = 0, r = 0, cur = 0;
    while(l < n && r < m) {
        if(a[l] <= b[r]) c[cur++] = a[l++];
        else c[cur++] = b[r++];
    }

    // Kono 1ta Array ar value insert baki thakle
    while(l < n) c[cur++] = a[l++];
    while(r < m) c[cur++] = b[r++];


    // Printing
    for(int i = 0; i < n+m; i++) cout << c[i] << " ";
    cout << endl;

    return 0;
}