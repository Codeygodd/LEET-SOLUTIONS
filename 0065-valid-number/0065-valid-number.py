class Solution:
    def isNumber(self, s: str) -> bool:
        seen_digit = seen_dot = seen_e = False
        for i, c in enumerate(s):
            if '0' <= c <= '9':
                seen_digit = True
            elif c in '+-':
                if i > 0 and s[i - 1] not in 'eE':
                    return False
            elif c == '.':
                if seen_dot or seen_e:
                    return False
                seen_dot = True
            elif c in 'eE':
                if seen_e or not seen_digit:
                    return False
                seen_e = True
                seen_digit = False
            else:
                return False
        return seen_digit