# https://programmers.co.kr/learn/courses/4008/lessons/13323
a, b = map(int, input().strip().split(' '))
print("{} {}".format(int(a//b), (a%b)) )
# // : 몫
# % : 나머지
