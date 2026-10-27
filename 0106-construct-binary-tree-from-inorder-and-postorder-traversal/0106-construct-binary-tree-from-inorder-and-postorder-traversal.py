class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if not postorder:
            return None
        root = TreeNode(postorder[-1])
        stack = [root]
        j = len(inorder) - 1
        for i in range(len(postorder) - 2, -1, -1):
            node = stack[-1]
            if node.val != inorder[j]:
                node.right = TreeNode(postorder[i])
                stack.append(node.right)
            else:
                while stack and stack[-1].val == inorder[j]:
                    node = stack.pop()
                    j -= 1
                node.left = TreeNode(postorder[i])
                stack.append(node.left)
        return root