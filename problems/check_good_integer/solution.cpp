class Solution {
public:
    bool checkGoodInteger(int n) {
        int digit_sum = 0;
        int square_sum = 0;
        int digit;
        int dividend = n;
        while(dividend >= 10 ){
            digit = dividend % 10;
            digit_sum += digit;
            square_sum += pow(digit,2);
            dividend = dividend/10;
        }
        digit_sum += dividend;
        square_sum += pow(dividend,2);
        if((square_sum - digit_sum) >= 50){
            return true;
        }
        else{
            return false;
        }
    }
};