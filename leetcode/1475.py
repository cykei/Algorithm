from typing import List

# 문제: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/?envType=daily-question&envId=2024-12-18
# 예시 : 
# Input: prices = [8,4,6,2,3]
# Output: [4,2,4,2,3]
# 각 상품에 할인을 적용한 최종 가격을 구해라. 
# 할인된 가격은 현재 상품 다음으로 현재 상품이하의 가격을 가진 상품의 가격 prices[j] 을 빼서 구한다.

# 제일 쉬운 풀이: O(n^2)
class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        output = [-1] * len(prices)
        for i in range(len(prices)):
            for j in range(i+1, len(prices)):
                if prices[i] >= prices[j]:
                    output[i] = prices[i] - prices[j]
                    break
            if output[i] == -1:
                output[i] = prices[i]
        return output

# 스택을 이용한 풀이: O(n)
class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        stack = [] #prices withou discount
        ans = prices[:]
        for i , price in enumerate(prices):
            while stack and prices[stack[-1]] >= price:
                ans[stack.pop()]-= price
            stack.append(i)
        return ans
