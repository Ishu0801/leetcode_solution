class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest_alt = 0;
        int current_alt = 0;
        for(int i=0;i<gain.size();i++){
            current_alt += gain[i];
            highest_alt = max(current_alt,highest_alt);
        }
        return highest_alt;
    }
};