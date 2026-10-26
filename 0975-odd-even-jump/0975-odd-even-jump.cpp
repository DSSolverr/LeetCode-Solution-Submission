class Solution {
public:
    void NGEEandNSEE(vector<int>& arr, vector<int>& nge, vector<int>& nse){
        int n=arr.size();

        multiset<pair<int,int>> st;

        for(int i=n-1; i>=0; i--){
            auto lb= st.lower_bound({arr[i], INT_MIN});
            auto prelb= lb;
            if(lb == st.end()) nge[i]=n;
            else{
                nge[i]=lb->second;
            }

            if(prelb == st.end()){
                if(st.size() == 0) nse[i]=n;
                else{
                    prelb--;
                    nse[i]=prelb->second;
                }
            }
            else{
                if(prelb->first == arr[i]){
                    prelb=st.upper_bound({arr[i], INT_MAX});
                    --prelb;
                    prelb=st.lower_bound({prelb->first, INT_MIN});
                    nse[i]=prelb->second;
                }
                else{
                    if(prelb == st.begin()) nse[i]=n;
                    else{
                        prelb--;
                        prelb= st.lower_bound({prelb->first, INT_MIN});
                        nse[i]=prelb->second;
                    }
                }
            }

            st.insert({arr[i], i});
        }
        
    }

    bool simulate(int idx, vector<int>& arr, auto& dp, auto& nse, auto& nge, bool even){
        
        if(idx == arr.size()-1) return true;
        int state = even ? 0 : 1;
        if(dp[idx][state] != -1) return dp[idx][state];
        

        if(even){
            if(nse[idx] == arr.size()) return dp[idx][state]=false;
            else return dp[idx][(even == true) ? 0 : 1] = simulate(nse[idx], arr, dp, nse, nge, !even);
        }
        else{
            if(nge[idx] == arr.size()) return dp[idx][state]= false;
            else return dp[idx][(even == true) ? 0 : 1] = simulate(nge[idx], arr, dp, nse, nge, !even);
        }
    }

    int oddEvenJumps(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        vector<int> nge(n), nse(n);
        NGEEandNSEE(arr, nge, nse);
        

        for(int i=0; i<arr.size(); i++){
            if(simulate(i, arr, dp, nse, nge, false)) ans++;
        }    
        return ans;
    }

};