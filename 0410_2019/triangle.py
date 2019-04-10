# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    #내림차순 정렬한다.
    A.sort(reverse=True)
    for i in range(len(A)-2):
        p,q,r=A[i],A[i+1],A[i+2]
        if (p<q+r and q<p+r and r<p+q):
            return 1
    return 0
