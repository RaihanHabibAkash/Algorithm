/*
Once upon a time, there was a treasure hunter who ventured into an ancient temple in search of a valuable artifact. The temple was filled with traps and obstacles, and the treasure hunter had to carry all of his equipment with him.

The treasure hunter had a backpack with a limited weight capacity, and he could only carry a certain amount of equipment with him. Each piece of equipment had its own weight and value, and the treasure hunter needed to choose which items to bring to maximize the total value while keeping the total weight under the limit.

Help the treasure hunter to choose which items to bring in his backpack to maximize their total value while keeping the total weight of his backpack under a certain limit. Each item can only be included once.

Input Format

First line will contain , the number of test cases.
The first line of each test case will contain (Number of items) and (Total weight of backpack).
Second line of each test case will contain an array  containing the weights of all items.
Third line of each test case will contain an array  containting the values of all items.
Constraints

; Here 
; Here 
Output Format

Output the maximum total value you can obtain in the backpack for each test case.
Sample Input 0

2
4 7
2 3 4 5
4 7 6 5
4 17
10 1 6 9
6 10 10 8
Sample Output 0

13
28
Explanation 0

In the first test case case, he can take 2nd and 3rd item which total weight is 3+4=7 and total value 
*/
// https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-06/challenges/adventure-1/
#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int weight[1005];
int val[1005];

int mx_store(int n, int mx_weight) {
    if(n < 0 || !mx_weight)
        return 0;
    if(dp[n][mx_weight] != -1)
        return dp[n][mx_weight];

    int option1 = -1;
    if(weight[n] <= mx_weight)
        option1 = mx_store(n-1, mx_weight - weight[n]) + val[n];
    
    return dp[n][mx_weight] = max(option1, mx_store(n-1, mx_weight));
}

int main() {
    int cs; cin >> cs;
    while(cs--) {
        memset(dp, -1, sizeof(dp));
        int n, mx_weight; cin >> n >> mx_weight;
        
        for(int i = 0; i < n; i++)
            cin >> weight[i];
        for(int i = 0; i < n; i++)
            cin >> val[i];

        cout << mx_store(n-1, mx_weight) << endl;
    }
    return 0;
}