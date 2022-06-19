// Copied
class Solution {
public:
    struct TrieNode {
        TrieNode *children[26];
        vector<int> indices;
        TrieNode () {
            memset(children, 0, sizeof(children));
        }
    };
    
    void insert(TrieNode *root, string &word, int idx) {
        TrieNode *curr = root;
        for (char c: word) {
            TrieNode *&child = curr->children[c - 'a'];
            if (child == nullptr) child = new TrieNode();
            if (child->indices.size() < 3)
                child->indices.push_back(idx);
            curr = child;
        }
    }
    
    TrieNode *build_trie(vector<string> &products) {
        TrieNode *root = new TrieNode();
        for (int i = 0; i < products.size(); ++i)
            insert(root, products[i], i);
        return root;
    }
    
    void find_products(TrieNode *root, string &searchWord, vector<string> &products, vector<vector<string>> &res) {
        res.resize(searchWord.size());
        TrieNode *curr = root;
        for (int i = 0; i < searchWord.size(); ++i) {
            TrieNode *&child = curr->children[searchWord[i] - 'a'];
            if (child == nullptr) break;
            for (int idx: child->indices)
                res[i].push_back(products[idx]);
            curr = child;
        }
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        TrieNode *root = build_trie(products);
        vector<vector<string>> res;
        find_products(root, searchWord, products, res);
        return res;
    }
};