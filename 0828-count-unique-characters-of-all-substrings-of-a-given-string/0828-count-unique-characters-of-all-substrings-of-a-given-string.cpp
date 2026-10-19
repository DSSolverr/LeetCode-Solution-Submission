class Solution {
public:
    int uniqueLetterString(string s) {

      int n=s.size();
      long long ct=0;
      unordered_map<int,vector<int>>mp;
      for(int i=0;i<n;i++){
        mp[s[i]].push_back(i);
      }

      for(auto it:mp){
        
        for(int j=0;j<it.second.size();j++){
            int x=it.second[j];

            int prev=(j==0)?-1:it.second[j-1];
            int nxt=(j==it.second.size()-1)?n:it.second[j+1];

            ct+=(x-prev)*(nxt-x);
        }
      }


return ct;

    }
};