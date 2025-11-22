# ============================================
# 📚 중간고사 범위 (Week 2-7)
# 주제: 재귀 알고리즘 - 팩토리얼
# ============================================
# Fri Sep 19
# 백준 문제 풀이

# BOJ_10872 : 팩토리얼
'''
num = int(input())

mul_total = 1

if num == 0:
    print(1)

else:
    for i in range(1,num + 1):
        mul_total *= i
    print(mul_total)
'''
# 짧은 버전
'''
num = int(input())
m = 1
for i in range(1,num + 1):
    m *= i
print(m)
'''

# BOJ_27434 : 팩토리얼 3
import sys
sys.setrecursionlimit(10**6)

def Factorial(N):
    if N == 0:
        return 1
    return N * Factorial(N - 1)

N = int(input())
print(f"{Factorial(N)}")

# 연습문제 # 2-1 : 최대 공약수 구하기 : 유클리드 알고리즘 : 다시 풀어보기
'''
def GCD(a : int, b : int) -> int:
    if b == 0:
        return a
    return GCD(b, a % b)

if __name__ == '__main__':
    print("임의의 두 정수를 입력하시오.")
    a = int(input('a: '))
    b = int(input('b: '))
    result = GCD(a,b)
    print(f"최대공약수(GCD): {result}")
'''