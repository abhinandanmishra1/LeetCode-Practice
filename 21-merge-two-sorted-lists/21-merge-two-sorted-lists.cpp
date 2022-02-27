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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(!list1) return list2;
        if(!list2) return list1;
        int val1=list1->val;
        int val2=list2->val;
        ListNode *result;
        if(val1<val2){
            result=new ListNode(val1);
            result->next=mergeTwoLists(list1->next,list2);
        }else{

            result=new ListNode(val2);
            result->next=mergeTwoLists(list1,list2->next);

        }
        return result;
        
    }
};