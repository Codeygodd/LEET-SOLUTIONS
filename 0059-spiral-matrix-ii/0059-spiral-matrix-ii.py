class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        m = [[0] * n for _ in range(n)]
        top, bot, left, right = 0, n - 1, 0, n - 1
        k = 1
        while top <= bot and left <= right:
            for j in range(left, right + 1):
                m[top][j] = k
                k += 1
            top += 1
            for i in range(top, bot + 1):
                m[i][right] = k
                k += 1
            right -= 1
            if top <= bot:
                for j in range(right, left - 1, -1):
                    m[bot][j] = k
                    k += 1
                bot -= 1
            if left <= right:
                for i in range(bot, top - 1, -1):
                    m[i][left] = k
                    k += 1
                left += 1
        return m