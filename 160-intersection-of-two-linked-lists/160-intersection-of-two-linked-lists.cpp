/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A=headA;
        while(headA){
            headA->val=-headA->val;
            headA=headA->next;
        }
        ListNode *ans=NULL;
        while(headB){
            if(headB->val<0){
                ans=headB;
                headB=headB->next;
                break;
            }
            headB->val=headB->val;
            headB=headB->next;
        }
        headA=A;
        while(headA){
            headA->val=-headA->val;
            headA=headA->next;
        }
        return ans;
    }
};