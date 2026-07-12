class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n){
            int &num = nums[i];
            if(num == i + 1){
                i++;
                continue;
            }
            else if(num <= 0 || num > n || num == nums[num - 1]){
                i++;
                continue;
            }
            else if((num > 0) && (num <= n) && (num != i + 1)){
                swap(num,nums[num - 1]);
            }
        }

        for(int i = 0;i < n;i++){
            if(nums[i] != i + 1){
                return i + 1;
            }
        }
        return (n + 1);
    }
};