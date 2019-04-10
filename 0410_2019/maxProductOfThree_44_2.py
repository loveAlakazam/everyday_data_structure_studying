# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    result=1
    for i in range(3):
        #A가 가지고 있는 원소가 모두 똑같은 원소인가?
        if len(set(A))==1:
            result*=A[0]
        
        #A가 가지고 있는 원소가 서로다른 원소인가?
        else:
            result*=max(A)
            A.pop(A.index(max(A)) )
    return result
