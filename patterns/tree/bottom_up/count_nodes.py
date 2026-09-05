from patterns.tree.lib import TreeNode


def count_nodes(node: TreeNode) -> int:
    # Base case.
    if node is None:
        return 0

    # Recursive call to the left subtree
    left = count_nodes(node.left)

    # Recursive call to the right subtree
    right = count_nodes(node.right)

    return left + right + 1  # Form the response in here, th e+1 is for the curent node.


if __name__ == "__main__":
    root = TreeNode(
        1, TreeNode(2, TreeNode(4), TreeNode(5)), TreeNode(3, TreeNode(6), TreeNode(7))
    )

    print("Nodes in the tree:", count_nodes(root))
