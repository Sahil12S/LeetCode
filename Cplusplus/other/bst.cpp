#include <iostream>
#include <stack>
#include <utility>

using namespace std;

class BST {

private:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int value) {
            val = value;
            left = nullptr;
            right = nullptr;
        }
    };

    TreeNode* root;

    TreeNode* deleteTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;

        return nullptr;
    }

    TreeNode* insert(int val, TreeNode* root) {
        if (root == nullptr) {
            // cout << "Create root node" << endl;
            root = new TreeNode(val);
        } else if (val < root->val) {
            root->left = insert(val, root->left);
        } else if (val > root->val) {
            root->right = insert(val, root->right);
        }
        return root;
    }

    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        if (root->left) {
            inorder(root->left);
        }
        cout << root->val << " ";
        inorder(root->right);
    }

    void preOrder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        cout << root->val << " ";

        if(root->left) {
            preOrder(root->left);
        }
        preOrder(root->right);
    }

    void postOrder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        if (root->left) {
            postOrder(root->left);
        }
        if (root->right) {
            postOrder(root->right);
        }
        cout << root->val << " ";
    }

    void inOrder2(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* curr = root;

        while (curr != nullptr || !s.empty()) {
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            cout << curr->val << " ";
            s.pop();

            curr = curr->right;
        }
    }

    void preOrder2(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* curr = root;

        while (curr != nullptr || !s.empty()) {
            while (curr != nullptr) {
                cout << curr->val << " ";
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            s.pop();
            curr = curr->right;
        }
    }

    void postOrder2(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* curr = root;

        if (curr == nullptr) {
            return;
        }

        do {
            while(curr) {
                if (curr->right) {
                    s.push(curr->right);
                }
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            s.pop();

            if (curr->right && !s.empty() && curr->right == s.top()) {
                s.pop();
                s.push(curr);
                curr = curr->right;
            } else {
                cout << curr->val << " ";
                curr = nullptr;
            }

        } while (!s.empty());
    }

    TreeNode* findMin(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        } else if (root->left == nullptr) {
            return root;
        } else {
            return findMin(root->left);
        }
    }

    TreeNode* findMax(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        } else if (root->right == nullptr) {
            return root;
        } else {
            return findMax(root->right);
        }
    }

    pair<bool, int> isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return make_pair(false, 0);
        }

        pair<bool, int> left_values = isBalanced(root->left);
        if (!left_values.first) {
            return make_pair(false, 0);
        }

        pair<bool, int> right_values = isBalanced(root->right);

        if (!right_values.first) {
            return make_pair(false, 0);
        }

        bool isBalanced = abs(left_values.second - right_values.second) <= 1;
        int height = max(left_values.second, right_values.second) + 1;

        return make_pair(isBalanced, height);
    }

    bool checkSymmetry(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        } else if (root1 != nullptr && root2 != nullptr) {
            return root1->val == root2->val && checkSymmetry(root1->left, root2->right) && checkSymmetry(root1->right, root2->left);
        }
        return false;
    }



public:
    BST() {
        root = nullptr;
    }
    ~BST() {

    }

    void insert(int x) {
        root = insert(x, root);
    }

    void doInOrder() {
        inorder(root);
        cout << endl;
    }

    void doInOrder2() {
        inOrder2(root);
        cout << endl;
    }

    void doPreOrder() {
        preOrder(root);
        cout << endl;
    }

    void doPreOrder2() {
        preOrder2(root);
        cout << endl;
    }

    void doPostOrder() {
        postOrder(root);
        cout << endl;
    }

    void doPostOrder2() {
        postOrder2(root);
        cout << endl;
    }

    int findMin() {
        return findMin(root)->val;
    }

    int findMax() {
        return findMax(root)->val;
    }

    void isBalanced() {
        pair<bool, int> ans = isBalanced(root);
        cout << "Balanced " << ans.first << ", height " << ans.second << endl;
    }

    bool isSymmetric() {
        return root == nullptr || checkSymmetry(root->left, root->right);
    }
};

int main(int argc, char const *argv[])
{
    BST tree;
    tree.insert(15);
    tree.insert(17);
    tree.insert(16);
    tree.insert(2);
    tree.insert(14);
    tree.insert(20);
    tree.insert(18);
    tree.insert(1);
    tree.insert(22);

    cout << "===>    Recursive Inorder traversal    <===" << endl;
    tree.doInOrder();

    cout << endl;
    cout << "===>    Interative Inorder traversal    <===" << endl;
    tree.doInOrder2();

    cout << endl;
    cout << "===>    Recursive Preorder traversal    <===" << endl;
    tree.doPreOrder();

    cout << endl;
    cout << "===>    Iterative Preorder traversal    <===" << endl;
    tree.doPreOrder2();
    
    cout << endl;
    cout << "===>    Recursive Postorder traversal    <===" << endl;
    tree.doPostOrder();

    cout << endl;
    cout << "===>    Iterative Postorder traversal    <===" << endl;
    tree.doPostOrder2();
    
    cout << endl;
    cout << "===>    Minimum in tree    <===" << endl;
    cout << tree.findMin() << endl;

    cout << endl;
    cout << "===>    Maximum in tree    <===" << endl;
    cout << tree.findMax() << endl;

    cout << endl;
    cout << "===>    Maximum height of tree    <===" << endl;
    tree.isBalanced();
    
    return 0;
}


