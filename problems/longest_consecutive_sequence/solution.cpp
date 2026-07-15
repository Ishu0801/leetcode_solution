class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        if(nums.empty()){
            return 0;
        }
        int longest = 1;
        for(auto el:nums){
            st.insert(el);
        }

        for(auto it:st){
            if(st.find(it -1) == st.end()){
                int x = it;
                int count = 1;
                while(st.find(x + 1) != st.end()){
                    x++;
                    count++;
                }
                longest = max(longest,count);
            }
        }

        return longest;
    }
};