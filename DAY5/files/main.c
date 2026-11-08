#include <stdio.h>

int main(){
    int a=0;

    for (int i=0; i<=100; i++){
        a=a+i;
    }
    
    printf("%d",a);
    return 0;
}
//--------------------------------------------------

eax, ebx


add
j 시리즈




--------
xor ebx, ebx   | 31 DB
cmp ebx, 100   | 83 FB 64
ja (line 30)  | 
add eax,ebx    | 01 D8
jmp (line 27)  | 

---------


eax, ebx, ecx, edx


eax가 100보다 작은 지 확인한다.
jne section2

section1.
a = a + i

jmp line 20

section2.

end

------
내용
확인
끋

