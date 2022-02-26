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
    
    int k=1;
    int getDecimalValue(ListNode* head) {
        if(head==NULL) return 0;
        int smallAns=getDecimalValue(head->next);
        int currAns=k*head->val;
        k*=2;
        return currAns+smallAns;
    }
};