# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A, K):
    # write your code in Python 3.6
    #비어있는 리스트이거나 K=0일때
    if len(A)==0 or K==0:
        return A
    
    B=None #tmp 같은 임시 보관 변수
    for i in range(1,K+1):
        B=A[:-1]
        B.insert(0,A[-1])#0번째인덱스에서 A[-1]을 넣는다.
        A=B
    return A
