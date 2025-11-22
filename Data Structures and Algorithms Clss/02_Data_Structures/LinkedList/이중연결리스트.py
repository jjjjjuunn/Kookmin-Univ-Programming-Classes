# ============================================
# 📚 중간고사 범위 (Week 2-7)
# 주제: 자료구조 - 이중 연결 리스트
# ============================================
# 이중 연결 리스트 구현 / tail, count 없는 ver.

'''
	이중 연결 리스트: 알고리즘 구현(Python)
		파일명: DLinkedList(head).py
			- 클래스: DNode
			- 클래스: DLinkedList
				생성자와 소멸자			: __init__, __del__
				노드 확인				: isEmpty, countNode
				노드 탐색				: frontNode, rearNode
				노드 삽입.삭제			: addRear, removeFront
				전체 원소(노드) 출력		: printLinkedList
'''
'''
# 노드(DNode): 데이터(data), 링크(Llink, Rlink)
class DNode:
    def __init__(self, data):
        self.__data = data
        self.__Llink = None
        self.__Rlink = None
    def getData(self):          return self.__data      # getattr(DNode, '__data')
    def getLlink(self):         return self.__Llink     # getattr(DNode, '__Llink')
    def getRlink(self):         return self.__Rlink     # getattr(DNode, '__Rlink')
    def setData(self, data):    self.__data = data      # setattr(DNode, '__data', 'data')
    def setLlink(self, Llink):  self.__Llink = Llink    # setattr(DNode, '__Llink', 'Llink')
    def setRlink(self, Rlink):  self.__Rlink = Rlink    # setattr(DNode, '__Rlink', 'Rlink')

# 이중 연결 리스트: DLinkedList(head)
class DLinkedList:
    def __init__(self):          # 생성자
        self.__head = None       # 첫 번째 노드
        #self.__tail = None     # 맨 마지막 노드
        #self.__count = 0       # 노드의 총 개수

    # 소멸자: 전체 노드 삭제
    def __del__(self):
        # while not self.isEmpty() :
        #     self.removeFront()
        while not self.isEmpty():
            old = self.__head
            self.__head = old.getRlink()
            del old

    # 빈 리스트 여부 판단
    def isEmpty(self) -> bool:
        return self.__head == None

    # 탐색: 노드의 총 개수(count)
    def countNode(self) -> int:
        if self.isEmpty():
            return 0
        
        count = 0
        rNode = self.__head
        while rNode:
            count +=1
            rNode = rNode.getRlink()
        return count

    # 탐색: 첫 번째 노드(head)
    def frontNode(self) -> DNode:
        # if self.isEmpty():
        #    return None
        return self.__head

    # 탐색: 맨 마지막 노드
    def rearNode(self) -> DNode:
        # if self.isEmpty():
        #    return None
        rNode = self.__head
        while rNode.getRlink() :
            rNode = rNode.getRlink()
        return rNode

    # 삽입: 맨 마지막 노드
    def addRear(self, num):
        newNode = DNode(num)
        if self.isEmpty():
            self.__head = newNode
        else:
            rNode = self.rearNode()
            rNode.setRlink(newNode)
            newNode.setLlink(rNode)
            
    # 삭제: 첫 번째 노드(head)
    def removeFront(self) -> None:
        if self.isEmpty():
            return
        
        old = self.__head
        self.__head = old.getRlink()
        if self.__head:
            self.__head.setLlink(None)

        del old

    # 출력: 리스트 전체 노드의 데이터(순방향)
    def printLinkedList(self) -> None:
        if self.isEmpty():
            print('입력된 데이터가 없습니다...')
            return
        
        print(f'\n### 입력된 데이터(순방향): {self.countNode()} ###')
        tNode = self.__head
        while tNode:
            print(f'{tNode.getData()} ->>', end=' ')
            tNode = tNode.getRlink()
        print(' None')
        
    # 출력: 리스트 전체 노드의 데이터(역방향)
    def printRevLinkedList(self) -> None:
        if self.isEmpty():
            print('입력된 데이터가 없습니다...')
            return
        
        print(f'\n### 입력된 데이터(역방향): {self.countNode()} ###')
        rNode = self.rearNode()
        while rNode:
            print(f'{rNode.getData()} ->>', end=' ')
            rNode = rNode.getLlink()
        print(' None')

if __name__ == '__main__':
    # __head = None
    dList = DLinkedList()

    while (True):
        num = int(input('임의의 정수 입력(종료: 0): '))
        if num == 0 :
            break
        # 맨 마지막 노드로 삽입
        dList.addRear(num)

	# 전체 원소 출력
    dList.printLinkedList()         # 순방향 출력
    dList.printRevLinkedList()      # 역방향 출력

    # del dList
	# dList.__del__()
'''

