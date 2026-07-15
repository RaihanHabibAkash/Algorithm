#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[100];
bool visited[100];
int level[100];

void bst(int srcNd) {
    queue<int> q;
    q.push(srcNd);
    visited[srcNd] = true;
    level[srcNd] = 0;

    while(!q.empty()) {
        int par = q.front();
        q.pop();

        for(int child : adj_list[par]) {
            if(!visited[child]) {
                q.push(child);
                visited[child] = true;
                level[child] = level[par] + 1;
            }
        }
    }
}

int main() {
    int nodes, edges; cin >> nodes >> edges;
    while(edges--) {
        int a, b; cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    
    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));

    bst(0);

    // Printing
    int lvl; cin >> lvl;
    vector<int> nums;
    for(int i = 0; i < nodes; i++)
        if(level[i] == lvl) nums.push_back(i);
    sort(nums.begin(), nums.end(), greater<int>());
    for(int num : nums) cout << num << " ";
    cout << endl;

    return 0;
}