class Solution {
public:

    int max_finder(vector<int>& arr){
        int maxi = 0;
        for(int i = 0;i < arr.size();i++){
            maxi = max(maxi,arr[i]);
        }
        return maxi;
    }

    int sum_finder(vector<int>& arr){
        int sum = 0;
        for(int i = 0;i < arr.size();i++){
            sum += arr[i];
        }
        return sum;
    }

    bool possible(vector<int>& nums,int max_sum,int total_array){
        int n = nums.size();
        int cnt = 1;
        int sum = 0;
        for(int i = 0;i < n;i++){
            if((nums[i] + sum) <= max_sum){
                sum += nums[i];
            }
            else{
                cnt++;
                sum = nums[i];
            }
        }
        if(cnt <= total_array){
            return true;
        }
        return false;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = max_finder(nums);
        int high = sum_finder(nums);
        while(low <= high){
            int mid = low + (high - low)/2;
            if(possible(nums,mid,k)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};