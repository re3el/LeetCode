/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void encode(TreeNode* root, stringstream &out)
    {
        if(root == NULL) out<<"#"<<" ";
        else
        {
            out<<root->val<<" ";
            encode(root->left,out);
            encode(root->right,out);            
        }       
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        stringstream out;
        encode(root,out);        
        return out.str();
    }
    
    TreeNode* decode(stringstream &in)
    {
        string val;
        in >> val;
        if(val == "#") return NULL;
        else
        {
            TreeNode *node = new TreeNode(stoi(val));
            node->left = decode(in);
            node->right = decode(in);
            return node;
        }        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {        
        stringstream in(data);
        return decode(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));