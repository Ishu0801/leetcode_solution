class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mpp;
        for(auto s:strs){
            string p = s;
            sort(p.begin(),p.end());
            mpp[p].push_back(s);
        }
        ans.reserve(mpp.size());
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};