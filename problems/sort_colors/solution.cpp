class Solution {
public:

    int pivot_finder(vector<int>& nums,int low,int high){
        int pivot = nums[low];
        int i = low;
        int j = high;
        while(i<j){
            while(nums[i]<=pivot && i < high){
                i++;
            }
            while(nums[j]>pivot && j > low){
                j--;
            }
            if(i<j){
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[low],nums[j]);
        return j;
    }

    void quick_sort(vector<int>& nums, int low , int high) {
        if(low<high){
            int pivot = pivot_finder(nums,low,high);
            quick_sort(nums,low,pivot - 1);
            quick_sort(nums,pivot+1,high);
        }
    }

    void sortColors(vector<int>& nums) {
        int high = nums.size()-1;
        quick_sort(nums,0,high);
        }
};