class Solution {
public:
    bool canJump(vector<int>& arr) {
        int max_reach = 0;
        for(int i = 0;i < arr.size();i++){
            int current_reach = arr[i] + i;
            max_reach = max(current_reach,max_reach);
            if(max_reach >= arr.size() - 1){
                return true;
            }
            if(max_reach == i){
                return false;
            }
        }
        return true;
    }
};