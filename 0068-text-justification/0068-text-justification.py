class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        res, i, n = [], 0, len(words)
        while i < n:
            j, length = i, 0
            while j < n and length + len(words[j]) + (j - i) <= maxWidth:
                length += len(words[j])
                j += 1
            gaps = j - i - 1
            if j == n or gaps == 0:
                line = " ".join(words[i:j])
                line += " " * (maxWidth - len(line))
            else:
                q, r = divmod(maxWidth - length, gaps)
                line = ""
                for k in range(i, j - 1):
                    line += words[k] + " " * (q + (1 if k - i < r else 0))
                line += words[j - 1]
            res.append(line)
            i = j
        return res