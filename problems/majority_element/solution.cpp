class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int maj = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(maj == nums[i]){
                count++;
            }
            else if(count == 0){
                maj = nums[i];
                count = 1;
            }
            else{
                count--;
            }
        }

        int verify = 0;
        for(int i=0;i<nums.size();i++){
            if(maj == nums[i]){
                verify++;
            }
        }

        if(verify > nums.size()/2){
            return maj;
        }
        return 0;
    }
};