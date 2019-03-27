# https://programmers.co.kr/learn/courses/4008/lessons/13326
s, n = input().strip().split(' ')
n = int(n)
print(s.ljust(n))
print(s.center(n))
print(s.rjust(n))
