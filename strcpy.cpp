#include <iostream>
#include <cassert>
using namespace std;
char* strcpy(const char* src, char* dst)
{
    assert(src!= nullptr && dst!= nullptr);
    char* addr = dst;
    while(*src!='\0')
    {
        *dst++ = *src++;
    }
    return addr;
}

bool str2int(char* str, int &num)
{
    assert(str!= nullptr);
    bool neg_flag = false;
    if(*str = '-')
    {
        neg_flag = true;
        str++;
    }
    while(!str!='\0')
    {
        if(*str<'0' || *str>'9')
        {
            return false;
        }
        num = 10 * num + *str++ - '0';
    }
    if(neg_flag)
    {
        num = -1 * num;
    }
    return true;
}
stol

int main(int argc, char* argv[])
{
    char a[] = "Hello World!";
    char b[20];
    strcpy(a, b);
    return 0;
}