# tail, head 있는 ver
class DNode:
    def __init__(self, data):
        self.__data = data
        self.__Llink = None
        self.__Rlink = None
    def getData(self):          return self.__data      # getattr(DNode, '__data')
    def getLlink(self):         return self.__Llink     # getattr(DNode, '__Llink')
    def getRlink(self):         return self.__Rlink     # getattr(DNode, '__Rlink')
    def setData(self, data):    self.__data = data      # setattr(DNode, '__data', 'data')
    def setLlink(self, Llink):  self.__Llink = Llink    # setattr(DNode, '__Llink', 'Llink')
    def setRlink(self, Rlink):  self.__Rlink = Rlink    # setattr(DNode, '__Rlink', 'Rlink')

# 이중 연결 리스트: DLinkedList(head)
class DLinkedList:
    def __init__(self):          # 생성자
        self.__head = None       # 첫 번째 노드
        self.__tail = None     # 맨 마지막 노드
        self.__count = 0       # 노드의 총 개수

    # 소멸자: 전체 노드 삭제
    def __del__(self):
        # while not self.isEmpty() :
        #     self.removeFront()
        while not self.isEmpty():
            old = self.__head
            self.__head = old.getRlink()
            del old
            self.__count -= 1

    # 빈 리스트 여부 판단
    def isEmpty(self) -> bool:
        return self.__head == None

    # 탐색: 노드의 총 개수(count)
    def countNode(self) -> int:
        '''
        if self.isEmpty():
            return 0
    
        count = 0
        rNode = self.__head
        while rNode:
            count +=1
            rNode = rNode.getRlink()
        '''
        return self.__count

    # 탐색: 첫 번째 노드(head)
    def frontNode(self) -> DNode:
        # if self.isEmpty():
        #    return None
        return self.__head

    # 탐색: 맨 마지막 노드
    def rearNode(self) -> DNode:
        # if self.isEmpty():
        #    return None
        '''
        rNode = self.__head
        while rNode.getRlink() :
            rNode = rNode.getRlink()
        return rNode
        '''
        return self.__tail

    # 삽입: 맨 마지막 노드
    def addRear(self, num):
        newNode = DNode(num)
        if self.isEmpty():
            self.__head = newNode
            self.__tail = newNode
        else:
            self.__tail.setRlink(newNode)
            newNode.setLlink(self.__tail)

        self.__tail = newNode
        self.__count += 1
            
    # 삭제: 첫 번째 노드(head)
    def removeFront(self) -> None:
        if self.isEmpty():
            return
        
        old = self.__head
        self.__head = old.getRlink()

        if self.__head is None:
            self.__tail = None
        else:
            self.__head.setLlink(None)

        del old

        self.__count -= 1
    # 출력: 리스트 전체 노드의 데이터(순방향)
    def printLinkedList(self) -> None:
        if self.isEmpty():
            print('입력된 데이터가 없습니다...')
            return
        
        print(f'\n### 입력된 데이터(순방향): {self.countNode()} ###')
        tNode = self.__head
        while tNode:
            print(f'{tNode.getData()} ->>', end=' ')
            tNode = tNode.getRlink()
        print(' None')
        
    # 출력: 리스트 전체 노드의 데이터(역방향)
    def printRevLinkedList(self) -> None:
        if self.isEmpty():
            print('입력된 데이터가 없습니다...')
            return
        
        print(f'\n### 입력된 데이터(역방향): {self.countNode()} ###')
        rNode = self.rearNode()
        while rNode:
            print(f'{rNode.getData()} ->>', end=' ')
            rNode = rNode.getLlink()
        print(' None')

if __name__ == '__main__':
    # __head = None
    dList = DLinkedList()

    while (True):
        num = int(input('임의의 정수 입력(종료: 0): '))
        if num == 0 :
            break
        # 맨 마지막 노드로 삽입
        dList.addRear(num)

	# 전체 원소 출력
    dList.printLinkedList()         # 순방향 출력
    dList.printRevLinkedList()      # 역방향 출력

    # del dList
	# dList.__del__()