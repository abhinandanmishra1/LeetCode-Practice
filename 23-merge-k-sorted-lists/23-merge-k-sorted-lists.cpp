class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1,ListNode *list2){
        if(!list1) return list2;
        if(!list2) return list1;
        if(list1->val<list2->val){
            ListNode *res=new ListNode(list1->val);
            res->next=mergeTwoLists(list1->next,list2);
            return res;
        }else{
            ListNode *res=new ListNode(list2->val);
            res->next=mergeTwoLists(list1,list2->next);
            return res;
        }
    }
    ListNode *mergeLists(vector<ListNode*>& lists,int start,int end){
        if(start>end) return NULL;
        if(start==end) return lists[start];
        int mid=start+(end-start)/2;
        ListNode *leftList=mergeLists(lists,start,mid);
        ListNode *rightList=mergeLists(lists,mid+1,end);
        return mergeTwoLists(leftList,rightList);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeLists(lists,0,lists.size()-1);
        
    }
};