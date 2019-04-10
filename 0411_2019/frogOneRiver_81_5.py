# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
# (url) 
# https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/
def solution(X, A):
    # write your code in Python 3.6
    path=X*[0]
    N=len(A)
    for k in range(N):
        path[A[k]-1]=1
        if all(path):
            return k
    return -1
