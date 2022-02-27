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
    bool isPalindrome(ListNode* head) {
       vector<int> arr;
        if(!head) return true;
        while(head!=NULL){
            arr.push_back(head->val);
            head=head->next;
        }
        auto arr2=arr;
        reverse(arr2.begin(),arr2.end());
        return arr==arr2;
    }
};