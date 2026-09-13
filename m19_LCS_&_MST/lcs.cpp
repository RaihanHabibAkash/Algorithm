// LCS --> Longest Common SubSequence

#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int dp[1005][1005];

int Lcs(int i, int j) {
    if(i < 0 || j < 0) return 0;

    if(dp[i][j] != -1) return dp[i][j]; 

    if(s1[i] == s2[j]) 
        return dp[i][j] = Lcs(i-1, j-1) + 1; // SubSequence found
    else 
        return dp[i][j] = max(Lcs(i-1, j), Lcs(i, j-1));
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> s1 >> s2;

    cout << Lcs(s1.size()-1, s2.size()-1) << endl;
    
    return 0;
}