# 로또 복권 : 번호 자동 생성
# 사용자가 원하는 매수 만큼 로또 복권의 번호를 자동 생성하여 출력하는 프로그램을 작성하세요.
'''
import random

num = int(input('로또 복권을 몇 장 구입하실래요? : '))

for _ in range(num):
    lotto_num_list = []

    while len(lotto_num_list) < 6:
        lotto_num = random.randint(1,45)
        if lotto_num not in lotto_num_list:
            lotto_num_list.append(lotto_num)

    lotto_num_list.sort()
    print(lotto_num_list)
'''
# 더 간단한 방법 : set을 사용하거나, random.sample을 쓰면 더 간단하게 구현할 수 있다.
'''
import random

num = int(input('몇 장 구매? : '))

for _ in range(num):
    lotto_num_list = random.sample(range(1,46),6)
    lotto_num_list.sort()
    print(lotto_num_list)
'''

# 클래스 : 캡슐화와 정보 은닉
class MyIterator:
    def __init__(self,data):
        self.__data = data
        self.__pos = 0
    # 클래스에 __iter__ 함수 구현 : 해당 클래스로 생성한 객체는 반복 가능한 객체가 된다.
    def __iter__(self):
        return self
    # 클래스에 __iter__함수를 구현할 경우 반드시 __next__함수를 구현해야 한다.
    def __next__(self):
        if self.__pos >= len(self.__data):
            raise StopIteration
        res = self.__data[self.__pos]
        self.__pos += 1
        return res
    
if __name__ == '__main__':
    aIter = MyIterator([10,20,30,40,50])

    it = iter(aIter)
    print(next(it))
    print(next(it))
    print(next(it))
    print(next(it))
    print(next(it))
    print(next(it))

    '''
    for item in aIter:
        print(item)
    '''