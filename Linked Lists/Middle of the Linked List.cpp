class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* tmp = head;
        int count = 0;
        while(tmp!=nullptr){
            tmp = tmp->next;
            count++;
        }
        int target = (count/2) + 1;
        count = 0;
        tmp = head;
        while(tmp!=nullptr){
            count++;
            cout<<count<<target;
            
            if(count == target){
                return tmp;
            }
            tmp = tmp->next;
        }
        return tmp;
    }
};