class Solution {
public:

    void reverse(string & str){
        int i = 0;
        int j = str.size() - 1;
        while(i < j){
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            i++;
            j--;
        }
    }

    string string_addition(string str1, string str2){
        if(str1.size() < str2.size()){
            return string_addition(str2,str1);
        }
        if(str1.empty()){
            return str2;
        }
        else if(str2.empty()){
        return str1;
        }
        int carry = 0;
        int i = str2.size() - 1;
        int j = str1.size() - 1;
        while(i >= 0){
            int digit1 = str2[i] - '0';
            int digit2 = str1[j] - '0';
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            str1[j] = sum + '0';
            i--;
            j--;
        }
        while(carry != 0){
            if(j < 0){
                str1 = to_string(carry) + str1;
                carry = 0;
            }
            else{
                int digit = str1[j] - '0';
                int sum = digit + carry;
                carry = sum / 10;
                sum = sum % 10;
                str1[j] = sum + '0';
                j--;
            }
        }
        return str1;
    }

    string multiply(string str1, string str2) {
        string ans = "";
        if(str1 == "0" || str2 == "0") return "0";
        for(int i = str2.size() - 1;i >= 0;i--){
            string temp = "";
            int digit1 = str2[i] - '0';
            int carry = 0;
            for(int j = str1.size() - 1;j >= 0;j--){
                int digit2 = str1[j] - '0';
                int num = (digit1 * digit2) + carry;
                carry  = num / 10;
                num = num % 10;
                temp.push_back('0' + num);
            }
            if(carry != 0){
                temp.push_back(carry + '0');
            }

            reverse(temp);

            for(int j = 0;j < (str2.size() - 1 -i);j++){
                temp.push_back('0');
            }

            ans = string_addition(ans,temp);
        }
        return ans;
    }
};