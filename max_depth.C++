#include <iostream>
#include <assert.h>
using namespace std;
class TreeNode
{
   public:
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode():value(0), right(nullptr), left(nullptr){}
    TreeNode(int val):value(val), right(nullptr), left(nullptr){}
    TreeNode(int val, TreeNode* l, TreeNode* r):value(val), right(r), left(l){}
    ~TreeNode(){}
};
int max_depth(TreeNode* tree, int size)
{
    int l_count, r_count;
    int l_max = 0, r_max = 0;
    for(int i = 0; i < size; ++i)
    {
        l_count = 1;
        r_count = 1;
        while(tree[i].left != nullptr)
        {
            l_count += 1;
            tree[i] = *tree[i].left;
        } 
        l_max = l_max > l_count ? l_max : l_count;
        while(tree[i].right != nullptr)
        {
            r_count += 1;
            tree[i] = *tree[i].right;
        } 
        r_max = r_max > r_count ? r_max : r_count;
    }
    return l_max > r_max ? l_max : r_max;
}
