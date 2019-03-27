# https://programmers.co.kr/learn/courses/4008/lessons/13340
num = int(input().strip())
ans=''
if num==1:
    for i in range(65,65+26):
        ans+=chr(i)
    
else: #num==0
    for i in range(97,97+26):
        ans+=chr(i)
print(ans)
