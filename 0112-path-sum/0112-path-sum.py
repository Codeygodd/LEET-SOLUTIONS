class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False
        stack = [(root, targetSum)]
        while stack:
            node, target = stack.pop()
            rem = target - node.val
            if not node.left and not node.right and rem == 0:
                return True
            if node.right:
                stack.append((node.right, rem))
            if node.left:
                stack.append((node.left, rem))
        return False