# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    #내림차순 정렬
    A.sort(reverse=True)
    
    ans=[ A[0]*A[1]*A[2], A[0]*A[-1]*A[-2] ]
    return max(ans)
