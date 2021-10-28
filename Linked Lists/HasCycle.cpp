// FLoyds cycle detection Algorithm

bool hasCycle(ListNode *head) {
    if(head == nullptr){return 0;}
    ListNode *p1 = head, *p2 = head;
    p2 = p2->next;
    if(p2!=nullptr){p2 = p2->next;}
    while(p1!=nullptr && p2!=nullptr && p1!=p2){
        p1 = p1->next;
        p2 = p2->next;
        if(p2!=nullptr){p2 = p2->next;}
    }
    if(p1==nullptr || p2==nullptr){return false;}
    return true;
}