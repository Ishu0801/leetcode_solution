class Solution {
public:

    int max_finder(vector<int>& arr){
        int maxi = arr[0];
        int n = arr.size();
        if(n == 1){
            return maxi;
        }
        for(int i = 1;i < n;i++){
            maxi = max(maxi,arr[i]);
        }
        return maxi;
    }

    long long req_time_finder(vector<int>& arr, int speed){
        long long time = 0;
        int n = arr.size();
        for(int i = 0;i < n;i++){
            time += (arr[i] + (long long)speed - 1)/speed;
        }
        return time;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int speed = 0;
        int maxi = max_finder(piles);
        int low = 1;
        int high = maxi;
        while(low <= high){
            int mid = low + (high - low)/2;
            long long time = req_time_finder(piles,mid);
            if(time > h){
                low = mid + 1;
            }
            else{
                high = mid - 1;
                speed = mid;
            }

        }
        return speed;
    }
};