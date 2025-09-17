# Wed Sep 17
# 연습문제 # 0 - 15 -> 자동차 클래스 : 상속과 메소드 재정의
'''
class Car:
    def __init__(self, model = '', color = '', speed = 0):
        self.__model = model
        self.__color = color
        self.__speed = speed

    def getSpeed(self):
        return self.__speed
    
    def setSpeed(self,speed):
        self.__speed = speed
    
    def drive(self):
        pass

    def printCar(self):
        print(f'모델 : {self.__model}, 색깔 : {self.__color}, 속도 : {self.__speed}')

class NewCar(Car):

    def drive(self):
        self.setSpeed(100)
        print(self.getSpeed())

    def upSpeed(self, value):
        self.setSpeed(self.getSpeed() + value)
        print(f'{self.getSpeed()}')

    def downSpeed(self, value):
        self.setSpeed(self.getSpeed() - value)
        print(f'{self.getSpeed()}')

if __name__ == '__main__':
    myCar = NewCar('Porsche', 'Red', 0)
    myCar.printCar()
    myCar.drive()
    myCar.upSpeed(10)
    myCar.downSpeed(10)
'''
