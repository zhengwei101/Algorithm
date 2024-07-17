#include <iostream>
using std::cout;
using std::endl;

 /*
 * Testcase Example:  '[4,2,7,1,3,6,9]'
 *
 * 翻转一棵二叉树。
 * 
 * 示例：
 * 
 * 输入：
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 2     7
 * ⁠/ \   / \
 * 1  3 6   9
 * 
 * 输出：
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 7     2
 * ⁠/ \   / \
 * 9  6 3   1
 * 
*/

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int x) : val(x) {}
};

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if(root == nullptr)
        {
            return nullptr;
        }
        TreeNode *tmpNode = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmpNode);
        return root;
    }
};

int main()
{

}