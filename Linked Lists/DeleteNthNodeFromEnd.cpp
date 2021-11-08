// Given the head of a linked list, 
// remove the nth node from the end of the list and return its head

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr){return head;}
        int count = 0;
        ListNode *temp =  head;
        while(temp!=nullptr){
            count++;
            temp = temp->next;
        }
        if(count<n){return head;}
        int target = count - n;
        count = 1;
        temp = head;
        if(target == 0){return head->next;}
        
        while(count!=target){
            count++;
            temp = temp->next;
        }
        temp->next = (temp->next)->next;
        return head;
    }
};