# ============================================
# 📚 기말고사 범위 (Week 9-12)
# 주제: 해시 테이블 - 폐쇄 주소 방식 (Chaining)
# ============================================
# Closed Addressing Methods

class Chaining:
    class SNode:    # 연결 리스트의 노드
        def __init__(self, data):
            self.data= data
            self.link= None

    def __init__ (self, n: int):
        self.__table = [None] * n
        self.__count = 0    # <- 데이터 개수 추적
        self.__MAX_LOAD_FACTOR = 1.5    # <- 임계값

    def __Hash(self, num):
        return num % len(self.__table)
    
    def __get_load_factor(self):
        """현재 로드 팩터 계산"""
        return self.__count / len(self.__table)
    
    def __resize(self):
        """테이블 크기 2배로 확장"""
        print(f'로드 팩터 {self.__get_load_factor():.2f} -> 테이블 확장 !')
        
        old_table = self.__table
        self.__table = [None] * (len(old_table) * 2)
        self.__count = 0

        # 모든 데이터 재삽입 (새로운 해시값으로 !!)
        for slot in old_table:
            tNode = slot
            while tNode:
                self.insert(tNode.data) # 재삽입
                tNode = tNode.link

    def insert(self, num):
        # 0. 로드 팩터 체크
        if self.__get_load_factor() >= self.__MAX_LOAD_FACTOR:
            self.__resize()

        # 1. 해시 함수로 slot 계산
        slot = self.__Hash(num)

        # Case 1: table[slot]이 None (비어있음)
        if self.__table[slot] == None:
            self.__table[slot] = self.SNode(num)
        
        # Case 2: table[slot]에 이미 노드가 있음 (충돌!)
        else:
            tNode = self.__table[slot]
            while tNode.link:
                tNode = tNode.link
            tNode.link = self.SNode(num)

        self.__count += 1
        return num
    
    def search(self, num):
        # 1. 해시 함수로 slot 계산
        slot = self.__Hash(num)
        
        # 2. table[slot]부터 시작
        tNode = self.__table[slot]

        # 3. 연결 리스트 순회하며 찾기
        while tNode:
            if tNode.data == num:
                return num
            tNode = tNode.link

        return None
    
    def delete(self, num):
        slot = self.__Hash(num)
        tNode = self.__table[slot]

        pre = None

        while tNode and tNode.data != num:
            pre = tNode
            tNode = tNode.link
        
        if tNode == None:
            return None
        
        if pre == None:
            self.__table[slot] = tNode.link
        
        else:
            pre.link = tNode.link

        self.__count -= 1
        data = tNode.data
        del tNode
        return data

    def output(self):
        print(f'\n현재 상태: {self.__count}개 / {len(self.__table)} slots')
        print(f'로드 팩터: {self.__get_load_factor():.2f}\n')

        for i in range(len(self.__table)):
            print(f'{i:3}', end='')

            tNode = self.__table[i]
            count = 0
            while tNode:
                print(f' --> {tNode.data}', end='')
                count += 1
                tNode = tNode.link
            
            if count > 3:
                print(f'  ⚠️ ({count}개)', end='')
            
            print('')

if __name__ == '__main__':       
    h = Chaining(13)

    import os
    import sys

    while (True):
        os.system('clear')
        print('\n ### 해시 테이블 ###')
        print('1) 데이터 삽입')
        print('2) 데이터 삭제')
        print('3) 데이터 검색')
        print('4) 전체 출력')
        print('5) 프로그램 종료\n')
        print('메뉴 선택 : ', end=' ')
        choice = int(input())

        if choice == 1:
            while True:
                print(f'입력된 데이터의 개수: {h._Chaining__count}')
                print(f'로드 팩터: {h._Chaining__get_load_factor():.2f}')
                num = int(input('삽입 할 데이터 입력(종료: 0): '))
                if num == 0:
                    break
                inserted = h.insert(num)
                if inserted: print(f'삽입 된 데이터: {inserted}')
                else: print(f'데이터 삽입에 실패하였습니다.')

        elif choice == 2:
            while True:
                num = int(input('삭제 할 데이터 입력(종료: 0): '))
                if num == 0:
                    break
                deleted = h.delete(num)
                if deleted: print(f'삭제 된 데이터: {deleted}')
                else: print(f'데이터가 존재하지 않습니다.')

        elif choice == 3:
            while True:
                num = int(input('검색 할 데이터 입력(종료: 0): '))
                if num == 0:
                    break
                searched = h.search(num)
                if searched: print(f'검색된 데이터: {h._Chaining__Hash(num)} 자리에: {searched}')
                else: print(f'데이터가 존재하지 않습니다.')

        elif choice == 4: h.output()

        elif choice == 5:
            print('프로그램 종료!!!')
            break
        else:
            print('잘못 선택 하셨습니다!')
        
        input("계속 하려면 엔터를 입력하십시오")
        
