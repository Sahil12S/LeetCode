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
struct Detail {
    TreeNode* node;
    unsigned int pos;
    int depth;
};

public:
    int widthOfBinaryTree(TreeNode* root) {
        if( root == nullptr )
        {
            return 0;
        }

        int maxWidth = 0;
        int currDepth = 0;
        int left = 0;
        queue< Detail* > q; // Store ID of node
        
        q.push( new Detail{root, 0, 0} );
        
        while ( !q.empty() )
        {
            int level = q.size();
            
            Detail* d = q.front();
            q.pop();
            
            
            if( d->node )
            {
                q.push( new Detail{ d->node->left, d->pos * 2, d->depth + 1 } );
                q.push( new Detail{ d->node->right, d->pos*2 + 1, d->depth + 1 } );
                if( currDepth != d->depth )
                {
                    currDepth = d->depth;
                    left = d->pos;
                }
                maxWidth = max( int(d->pos - left + 1), maxWidth );
            }
        }
        return maxWidth;
    }
};