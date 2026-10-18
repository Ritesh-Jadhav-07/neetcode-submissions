class Solution {
public:

    bool dfs(int node , vector<vector<int>>&adj , vector<int>&vis , vector<int>&path , stack<int>&st){
        vis[node] = 1;
        path[node] = 1;

        for(auto i : adj[node]){
            if(!vis[i]){
                if(!dfs(i , adj , vis , path , st)){
                    return false;
                }
            }
                else if(path[i] == 1) return false;
        }

        st.push(node);
        path[node] = 0;

        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>vis(numCourses);
        vector<int>path(numCourses);
        vector<int>ans;
        stack<int>st;
        for(auto i : prerequisites){
            adj[i[1]].push_back(i[0]);
        }

        for(int i = 0;i<numCourses;i++){
            if(!vis[i]){
                if(!dfs(i , adj , vis , path , st)){
                    return {};
                }
            }
            else if(path[i] == 1){
                    return {};
                }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
