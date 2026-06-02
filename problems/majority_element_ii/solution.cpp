class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int maj_el1 = 0;
        int maj_el2 = 0;
        int count1 = 0;
        int count2 = 0;
        vector<int> result;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(maj_el1 == nums[i]){
                count1++;
            }
            else if(maj_el2 == nums[i]){
                count2++;
            }
            else if(count1 == 0){
                maj_el1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0){
                maj_el2 = nums[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        int verify_count1 = 0;
        int verify_count2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == maj_el1){
                verify_count1++;
            }
            else if(nums[i] == maj_el2){
                verify_count2++;
            }
        }

        if(verify_count1 > n/3){
            result.push_back(maj_el1);
        }
        if(verify_count2 > n/3){
            result.push_back(maj_el2);
        }
        return result;
    }
};