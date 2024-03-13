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

## 2일차
- linux는 텍스트기반이다.
- nano test.c -> c언어 코드를 작성할수 있는 환경이 생성된다.

![printf예제](https://raw.githubusercontent.com/been2525/embedded-system-2024/main/images/printf.png)