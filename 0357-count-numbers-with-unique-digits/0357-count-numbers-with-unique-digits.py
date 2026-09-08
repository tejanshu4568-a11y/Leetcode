class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n == 0:
            return 1
        
        ans = 10
        available_digits = 9
        current_choices = 9
        
        for i in range(2, n + 1):
            current_choices *= available_digits
            ans += current_choices
            available_digits -= 1
            
        return ans