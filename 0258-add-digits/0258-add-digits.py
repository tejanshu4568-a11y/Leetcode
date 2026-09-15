class Solution:
  def addDigits(self, num: int) -> int:
    while num >= 10:
      total_sum = 0
      while num > 0:
        total_sum += num % 10
        num //= 10
      num = total_sum
    return num