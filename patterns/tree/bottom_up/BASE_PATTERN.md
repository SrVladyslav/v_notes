# In order to work with trees, you should know how to pass the info from the root to the leaves.

```python
def count_nodes(node: TreeNode) -> int:
    if node is None:
        return ... # Base case: what should be returned for the empty three?

    left = count_nodes(node.left) # Recursive call to the left subtree
    right = count_nodes(node.right) # Recursive call to the right subtree

    return ... # Form the response in here to pass to the parent
```

## Typical error while paying with trees

1. Do extra check while processing the info in the base case

```python
# BAD
def count_nodes(node: TreeNode) -> int:
    if node.left is None and node.right is None:
        return 1

    ...
```

2. Forget to add the base case.

> ![IMPORTTANT]
> If you are working with trees (recursion), you should ALWAYS ADD A BASE CASE IN ORDER TO CHECK FOR THE VOID LEAF.
