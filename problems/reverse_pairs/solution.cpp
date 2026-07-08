class Solution {
public:

    int counter(vector<int>& arr,int low,int mid,int high){
        int count = 0;
        int right = mid + 1;
        for(int i = low;i <= mid;i++){
            while(right <= high && arr[i] > (long long)2 * arr[right]){
                right++;
            }
            count += right - (mid + 1);
        }
        return count;
    }

    void merger(vector<int>& arr,vector<int>& temp,int low,int mid,int high){
        int left = low;
        int right = mid + 1;
        int index = low;
        while(left <= mid && right <= high){
            if(arr[left] < arr[right]){
                temp[index] = arr[left];
                left++;
                index++;
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

    int merge_sort(vector<int>& arr,vector<int>& temp,int low,int high){
        int count = 0;
        if(low >= high){
            return count;
        }
        int mid = low + (high - low)/2;
        count += merge_sort(arr,temp,low,mid);
        count += merge_sort(arr,temp,mid+1,high);
        count += counter(arr,low,mid,high);
        merger(arr,temp,low,mid,high);
        return count;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);
        int low = 0;
        int high = n - 1;
        int count = merge_sort(nums,temp,low,high);
        return count;
    }
};