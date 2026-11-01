class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), moves = 0;
        vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(2, 0)));
        queue<array<int,3>> q;
        q.push({0,0,0}); //{i,j,dir} dir = (0 -> right, 1 -> down)
        vis[0][0][0] = 1;

        auto rightMove = [&](int i, int j, int dir) {
             if(dir==0) {
                return (j<m-2 and grid[i][j+2]==0);
             } 
             if(i<n-1 and j<m-1 and grid[i][j+1]==0 and grid[i+1][j+1]==0) return true;
             return false;
        };
        auto downMove = [&](int i, int j, int dir) {
             if(dir==1) {
                return (i<n-2 and grid[i+2][j]==0);
             } 
             if(i<n-1 and j<m-1 and grid[i+1][j]==0 and grid[i+1][j+1]==0) return true;
             return false;
        };

        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                array<int,3> a = q.front();
                q.pop();

                int i = a[0], j = a[1], dir = a[2];

                // cout<<i<<" "<<j<<" "<<dir<<" : "<<moves<<endl;
                if(i==n-1 and j==m-2 and dir==0) return moves;

                if(rightMove(i,j,dir) and !vis[i][j+1][dir]) { //move right
                    vis[i][j+1][dir] = 1;
                    q.push({i, j+1, dir});
                }
                if(downMove(i,j,dir) and !vis[i+1][j][dir]) { //move down
                    vis[i+1][j][dir] = 1;
                    q.push({i+1, j, dir});
                }
                if(i<n-1 and j<m-1 and dir==0 and grid[i+1][j]==0 and grid[i+1][j+1]==0 and !vis[i][j][1]) { //change dir from right to down (clockwise)
                    vis[i][j][1] = 1;
                    q.push({i, j, 1});
                }
                if(j<m-1 and i<n-1 and dir==1 and grid[i][j+1]==0 and grid[i+1][j+1]==0 and !vis[i][j][0]) { //change dir from down to right (anti-clockwise)
                    vis[i][j][0] = 1;
                    q.push({i, j, 0});
                }
            }
            moves++;
        }
        return -1;
    }
};