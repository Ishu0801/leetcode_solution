class Solution {
public:
    int divide(int Dividend, int Divisor) {
        int result;
        long long exp;
        long long dividend = Dividend;
        long long divisor = Divisor;
        if(divisor == 0){
            return -1;
        }
        if((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0) ){
            exp = dividend / divisor;
            if(exp > INT_MAX){
                result = INT_MAX;
            }
            else{
                result = exp;
            }
        }
        else if((dividend < 0 && divisor > 0) || dividend > 0 && divisor < 0){
            if(dividend < 0 ){
                dividend = -(dividend);
            }
            if(divisor < 0){
                divisor = -(divisor);
            }
            result = -(dividend / divisor);
        }
        return result;
    }
};