/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2,carry=0) {
    if(!l1 && !l2){
        if(!carry) return null;
        return new ListNode(carry);
    }
    if(!l1){
        if(!carry) return l2;
        let val = l2.val + carry;
        let ans = new ListNode(val%10);
        carry = parseInt(val/10);
        ans.next = addTwoNumbers(l1,l2.next,carry);
        return ans;
    }
    if(!l2){
        if(!carry) return l1;
        let val = l1.val + carry;
        let ans = new ListNode(val%10);
        carry = parseInt(val/10);
        ans.next = addTwoNumbers(l1.next,l2,carry);
        return ans;
    }
    let val = l1.val + carry + l2.val;
    let ans = new ListNode(val%10);
    carry = parseInt(val/10);
    ans.next = addTwoNumbers(l1.next,l2.next,carry);
    return ans; 
    
};