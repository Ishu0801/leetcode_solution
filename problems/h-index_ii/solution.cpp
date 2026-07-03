class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0;
        int high = n - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            int high_part = (n - mid);
            if(citations[mid] < high_part){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return n - low ;
    }
};

