/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
      queue<vector<Node *>> q;
      q.push({root});
      while(!q.empty()){
          auto arr=q.front();
          vector<Node *> v;
          q.pop();
          int i=0;
          // cout<<arr.size()<<endl;
          for( i=0;i<arr.size()-1;i++){
              arr[i]->next=arr[i+1];
              
              if(arr[i]->left!=NULL) v.push_back(arr[i]->left);
              if(arr[i]->right!=NULL) v.push_back(arr[i]->right);
          }
          arr[i]->next=NULL;
          if(arr[i]->left!=NULL) v.push_back(arr[i]->left);
          if(arr[i]->right!=NULL) v.push_back(arr[i]->right);
          if(v.size()>0)
          q.push(v);
          // cout<<v.size()<<endl;
          
      }  
        return root;
    }
};