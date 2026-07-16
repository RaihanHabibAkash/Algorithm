class Solution {
public:
bool visited[3005];
    void bfs(vector<vector<int>>& rooms, int srcNd) {
        queue<int> q;
        q.push(srcNd);
        visited[srcNd] = true;

        while(!q.empty()) {
            int par = q.front();
            q.pop();

            for(int child : rooms[par]) {
                if(!visited[child]) {
                    q.push(child);
                    visited[child] = true;
                }
            }

        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        bfs(rooms, 0);

        for(int i = 0; i < rooms.size(); i++)
            if(!visited[i]) return false;
            
        return true;        
    }
};