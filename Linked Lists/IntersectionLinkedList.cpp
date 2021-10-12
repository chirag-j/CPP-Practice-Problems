// Given the heads of two singly linked-lists headA and headB, 
// return the node at which the two lists intersect. 
// If the two linked lists have no intersection at all, return null.

// Best approach : 

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // unordered_set<ListNode *> A;
        ListNode * tmpa = headA, * tmpb = headB;
        if(tmpa==NULL || tmpb==NULL){return NULL;}
        while(tmpa!=tmpb){
            if(tmpa!=NULL){
                tmpa = tmpa->next;
            }
            else{
                tmpa = headB;
            }
            if(tmpb!=NULL){
                tmpb = tmpb->next;
            }
            else{
                tmpb = headA;
            }
        }
        return tmpa;
    }
};

// Works but not efficient

// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         unordered_set<ListNode *> A;
//         ListNode * tmpa = headA, * tmpb = headB;
//         if(tmpa==NULL || tmpb==NULL){return NULL;}
//         while(tmpa != NULL || tmpb != NULL){
//             if(tmpa!=NULL){
//                 if(A.find(tmpa) == A.end()){
//                     A.insert(tmpa);
//                     tmpa = tmpa->next;
//                 }
//                 else{return tmpa;}
//             }
//             if(tmpb!=NULL){
//                 if(A.find(tmpb) == A.end()){
//                     A.insert(tmpb);
//                     tmpb=tmpb->next;
//                 }
//                 else{return tmpb;}
//             }
//         }
//         return NULL;
//     }
// };