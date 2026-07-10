class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        while(s[i] == ' '){
            i++;
        }
        bool is_neg = false;
        bool is_pos = false;
        if(s[i] == '-'){
            is_neg = true;
            i++;
        }
        if(s[i] == '+'){
            is_pos = true;
            i++;
        }
        if(is_neg && is_pos){
            return 0;
        }
        int sum = 0;
        while(i < n && isdigit(s[i])){
            int digit = s[i] - '0';
            if(sum > INT_MAX/10 || (sum == INT_MAX/10 && digit > INT_MAX % 10)){
                return is_neg ? INT_MIN : INT_MAX;
            }
            sum = sum * 10 + digit;
            i++;
        }
        return is_neg ? -sum : sum;
    }
};