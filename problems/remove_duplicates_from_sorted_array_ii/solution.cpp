class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2){
            return nums.size();
        }
        int p = 2;
        for(int i = 2;i<nums.size();i++){
            if(nums[i] != nums[p - 2]){
                nums[p] = nums[i];
                p++;
            }
        }
        return p;
    }
};