 // Definition for singly-linked list.
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
// vector<ListNode> res;


int giveNumber(ListNode *a, int &m){
 	if(a->next == nullptr){
 		return (a->val)*m;
 	}
 	int my_m = m;
 	m = m*10;
 	return giveNumber(a->next, m) + (a->val)*my_m;
}

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         int m=1;
//         int num1 = giveNumber(l1, m);
//         m = 1;
//         int sum = giveNumber(l2, m) + num1;
//         int n = log10(sum) +1;
//         // cout<<sum<<" "<<n<<endl;
//         ListNode *res = new ListNode(n);
        
//         // res.resize(n);
//         m = 10;
//         for(int i=0; i<n; i++){
//             int temp = sum%m;
//             if(i+1!=n){
//                 res[i].val = temp;
//                 res[i].next = &res[i+1];
//             }
//             else{
//                 res[i].val = temp;
//                 res[i].next = nullptr;
//             }
//             sum/=10;
//         }
//         m = 1;
//         return &res[0];
        
//     }
// };
ListNode* reverseList(ListNode *l1){
    ListNode * temp = l1;
    l1 = l1->next;
    ListNode* lfront;
    // cout<<temp->val;
    temp->next = nullptr;
    while(l1!=nullptr){
        lfront = l1->next;
        l1->next = temp;

        temp = l1;
        l1 = lfront;
    }
    return temp;
}
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1 = reverseList(l1);
        // l2 = reverseList(l2);
        ListNode* t1 = l1, *t2 = l2;
        ListNode* smn = new ListNode;
        ListNode* stemp = smn;
        ListNode* last;
        
        int carry = 0;
        while(t1!=nullptr && t2!=nullptr){
            int temp = t1->val + t2->val + carry;
            stemp->val = temp%10;
            // cout<<stemp->val<<" ";
            carry = temp/10;
            t1 = t1->next;
            t2 = t2->next;
            last = stemp;
            stemp->next = new ListNode;
            stemp = stemp->next;
        }
        
        if(t1==nullptr){
            t1 = t2;            //just maintaining t1 as the list which is not null yet
        }
        while(t1!=nullptr){
            // if(t1==nullptr){
            //     stemp->val = carry;
            //     last = stemp;
            //     break;
            // }
            int temp = t1->val+ carry;
            // cout<<temp<<" ";
            stemp->val = temp%10;
            // cout<<stemp->val<<" ";
            carry = temp/10;
            t1 = t1->next;
            last = stemp;
            stemp->next = new ListNode;
            stemp = stemp->next;
        }
        if(carry!=0){
            stemp->val = carry;
            last = stemp;
        }
        
        last->next = nullptr;
        return smn;
        
    }
};


int main(){
    ListNode a(2), b(4, &a), c(3, &b);
    ListNode d(9), e(6, &d), f(4, &e);
    // lst->val = 5;
    // lst->next = lst+1;
    // (lst+1)->val = 4;
    // lst = reverseList(&f);
    Solution prob;
    ListNode* res = prob.addTwoNumbers(&c, &f);
    int m = 1;
    cout<<giveNumber(res, m);
    // ListNode*lst = new ListNode[3];
    // cout<<res->val;

    // ListNode l1[3], l2[3];

    return 0;
}