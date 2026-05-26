class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int count = 1;
        int num = nums[0];
        int i=0;
        while(i<nums.size()){
            if(num == nums[i]){
                if(count>k){
                    nums.erase(nums.begin()+i);
                    i--;
                }
                count++;
                i++;
            }
            else{
                count = 1;
                num = nums[i];
            }
        }
        return nums;
    }
};