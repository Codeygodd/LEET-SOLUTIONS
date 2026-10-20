from collections import Counter

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])
        cnt = Counter(ch for row in board for ch in row)
        for ch, c in Counter(word).items():
            if cnt[ch] < c:
                return False
        if cnt[word[0]] > cnt[word[-1]]:
            word = word[::-1]
        L = len(word)

        def dfs(i, j, k):
            if board[i][j] != word[k]:
                return False
            if k == L - 1:
                return True
            tmp = board[i][j]
            board[i][j] = '#'
            for di, dj in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                ni, nj = i + di, j + dj
                if 0 <= ni < m and 0 <= nj < n and board[ni][nj] != '#' and dfs(ni, nj, k + 1):
                    board[i][j] = tmp
                    return True
            board[i][j] = tmp
            return False

        for i in range(m):
            for j in range(n):
                if dfs(i, j, 0):
                    return True
        return False