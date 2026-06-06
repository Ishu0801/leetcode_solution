class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int j = 0;
        int max_sum = nums[0];
        int sum = 0;
        while(j < nums.size()){
            sum += nums[j];
            max_sum = max(max_sum,sum);
            if(sum < 0 ){
                sum = 0;
            }
            j++;
        }
        return max_sum;
    }
};