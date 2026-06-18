class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 3){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int result = 0; 
        int min_diff = INT_MAX;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i] == nums[i - 1]){
                continue;
            }
            int j = i+1;
            int k = n-1;
            while(j < k){
                long long sum = nums[i] + nums[j] + nums[k];
                int diff = sum - target;
                if(diff < 0){
                    diff = -(diff);
                }
                if(min_diff > diff){
                    min_diff = diff;
                    result = sum;
                }
                if(sum < target){
                    j++;
                }
                else if(sum > target){
                    k--;
                }
                else{
                    return sum;
                }
            }
        }
        return result;
    }
};