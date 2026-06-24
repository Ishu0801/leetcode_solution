class Solution {
public:
    int maxArea(vector<int>& arr) {
        int i = 0;
        int j = arr.size() - 1;
        int maxi = INT_MIN;
        while(i < j){
            int width = j - i;
            int height = min(arr[i],arr[j]);
            int area = height * width;
            maxi = max(area,maxi);

            if(arr[i] < arr[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxi;
    }
};