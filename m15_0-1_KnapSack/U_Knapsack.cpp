/*

U. Knapsack
time limit per test2 seconds
memory limit per test256 megabytes
There are N
 items numbered from 1 to N
. The ith
 item has a weight of wi
 and a value of vi
.

You have to choose some items out of the N
 items and carry them home in a knapsack. The capacity of the knapsack is W
 which donate the maximum weight that can be carried inside the knapsack. In other words, W
 means the total summation of all weights of items that can be carried in the knapsack.

Print maximum possible sum of values of items that you can take home.

Note: Solve this problem using recursion.

Input
First line contains two numbers N
 and W
 (1≤N≤20,1≤W≤100)
 number of items and the capacity of the knapsack.

Next N
 lines will contain two numbers wi
 and vi
 (1≤wi≤50,1≤vi≤1000)

Output
Print maximum possible sum of values of items that you can take home.

Examples
InputCopy
3 8
3 30
4 50
5 60
OutputCopy
90
InputCopy
6 15
6 5
5 6
6 4
6 6
3 5
7 2
OutputCopy
17
*/
// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/U
#include <bits/stdc++.h>
using namespace std;

int dp[25][105];
int val[25], weight[25];

int knapSack(int i, int max_weight) {
    if(i < 0 || !max_weight)
        return 0;
    if(dp[i][max_weight] != -1)
        return dp[i][max_weight];

    int option1 = -1, option2;

    if(weight[i] <= max_weight)
        option1 = knapSack(i-1, max_weight - weight[i]) + val[i];
    option2 = knapSack(i-1, max_weight);

    return dp[i][max_weight] = max(option1, option2);
}

int main() {
    int n, max_weight; cin >> n >> max_weight;
    memset(dp, -1, sizeof(dp));

    for(int i = 0; i < n; i++) {
        cin >> weight[i];
        cin >> val[i];
    }

    cout << knapSack(n-1, max_weight) << endl;

    return 0;
}