# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    N=len(A)
    MAX= max(A)
    if N==MAX:
        A.sort()
        B=list(range(1,MAX+1))
        #A=[3,3,3] MAX=3 VS A=[1,2,3] MAX=3
        if A==B:
            return 1
        else:# A!=B
            return 0
    else:# [1, 10]의 경우, [1,3,4]의 경우...
        return 0
        
