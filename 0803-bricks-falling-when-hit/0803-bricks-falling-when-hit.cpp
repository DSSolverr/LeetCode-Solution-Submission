class Solution {
public:
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,1,-1};
    #define vi vector<int>
    #define vvi vector<vector<int>>
struct DSU {
    vi parent, sz;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        sz.assign(n, 1);
    }
    int find(int i){
        if(parent[i]==i) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (sz[root_i] < sz[root_j]) swap(root_i, root_j);
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];
        }
    }
};
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int n=grid.size(),m=grid[0].size();
        vvi curg=grid;
        for(auto &h:hits){
            curg[h[0]][h[1]]=0;
        }
        DSU dsu(n*m+1);
        auto id=[&](int i,int j){
            return i*m+j;
        };
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(curg[i][j]==1){
                int idx=id(i,j);
                if(i==0){
                    dsu.unite(idx,n*m);
                }
                if(i+1<n and curg[i+1][j]==1){
                    dsu.unite(idx,id(i+1,j));
                }
                if(j+1<m and curg[i][j+1]==1){
                    dsu.unite(idx,id(i,j+1));
                }
               }
           }
        }
        vi res(hits.size());
        for(int k=hits.size()-1;k>=0;k--){
            int hr=hits[k][0],hc=hits[k][1];
            if(grid[hr][hc]==0){
                res[k]=0;continue;
            }
            int ind=id(hr,hc);
            int prv=dsu.sz[dsu.find(n*m)];
            if(hr==0){
                dsu.unite(ind,n*m);
            }
            for(int i=0;i<4;i++){
                int nr=hr+dr[i];
                int nc=hc+dc[i];
                if(nr>=0 and nr<n and nc>=0 and nc<m and curg[nr][nc]==1){
                    dsu.unite(ind,id(nr,nc));
                }
            }
            curg[hr][hc]=1;
            int cursz=dsu.sz[dsu.find(n*m)];;
            if(dsu.find(ind)==dsu.find(n*m)){
                res[k]=max(0,cursz-prv-1);
            }
            else res[k]=0;
        }
        return res;
    }
};