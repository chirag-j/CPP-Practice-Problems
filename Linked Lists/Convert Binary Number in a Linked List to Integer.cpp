class Solution {
public:
    int multiplier = 1;
    int getDecimalValue(ListNode* head) {
        if(head->next!=nullptr){
            int temp = getDecimalValue(head->next) + (head->val)*multiplier;
            multiplier*=2;
            return temp;
        }
        else{
            int temp = (head->val)*multiplier;
            multiplier*=2;
            return temp;
        }
    }
};