from collections import Counter

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not t or len(t) > len(s):
            return ""
        need = Counter(t)
        missing = len(t)
        left = 0
        best_len, best_l = float('inf'), 0
        for right, c in enumerate(s):
            if need[c] > 0:
                missing -= 1
            need[c] -= 1
            if missing == 0:
                while need[s[left]] < 0:
                    need[s[left]] += 1
                    left += 1
                if right - left + 1 < best_len:
                    best_len, best_l = right - left + 1, left
                need[s[left]] += 1
                missing += 1
                left += 1
        return "" if best_len == float('inf') else s[best_l:best_l + best_len]