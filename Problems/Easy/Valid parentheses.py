class Solution(object):
    def isValid(self, s):
        if len(s) == 0:
            return True
        brackets_map = {
            '(': ')',
            '{': '}',
            '[': ']'
        }
        stack = []

        for char in s:
            if char in brackets_map:    #check if starting bracking
                stack.append(char)
            elif stack and char == brackets_map[stack[-1]]:  # matched the closed one 
                stack.pop()
            else:  # no brackets
                return False

        return not stack