class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0){
            return 0;
        }
        int left = 0;
        int right = n  - 1;
        int max_left = INT_MIN;
        int max_right = INT_MIN;
        int traped_water = 0;
        while(left < right){
            if(height[left] < height[right]){
                if(height[left] >= max_left){
                    max_left = height[left];
                }
                else{
                    traped_water += max_left - height[left];
                }
                left++;
            }
            else{
                if(height[right] >= max_right){
                    max_right = height[right];
                }
                else{
                    traped_water += max_right - height[right];
                }
                right--;
            }
        }
        return traped_water;
    }
};