#include <stdio.h>

void func();				//함수정의

void main()
{
	func();       //함수호출

}

void func();		//함수선언
{
	printf("func()\n")
}
