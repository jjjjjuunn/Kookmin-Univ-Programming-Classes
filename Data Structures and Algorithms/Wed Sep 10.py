# Wed Sep 10 
# 파이썬 기초 개념 다시 다지는 시간

# 연습문제 #0-6 : 사칙연산 : 예외 처리
'''
x, y, z = input("수식을 입력하세요(예: 10 + 20): ").split()

x = int(x)
z = int(z)

try:
    match y:
        case '+':
            result = x + z
        case '-':
            result = x - z
        case '*':
            result = x * z
        case '/':
            result = x / z
        case default:
            raise Exception('지원하지 않는 연산자입니다.')

except ZeroDivisionError as e : print(f"오류 : {e}") 
except Exception as e : print(f'오류 : {e}')

else:
    print(f'{x} {y} {z} = {result}')
'''

# 연습문제 # 0-10 : 최댓값과 최솟값 반환 함수 : 리스트
# 사용자로부터 임의의 정수를 입력 받아서, 그 중 가장 큰 수와 가장 작은 수를 모두 반환하는 함수를 작성하세요.
def MAXMIN(sList):
    if sList == []:
        return None, None
    max, min = sList[0], sList[0]

    for i in sList:
        if max < i:
            max = i
        if min > i:
            min = i
            
    return max, min

print('임의의 정수를 입력하세요...')
sList = []

i = 0
while True:
    a = input(f'sList[{i}]: ')
    if a == "end" or a == "":
        break
    sList.append(int(a))
    i += 1

result = MAXMIN(sList)

print(f'최대값: {result[0]}, 최소값: {result[1]}')