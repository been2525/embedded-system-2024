# embedded-system-2024
IoT개발자 임베디드시스템 학습리포지토리

## 1일차
- 라즈베리파이 프로그램 설치
- sudo apt update
- sudo apt upgrade -y
- 환경설정
	- 편집기: 코드 작업할 때 사용하는 프로그램(nano)
- 기본명령어(c)
	- 기존 PC같이 사용하면 안된다.
	- 순서에 맞추어서 사용(동작중에 다른 명령어 처리 안됨)
	- ls -> list
	- pwd -> 현재 내위치
	- mkdir->새로우 디렉터리 만듬
	- rm -> remove
	- rm -fr Work -> Work 삭제	
	- ls -a->숨겨진 파일까지 다 볼수있게 해준다.
	- clear -> 화면지움
	- ls -l -> 상세하게 보여줌
	- cd->chage diretory
	- ~ 
	- .. 상위디렉토리로 빠져나감
	- /etc 환경관련 파일
	- sudo -> 관리자권한으로 접근하게 해주는 명령어
	
``` C
nano /etc/nanorc
```

![제거예제](https://raw.githubusercontent.com/been2525/embedded-system-2024/main/picture/제거.png)


## 2일차
- linux는 텍스트기반이다.
- nano test.c -> c언어 코드를 작성할수 있는 test라는 코딩 환경이 생성된다.

![printf예제](https://raw.githubusercontent.com/been2525/embedded-system-2024/main/picture/printf.png)
- mv 이동
- cp copy
- gcc test03.c 실행파일을 안줄때는 이렇게 한다 -> a.out 생성
- gcc -o t3 test03.c -> 꼭 이 순서 지킬것

![출력예제](https://raw.githubusercontent.com/been2525/embedded-system-2024/main/picture/출력.png)

![출력값](https://raw.githubusercontent.com/been2525/embedded-system-2024/main/picture/출력값.png)

![for문예제](https://raw.githubusercontent.com/been2525/embedded-system-2024/main/picture/for문.png)

![for문출력값](https://raw.githubusercontent.com/been2525/embedded-system-2024/main/picture/for문출력값.png)

- C언어 반복문 복습

## 3일차
- 연결리스트
	- 할당
	- 삭제
	- 전위삽입
	- 후위삽입
```C
node* curr = head -> next
while(curr != NULL)
{
	printf("%d\n", curr->data);
	curr -> next;
}
```

## 4일차
- 연결리스트
	- 할당
	- 삭제
	- 전위삽입
	- 후위삽입
	- 헤드파일 다 함수로 만들어보기
	
## 5일차
- 스택
- 연결리스트를 활용하여서 스택만들기

## 6일차
- 큐
- 연결리스트를 활용하여서 큐만들기
- makefile을 활용하여서 바로 실행파일 만들기

## 7일차
- 파일입출력
	- 리눅스기반 파일 입출력
		- open은 리눅스 전용
		- 리눅스는 실패시 -1 반환
		- O_CREAT : 필요하면 파일을 생성
		- O_WRONLY : 쓰기 전용으로 파일 오픈
		- 파일입출력을 활용하여서 파일 복사하기