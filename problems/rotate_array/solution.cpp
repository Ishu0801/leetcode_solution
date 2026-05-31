class Solution {
public:

    void reverse(vector<int>&nums, int start, int end){
        int i= start;
        int j = end;
        while(i<=j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        if(k==0 || nums.size()==0){
            return;
        }
        int p_of_rot = nums.size()-k-1;
        reverse(nums,0,p_of_rot);
        reverse(nums,p_of_rot+1,nums.size()-1);
        reverse(nums,0,nums.size()-1);
    }
};