class Solution {
public:

    void merger(vector<int>& arr,vector<int>& temp,int low,int mid,int high){
        int n = arr.size();
        int left = low;
        int right = mid + 1;
        int index = low;
        while(left <= mid && right <= high){
            if(arr[left] < arr[right]){
                temp[index] = arr[left];
                index++;
                left++;
            }
            else{
                temp[index] = arr[right];
                index++;
                right++;
            }
        }
        while(left <= mid){
            temp[index] = arr[left];
            index++;
            left++;
        }
        while(right <= high){
            temp[index] = arr[right];
            index++;
            right++;
        }

        for(int i = low;i <= high;i++){
            arr[i] = temp[i];
        }
    }

    void merge_sort(vector<int>& arr,vector<int>& temp,int low,int high){
        if(low >= high){
            return;
        }
        int mid = low + (high - low)/2;
        merge_sort(arr,temp,low,mid);
        merge_sort(arr,temp,mid+1,high);
        merger(arr,temp,low,mid,high);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        vector<int> temp(n);
        merge_sort(nums,temp,low,high);
        return nums;
    }
};