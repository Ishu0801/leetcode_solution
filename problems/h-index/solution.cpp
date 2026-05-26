class Solution {
public:

    int pivot_finder(vector<int>& arr, int low, int high){
        int pivot = arr[low];
        int i = low;
        int j = high;
        while(i<j){
            while(arr[i]>=pivot && i<high){
                i++;
            }
            while(arr[j]<pivot && j>low){
                j--;
            }
            if(i<j){
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[j],arr[low]);
        return j;
    }

    void quick_sort(vector<int>& arr, int low, int high){
        if(low<high){
            int pivot = pivot_finder(arr,low,high);
            quick_sort(arr,low,pivot-1);
            quick_sort(arr,pivot+1,high);
        }
    }

    int hIndex(vector<int>& citations) {
        int n = citations.size();
        quick_sort(citations,0,n-1);
        int count = 0;
        for(int i=0;i<n;i++){
            if(citations[i]>=i+1){
                count++;
            }
        }
        return count;
    }
};