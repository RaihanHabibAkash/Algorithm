#include <bits/stdc++.h>
using namespace std;

int fibo(int n) { // O(2^N)
    if(n < 2)
        return n; // return 0 or 1 only
    return fibo(n-1) + fibo(n-2);
}

int main() {
    int n; cin >> n;
    cout << fibo(n) << endl;

    return 0;
}
