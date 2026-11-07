#include <windows.h>
#include <stdio.h>

int main(void)
{
    int a = 5;          // 초기값
    a = a + 1;          // 리버싱 대상: add 연산

    char buf[64];
    wsprintfA(buf, "a = %d", a);

    MessageBoxA(NULL, buf, "Reversing Demo", MB_OK | MB_ICONINFORMATION);

    return 0;
}