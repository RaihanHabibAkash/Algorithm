/*
Pile of Word is a word formed by rearranging the letters of another word, using all the original letters exactly once. In other words, it involves creating a new word by rearranging the characters of a given word. It is possible that after rearranging it looks like the original one.

You will be given two strings  and . You need to determine if the strings are Pile of Word of each other.

Input Format

First line will contain , the number of test cases.
Each line of the test case will contain  and  separated by a space. The string will contain Enlish small alphabets only.
Constraints

. Here || means the length of string.
Output Format

Ouptut  if the strings are Pile of Word to each other,  otherwise.
Sample Input 0

4
eat tea
madam madam
ball all
ant tan
Sample Output 0

YES
YES
NO
YES
*/
// https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-06/challenges/pile-of-word-37-3/
#include <bits/stdc++.h>
using namespace std;

int vis[26];

int main() {
    int cs; cin >> cs;
    while(cs--) {
        string s1, s2; cin >> s1 >> s2;
        memset(vis, 0, sizeof(vis));
        bool flag = true;

        // Storeing the char in vis
        for(char x : s1)
            vis[x -'a']++;

        // Checking with 2 string
        for(char x : s2) {
            if(!vis[x -'a'])
                flag = false;
            else
                vis[x-'a']--;
        }

        // If array any char is still 1 or more, means extra value
        for(int i = 0; i < 26; i++)
            if(vis[i])
                flag = false;

        cout << (flag ? "YES" : "NO") << endl;
    }

    return 0;
}