#include <stdio.h>

void main()
{
	printf("%d\n",35); 	// 정수출력
	printf("%d\n", 0123);	//83출력됨. 0은 8진수를 나타내는 기호 ->8진수로 출력됨
	printf("%d\n", 0xACC);// 16진수
	printf("%f\n", 3.14);

	printf("int: %d\n", sizeof(int));
	printf("float: %d\n", sizeof(float));
	printf("double: %d\n", sizeof(double));
	printf("%c\n", 'A');
	printf("%d\n", 'A');
	printf("%c\n", 97);

	printf("%s\n", "RaspberryPi OS!!\n");
	

}
