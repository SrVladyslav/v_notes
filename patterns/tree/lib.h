
template <typename T>
struct TreeNode
{
    T value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(T value, TreeNode *left, TreeNode *right) : value(value), left(left), right(right) {}
};