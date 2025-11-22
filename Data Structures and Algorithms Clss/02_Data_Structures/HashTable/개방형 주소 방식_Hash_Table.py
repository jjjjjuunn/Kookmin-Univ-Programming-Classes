# ============================================
# 📚 기말고사 범위 (Week 9-12)
# 주제: 해시 테이블 - 개방형 주소 방식 (Open Addressing)
# ============================================
'''
	해시 테이블: 알고리즘 구현(Python) -- 개방형 주소 방식
		파일명: HashOpenAddressing.py
        	- __main__: 데이터 삽입.삭제.검색, 전체 출력
		- 클래스: HashOpenAddressing
			데이터 삽입: insert
			데이터 삭제: delete
			데이터 검색: search
			전체 출력: output
'''

# 클래스 설계: HashOpenAddressing
class HashOpenAddressing: 
    def __init__(self, n:int):
        self.__table = [ None for i in range(n) ]
        self.__count = 0
        self.__DELETED = -54321

    # 해시 함수
    def __Hash(self, i:int, num) -> int:
        return (num + i) % len(self.__table)        # 선형 조사
        # return (num + i*i) % len(self.__table)    # 이차 조사

    # 데이터 삽입.삭제.검색
    def insert(self, num):
        # 1. 테이블이 가득 찼는지 확인
        if self.__count >= len(self.__table):
            print("해시 테이블이 가득 찼습니다!")
            return None
        '''
        #2. 이미 존재하는 값인지 확인 (선택사항)
        if self.search(num):
            print(f"{num}은(는) 이미 존재합니다 !")
            return None
        '''
        # 3. 삽입 시도
        for i in range(len(self.__table)):
            slot = self.__Hash(i, num)
            # \(백슬래시) : 줄 바꿈 연속 기호 : Python에서 긴 코드를 여러 줄로 나눌 때 사용하는 기호
            if self.__table[slot] == None \
            or self.__table[slot] == self.__DELETED:
                self.__table[slot] = num
                self.__count += 1
                return num

        return None
    
    def delete(self, num):
        i = 0
        while i < len(self.__table):
            index = self.__Hash(i, num)

            if self.__table[index] == num:
                self.__table[index] = self.__DELETED
                self.__count -= 1
                print(f'{num} 삭제 성공 !!')
                return True
            
            elif self.__table[index] == None:
                print(f' {num} 은(는)해시 테이블에 존재하지 않습니다. 다시 입력하십시오.')
                return False

            else:
                i += 1  # 그 자리가 __DELETED면 다음 칸도 검사함.

        return None

    def search(self, num):
        i = 0

        while i < len(self.__table):
            index = self.__Hash(i, num)

            if self.__table[index] == num:
                print(f'{num}은 해시 테이블의 index(0~{len(self.__table)-1}): {index}에 존재합니다 !')
                return num
            
            elif self.__table[index] == None:
                return None
            
            else:
                i += 1

        return None

    # 전체 출력
    def output(self) -> None:
        print(f'count({self.__count}): {self.__table}')

if __name__ == '__main__':
    import os		# system
    import sys  	# exit

    h = HashOpenAddressing(13)
    while (True):
        os.system('clear')
        print('\n ### 해시 테이블 ###')
        print('1) 데이터 삽입')
        print('2) 데이터 삭제')
        print('3) 데이터 검색')
        print('4) 전체 출력')
        print('5) 프로그램 종료\n')
        choice = int(input('메뉴 선택: '))

        match choice:
            case 1:
                while True:
                    print(f'\n현재 저장된 데이터: {h._HashOpenAddressing__count}/13')
                    num = int(input('임의의 정수 입력(종료: 0): '))
                    if num == 0: break
                    
                    result = h.insert(num)
                    if result:
                        print(f'✅ {result} 삽입 성공!')
                    else:
                        break

            case 2:
                while True:
                    num = int(input('임의의 정수 입력(종료: 0): '))
                    if num == 0: break
                    h.delete(num)
            case 3:
                while True:
                    num = int(input('임의의 정수 입력(종료: 0): '))
                    if num == 0: break
                    searched = h.search(num)
                    if searched == None:
                        print(f'{num}: 데이터가 존재하지 않습니다 !')
                        
            case 4: h.output()
            case 5:
                sys.exit("\n프로그램 종료!!!")
            case _: print('\n잘못 선택 하셨습니다. \n')
        input("계속하려면 엔터키를 누르십시오.")

    # del h
    # h.__del__