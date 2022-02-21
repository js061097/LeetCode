/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy =  new ListNode();
        ListNode* tail = dummy;
        int carry = 0;
        
        while(l1!=nullptr || l2!=nullptr){
            int l1val = (l1==nullptr)? 0: l1->val;
            int l2val = (l2==nullptr)? 0: l2->val;
            
            int sum = l1val + l2val + carry;
            carry = sum/10;
            
            ListNode* newnode = new ListNode(sum%10);
            tail->next = newnode;
            tail = tail->next;
            
            if(l1!=nullptr)  l1=l1->next;
            if(l2!=nullptr)  l2=l2->next;
        }
        if(carry==1){
            ListNode* newnode = new ListNode(1);
            tail->next = newnode;
            tail = tail->next;
        }
        return dummy->next;
    }
};


/*SAMPLE CASES
l1 9 
l2 9
return 8 1

l1 9 9
l2 9
return 8 0 1
*/
