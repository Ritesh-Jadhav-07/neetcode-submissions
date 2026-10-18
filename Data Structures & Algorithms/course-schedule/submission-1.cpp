class Solution {
public:

    bool dfs(int node, vector<vector<int>>&adj , vector<int>&vis , vector<int>&path){
        vis[node] = 1;

        path[node] = 1;

        for(auto i : adj[node]){
            if(!vis[i]){
                if(!dfs(i , adj , vis , path)) return false;
            }else if (path[i] == 1) return false;
        }

        path[node] = 0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>vis(numCourses);
        vector<int>path(numCourses);

        for(auto i : prerequisites){
            adj[i[1]].push_back(i[0]);
        }

        for(int i = 0;i<numCourses;i++){
            if(!vis[i]){
                if(!dfs(i , adj , vis , path)) return false;
            }
        }

        return true;
    }
};
