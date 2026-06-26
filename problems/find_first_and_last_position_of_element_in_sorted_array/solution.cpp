class Solution {
public:

    int lower_bound(vector<int>& arr,int target){
        int n = arr.size();
        int ans = n;
        int low = 0;
        int high = n - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] >= target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }

    int upper_bound(vector<int>& arr,int target){
        int n = arr.size();
        int ans = n;
        int low = 0;
        int high = n - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] > target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(nums.empty()){
            return {-1,-1};
        }
        int lb = lower_bound(nums,target);
        int ub = upper_bound(nums,target);
        if( lb < n && nums[lb] == target){
            return {lb,ub -1};
        }
        return {-1,-1};
    }
};