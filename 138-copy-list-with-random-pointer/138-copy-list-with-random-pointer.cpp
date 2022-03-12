/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node *newNode(Node *head,unordered_map<Node *,Node *>&mp){
        if(!head) return NULL;
        if(mp.find(head)!=mp.end()) return mp[head];
        return mp[head]=new Node(head->val);
    }
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        unordered_map<Node *,Node *>mp;
        Node *temp=head;
        while(temp!=NULL){
            Node *curr=newNode(temp,mp);
            curr->next=newNode(temp->next,mp);
            curr->random=newNode(temp->random,mp);
            temp=temp->next;
        }
        return mp[head];
    }
};