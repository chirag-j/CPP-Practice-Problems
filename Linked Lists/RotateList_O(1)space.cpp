class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        Node *tmp1;
        tmp1 = head;
        Node *tmp2 = tmp1->next;
        if(tmp2 == NULL){
            return head;
        }
        
        Node* tmp3 = tmp2->next;
        tmp1->next = NULL;
        
        while(1){
            // cout<<tmp1->data<<" ";
            tmp2->next = tmp1;
            tmp1 = tmp2;
            tmp2 = tmp3;
            if(tmp3 == NULL){
                break;
            }
            tmp3 = tmp3->next;
        }
        Node *tp = tmp2;
        // cout<<tmp1->data;
        
        // while(tp!=NULL){
        //     cout<<tp->data<<" ";
        //     tp = tp->next;
        // }
        return tmp1;
        
        // code here
        // return head of reversed list
    }
    
};