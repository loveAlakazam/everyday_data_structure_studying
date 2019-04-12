# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    A.sort()
    MAX=A[-1]
    A=set(A)
    B=set(range(1,MAX+1))
    if len(A-B)==0  and len(B-A)==0:
        return 1
    return 0
