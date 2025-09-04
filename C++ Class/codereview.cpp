// # ** Chapter 2
/* #예제 2-4 : 키보드에서 문자열 입력 받고 출력
#include <iostream>
using namespace std;

int main(void){
    cout << "이름을 입력하세요 >>";

    char name[11];
    cin >> name;

    cout << "이름은 " << name << "입니다.\n";

    return 0;
}
*/
/* #예제 2-5 : C-string을 이용하여 암호가 입력되면 프로그램을 종료하는 예 --> cstring 활용 문제
#include<cstring>
#include<iostream>
using namespace std;

int main(void)
{
    char password[11];
    cout << "프로그램을 종료하려면 암호를 입력하세요." << endl;
    while(true)
    {
        cout<<"암호>>";
        cin >> password;
        if(strcmp(password,"C++")==0)
        {
            cout << "프로그램을 정상 종료합니다." << endl;
            break;
        }
        else
            cout << "암호가 틀립니다 !" << endl;
    }

    return 0;
}
*/
//cin.getline(char buf[],int size, char delimitChar) --> 함수 프로토 타입
/* #예제 2-6 : cin.getline()을 이용한 문자열 입력
#include <iostream>
using namespace std;

int main(void)
{
    cout << "주소를 입력하세요 >>";

    char address[100];
    cin.getline(address,100,'\n');

    cout << "주소는 " << address << "입니다.";
    return 0;
}
*/
// string 클래스 --> C++에서 강력 추천, C++ 표준 클래스. #include<string> 필요, cstring보다 다루기 쉬움
/* #예제 2-7 : string 클래스를 이용한 문자열 입력 및 다루기 --> 다시 보기 --> getline(cin,singer)
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string song("Falling in Love with you");
    string elvis("Elvis Presley");
    string singer;

    cout << song + "를 부른 가수는";
    cout << "(힌트: 첫글자는 " << elvis[0] << ")?" << endl;

    getline(cin,singer);        //암기의 영역
    if(singer == elvis){
        cout << "맞았습니다."<< endl;
    }
    else
        cout << "틀렸습니다." + elvis + "입니다." << endl;

    return 0;
}
*/
// # ** Chapter 3 : 클래스와 객체
/* #예제 3-1 : Circle 클래스의 객체 생성 및 활용
#include<iostream>
using namespace std;

class Circle{
public:
    int radius;
    double getArea();
};                      // class 선언부에 세미콜론 잊지않기

double Circle::getArea(){
    return 3.14*radius*radius;
}

int main(void){
    Circle donut;
    donut.radius = 1;
    double area = donut.getArea();
    cout << "donut 면적은 " << area << endl;

    Circle Pizza;
    Pizza.radius = 30;
    area = Pizza.getArea();
    cout << "Pizza 면적은 "<< area << endl;

    return 0;
}
*/
/* #예제 3-2 : Rectangle 클래스 만들기
#include <iostream>
using namespace std;

class Rectangle{
public:
    int width;
    int height;
    int getArea();
};

int Rectangle :: getArea(){
    return width * height ;
}

int main(void)
{
    Rectangle rect;
    cout << "밑변과 높이의 길이를 입력하시오.>>";
    cin >> rect.width >> rect.height ;

    cout << "사각형의 면적은 " << rect.getArea() << endl;

    return 0;
}
*/
/* #예제 3-3 : 2개의 생성자를 가진 Circle 클래스
#include <iostream>
using namespace std;

class Circle{
public :
    int radius;
    Circle();
    Circle(int r);
    double getArea();
};

Circle :: Circle(){
    radius = 1;
    cout << "반지름" << radius << " 원 생성" << endl;
}

Circle :: Circle(int r){
    radius = r;
    cout << "반지름" << radius << " 원 생성" << endl;
}

double Circle::getArea(){
    return 3.14*radius*radius;
}

int main(void){
    Circle donut;
    double area = donut.getArea();
    cout << "donut 면적은" << area << endl;

    Circle pizza(30);
    area = pizza.getArea();
    cout << "pizza 면적은" << area << endl;

    return 0;
}
*/
/* #예제 3-4 : 생성자에서 다른 생성자 호출 연습(위임 생성자 만들기) --> 아직까지 이 부분을 완벽히 알 필요는 없다.
#include <iostream>
using namespace std;

class Circle{
public:
    int radius;
    Circle();
    Circle(int r);
    double getArea();
};

Circle :: Circle() : Circle(1){}

Circle :: Circle(int r){
    radius = r;
    cout << "반지름 " << radius << " 원 생성." << endl;
}

double Circle :: getArea(){
    return 3.14 * radius * radius;
}

int main(void){
    Circle donut;
    double area = donut.getArea();
    cout << "donut 면적은" << area << endl;

    Circle pizza(30);
    area = pizza.getArea();
    cout << "pizza 면적은" << area << endl;

    return 0;
}
*/
/* #예제 3-6 : Rectangle 클래스 만들기
#include <iostream>
using namespace std;

class Rectangle{
public:
    Rectangle();
    Rectangle(int a, int b);
    Rectangle(int length);
    int width, height;
    bool isSquare();
};

Rectangle :: Rectangle(){
    height = width = 1;
}

Rectangle :: Rectangle(int a, int b){
    width = a;
    height = b;
}

Rectangle :: Rectangle(int length){
    width = height = length;
}

bool Rectangle :: isSquare(){
    if(width == height) return true;
    else return false;
}

int main(void)
{
    Rectangle rect1;
    Rectangle rect2(3,5);
    Rectangle rect3(3);

    if(rect1.isSquare()) cout << "rect1은 정사각형이다." << endl;
    if(rect2.isSquare()) cout << "rect2은 정사각형이다." << endl;
    if(rect3.isSquare()) cout << "rect3은 정사각형이다." << endl;

    return 0;
}
*/
/* #예제 3-7 : Circle 클래스에 소멸자 작성 및 실행
#include <iostream>
using namespace std;

class Circle{
public :
    int radius;
    Circle();
    Circle(int r);
    ~Circle();
    double getArea();
};

Circle :: Circle(){
    radius = 1;
    cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle :: Circle(int r){
    radius = r;
    cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle :: ~Circle(){
    cout << "반지름 " << radius << " 원 소멸" << endl;
}

double Circle::getArea(){
    return 3.14*radius*radius;
}

int main(void){
    Circle donut;
    Circle pizza(30);

    return 0;
}
*/
// **2April
/* **예제 3-8 지역 객체와 전역 객체의 생성 및 소멸 순서
#include <iostream>
using namespace std;

class Circle{
public:
    int radius;
    Circle();
    Circle(int r);
    ~Circle();
    double getArea();
};

Circle :: Circle(){
    radius = 1;
    cout << "반지름" << radius << "원 생성" << endl;
}

Circle::Circle(int r){
    radius = r;
    cout << "반지름" << radius << "원 생성" << endl;
}

Circle :: ~Circle(){
    cout << "반지름" << radius << "원 소멸" << endl; 
}

double Circle :: getArea(){
    return 3.14*radius*radius;
}

Circle globalDonut(1000);
Circle globalPizza(2000);

void f(){
    Circle fDonut(100);
    Circle fPizza(200);
}

int main(void)
{
    Circle mainDonut;
    Circle mainPizza(30);
    f();

    return 0;
}
*/
/* ** Chapter 4 */
/* **예제 4-1 객체 포인터 선언 및 활용
#include <iostream>
using namespace std;

class Circle{
    int radius;
public:
    Circle(){radius = 1;}
    Circle(int r) {radius = r;}
    double getArea();
};

double Circle::getArea(){
    return 3.14*radius*radius;
}

int main(void)
{
    Circle donut;
    Circle Pizza(30);

    cout << donut.getArea() << endl;

    Circle *p;
    p = &donut;

    cout << p->getArea() << endl;
    cout << (*p).getArea() << endl;

    p=&Pizza;
    cout << p->getArea() << endl;
    cout << (*p).getArea() << endl;

    return 0;
}
*/
/* **예제 4-2 Circle 클래스의 배열 선언 및 활용
#include <iostream>
using namespace std;

class Circle{
    int radius;
public:
    Circle(){radius = 1;}
    Circle(int r) {radius = r;}
    void setRadius(int r) {radius = r;}
    double getArea();
};

double Circle::getArea(){
    return 3.14*radius*radius;
}

int main(void)
{
    Circle circleArray[3];

    circleArray[0].setRadius(10);
    circleArray[1].setRadius(20);
    circleArray[2].setRadius(30);

    for(int i = 0 ; i<3 ; i++){
        cout << "Circle" << i << "의 면적은" << circleArray[i].getArea() << endl;
    }

    Circle *p;
    p = circleArray;
    for(int i=0 ; i<3 ; i++){
        cout << "Circle" << i << "의 면적은" << (*p).getArea() << endl;
        p++;
    }


    return 0;
}
*/
/* **예제 4-4 Circle 클래스의 2차원 배열 선언 및 활용
#include <iostream>
using namespace std;

class Circle{
    int radius;
public:
    Circle(){radius = 1;}
    Circle(int r) {radius = r;}
    void setRadius(int r) {radius = r;}
    double getArea();
};

double Circle::getArea(){
    return 3.14 * radius * radius;
}

int main(void)
{
    Circle circles[2][3];
    
    circles[0][0].setRadius(1);
    circles[0][1].setRadius(2);
    circles[0][2].setRadius(3);
    circles[1][0].setRadius(4);
    circles[1][1].setRadius(5);
    circles[1][2].setRadius(6);

    for(int i = 0 ; i<2 ; i++){
        for(int j = 0 ; j<3 ; j++)
        {
            cout << "Circle[" << i << "," << j << "]의 면적은 ";
            cout << circles[i][j].getArea() << endl;
        }
    }

    return 0;
}
*/
/* **예제 4-5 정수형 공간의 동적 할당 및 반환 예
#include <iostream>
using namespace std;

int main(void)
{
    int *p;
    
    p = new int;
    if(!p){
        cout << "메모리를 할당할 수 없습니다.";
        return 0;
    }

    *p = 5;
    int n = *p;
    cout << "*p=" << *p << '\n';
    cout << "n=" << n << '\n';

    delete p;

    return 0;
}
*/
/* **예제 4-6 정수형 배열의 동적 할당 및 반환
#include <iostream>
using namespace std;

int main(void)
{
    cout << "입력할 정수의 개수는?";
    int n;
    cin >> n;
    if(n<=0) return 0;
    int *p = new int[n];
    
    if(!p){
        cout << "메모리를 할당할 수 없습니다.";
        return 0;
    }

    for(int i = 0; i<n ; i++)
    {
        cout << i+1 << "번째 정수 :";
        cin >> p[i];
    }
    
    int sum = 0;
    for(int i =0 ; i<n ; i++){
        sum += p[i];
    }
    cout << "평균 = " << sum/n << endl;

    delete [] p;    //이건 암기의 영역이다.

    return 0;
}
*/
/* **예제 4-7 Circle 객체의 동적 생성 및 반환
#include <iostream>
using namespace std;

class Circle{
    int radius;
public:
    Circle();
    Circle(int r);
    ~Circle();
    void setRadius(int r){radius = r;}
    double getArea() {return 3.14*radius*radius;}
};

Circle :: Circle(){
    radius = 1;
    cout << "생성자 실행 radius = " << radius << endl;
}

Circle::Circle(int r){
    radius = r;
    cout << "생성자 실행 radius = " << radius << endl;
}
 
Circle :: ~Circle(){
    cout << "소멸자 실행 radius = " << radius << endl;
}

int main(void)
{
    Circle *p,*q ;
    p = new Circle;
    q = new Circle(30);
    cout << (*p).getArea() << endl << q->getArea() << endl;

    delete q;
    delete p;

    return 0;
}
*/
/* **예제 4-8 Circle 객체의 동적 생성과 반환 응용
#include <iostream>
using namespace std;

class Circle{
    int radius;
public:
    Circle();
    Circle(int r);
    ~Circle();
    void setRadius(int r){radius = r;}
    double getArea() {return 3.14*radius*radius;}
};

Circle :: Circle(){
    radius = 1;
    cout << "생성자 실행 radius = " << radius << endl;
}

Circle::Circle(int r){
    radius = r;
    cout << "생성자 실행 radius = " << radius << endl;
}
 
Circle :: ~Circle(){
    cout << "소멸자 실행 radius = " << radius << endl;
}

int main(void)
{
    int radius;
    while(true)
    {
        cout << "정수 반지름 입력(음수이면 종료) >>";
        cin >> radius;
        if(radius<0) break;
        Circle *p = new Circle(radius);
        cout << "원의 면적은" << (*p).getArea() << endl;
        delete p;
    }

    return 0;
}
*/
/* **예제 4-9 Circle 배열의 동적 생성 및 반환
#include <iostream>
using namespace std;

class Circle{
    int radius;
public:
    Circle();
    Circle(int r);
    ~Circle();
    void setRadius(int r){radius = r;}
    double getArea() {return 3.14*radius*radius;}
};

Circle :: Circle(){
    radius = 1;
    cout << "생성자 실행 radius = " << radius << endl;
}

Circle::Circle(int r){
    radius = r;
    cout << "생성자 실행 radius = " << radius << endl;
}
 
Circle :: ~Circle(){
    cout << "소멸자 실행 radius = " << radius << endl;
}

int main(void)
{
    Circle *pArray = new Circle[3];

    pArray[0].setRadius(10);
    pArray[1].setRadius(20);
    pArray[2].setRadius(30);

    for(int i=0;i<3;i++)
    {
        cout << pArray[i].getArea() << endl;
    }
    Circle *p = pArray ;
    for(int i =0 ; i<3 ; i++)
    {
        cout << p->getArea() << '\n';
        p++;
    }

    delete [] pArray;

    return 0;
}
*/
/* **예제 4-10 객체 배열의 동적 생성과 반환 응용
#include <iostream>
using namespace std;

class Circle{
    int radius;
public :
    Circle();
    ~Circle(){};
    void setRadius(int r){radius = r;}
    double getArea(){return 3.14 * radius * radius;}
};

Circle :: Circle(){
    radius = 1;
}

int main(void)
{
    cout << "생성하고자 하는 원의 개수 ?";
    int n,radius;
    cin >> n;

    Circle *pArray = new Circle[n];
    for(int i = 0; i<n ; i++){
        cout << "원" << i+1 << ": ";
        cin >> radius;
        pArray[i].setRadius(radius);
    }
    
    int count = 0;
    Circle *p = pArray;
    for(int i = 0 ; i<n ; i++){
        cout << p->getArea() << ' ';
        if(p->getArea() >= 100 && p->getArea()<=200) count++;
        p++;
    }
    cout << endl << "면적이 100에서 200사이인 원의 개수는" << count << endl;

    delete [] pArray;

    return 0;
}
*/
// **9April
/* **예제 4-11 string 클래스를 이용한 문자열 생성 및 출력
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string str;
    string address("서울시 성북구 솔샘로 6길 35-11");
    string copyAddress(address);

    char text[] = {'L','o','v','e',' ','C','+','+','\0'};
    string title(text);

    cout << str << endl;
    cout << address << endl;
    cout << copyAddress << endl;
    cout << title << endl;

    return 0;
}
*/
/* **예제 4-12 string 배열 선언과 문자열 키 입력 응용
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string names[5];
    
    for(int i = 0 ; i<5 ; i++)
    {
        cout << "이름 >>";
        getline(cin,names[i],'\n');
    }

    string latter = names[0];
    for(int i = 1 ; i<5 ; i++)
    {
        if(latter < names[i])
        {
            latter = names[i];
        }
    }
    cout << "사전에서 가장 뒤에 나오는 문자열은" << latter << endl;

    return 0;
}
*/
/* ** Chapter 5 */
/* ** 예제 5-1 : '값에 의한 호출'시 매개 변수의 생성자 실행되지 않음
#include <iostream>
using namespace std;

class Circle{
private:
    int radius;
public:
    Circle();
    Circle(int r);
    ~Circle();
    double getArea(){return 3.14 * radius * radius;}
    int getRadius() {return radius;}
    void setRadius(int radius) {this->radius = radius ;}
};

Circle::Circle(){
    radius = 1;
    cout << "생성자 실행 radius = " << radius << endl;
}

Circle::Circle(int radius){
    this->radius = radius ;
    cout << "생성자 실행 radius = " << radius << endl; 
}

Circle :: ~Circle(){
    cout << "소멸자 실행 radius = " << radius << endl;
}

void increase(Circle c){       
    int r = c.getRadius();
    c.setRadius(r+1);
}

int main(void)
{
    Circle waffle(30);
    increase(waffle);
    cout << waffle.getRadius() << endl;

    return 0;
}
*/
/* ** 예제 5-1 : '주소에 의한 호출'시 매개 변수의 생성자,소멸자 실행되지 않음
#include <iostream>
using namespace std;

class Circle{
private:
    int radius;
public:
    Circle();
    Circle(int r);
    ~Circle();
    double getArea(){return 3.14 * radius * radius;}
    int getRadius() {return radius;}
    void setRadius(int radius) {this->radius = radius ;}
};

Circle::Circle(){
    radius = 1;
    cout << "생성자 실행 radius = " << radius << endl;
}

Circle :: Circle(int radius){
    this->radius = radius ;
    cout << "생성자 실행 radius = " << radius << endl; 
}

Circle :: ~Circle(){
    cout << "소멸자 실행 radius = " << radius << endl;
}

void increase(Circle *p){       
    int r = (*p).getRadius();
    (*p).setRadius(r+1);
}

int main(void)
{
    Circle waffle(30);
    increase(&waffle);
    cout << waffle.getRadius() << endl;

    return 0;
}
*/
// **10 April **참조 개념 중요함 !!! 참조도 당연히 시험에 나옴
/* **예제 5-2 객체 리턴
#include <iostream>
using namespace std;

class Circle{
    int radius;
public:
    Circle(){radius = 1;}
    Circle(int radius){this -> radius = radius;}
    void setRadius(int radius){this -> radius = radius;}
    double getArea(){return 3.14 * radius * radius;}
};

Circle getCircle(){
    Circle tmp(30);
    return tmp;
}

int main(void)
{
    Circle c;
    cout << c.getArea()<<endl;

    c = getCircle();
    cout << c.getArea() << endl;

    return 0;
}
*/
/* **예제 5-3 기본 타입 변수에 대한 참조
#include <iostream>
using namespace std;

int main(void)
{
    cout << "i" << '\t' << "n" << '\t' << "refn" << endl;
    int i =1;
    int n =2;
    int &refn = n;
    n=4;
    refn++;
    cout << i << '\t' << n << '\t' << refn << endl;

    refn = i;
    refn++;
    cout << i << '\t' << n << '\t' << refn << endl;

    int *p = &refn;
    *p = 20;
    cout << i << '\t' << n << '\t' << refn << endl;

    return 0;
}
*/
/* **예제 5-4 객체에 대한 참조
#include <iostream>
using namespace std;

class Circle{
    int radius;
public:
    Circle(){radius = 1;}
    Circle(int radius){this -> radius = radius;}
    void setRadius(int radius){this -> radius = radius;}
    double getArea(){return 3.14 * radius * radius;}
};

int main(void){
    Circle circle;
    Circle &refc = circle;
    refc.setRadius(10);
    cout << refc.getArea() << " " << circle.getArea() << endl;
}
*/
/* **예제 5-5 참조 매개 변수로 평균 리턴하기
#include <iostream>
using namespace std;

bool average(int a[],int size, int& avg){
    if(size <= 0)
    return false;
    int sum = 0;
    for(int i = 0 ; i<size ; i++)
    sum += a[i];
    avg = sum /size;
    return true;
}

int main(void)
{
    int x[] = {0,1,2,3,4,5};
    int avg;
    if(average(x,6,avg)) cout << "평균은" << avg << endl;
    else cout << "매개 변수 오류" << endl;

    if(average(x,-2,avg)) cout << "평균은" << avg << endl;
    else cout << "매개 변수 오류" << endl;

    return 0;
}
*/
/* **예제 5-6 참조에 의한 호출로 Circle 객체에 참조 전달
#include <iostream>
using namespace std;

class Circle{
private:
    int radius;
public:
    Circle();
    Circle(int r);
    ~Circle();
    double getArea() {return 3.14*radius*radius;}
    int getRadius(){return radius;}
    void setRadius(int radius){this -> radius = radius;}
};

Circle :: Circle(){
    radius = 1;
    cout << "생성자 실행 radius = " << radius << endl;
}

Circle::Circle(int radius){
    this -> radius = radius;
    cout << "생성자 실행 radius = " << radius << endl;
}
 
Circle :: ~Circle(){
    cout << "소멸자 실행 radius = " << radius << endl;
}

void increaseCircle(Circle& c){
    int r = c.getRadius();
    c.setRadius(r+1);
}

int main(void)
{
    Circle waffle(30);
    increaseCircle(waffle);
    cout << waffle.getRadius() << endl;

    return 0;
}
*/
/* **예제 5-7 참조 매개 변수를 가진 함수 만들기
#include <iostream>
using namespace std;

class Circle{
    int radius;
public:
    Circle() {radius = 1;}
    Circle(int radius){this -> radius = radius;}
    void setRadius(int radius){this -> radius = radius;}
    double getArea(){return 3.14 * radius *radius;}
};

int readRadius(Circle& c){
    int r;
    cout << "정수 값으로 반지름을 입력하세요 >> ";
    cin >> r;
    c.setRadius(r);
}

int main(void)
{
    Circle donut;
    readRadius(donut);
    cout << "donut의 면적 = " << donut.getArea() << endl;

    return 0;
}
*/
/* **예제 5-8 간단한 참조 리턴 사례
#include <iostream>
using namespace std;

char& find(char s[],int index)
{
    return s[index];
}

int main(void)
{
    char name[] = "Mike";
    cout << name << endl;

    find(name,0) = 'S';
    cout << name << endl;

    char& ref = find(name,2);
    ref = 't';
    cout << name << endl;

    return 0;
}
*/
/* **예제 5-9 Circle의 복사 생성자와 객체 복사
#include <iostream>
using namespace std;

class Circle{
private:
    int radius;
public :
    Circle(const Circle& c); //복사 생성자 선언
    Circle(){radius = 1;}
    Circle(int radius){this -> radius = radius;}
    double getArea(){return 3.14 * radius *radius;} 
};

Circle :: Circle(const Circle& c){
    this -> radius = c.radius;
    cout << "복사 생성자 실행 radius = " << radius << endl;
}

int main(void)
{
    Circle src(30);
    Circle dest(src);   // 객체가 객체를 품었다.

    cout << "원본의 면적 = "<< src.getArea() << endl;
    cout << "사본의 면적 = " << dest.getArea() << endl;
    
    return 0;
}
*/
// Chapter 6 : 함수 중복과 static 멤버
/* 예제 6-1 : big() 함수 중복 연습
#include <iostream>
using namespace std;

int big(int a, int b){
    if(a>b) return a;
    else return b;
}

int big(int a[],int size){
    int res = a[0];
    for(int i=1 ; i<size ; i++){
        if(res<a[i]) res = a[i];
    }
    return res;
}

int main(){
    int array[5] = {1,9,-2,8,6};
    cout << big(2,3) << endl;
    cout << big(array,5) << endl;

    return 0;
}
*/
/* 예제 6-2 : sum() 함수 중복 연습
#include <iostream>
using namespace std;

int sum(int a, int b){
    int s = 0;
    for(int i = a ; i<=b ; i++){
        s += i ;
    }
    return s;
}

int sum(int a){
    int s = 0;
    for(int i = 1 ; i<=a ; i++) s+=i;
    return s;
}

int main(){
    cout << sum(3,5) << endl;
    cout << sum(3) << endl;
    cout << sum(100) << endl;

    return 0;
}
*/
/* 예제 6-3 : 디폴트 매개 변수를 가진 함수 선언 및 호출
#include <iostream>
#include <string>
using namespace std;

void star(int a=5);
void msg(int id, string text ="blank");

void star(int a){
    for(int i=0; i<a; i++) cout << '*';
    cout << endl;
}

void msg(int id, string text){
    cout << id << ' ' << text << endl; 
}

int main()
{
    star();
    star(10);

    msg(10);
    msg(10,"Hello");

    return 0;
}
*/
/* 예제 6-4 : 디폴트 매개 변수를 가진 함수 만들기 연습
#include <iostream>
using namespace std;

void f(char c=' ', int line = 1);

void f(char c, int line){
    for(int i=0; i<line ; i++){
        for(int j=0 ; j<10 ; j++){
            cout << c;
        }
    cout << endl;
    }
}

int main()
{
    f();
    f('%');
    f('@',5);

    return 0;
}
*/
/* 예제 6-5 : 디폴트 매개 변수를 이용하여 중복 함수 간소화 연습
#include <iostream>
using namespace std;

void fillLine(int n=25,char c='*'){
    for(int i=0 ; i<n ; i++){
        cout << c;
    }
    cout << endl;
}

int main()
{
    fillLine();
    fillLine(10,'%');

    return 0;
}
*/
/* 예제 6-6 : 생성자 함수의 중복 간소화
#include<iostream>
using namespace std;

class MyVector{
    int* p;
    int size;
public:
    MyVector(int n=100){
        p = new int [n];
        size = n;
    }
    ~MyVector() {delete [] p;}
};

int main()
{
    MyVector *v1, *v2;
    v1 = new MyVector();
    v2 = new MyVector(1024);

    delete v1;
    delete v2;

    return 0;
}
*/
/* Static 실습
#include <iostream>
using namespace std;

class Person{
public:
    int money;
    void addMoney(int money){
        this->money += money;
    }

    static int sharedMoney;
    static void addShared(int n){
        sharedMoney += n;
    }
};

int Person::sharedMoney = 10;

int main()
{
    Person :: addShared(50);
    cout << Person :: sharedMoney << endl;

    Person han;
    han.money = 100;
    han.sharedMoney = 200;
    Person :: sharedMoney = 300;
    Person :: addShared(100);

    cout << han.money << ' ' 
        << Person :: sharedMoney << endl;
    return 0;
}
*/
/* Chatper 7 */
// Friend ? 내 가족의 일원은 아니지만 내 가족과 동일한 권한을 가진 일원으로 인정받은 사람
/* 예제 7-1: 프렌드 함수 만들기
#include <iostream>
using namespace std;

class Rect;
bool equals(Rect r, Rect s);

class Rect{
    int width, height;
public:
    Rect(int width, int height) {this->width = width; this ->height = height;}
    friend bool equals(Rect r, Rect s);
};

bool equals(Rect r, Rect s){
    if(r.width == s.width && r.height == s.height) return true;
    else return false;
}

int main()
{
    Rect a(3,4),b(4,5);
    if(equals(a,b)) cout << "equal" << endl;
    else cout << "not equal" << endl;

    return 0;
}
*/
/* 예제 7-2 : 다른 클래스의 멤버 함수를 프렌드로 선언
#include <iostream>
using namespace std;

class Rect;

class RectManager{
public:
    bool equals(Rect r, Rect s);
};

class Rect{
    int width, height;
public:
    Rect(int width, int height){this-> width = width; this->height = height;}
    friend bool RectManager :: equals(Rect r, Rect s);
};
bool RectManager :: equals(Rect r, Rect s){
        if(r.width == s.width && r.height == s.height) return true;
        else return false;
}

int main()
{
    Rect a(3,4), b(3,4);
    RectManager man;

    if(man.equals(a,b)) cout << "equal" << endl;
    else cout << "not equal" << endl;

    return 0;
}
*/
/* 예제 7-3 : 다른 클래스 전체를 프렌드로 선언
#include <iostream>
using namespace std;

class Rect;

class RectManager{
public:
    bool equals(Rect r, Rect s);
    void copy(Rect& dest, Rect& src);
};

class Rect{
    int width, height;
public:
    Rect(int width, int height){this -> width = width; this ->height = height;}
    friend RectManager;
};

bool RectManager :: equals(Rect r, Rect s){
    if(r.width == s.width && r.height == s.height) return true;
    else return false;
}

void RectManager :: copy(Rect& dest, Rect& src){
    dest.width = src.width; dest.height = src.height;
}

int main()
{
    Rect a(3,4),b(5,6);
    RectManager man;

    man.copy(b,a);
    if(man.equals(a,b)) cout << "equal" << endl;
    else cout << "not equal" << endl;

    return 0;
}
*/
/* 예제 7-4 : 두 개의 Power 객체를 더하는 +연산자 작성
#include <iostream>
using namespace std;

class Power{
    int kick;
    int punch;
public:
    Power(int kick = 0, int punch =0){
        this->kick = kick; this->punch = punch;
    }
    void show();
    Power operator+ (Power op2);
};

void Power :: show(){
    cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power Power :: operator+ (Power op2){
    Power tmp;
    tmp.kick = this->kick + op2.kick;
    tmp.punch = this->punch + op2.punch;
    return tmp;
}

int main()
{
    Power a(3,5),b(4,6),c;
    c = a+b ;
    a.show();
    b.show();
    c.show();

    return 0;
}
*/
/* 예제 7-5 : 두 개의 Power 객체를 비교하는 == 연산자 작성
#include <iostream>
using namespace std;

class Power{
    int kick;
    int punch;
public:
    Power(int kick = 0, int punch =0){
        this->kick = kick; this->punch = punch;
    }
    void show();
    bool operator== (Power op2);
};

void Power :: show(){
    cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

bool Power :: operator== (Power op2){
    if(this->kick == op2.kick && this->punch == op2.punch) return true;
    else return false;
}

int main(){
    Power a(3,5), b(3,5);
    a.show();
    b.show();
    if(a==b) cout << "두 파워가 같다." << endl;
    else cout << "두 파워가 다르다" << endl;

    return 0;
}
*/
/* 예제 7-6 : 두 Power 객체를 더하는 += 연산자 작성
#include <iostream>
using namespace std;

class Power{
    int kick;
    int punch;
public:
    Power(int kick = 0, int punch =0){
        this->kick = kick; this->punch = punch;
    }
    void show();
    Power& operator += (Power op2);
};

void Power :: show(){
    cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power& Power :: operator+=(Power op2){
    kick = kick + op2.kick;
    punch = punch + op2.punch;
    return *this;
}

int main()
{
    Power a(3,5),b(4,6),c;
    a.show();
    b.show();
    c = a += b;
    a.show();
    c.show();

    return 0;
}
*/
/* 멤버 함수로 단항 연산자 구현 ** 잘 봐두기 */
/* 예제 7-8 : 전위 ++ 연산자 작성
#include <iostream>
using namespace std;

class Power{
    int kick;
    int punch;
public:
    Power(int kick = 0, int punch =0){
        this->kick = kick; this->punch = punch;
    }
    void show();
    Power& operator++ ();
};

void Power :: show(){
    cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power& Power :: operator++(){
    kick ++;
    punch ++;
    return *this;
}

int main()
{
    Power a(3,5),b;
    a.show();
    b.show();
    b = ++a;
    a.show();
    b.show();

    return 0;
}
*/
/* 예제 7-9 : Power 클래스에 ! 연산자 작성
#include <iostream>
using namespace std;

class Power{
    int kick;
    int punch;
public:
    Power(int kick = 0, int punch =0){
        this->kick = kick; this->punch = punch;
    }
    void show();
    bool operator! ();
};

void Power :: show(){
    cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

bool Power :: operator!(){
    if(kick==0 && punch==0) return true;
    else return false;
}

int main()
{
    Power a(0,0),b(5,5);
    if(!a) cout << "a의 파워가 0이다." << endl;
    else cout << "a의 파워가 0이 아니다." << endl;

    if(!b) cout << "b의 파워가 0이다." << endl;
    else cout << "b의 파워가 0이 아니다." << endl;

    return 0;
}
*/
/* 예제 7-10 : 후위 ++ 연산자 작성
#include <iostream>
using namespace std;

class Power{
    int kick;
    int punch;
public:
    Power(int kick = 0, int punch =0){
        this->kick = kick; this->punch = punch;
    }
    void show();
    Power operator++ (int x);
};

void Power :: show(){
    cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power Power :: operator++(int x){
    Power tmp = *this;
    kick ++;
    punch ++;
    return tmp;
}

int main()
{
    Power a(3,5),b;
    a.show();
    b.show();
    b = a++;
    a.show();
    b.show();

    return 0;
}
*/
/* 예제 7-11 : 2+a를 위한 + 연산자 함수를 프렌드로 작성
#include <iostream>
using namespace std;

class Power{
    int kick;
    int punch;
public:
    Power(int kick = 0, int punch =0){
        this->kick = kick; this->punch = punch;
    }
    void show();
    friend Power operator+(int op1, Power op2);
};

void Power :: show(){
    cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power operator+(int op1, Power op2){
    Power tmp;
    tmp.kick = op1 + op2.kick;
    tmp.punch = op1 + op2.punch;
    return tmp;
}

int main()
{
    Power a(3,5),b;
    a.show();
    b.show();
    b = 2+a;
    a.show();
    b.show();

    return 0;
}
*/
/* 예제 7-12 : a+b를 위한 연산자 함수를 프렌드로 작성 
#include <iostream>
using namespace std;

class Power{
    int kick;
    int punch;
public:
    Power(int kick = 0, int punch =0){
        this->kick = kick; this->punch = punch;
    }
    void show();
    friend Power operator+(Power op1, Power op2);
};

void Power :: show(){
    cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power operator +(Power op1,Power op2){
    Power tmp;
    tmp.kick = op1.kick + op2.kick;
    tmp.punch = op1.punch + op2.punch;
    return tmp;
}

int main()
{
    Power a(3,4),b(4,5),c;
    c = a+b;

    a.show();
    b.show();
    c.show();

    return 0;
}
*/
/* 예제 7-13 : ++연산자를 프렌드로 작성한 예 -- 매개변수 &는 필수, 리턴타입 &는 경우에 따라!
#include <iostream>
using namespace std;

class Power{
    int kick;
    int punch;
public:
    Power(int kick = 0, int punch =0){
        this->kick = kick; this->punch = punch;
    }
    void show();
    friend Power& operator++(Power& op1);
    friend Power operator++(Power& op1, int x);
};

void Power :: show(){
    cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power& operator++(Power& op1){              // 전위 ++
    op1.kick ++;
    op1.punch ++;
    return op1;
}

Power operator++(Power& op1, int x){        // 후위 ++
    Power tmp = op1;
    op1.kick ++;
    op1.punch ++;
    return tmp;
}

int main()
{
    Power a(3,5),b;
    b = ++a;
    a.show(); b.show();

    b = a++;
    a.show(); b.show();

    return 0;
}
*/
/* 예제 7-14 : 참조를 리턴하는 << 연산자 작성(Power vs Power& 차이 고찰 : 지속 연산자 실행)
#include <iostream>
using namespace std;

class Power{
    int kick;
    int punch;
public:
    Power(int kick = 0, int punch =0){
        this->kick = kick; this->punch = punch;
    }
    void show();
    Power operator << (int n);
};

void Power :: show(){
    cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power Power :: operator<< (int n){
    kick += n;
    punch += n;
    return *this;
}

int main()
{
    Power a(1,2),b;
    b = a << 3 << 5 << 6;

    a.show();
    b.show();

    return 0;
}
*/
// Chapter 8 : 상속
/* 예제 8-1 : Point 클래스를 상속받는 ColorPoint 클래스 만들기
#include <iostream>
#include <string>
using namespace std;

class Point{
    int x,y;
public:
    void set(int x, int y){this->x = x; this->y = y;}
    void showPoint(){
        cout << "(" << x << "," << y << ")" << endl;
    }
};

class ColorPoint : public Point {
    string color;
public:
    void setColor(string color) {this -> color = color;}
    void showColorPoint();
};

void ColorPoint :: showColorPoint(){
    cout << color << ":";
    showPoint();
}

int main()
{
    Point p;
    ColorPoint cp;
    cp.set(3,4);
    cp.setColor("Red");
    cp.showColorPoint();

    return 0;
}
*/
/* ** 업캐스팅과 다운캐스팅 실습
#include <iostream>
#include <string>
using namespace std;

class Point{
    int x,y;
public:
    void set(int x, int y){this->x = x; this->y = y;}
    void showPoint(){
        cout << "(" << x << "," << y << ")" << endl;
    }
};

class ColorPoint : public Point {
    string color;
public:
    void setColor(string color) {this -> color = color;}
    void showColorPoint();
};

void ColorPoint :: showColorPoint(){
    cout << color << ":";
    showPoint();
}

int main() {
	ColorPoint cp;
	ColorPoint *pDer;
	Point* pBase = &cp; // 업캐스팅

	pBase->set(3,4); 
	pBase->showPoint(); 

	pDer = (ColorPoint *)pBase; // 다운캐스팅
	pDer->setColor("Red"); // 정상 컴파일
	pDer->showColorPoint(); // 정상 컴파일

    return 0;
}
*/
/* 예제 8-3 : TV, WideTV, SmartTV 생성자 매개 변수 전달
#include <iostream>
#include <string>
using namespace std;

class TV{
    int size;
public:
    TV(){size = 20;}
    TV(int size){this -> size = size;}
    int getSize(){return size;}
};

class WideTV : public TV{
    bool videoln;
public:
    WideTV(int size, bool videoln):TV(size){
        this->videoln = videoln;
    }
    bool getVideoln() {return videoln;}
};

class SmartTV : public WideTV{
    string ipAddr;
public:
    SmartTV(string ipAddr,int size): WideTV(size,true){
        this->ipAddr = ipAddr;
    }
    string getIpAddr() {return ipAddr;}
};

int main()
{
    SmartTV htv("192.0.0.1",32);
    cout << "size=" << htv.getSize() << endl;
    cout << "videoln=" << boolalpha <<htv.getVideoln() << endl;
    cout << "IP=" << htv.getIpAddr() << endl;

    return 0;
}
*/
/* 예제 8-7 : Adder와 Subtractor를 다중 상속 받는 Calculator 클래스 작성
#include<iostream>
using namespace std;

class Adder{
protected:
    int add(int a, int b){return a+b;}
};

class Subtractor{
protected:
    int sub(int a, int b){return a-b;}
};

class Calculator : public Adder,public Subtractor{
public:
    int calc(char op, int a, int b);
};

int Calculator :: calc(char op, int a, int b){
    int res=0;
    switch(op){
        case '+': res = add(a,b); break;
        case '-': res = sub(a,b); break;
    }
    return res;
}

int main(){
    Calculator handCalculator;
    cout << "2 + 4 = " << handCalculator.calc('+',2,4) << endl;
    cout << "100 - 8 = " << handCalculator.calc('-',100,8) << endl;

    return 0;
}
*/
// Chapter 9 : 가상 함수와 추상 클래스
// 함수 재정의,**오버라이딩,동적 바인딩 ! 
/* 예제 9-1 : 파생클래스에서 함수를 재정의 하는 사례
#include <iostream>
using namespace std;

class Base{
public:
    void f(){cout << "Base::f() called" << endl;}
};

class Derived : public Base {
public:
    void f() {cout << "Derived::f() called" << endl;}
};

int main()
{
    Derived d, *pDer;
    pDer = &d;
    pDer -> f();

    Base* pBase;
    pBase = pDer; // 업캐스팅
    pBase -> f();

    return 0;
}
*/
/* 예제 9-2 : 오버라이딩과 가상 함수 호출
#include <iostream>
using namespace std;

class Base{
public:
    virtual void f(){cout << "Base::f() called" << endl;}
};

class Derived : public Base {
public:
    virtual void f() {cout << "Derived::f() called" << endl;}
};

int main()
{
    Derived d, *pDer;
    pDer = &d;
    pDer -> f();

    Base* pBase;
    pBase = pDer; // 업캐스팅
    pBase -> f();

    return 0;
}
*/
/* 예제 9-3 : 상속이 반복되는 경우 가상 함수 호출
#include <iostream>
using namespace std;

class Base{
public:
    virtual void f() {cout << "Base::f() called"<< endl;}
};

class Derived : public Base{
public :
    void f() {cout << "Derived::f() called" << endl;}
};

class GrandDerived : public Derived{
public :
    void f() {cout << "GrandDerived::f() called" << endl;}
};

int main()
{
    GrandDerived g;
    Base *bp;
    Derived *dp;
    GrandDerived *gp;

    bp = dp = gp = &g;

    bp -> f();
    dp -> f();
    gp -> f();



    return 0;
}
*/
/* 예제 9-4 : 범위 지정 연산자(::)를 이용한 기본 클래스의 가상 함수 호출
#include <iostream>
using namespace std;

class Shape{
public :
    virtual void draw(){
        cout << "--Shape--";
    }
};

class Circle : public Shape{
public:
    void draw(){
        Shape :: draw();
        cout << "Circle" << endl;
    }
};

int main(){
    Circle circle;
    Shape *pShape = &circle;

    pShape -> draw();
    pShape -> Shape :: draw();
}
*/
// Chapter 10 : 템플릿과 표준 템플릿 라이브러리(STL)
/* 예제 10-1 : 제네릭 myswap() 함수 만들기
#include <iostream>
using namespace std;

class Circle{
    int radius;
public :
    Circle(int radius =1) {this->radius = radius;}
    int getRadius() {return radius;}
};

template <class T>
void myswap(T&a, T&b){
    T tmp;
    tmp = a;
    a = b;
    b= tmp;
}

int main()
{
    int a = 4, b=5;
    myswap(a,b);
    cout << "a=" << a << "," << "b=" << b << endl;

    double c = 0.3 , d = 12.5;
    myswap(c,d);
    cout << "c=" << c << "," << "d=" << d << endl;

    Circle donut(5), pizza(20);
    myswap(donut,pizza);
    cout << "donut 반지름 = " << donut.getRadius() << endl;
    cout << "pizza 반지름 = " << pizza.getRadius() << endl;

    return 0;
}
*/
/* 예제 10-2 : 큰 값을 리턴하는 bigger() 함수 만들기 연습
#include <iostream>
using namespace std;

template <class T>
T bigger(T a, T b){
    if(a>b)
        return a;
    else return b;
}

int main()
{
    int a = 20, b= 50;
    char c = 'a', d= 'z';
    cout << "bigger(20,50)의 결과는" << bigger(a,b) << endl;
    cout << "bigger('a','z')의 결과는 " << bigger(c,d) << endl;

    return 0;
}
*/
/* 예제 10-3 : 배열의 합을 구하여 리턴하는 제네릭 add() 함수 만들기 연습
#include <iostream>
using namespace std;

template <class T>
T add(T data[], int n){
    T sum = 0;
    for(int i = 0 ; i<n ; i++){
        sum += data[i];
    }
    return sum;
}

int main()
{
    int x[] = {1,2,3,4,5};
    double d[] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7};

    cout << "sum of x[] = " << add(x,5) << endl;
    cout << "sum of d[] = " << add(d,6) << endl;

    return 0;
}
*/
/* 예제 10-4 : 배열을 복사하는 제네릭 함수 mcopy() 함수 만들기 연습
#include <iostream>
using namespace std;

template <class T1, class T2>
void mcopy(T1 src[],T2 dest[],int n){
    for(int i=0 ; i<n ; i++){
        dest[i] = (T2)src[i];
    }
}

int main()
{
    int x[] = {1,2,3,4,5};
    double d[5];
    char c[5] = {'H','e','l','l','o'};
    char e[5];

    mcopy(x,d,5);
    mcopy(c,e,5);

    for(int i=0;i<5 ; i++) cout << d[i] << ' ';
    cout << endl;
    for(int i=0 ; i<5 ; i++) cout << e[i] << ' ';
    cout << endl;

    return 0;
}
*/
/* 예제 10-9 : vector 컨테이너 활용하기
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for(int i=0 ; i<v.size() ; i++){
        cout << v[i] << " ";
    }
    cout << endl;

    v[0] = 10;
    int n = v[2];
    v.at(2) = 5;
    
    for(int i=0 ; i<v.size() ; i++ ){
        cout << v[i] <<" ";
    }
    cout << endl;

    return 0;
}
*/
/* 예제 10-10 : 문자열을 저장하는 벡터 만들기 연습
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> sv;
    string name;

    cout << "이름을 5개 입력하라" << endl;
    for(int i=0 ; i<5 ; i++){
        cout << i+1 << ">>";
        getline(cin,name);
        sv.push_back(name);
    }
    name = sv.at(0);
    for(int i=1 ; i<sv.size() ; i++){
        if(name < sv[i]) name = sv[i];
    }
    cout << "사전에서 가장 뒤에 나오는 이름은 " << name << endl;

    return 0;
}
*/
/* 예제 10-11 : iterator를 사용하여 vector 의 모든 원소에 2 곱하기
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vector<int>:: iterator it;

    for(it = v.begin(); it != v.end() ; it++){
        int n = *it;
        n = n*2;
        *it = n;
    }

    for(it = v.begin() ; it != v.end() ; it++){
        cout << *it << ' ';
    }
    cout << endl;

    return 0;
}
*/
/* 예제 10-13 : sort() 함수를 이용한 vector 소팅
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;
    cout << "<<5개의 정수를 입력하세요>>" ;
    for(int i=0 ; i<5 ; i++){
        int n;
        cin >> n;
        v.push_back(n);
    }

    sort (v.begin(),v.end(),greater<int>());

    vector<int> :: iterator it;

    for(it = v.begin(); it != v.end() ; it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
*/
// ** C++ 코드 짜는 연습 **
/*
#include <iostream>
using namespace std;

const double PI = 3.14159;

class Circle {
private:
    double radius;
public:
    Circle() : radius(1) {}
    Circle(double rad) : radius(rad) {}
    double getArea();
    double getCircumference();
};

double Circle :: getArea(){
    return PI*radius*radius;
}

double Circle :: getCircumference(){
    return 2*PI*radius;
}

int main()
{
    Circle circle1, circle2(3);
    
    cout << "원1의 넓이 : " << circle1.getArea() << endl;
    cout << "원2의 넓이 : " << circle2.getArea() << endl;
    cout << "원1의 원주 : " << circle1.getCircumference() << endl;
    cout << "원2의 원주 : " << circle2.getCircumference() << endl;

    return 0;
}
*/
/*
#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;
public:
    Rectangle() : length(1), width(1) {}
    Rectangle(double l, double w) : length(l),width(w) {}
    double CalculateArea();
    double CalculatePerimeter();
};

double Rectangle::CalculateArea(){
    return length*width;
}

double Rectangle::CalculatePerimeter(){
    return 2*length + 2*width;
}

int main()
{
    double width, length;
    cout << "Set width and length !" << endl;
    cout << "width : ";
    cin >> width ;
    cout << "length : ";
    cin >> length;

    Rectangle rect(length,width), rect1;
    
    double Area;
    Area = rect.CalculateArea();
    cout << "Area : " << Area << endl;
    cout << "Area 2 : " << rect1.CalculateArea() << endl;

    double Perimeter;
    Perimeter = rect.CalculatePerimeter();

    cout << "Perimeter : " << Perimeter << endl;
    

    return 0;
}
*/
/*
#include <iostream>
using namespace std;

const double PI = 3.14;

class Shape{
public:
    virtual double CalArea() = 0 ;
    virtual double CalPerimeter() = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle() : radius(1) {}
    Circle(double rad) : radius(rad) {}
    double CalArea() override {return PI*radius*radius;}
    double CalPerimeter() override {return 2*PI*radius;}
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle() : length(1), width(1) {}
    Rectangle(double len, double wid) : length(len),width(wid) {}
    double CalArea()override {return length * width;}
    double CalPerimeter()override {return 2*(length+width);}
};

int main()
{
    Circle circle1;
    Rectangle rect1;

    cout << "원의 면적 : " << circle1.CalArea() << endl;
    cout << "사각형의 면적 : " << rect1.CalArea() << endl;
    cout << "원의 둘레 : " << circle1.CalPerimeter() << endl;
    cout << "사각형의 둘레 : " << rect1.CalPerimeter() << endl; 

    return 0;
}
*/
/*
#include <iostream>
#include <string>
using namespace std;

class Triangle {
private:
    double side1,side2,side3;
public:
    Triangle() : side1(3), side2(4), side3(5) {}
    Triangle(double s1,double s2, double s3) : side1(s1) ,side2(s2), side3(s3) {}
    void typedetermine();
};

void Triangle :: typedetermine(){
    if(side1 == side2 and side1 == side3){
        cout << "Equilateral Triangle" << endl;
    }
    else if(side1 == side2 or side2 == side3 or side1 == side3){
        cout << "Isosceles Triangle" << endl;
    }
    else cout << "Scalene Triangle" << endl;
}


int main()
{
    Triangle tri1,tri2(3,3,3), tri3(1,3,3), tri4(1,1,3), tri5(1,3,1);
    cout << "tri1 : ";
    tri1.typedetermine();

    cout << "tri2 : ";
    tri2.typedetermine();

    cout << "tri3 : ";
    tri3.typedetermine();

    cout << "tri4 : ";
    tri4.typedetermine();

    cout << "tri5 : ";
    tri5.typedetermine();


    return 0;
}
*/
// 정렬 알고리즘 구현 해보기
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int array[5] = {};

    for(int i = 0 ; i < 5 ; i++){
        cout << "array[" << i << "] : " ;
        cin >> array[i] ;
    }
    for(int i = 0 ; i < 5 ; i++ ){
        cout << array[i] << " ";
    }
    cout << endl << "sorting..." << endl;

    for(int i = 0 ; i<5 ; i++){
        for(int j = i+1 ; j<5 ; j++){
            if(array[i]>array[j]){
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
    for(int i = 0 ; i < 5 ; i++){
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
*/

/*
int big(int a, int b){
    if(a>b) return a;
    else return b;
}

int big(int a[],int size){
    int res = a[0];
    for(int i = 1 ; i < size ; i++){
        if(res < a[i]) res = a[i];
    }
    return res;
}
int main(){
    int array[5] = {1,9,-2,8,6};
    cout << big(2,3) << endl;
    cout << big(array,5) << endl;

    return 0;
}
*/
/*
class MyVector{
private:
    int *p;
    int size;
public:
    MyVector(int n = 100){p=new int[n], size = n;}
    ~MyVector() {delete [] p;}
};

int main()
{
    MyVector *v1,*v2;

    v1 = new MyVector();
    v2 = new MyVector(1024);

    delete v1;
    delete v2;

    return  0;
}
*/
/*
class Power {
	int kick; 
	int punch; 
public:
	Power(int kick=0, int punch=0) {
		this->kick = kick; this->punch = punch;
	}
	void show();
	Power& operator+= (Power op2); // += 연산자 함수 선언
};

void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power& Power::operator+=(Power op2) {
	kick = kick + op2.kick; // kick 더하기
	punch = punch + op2.punch; // punch 더하기
	return *this; // 합한 결과 리턴
}

int main() {
	Power a(3,5), b(4,6), c;
	a.show();
	b.show();
	c = a += b; // 파워 객체 더하기
	a.show();
	c.show();
}
*/
/*
class Circle{
    int radius;
public:
    Circle() : radius(1) {}
    Circle(int rad) : radius(rad) {}
    int getRadius() {return radius;}
};

template <class T>
void mySwap(T & a, T &b ){
    T tmp;
    tmp =a;
    a = b;
    b = tmp;
}

template<class T1,class T2>
void mySwap(T1& a, T2& b){
    a = a+b;
}


int main(){
    int a = 4, b = 5;
    mySwap(a,b);
    cout << "a: " << a << ", b: " << b << endl;

    double c = 0.3 , d = 12.5 ;
    mySwap(c,d);
    cout << "c: " << c << ", d: " << d << endl;

    Circle donut, pizza(30);
    mySwap(donut,pizza);
    cout << "donut: " << donut.getRadius() << ", pizza: " << pizza.getRadius() << endl;

    return 0;
}
*/
/*
#include <vector>

int main()
{
    vector<int> v;
    v.push_back(4);
    v.push_back(8);
    v.push_back(16);

    vector<int>::iterator it;

    for(it=v.begin() ; it!=v.end() ; it++){
        int n = *it;
        n = n*2;
        *it = n;
    }

    for(it=v.begin() ; it != v.end() ; it++){
        cout << *it << " " ;
    }
    cout << endl;

    return 0;
}
*/
/*
#include <vector>
#include <algorithm>

int main()
{
    vector <int> v;

    cout << "5개의 정수를 입력하세요 >> ";
    for(int i = 0 ; i<5 ; i++){
        int n;
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(),v.end(),greater<int>());

    for(auto it=v.begin(); it!=v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
*/
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class ArrayData{
    int output[5] = { 0, };
public:
    ArrayData(int input[5]);
    void AscendingOrderFunction();
    void DescendingOrderFunction();
    friend void MaxMinFunction(ArrayData P);   
    ArrayData operator +(ArrayData Q);          
    int* getArray();                        // 추가 구현
    void ShowArray() const;                 // 추가 구현
};

ArrayData :: ArrayData(int input[5]) {
    for(int i = 0 ; i<5 ; i++){
        this->output[i] = input[i];
    }
}

void ArrayData :: AscendingOrderFunction(){
    
    cout << "ascending" << endl;

    vector<int> int_v;
    for(int i = 0 ; i<5 ; i++){
        int_v.push_back(this->output[i]);
    }
    sort(int_v.begin(),int_v.end());

    for(auto it = int_v.begin() ; it!= int_v.end() ; it++){
        cout << *it << " ";
    }
    cout << endl;

    for(int i = 0 ; i<5 ; i++){
        output[i] = int_v.at(i);
    }
}

void ArrayData :: DescendingOrderFunction(){
    
    cout << "descending" << endl;
    vector<int> int_v;
    for(int i = 0 ; i<5 ; i++){
        int_v.push_back(this->output[i]);
    }
    sort(int_v.begin(),int_v.end(),greater<int>());

    for(auto it = int_v.begin() ; it!= int_v.end() ; it++){
        cout << *it << " ";
    }
    cout << endl;
        for(int i = 0 ; i<5 ; i++){
        output[i] = int_v.at(i);
    }
}

void MaxMinFunction(ArrayData P){
    cout << "MaxMin" << endl;
    int max = P.output[0], min = P.output[0];
    for(int i =1 ; i<5 ; i++){
        if(max < P.output[i]) max = P.output[i];
    }
    for(int i =1 ; i<5 ; i++){
        if(min > P.output[i]) min = P.output[i];
    }
    cout << "Max value is " << max << endl;
    cout << "Min value is " << min << endl;
}

ArrayData ArrayData :: operator +(ArrayData Q){
    int resArray[5];
    cout << "operator+" << endl;
    for(int i = 0 ; i<5 ; i++){
        resArray[i]= this->output[i] + Q.output[i];
    }
    return ArrayData(resArray);
}

int* ArrayData :: getArray() {
    return output;
}

void ArrayData :: ShowArray()const {
    for(int i = 0 ; i < 5 ; i++){
        cout << output[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "[[ 2nd Coding Assignment ]]" << endl;
    cout << "Write the five integer between 0 and 100: ";

    int int_array[5] = {};

    for(int i = 0 ; i<5 ; i++){
        cin >> int_array[i];
    }

    for(int i = 0 ; i<5 ; i++){
        if(int_array[i]<0 or int_array[i] > 100){
            cout << "Input is incorrect. So, this program is over ." << endl;
            exit(0);
        }
        for(int j = i+1 ; j<5 ; j++){
            if(int_array[i] == int_array[j]){
                cout << "Input is incorrect. So, this program is over ." << endl;
                exit(0);
            }
        }
    }

    for(int i = 0 ; i<5 ; i++){
        cout << int_array[i] << ' ';
    }
    cout << endl;

    ArrayData myArray(int_array);
    
    string choose_mode;
    cout << "Please select the mode(ascending or descending or maxmin or operator+): ";
    cin >> choose_mode;

    if(choose_mode == "ascending"){
        myArray.AscendingOrderFunction();
    }

    else if(choose_mode == "descending"){
        myArray.DescendingOrderFunction();
    }

    else if(choose_mode == "maxmin"){
        MaxMinFunction(myArray);
    }
    else if(choose_mode == "operator+"){

        myArray.AscendingOrderFunction();
        ArrayData tmpArray1(myArray.getArray());

        myArray.DescendingOrderFunction();
        ArrayData tmpArray2(myArray.getArray());
        
        ArrayData resArray(tmpArray1+tmpArray2);
        resArray.ShowArray();
    }
    else{
        cout << "Mode is incorrect. So, this program is over" << endl;
        exit(0);
    }
    return 0;
}
*/
/* 기말 코드
#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;


class Processing {
public:
    virtual void f() {
	  cout << "Processing :: f() called" << endl;
    }
};

class ArrayProcessing : public Processing {
    int ArrayData[6] = { 0, };
public:
    ArrayProcessing(int input1[3], int input2[3]);
    friend void DigitPlusFunction(ArrayProcessing& C);  //참조 매개변수
    void AscendingOrderFunction();
    void DescendingOrderFunction();
    friend ArrayProcessing operator+(ArrayProcessing D, int p[6]);
    virtual void f() {
	  cout << "ArrayProcessing :: f() called" << endl;
    }
    void showArray() const;						    // 추가 구현부
};

ArrayProcessing :: ArrayProcessing(int input1[3], int input2[3]) {
    for (int i = 0; i < 3; i++) {
	  ArrayData[i] = input1[i];
    }
    for (int i = 0; i < 3; i++) {
	  ArrayData[i + 3] = input2[i];
    }
}

void DigitPlusFunction(ArrayProcessing& C) {
    cout << "[ Original result ]" << endl;
    C.showArray();
    cout << endl << "[ Digit result ]" << endl;

    for (int i = 0; i < 6; i++) {
	  int sum = 0;
	sum +=C.ArrayData[i] / 10;
	sum += C.ArrayData[i] % 10;
	cout << sum << " ";
    }
}

void ArrayProcessing::AscendingOrderFunction() {
    cout << "[ Original result ]" << endl;
    showArray();
    vector<int>v;
    
    for (int i = 0; i < 6; i++) {
	  v.push_back(this->ArrayData[i]);
    }
    sort(v.begin(), v.end());

    cout << endl << "[ Ascending result ]" << endl;
    for (auto it = v.begin(); it != v.end(); it++) {
	  cout << *it << " ";
    }
    cout << endl;

}

void ArrayProcessing::DescendingOrderFunction(){
    cout << "[ Original result ]" << endl;
    showArray();

    vector<int>v;

    for (int i = 0; i < 6; i++) {
	  v.push_back(this->ArrayData[i]);
    }
    sort(v.begin(), v.end(),greater<int>());

    cout << endl << "[ Descending result ]" << endl;
    for (auto it = v.begin(); it != v.end(); it++) {
	  cout << *it << " ";
    }
    cout << endl;

}

ArrayProcessing operator+(ArrayProcessing D, int p[6]) {
    int resArray1[3];
    int resArray2[3];
    
    for (int i = 0; i < 3; i++) {
	  resArray1[i] = D.ArrayData[i] + p[i];
    }
    for (int i = 3; i < 6; i++) {
	  resArray2[i-3] = D.ArrayData[i] + p[i];
    }
    
    return ArrayProcessing(resArray1,resArray2);
}

void ArrayProcessing :: showArray() const {

    for (int i = 0; i < 6; i++) {
	  cout << ArrayData[i] << " ";
    }
    cout << endl;
}

int main()
{
    int Array1[3] = {};
    int Array2[3] = {};

    cout << "[[ Final Exam ]]" << endl;
    cout << "Write the three integers between 10 and 99 for InputONE: ";
    for (int i = 0; i < 3; i++) {
	  int n;
	  cin >> n;
	  Array1[i] = n;
    }
    for (int i = 0; i < 3; i++) {
	  if (Array1[i] < 10 or Array1[i]>99) {
		cout << "InputONE is incorrect. So, this program is over.";
		exit(0);
	  }
    }
    cout << "Write the three integers between 10 and 99 for InputTWO: ";
    for (int i = 0; i < 3; i++) {
	  int n;
	  cin >> n;
	  Array2[i] = n;
    }
    for (int i = 0; i < 3; i++) {
	  if (Array2[i] < 10 or Array2[i]>99) {
		cout << "InputTWO is incorrect. So, this program is over.";
		exit(0);
	  }
    }
    
    cout << endl << "InputONE is ";
    for (int i = 0; i < 3; i++) {
	  cout << Array1[i] << " ";
    }
    cout << endl;

    cout << "InputTWO is ";
    for (int i = 0; i < 3; i++) {
	  cout << Array2[i] << " ";
    }
    cout << endl;

    ArrayProcessing NewArray(Array1, Array2);

    cout << endl << "Please select the mode(digit or ascending or descending or adding):";

    string select_mode;
    cin >> select_mode;

    if (select_mode == "digit") {
	  DigitPlusFunction(NewArray);
    }

    else if (select_mode == "ascending") {
	  NewArray.AscendingOrderFunction();
    }

    else if (select_mode == "descending") {
	  NewArray.DescendingOrderFunction();
    }

    else if (select_mode == "adding") {
	  NewArray.showArray();
	  cout << endl <<"Write the six integers between 0 and 100 for a new p array: ";
	  
	  int AddingArray[6] = {};
	  for (int i = 0; i < 6; i++) {
		int n;
		cin >> n;
		AddingArray[i] = n;
	  }
	  ArrayProcessing ResArray(NewArray + AddingArray);
	  
	  cout << "[ Adding result ]" << endl;
	  ResArray.showArray();
    }

    else if (select_mode == "virtual") {
	  NewArray.showArray();

	  ArrayProcessing* pDer = &NewArray;
	  Processing* pBase = pDer;

	  pDer->f();

      Processing test;
      test.f();
    }
    return 0;
}
*/
