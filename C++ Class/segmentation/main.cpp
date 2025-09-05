#include "Calculator.h" 

/* ** 코드 작성시 주의 사항 *필독*
    Vscode 와 Windows 환경의 Visual Studio 2022는 빌드 시스템과 프로젝트 관리 방식의 차이가 있다. 
    Vscode는 가벼운 코드 편집기로, 별도의 프로젝트 관리 시스템이 내장되어 있지 않다.
    따라서, 사용자가 직접 컴파일 명령어를 작성하거나, 빌드시스템(예: Makefile, CMake)을 설정해야한다.
    컴파일 명령어는 VS Code의 터미널에 
    g++ main.cpp Calculator.cpp Adder.cpp -o main 라고 입력하고 이후 ./main으로 실행한다. 
    추가적인 내용이 궁금하다면 내가 ChatGpt Archive에 넣어놨으니 참고할 것.
*/

/*
#include "Calculator.cpp"
#include "Adder.cpp"
#include "Adder.h"
*/

int main(void)
{
    Calculator clac;
    clac.run();

    return 0;
}
