class Solution {
public:

    int max_finder(vector<int>& arr){
        int maxi = INT_MIN;
        int inx = -1;
        for(int i = 0;i < arr.size();i++){
            if(maxi < arr[i]){
                maxi = arr[i];
                inx = i;
            }
        }
        return inx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = n - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            int maxi = max_finder(mat[mid]);
            int left = -1;
            int right = -1;
            if((mid - 1) >= 0){
                left = mat[mid - 1][maxi];
            }
            if((mid + 1) < n){
                right = mat[mid + 1][maxi];
            }
            if((mat[mid][maxi] > left) && (mat[mid][maxi] > right)){
                return {mid,maxi};
            }
            else if(mat[mid][maxi] < left){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return {-1,-1};
    }
};