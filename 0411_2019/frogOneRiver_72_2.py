# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(X, A):
    # write your code in Python 3.6
    path=[0]*X
    N= len(A)
    for k in range(N):#0,1,2,...,N
        if path[ A[k]-1]==0:
            path[A[k]-1]=1
        if (0 in path) is False:
            return k
    return -1
