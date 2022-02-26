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
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head->next)
            return head;
        int n = numOfNodes(head);
        ListNode* swap;
        if(n==2){
            swap = head->next;
            head->next = nullptr;
            swap->next = head;
            head = swap;
            return head;
        }
        if(k>n)
            return head;
        ListNode* ptr = head;
        ListNode* prev1,*curr1,*forw1;
        ListNode* prev2,*curr2,*forw2;
        int i=1;
        
        while(i<n){
            if(i==(k-1)){
                prev1 = ptr;
                curr1 = ptr->next;
                forw1 = ptr->next->next;
            }
            if(i==(n-k)){
                prev2 = ptr;
                curr2 = ptr->next;
                forw2 = ptr->next->next;
            }
            ptr=ptr->next;
            i++;
            if(i==(n-1) && k == n){
                prev2 = ptr;
                curr2 = ptr->next;
                forw2 = ptr->next->next;
            }
        }
        
        if(k==n){
            prev2->next = head;
            curr2->next = head->next;
            head->next = nullptr;
            head = curr2;
            return head;
        }
        if(k==1){
            swap = head->next;
            head->next = nullptr;
            curr2->next = swap;
            prev2->next = head;
            head = curr2;
            return head;
        }
        swap = prev1->next;
        prev1->next = prev2->next;
        prev2->next = swap;
        swap = curr1->next;
        curr1->next = curr2->next;
        curr2->next = swap;
        
        return head;
        
    }
    int numOfNodes(ListNode* head){
        int count = 1;
        while(head->next){
            count++;
            head = head->next;
        }
        return count;
    }
};
