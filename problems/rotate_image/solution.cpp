class Solution {
public:

    void reverser(vector<int>& arr){
        int i = 0;
        int j = arr.size() - 1;
        while(i<j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 1;i < n;i++){
            for(int j = 0;j < i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i = 0;i < n;i++){
            reverser(matrix[i]);
        }
    }
};