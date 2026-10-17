class Solution {
public:
    int cnt = 0;
    int maxi = 0;
    void dfs(int i , int j , vector<vector<int>>& grid ){
        grid[i][j] = 2;
        cnt++;
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};

        for(int k = 0;k<4;k++){
            int ni = i + dx[k];
            int nj = j + dy[k];

            if( ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && grid[ni][nj] == 1){
                
                dfs(ni , nj , grid );
            }
        }

        
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    
                cnt = 0;
                    dfs(i,j,grid);
                maxi = max(cnt , maxi);
                }
            }
        }

        return maxi;
    }
};
