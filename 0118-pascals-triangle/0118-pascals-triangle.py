class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = [[1]]
        for _ in range(1, numRows):
            prev = res[-1]
            res.append([1] + [prev[j] + prev[j + 1] for j in range(len(prev) - 1)] + [1])
        return res