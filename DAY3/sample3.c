



a = ???
b= ???
c = ????



if(a == b)  
{
    char buf[64];
    wsprintfA(buf, "a랑 b는 일치하며 숫자 [%d]입니다", a);
    MessageBoxA(NULL, buf, "Result", MB_OK);
} else {
    MessageBoxA(NULL, "a랑 b는 일치하지 않습니다", "Result", MB_OK);
}
