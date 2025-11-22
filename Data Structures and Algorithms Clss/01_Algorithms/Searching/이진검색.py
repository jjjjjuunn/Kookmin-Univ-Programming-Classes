# ============================================
# 📚 중간고사 범위 (Week 2-7)
# 주제: 검색 알고리즘 - 이진 검색
# ============================================
# Fri Sep 26

# BaekJoon 1920 : 수찾기 : Silver 4
'''
import sys

N = int(sys.stdin.readline())
N_list = list(map(int, sys.stdin.readline().split()))   # list 검색: O(N)
# N_list = set(map(int, sys.stdin.readline().split()))   # list 검색: O(1)

M = int(sys.stdin.readline())
M_list = list(map(int, sys.stdin.readline().split()))

for x in M_list:
    print(1) if x in N_list else print(0)
'''
# 연습문제 #3-4 : 이진 검색 : 재귀적 용법
'''
def binarySearch(sList, first: int, last: int, key: int) -> int:
    if first > last:
        return None
    mid = (first + last) // 2

    if key == sList[mid]:
        return mid
    elif key < sList[mid]:
        index = binarySearch(sList, first, mid -1, key)
    elif key > sList[mid]:
        index = binarySearch(sList, mid +1, last, key)

    return index
    

if __name__ == '__main__':
    num_list = [5, 19, 13, 17, 21, 28, 37, 46, 55, 88]
    while True:
        num = int(input("검색 데이터 입력(검색 종료: 0): "))
        if num == 0:
            break
        index = binarySearch(num_list, 0, len(num_list) - 1, num)
        
        if index == None:
            print("해당 값이 존재하지 않습니다.")
        else:
            print(f'검색된 데이터: {index + 1}번째 {num_list[index]}')
'''
# 연습문제 #3-5 : 이진 검색 : 비재귀적 용법
