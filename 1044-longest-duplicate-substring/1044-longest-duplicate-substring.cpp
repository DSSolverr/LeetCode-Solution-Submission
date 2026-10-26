class Solution {
public:
    // Function to calculate rolling hash for substrings of given window length
    string rolling_hash(string& str, int& window){
        const long long multiplier=31; // Constant multiplier for hashing
        const long long mod=1000000007; // Modulus for hashing

        // Initialize the hash value for the first window
        long long hashedvalue=0;
        for(int i=0;i<window;i++){
            hashedvalue=(hashedvalue*multiplier+(str[i]-'a'+1))%mod;
        }

        // Precompute the power value to efficiently remove the contribution of the first character
        long long power=1;
        for(int i=1;i<window;i++){
            power=(power*multiplier)%mod;
        }

        // Map to store hash values and their corresponding indices
        unordered_map<long long,vector<int>> mp;
        hashedvalue%=mod;
        mp[hashedvalue].push_back(0);

        // Iterate through the string to calculate hash values for each window
        for(int i=1;i+window<=str.length();i++){
            // Remove the contribution of the first character and update the hash value
            hashedvalue-=((str[i-1]-'a'+1)*power);

            // Ensure hashed value is non-negative
            while(hashedvalue<0)    hashedvalue+=mod;
            hashedvalue%=mod;

            // Multiply by multiplier and add the contribution of the next character
            hashedvalue*=31;
            hashedvalue%=mod;
            hashedvalue+=(str[i+window-1]-'a'+1);
            hashedvalue%=mod;

            // If the hash value already exists in the map, check for potential duplicates
            if(mp.find(hashedvalue)!=mp.end())    {
                for(auto st: mp[hashedvalue]){
                    string old=str.substr(st,window);
                    string newstr=str.substr(i,window);
                    if(old==newstr) return newstr; // Return duplicated substring
                }
            }
            // Update the map with the current hash value and index
            mp[hashedvalue].push_back(i);
        }
        // Return empty string if no duplicated substring found
        return "";
    }

    // Main function to find the longest duplicated substring using binary search
    string longestDupSubstring(string str) {
        // Initialize the search range for binary search
        int s=1;
        int e=str.length()-1;
        string ans=""; // Initialize result

        // Perform binary search on the possible lengths of duplicated substrings
        while(s<=e){
            int mid=s+(e-s)/2; // Calculate mid length
            string temp=rolling_hash(str,mid); // Calculate duplicated substring of current length
            if(temp.length()>0){
                ans=temp; // Update result if duplicated substring found
                s=mid+1; // Narrow down the search range
            }
            else{
                e=mid-1; // Narrow down the search range
            }
        }
        // Return the longest duplicated substring found
        return ans;
    }
};