# ============================================
# 📚 중간고사 범위 (Week 2-7)
# 주제: 자료구조 - 단순 연결 리스트
# ============================================
# 단순 연결 리스트
# head만 해서 구현한 건 stack버전으로 바꿔보기 - 중간고사 대비
# head, tail 해서 구현한 건 큐 버전으로 바꿔보기 - 중간고사 대비 
class SNode:
    def __init__(self, data):
        self.__data = data
        self.__link = None
    def getData(self):
        return self.__data
    def getLink(self):
        return self.__link
    def setData(self, data):
        self.__data = data
    def setLink(self,link):
        self.__link = link

class SLinkedList:
    def __init__(self):         # 생성자
        self.__head = None      # 첫 번째 노드
        self.__tail = None    # 맨 마지막 노드
        self.__count = 0      # 노드의 총 개수

    def __del__(self):
        while not self.isEmpty():
            old = self.__head
            self.__head = old.getLink()
            del old
            self.__count -= 1

    def isEmpty(self) -> bool:
        return self.__head == None
    
    def countNode(self) -> int:
        '''
        count = 0
        rNode = self.__head
        while rNode:
            count += 1
            rNode = rNode.getLink()
        return count
        '''
        return self.__count
    
    def frontNode(self) -> SNode:
        return self.__head
    
    def rearNode(self) -> SNode:
        '''
        if self.isEmpty():
            return None
        rNode = self.__head

        while rNode.getLink():
            rNode = rNode.getLink()
        return rNode
        '''
        return self.__tail
    
    def addRear(self, num) -> None:
        newNode = SNode(num)
        if self.isEmpty():
            self.__head = newNode
        else:
            self.__tail.setLink(newNode)

        self.__tail = newNode
        self.__count += 1
    
    def removeFront(self) -> None:
        if self.isEmpty():
            return
        
        old = self.__head
        self.__head = old.getLink()
        
        if self.__head is None:
            self.__tail = None
        
        del old
        self.__count -= 1
    
    def printLinkedList(self) -> None:
        if self.isEmpty():
            print('입력된 데이터가 없습니다 !!!')
            return
        
        print('\n### 입력된 데이터 ###')
        temp = self.__head
        while temp:
            if temp.getLink():
                print(temp.getData(), end = ' -> ')
            else:
                print(temp.getData())
            temp = temp.getLink()

if __name__ == '__main__':
    sList = SLinkedList()

    while(True):
        num = int(input('임의의 정수 입력(종료: 0): '))
        if num == 0:
            break
        sList.addRear(num)

    sList.printLinkedList()
    print(f'노드의 총 개수: {sList.countNode()}')

    if sList.isEmpty():
        print('입력된 데이터가 없습니다 !!!')
    else:
        print(f'첫번째 노드의 데이터: {sList.frontNode().getData()}')
        print(f'마지막 노드의 데이터: {sList.rearNode().getData()}')
    print()
