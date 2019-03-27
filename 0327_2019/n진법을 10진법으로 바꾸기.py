# https://programmers.co.kr/learn/courses/4008/lessons/13168
num, base = map(int, input().strip().split(' '))
num2= [int(x) for x in list(str(num))] #12->"12"->["1", "2"] ->[1,2] ->(num2.reverse)->[2,1]
num2.reverse()
power=0
result=0
for x in num2:
    result+= x*(base**power)
    power+=1
print(result)
