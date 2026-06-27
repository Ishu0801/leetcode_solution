class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        // int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] == target){
                return mid;
            }
            //left part is sorted
            if(arr[mid] >= arr[low]){
                //target lies in left part
                if(target >= arr[low] && target < arr[mid]){
                    high = mid - 1;
                }
                //target lies in right part
                else{
                    low = mid + 1;
                }
            }
            //right part is sorted
            else{
                //target lies in right part
                if(target > arr[mid] && target <= arr[high]){
                    low = mid + 1;
                }
                //target lies in left part
                else{
                    high = mid - 1;
                }

            }
        }
        return -1;
    }
};