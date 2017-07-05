//
// Created by xujingguo on 17-7-5.
//

#include "fileSys.h"

#include <string>
#include <stdio.h>
#include <stdlib.h>
#ifndef _WIN32                   //Linux platform
#include <termio.h>
#ifndef STDIN_FILENO
#define STDIN_FILENO 0
#endif

int getch(void)
{
    struct termios tm, tm_old;
    int fd = STDIN_FILENO, c;
    if(tcgetattr(fd, &tm) < 0)
        return -1;
    tm_old = tm;
    cfmakeraw(&tm);
    if(tcsetattr(fd, TCSANOW, &tm) < 0)
        return -1;
    c = fgetc(stdin);
    if(tcsetattr(fd, TCSANOW, &tm_old) < 0)
        return -1;
    return c;
}

#else                            //WIN32 platform
#include <conio.h>
#endif


#define BACKSPACE 8
#define ENTER     13
#define ALARM     7
using namespace std;

string inputPassword()
{
    char ch;  //输入字符
    int nCount = 0;   //输入字符计数
    string strPassword;  //要返回的即结果
    static char p[PWDSIZ]="";
    while((ch = getch())!= -1 && ch != ENTER)
    {
        if(nCount == PWDSIZ && ch != BACKSPACE)
        {
            putchar(ALARM);
            continue;
        }
        if(ch == BACKSPACE)
        {
            nCount--;
            putchar(BACKSPACE);
            putchar(' ');
            putchar(BACKSPACE);
        }
        else
        {
            p[nCount] = ch;
            putchar('*');
            nCount++;
        }
    }

    if(ch == -1)
    {
        while(nCount != -1)
        {
            p[nCount--] = '\0';
        }
        return NULL;
    }

    strPassword = p;
    return strPassword;
}