class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        vector<int> arr(256,-1);
        int longest_substring = 0;
        int i = 0;
        int j = 0;
        while(j < s.size()){
            if(arr[s[j]] != -1 && arr[s[j]] >= i){
                i = arr[s[j]] + 1;
            }

            arr[s[j]] = j;

            longest_substring = max(longest_substring,j - i + 1);
            j++;
        }
        return longest_substring;
    }
};