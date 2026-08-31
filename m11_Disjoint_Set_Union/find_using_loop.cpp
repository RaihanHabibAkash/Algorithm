#include <bits/stdc++.h>
using namespace std;

int leader[1005];

int find(int node) { // O(N)
    while(leader[node] != -1)
        node = leader[node];

    return node;
}

int main() {
    memset(leader, -1, sizeof(leader));

    // Don't need to set mannualy again
    leader[0] = 1;
    leader[1] = -1;
    leader[2] = 1;
    leader[3] = 1;
    leader[4] = 5;
    leader[5] = 3;
    // 0,2--> 1 <--3 <--5 <--4

    cout << find(4) << endl;

    return 0;
}
