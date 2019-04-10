# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(X, A):
    # write your code in Python 3.6
    elements=list(range(1,X+1))
    idxs=[]
    for e in elements:
        if (e in A) is False:
            return -1
        
        idxs.append(A.index(e))
    return max(idxs)

#
# trial 4 -> result=54
'''
def solution(X, A):
    # write your code in Python 3.6
    elements=list(range(1,X+1))
    idxs=[]
    for e in elements:
        if (e in A) is False:
            return -1
        
        idxs.append(A.index(e))
    return max(idxs)
'''
