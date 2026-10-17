class Solution {
public:
    int bfs(int r,int c,int nr,int nc,vector<vector<int>>& forest) {
        if(r==nr && c==nc) return 0; 
        int m=forest.size();
        int n=forest[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{r,c}});
        vis[r][c]=1;
        int row[4]={1,-1,0,0};
        int col[4]={0,0,1,-1};
        while(!q.empty()) {
            auto [count,p]=q.front();
            q.pop();
            int a=p.first;
            int b=p.second;
            for(int i=0;i<4;i++) {
                int na=a+row[i];
                int nb=b+col[i];
                if(na>=0 && nb>=0 && na<m && nb<n && !vis[na][nb] && forest[na][nb]!=0) {
                    if(na==nr && nb==nc) return count+1;
                    vis[na][nb]=1;
                    q.push({count+1,{na,nb}});
                }
            }
        }
        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {
        int m=forest.size();
        int n=forest[0].size();
        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(forest[i][j]>1) {
                    v.push_back({forest[i][j],{i,j}});
                }
            }
        }
        sort(v.begin(),v.end());
        int count=0;
        int r=0,c=0;
        for(auto& t:v) {
            int nr=t.second.first;
            int nc=t.second.second;
            int dis=bfs(r,c,nr,nc,forest);
            if(dis==-1) return -1;
            count+=dis;
            r=nr;
            c=nc; 
        }
        return count;
    }
};