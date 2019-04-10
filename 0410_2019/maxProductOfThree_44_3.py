def solution(A):
A.sort(reverse=True)
result=1
for i in range(3):
  result*=A[i]
return result  
