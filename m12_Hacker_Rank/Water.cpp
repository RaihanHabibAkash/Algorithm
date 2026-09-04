/*
You are given an array  representing the heights of  vertical lines positioned at equally spaced intervals along a two-dimensional plane. The -th line's height is represented by the integer  where  and the height will be unique.

You need to find the two lines, such that together with the x-axis forms a container that can hold the most water in term of height.

Note: Print the left index first, then the right index.

Input Format

First line will contain , the number of test cases.
First line of each test case will contain .
Second line of each test case will contain the array .
Constraints

Output Format

Ouptut two integers, the index of those two lines that can contain the most water in term of height.
Sample Input 0

2
9
1 8 3 4 0 7 6 5 2
5
5 2 1 6 3
Sample Output 0

1 5
0 3
Explanation 0

In the first test case, you can choose index 1 and 5 that can hold the most water in height which is 7.
image
*/
// https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-06/challenges/water-4-1/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int cs; cin >> cs;

    while(cs--) {
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        int lar1 = -1,
            lar2 = -1,
            idx1, idx2;

        for(int i = 0; i < n; i++) {
            if(arr[i] > lar1) {
                lar2 = lar1;
                idx2 = idx1;

                lar1 = arr[i];
                idx1 = i;
            }
            else if(arr[i] > lar2) {
                lar2 = arr[i];
                idx2 = i;
            }
        }

        cout << min(idx1, idx2) << " " << max(idx1, idx2) << endl;
    }

    return 0;
}