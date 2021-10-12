class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* t1, *t2, *tmp;
        if(head==nullptr){return head;}
        t1 = head;
        t2 = head->next;
        // if(t2!=nullptr){head = t2;}
        head = (t2!=nullptr)? t2:t1;
        while(t2!=nullptr){
            tmp = t2->next;
            t2->next = t1;
            t1->next = (tmp!=nullptr && tmp->next!=nullptr)? tmp->next:tmp;
            t1 = tmp;
            t2 = (tmp!=nullptr)? t1->next:tmp;
        }
        return head;
    }
};