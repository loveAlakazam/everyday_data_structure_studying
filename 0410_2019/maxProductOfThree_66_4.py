# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    # 가장큰수 3개 선택 vs 가장작은수2개(음수) 선택
    A.sort(reverse=True) # 내림차순 정렬
    # A[1:] 에서 최댓값 최솟값을 찾는다.
    # result1 = A[0] * A[1] * A[2]
    # result2 = A[0] * A[len(A)-1] * A[len(A)-2]
    maxA=A.pop(0)
    result1, result2=maxA,maxA
    for i in range(2):
        result1*=max(A)
        result2*=min(A)
        A.remove(max(A))
        A.remove(min(A))
    if result1<result2:
        return result2
    return result1
