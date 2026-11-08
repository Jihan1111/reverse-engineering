# DAY6 ASM 작성 및 실행과 정리 그리고 함수  
### 시작하기 전에...  
선생님께 .exe실행 파일을 전송받았습니다.  
이 실행피일 이름은 **loop.exe**이고 레치스터(변수)EAX의 갋을 10진수와 16진수로 보여주는 윈도우 api알림창을 띄웁니다.

<img src="./files/image/image.png" width="200" style="margin-left: 30px;border-radius: 12px;" />

어셈블리 코드 내부에는 자율적으로 코드를 짤수 있는 (nop)영역이 있습니다.

<img src="./files/image/image copy.png" width="1200" style="margin-left: 30px;border-radius: 12px;" />

이 nop영역에서 코드를 짜고 그 EAX의 갋을 바꾸면 출력은 바뀐 EAX의 갋을 보여줍니다.  
## ASM 작성 연습 주제 선정  
주제는 선생님이 제시 하였고 어셈블리를 사용하여 1부터 100까지 모든 숫자를 더하는 코드를 작성해야 합니다.  
규칙 에시: 1 + 2 + 3 + 4 + 5 + 6... + 100 = ?  
먼저 정답을 이야기 한다면, 1부터 100까지 모든 수를 더한 갋은 5050이 되야 합니다.  
## ASM 로직 구상  
ASM을 먼저 마로 작성을 하려면 시간이 오래 걸리고 난이도가 너무 높기 떄문에 먼저 C를 사용하여 초기 설계도를 만들어 보았습니다.  
다음에 나오는 코드는 그 설계도의 모습과 설명입니다. 
```c
#include <stdio.h>              //c 선언

int main(){                     //main함수 선언(본문 만들기)
    int a=0;                    //a라는 변수 선언

    for (int i=0; i<=100; i++){ //i라는 변수와(0) 100까지 i에다 1식 더하면서 17번 줄까지 있는 내용 반복
        a=a+i;                  //a에다i를 더하기(누적)
    }                           //반복문 경계선
    
    printf("%d",a);             //a를 출력(ASM에서 이 코드는 구연 되어 있습니다)
    return 0;                   //반환(지금은 필요 없음)
}
```  
| *[원문 :DAY5 main.c](../DAY5/files/main.c)*  
## ASM실전 작성  
C의 로직을 토데로 ASM을 작성하였고 그 결과는 이렇습니다.  
```asm
xor ebx, ebx   
cmp ebx, 100   
ja (line 30)   
add eax,ebx    
jmp (line 27)  
```  
| *[원문 :DAY5 main.c](../DAY5/files/main.c)*   
그런데 실제 작성된 모습이 조금 다릅니다.  

<img src="./files/image/image copy 2.png" width="1500" style="margin-left: 30px;border-radius: 12px;" />  

이는 코드가 쓴 갋과 출력이 요구하는 갋이 달라 살작 변경을 해 주었습니다(기본 원리는 100%같음)  
또 작성은 전부 16진수를 직접 입력 하여야 합니다. 
## 스텍과 함수  
