// question
// Given two non-negative integers, num1 and num2 represented as string, 
// return the sum of num1 and num2 as a string.
// solution similar to hand addition of two big numbers

class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size()-1, m = num2.size()-1, carry = 0;
        string res="";
        int temp;
        while(n>=0 && m>=0){
            temp = int(num1[n]) + int(num2[m]) -48-48 + carry;
            if(temp>=10){
                res+=to_string(temp%10);
                carry = temp/10;
            }
            else{
                res+=to_string(temp);
                carry = 0;
            }
            n--;
            m--;
        }
        if(n<0 && m<0){
            if(carry != 0){
                res+=to_string(carry);
            }
            reverse(res.begin(), res.end());
            return res;
        }
        else if(n<0){
            num1 = num2;
            n = m;
        }
        
        while(n>=0){
            temp = int(num1[n])-48 + carry;
            if(temp>=10){
                res+=to_string(temp%10);
                carry = temp/10;
            }
            else{
                res+=to_string(temp);
                carry = 0;
            }
            n--;
        }
        if(carry != 0){
            res+=to_string(carry);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};