# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
# retry 44/100
from itertools import combinations
def solution(A):
    # write your code in Python 3.6
    # 조합의 가짓수를 이용.. (중복을 배제)
    cases= list(combinations(A,3))
    max_value=float('-inf') #음의 무한대를 최댓값으로 설정.
    for case in cases:
        result=1
        for i in range(3):
            result*=case[i]
        if result>max_value:
            max_value = result
    return max_value
