class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int ans = INT_MAX;
        int low = 0;
        int high = n - 1;
        if(arr[high] > arr[low]){
            return arr[low];
        }
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] >= arr[low]){
                ans = min(ans,arr[low]);
                low = mid + 1;
            }
            else{
                ans = min(ans,arr[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};