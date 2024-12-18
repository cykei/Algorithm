# 제곱 ㄴㄴ수
# 2024-12-18 2:15~3:31
# 문제: min과 max가 주어지면, min보다 크거나 같고, max보다 작거나 같은 제곱ㄴㄴ수가 몇 개 있는지 출력한다.
# 풀이: 에라토스트테네스의 체를 이용해서 푸는 문제. 제곱수의 min ~ max 사이의 배수를 제거하는 형식으로 시간복잡도를 줄일 수 있다. 

import sys
import math
input = sys.stdin.readline

min, max = map(int, input().split())
cnt = max+1 - min
li = [0] * (max+1 - min)

for i in range(2, int(math.sqrt(max)) + 1) : # 제곱수
    start = (min // (i*i)) * (i*i)
    for j in range(start, max+1, i*i): # min-max 순회
        if j - min >= 0 and li[j-min] == 0:
            li[j-min] = 1
            cnt -= 1

print(cnt)
