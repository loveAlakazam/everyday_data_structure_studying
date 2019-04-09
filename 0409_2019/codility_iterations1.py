def solution(N):
    # write your code in Python 3.6
    ans =[]
    # N을 이진수로 바꾼다. bin(15)=>'0b1111' => bin(15)[2:]='1111'
    binaryN= list(bin(N)[2:])
    
    #binaryN에 0이 존재하지 않는다면 (모두다 1) => 0으로 리턴
    if ('0' in binaryN) is False:
        return 0
    
    #binaryN에 1이 2개미만이면(1개, 또는 없다면) => 0으로 return
    if binaryN.count('1') < 2:
        return 0
    
    #1 ( 0, 0, ..0 ) 1 찾는다. 1사이에있는 0들의 개수가 가장 큰걸 찾는다.
    # '1'의 인덱스번호 출력
    binaryN2=list(enumerate(binaryN))
    ones_idx=[ x[0] for x in binaryN2 if x[1]=='1']
    for x in range(len(ones_idx)-1):
        ans.append(ones_idx[x+1]-ones_idx[x]-1)
    return max(ans)
