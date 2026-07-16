class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() == 2){
            return nums;
        }
        int XOR = 0;
        for(int i = 0;i < nums.size();i++){
            XOR ^= nums[i];
        }
        int set_bit = 0;
        while(1){
            if(((XOR) & (1<<set_bit)) != 0){
                break;
            }
            set_bit++;
        }

        int XOR_0 = 0;
        int XOR_1 = 0;
        for(int i = 0;i < nums.size();i++){
            if(((nums[i]) & (1<<set_bit)) == 0){
                XOR_0 ^= nums[i];
            }
            else{
                XOR_1 ^= nums[i];
            }
        }

        return {XOR_0,XOR_1};
    }
};