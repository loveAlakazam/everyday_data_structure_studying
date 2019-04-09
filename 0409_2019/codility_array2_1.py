# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    ans=[]
    eleList= list(set(A))
    for e in eleList:
        ans.append(A.count(e))
    idx=None
    for e in ans:
        if e%2!=0:
            idx=ans.index(e)
            break
    return eleList[idx]
    
    #다시 풀어볼것.
