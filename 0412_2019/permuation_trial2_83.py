# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    #정렬
    A.sort()
    MAX= A[-1]
    B=list(range(1,MAX+1))
    if (len(A)>len(B)) or (len(A)<len(B)):
        return 0
    if A==B:
        return 1
    return 0
