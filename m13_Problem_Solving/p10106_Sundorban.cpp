/*
Sundorban

Time Limit: 1 sec

 

The Problem

The Sundarbans mangrove forest, one of the largest such forests in the world (140,000 ha), lies on the delta of the Ganges, Brahmaputra and Meghna rivers on the Bay of Bengal. It is adjacent to the border of India’s Sundarbans World Heritage site inscribed in 1987.

Suppose you lost in a dense area of Sundorban and it is getting dark. There is at least one path that leads you to the city on the other side but you cannot see anything until you are right in front of it as the trees and bushes obscure the path.

 

Now find a way .Your goal is to go out of the jungle as fast as you can before it gets dark.

 

The Input
Input start with a number N and then the matrix of size N x N filled with S, E, T, and P which is our map. Map contains a single S representing the start point, and single E representing the endpoint and P representing the path and T representing the Tree. Input is terminated by EOF.

 

The Output
For each input set output single integer i.e. minimum number of moves from S to E.

 

Assumptions:
You can assume that the maps would be in square form and can be up to a maximum size of 30X30. You can move in four directions North East West South.
You can move in any direction when you find P but cannot move to a point where a T is present.

 

Sample Input

5

S P P P P

T P T P P

T P P P P

P T E T T

P T P T T

 

Sample Output

5
*/
// https://school.outsbook.com/problems/problemdetails/10106
#include <bits/stdc++.h>
using namespace std;

char grid[35][35];
int lvl[35][35];
bool vis[35][35];
vector< pair<int,int> > mv;
int n;

bool valid(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= n)
        return false;
    return true;
}

void bfs(int si, int sj) {
    queue< pair<int,int> > q;
    lvl[si][sj] = 0;
    vis[si][sj] = true;
    q.push({si, sj});

    while(!q.empty()) {
        int pi = q.front().first,
            pj = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int ci = pi + mv[i].first,
                cj = pj + mv[i].second;

            if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != 'T') {
                q.push({ci, cj});
                vis[ci][cj] = true;
                lvl[ci][cj] = lvl[pi][pj] + 1;
            }
        }
    }
}

int main() {
    mv.push_back({-1,0});
    mv.push_back({1,0});
    mv.push_back({0,-1});
    mv.push_back({0,1});

    while(cin >> n) {
        int si, sj, di, dj;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                cin >> grid[i][j];

                if(grid[i][j] == 'S') {
                    si = i;
                    sj = j;
                }

                if(grid[i][j] == 'E') {
                    di = i;
                    dj = j;
                }

                lvl[i][j] = -1;
                vis[i][j] = false;
            }

            bfs(si, sj);
            cout << lvl[di][dj] << endl;
    }

    return 0;
}
