class Solution {
public:
    int reverse(int x) {
        int digit = 0;
        int final_digit = 0;
        while(x != 0){
            digit = x % 10;
            if(final_digit > INT_MAX/10 ||(final_digit == INT_MAX && digit > 7)){
                return 0;
            }
            if(final_digit < INT_MIN/10 ||(final_digit == INT_MIN && digit < -8)){
                return 0;
            }
            final_digit = final_digit * 10 + digit;
            x = x / 10;
        }
        if(x < 0){
            return -final_digit;
        }
        return final_digit;
    }
};