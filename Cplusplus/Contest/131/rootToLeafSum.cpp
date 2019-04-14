/*
ven a binary tree, each node has value 0 or 1.  
Each root-to-leaf path represents a binary number starting with the most significant bit. 
For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.
Return the sum of these numbers.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int toDecimal( string binary )
    {
        int ans = 0;
        for ( int i = 0; i < binary.length(); i++ )
        {
            if( binary[i] == '1' )
            {
                ans += pow( 2, i );
            }
        }
        return ans;
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        if ( root == nullptr )
        {
            return 0;
        }
        int result = 0;
        stack<pair<TreeNode*, string>> stk;
        string s = "";
        stk.push( make_pair( root, to_string( root->val) + s ) );
        
        while ( !stk.empty() )
        {
            auto temp = stk.top();
            stk.pop();
            
            if ( temp.first->right )
            {
                stk.push( make_pair( temp.first->right, to_string(temp.first->right->val) + temp.second ) );
            }
            
            if ( temp.first->left )
            {
                stk.push( make_pair( temp.first->left, to_string(temp.first->left->val) + temp.second ) );
            }
            
            if ( !temp.first->left && !temp.first->right )
            {
                result += toDecimal( temp.second );
            }
        }
        
        return result;
    }
};