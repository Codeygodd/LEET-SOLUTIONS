class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        res = []
        if not root:
            return res
        stack = [(root, targetSum, [])]
        while stack:
            node, target, path = stack.pop()
            path = path + [node.val]
            rem = target - node.val
            if not node.left and not node.right:
                if rem == 0:
                    res.append(path)
                continue
            if node.right:
                stack.append((node.right, rem, path))
            if node.left:
                stack.append((node.left, rem, path))
        return res