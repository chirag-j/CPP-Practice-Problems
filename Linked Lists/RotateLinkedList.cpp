class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        Node* itr = head;
        queue<Node*> fr;
    
        for(int i=0; i<=k; i++){
            if(i==k){
                if(itr==NULL){
                    return head;
                }
                head = itr;
                continue;
            }
            fr.push(itr);
            itr = itr->next;
        }
        
        //Go to the last element
        while(itr->next!=NULL){
            itr = itr->next;
        }
        
        //Add all elements from the queue to end of linked list;
        for(int i=0; i<k; i++){
            itr->next = fr.front();
            itr=itr->next;
            fr.pop();
        }
        itr->next = NULL;
        // Your code here
        return head;
    }
};