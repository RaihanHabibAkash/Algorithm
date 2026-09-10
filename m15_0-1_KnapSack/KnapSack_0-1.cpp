#include <bits/stdc++.h>
using namespace std;

int val[1005], weight[1005]; 

int knap_sack(int i, int max_weight) { // O(2^N)
    if(i < 0 || !max_weight)
        return 0;

    int option1 = -1, option2;

    // If there is enough space for it, 2 options. If not 1 option left(It will not update)
    if(weight[i] <= max_weight)
        option1 = knap_sack(i - 1, max_weight - weight[i]) + val[i];
    option2 = knap_sack(i - 1, max_weight);

    return  max(option1, option2);
}

int main() {
    int n, max_weight;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> val[i];
    for(int i = 0; i < n; i++)
        cin >> weight[i];

    cin >> max_weight;
    cout << knap_sack(n - 1, max_weight) << endl;

    return 0;
}
