class Solution {
public:

    void reverse(vector<int>& arr,int low, int high){
        int i = low;
        int j = high;
        while(i<j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }

    void nextPermutation(vector<int>& nums) {
        int index = -1;
        for(int i= nums.size() - 2; i>=0;i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }

        if(index == -1){
            reverse(nums,0,nums.size()-1);
            return;
        }

        for(int i = nums.size()-1;i>index;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }

        int low = index + 1;
        int end = nums.size() - 1;
        reverse(nums,low,end);
    }
};