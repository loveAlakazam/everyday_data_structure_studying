# codility
# url: https://app.codility.com/programmers/lessons/6-sorting/distinct/
# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    A=list(set(A))
    return len(A)
