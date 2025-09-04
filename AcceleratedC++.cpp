/* Page25
#include<iostream>

int main(){
    std :: cout << "Hello, World !" << std :: endl;
    return 0;
}
*/
// Chapter 0 : 연습문제
/* 0-2
#include <iostream>

int main(){
    std::cout << "This (\") is a quote, and this (\\) is a backslash." << std::endl;

    return 0;
}
*/
// Chapter 1 : 문자열 사용
/*
#include <iostream>
#include <string>

int main()
{
    // 이름을 물음
    std :: cout << "Please enter your first name : " ;

    //이름을 읽어 들임
    std :: string name;
    std :: cin >> name ;

    std :: cout << "Hello, " << name << "!" << std:: endl;

    return 0;
}
*/
/* 이름을 입력받아 테두리로 묶인 인사말을 생성
#include<iostream>
#include <string>
int main(){
    std :: cout << "Please enter your first name: ";
    std :: string name;
    std :: cin >> name;

    const std :: string greeting = "Hello, " + name + "!";

    const std :: string spaces(greeting.size(),' ');
    const std :: string second = "* " + spaces + " *";
    
    const std :: string first(second.size(),'*');


    std :: cout << std::endl;
    std :: cout << first << std :: endl;
    std :: cout << second << std :: endl;
    std :: cout << "* " << greeting << " *" << std :: endl;
    std :: cout << second << std :: endl;
    std :: cout << first << std :: endl;


    return 0;
}
*/
