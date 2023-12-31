# 소스코드 사용법
소스코드를 받을 경로를 지정 후 
```
git clone https://github.com/hyeok2lee/OpenSource-Last-HomeWork.git
```
받아진 파일 중 main.c 파일의 내용을 visual studio 등 c 컴파일러를 갖춘 툴을 이용하여 소스코드의 내용을 복사하여 실행해서 사용하면 된다.

### 중위수식 -> 후위수식으로 변환하는 프로그램

- 다음 코드는 스택을 이용하여 중위수식의 입력데이터를 받아 후위수식으로 변환하는 프로그램이다.
- 스택은 연결리스트로 구현되어있다.
- 연산자는 아래와 같은 연산자들로 이루어져있으며 우선순위는 다음과 같다.

![image](https://github.com/hyeok2lee/OpenSource-Last-HomeWork/assets/127758902/e8ca48ce-016c-4e52-b41b-ee5f0fbef763)

- 같은 우선순위를 갖는 연산자들은 왼쪽에서 오른쪽으로 계산한다.
- 입출력에 대한 설명
	1) 첫번째 라인 : 수식의 개수
    2) 두번째라인부터 수식의 개수만큼
    	- 하나의 줄에 수식이 공백없이 입력된다.
- 입력 예시
5
A*B+C+(D+E)*F		-> 		AB*C+DE+F*+
A+B*C				-> 		ABC*+
A/B-C+D*E-F*G		->		AB/C-DE*+FG*-
A+(B*C+D)*E			->		ABC*D+E*+
A&&B||C||!(E>F)		-> 		AB&&C||EF>!||

**밑에 입력 테스트 케이스 복사해서 사용**
```
5
A*B+C+(D+E)*F
A+B*C
A/B-C+D*E-F*G
A+(B*C+D)*E
A&&B||C||!(E>F)
```


### 프로그램 실행 예시

![image](https://github.com/hyeok2lee/OpenSource-Last-HomeWork/assets/127758902/2e08a41b-95d8-4e3c-b6ee-9cb387663dcd)

