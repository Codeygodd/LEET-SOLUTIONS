class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        def helper(lo, hi):
            if lo > hi:
                return None
            mid = (lo + hi) // 2
            return TreeNode(nums[mid], helper(lo, mid - 1), helper(mid + 1, hi))

        return helper(0, len(nums) - 1)