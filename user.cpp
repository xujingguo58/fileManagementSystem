//
// Created by xujingguo on 2017/7/6.
//
#include "fileSys.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <cstring>


using namespace std;

User::User() {
    FILE *fp;
    int i = 0;
    if (fp = fopen("C:\\Users\\xujingguo\\Desktop\\file\\password.txt", "r")) {
        while (fscanf(fp, "%s %s", &pwd[i].username, &pwd[i].password) != EOF) {
            //cout <<pwd[i].username << pwd[i].password << endl;
            i++;
            nPwdNum++;
        }
    } else {
        cout << "error";
    }
    fclose(fp);
}

/**
 * [User::inputPassword 输入密码 以*显示]
 * @return [返回输入的字符串]
 */
string User::inputPassword()  
{
    char c;  //输入字符
    int nCount = 0;   //输入字符计数
    string strPassword;  //要返回的即结果
    while ((c = getch()) != '\r') {

        if (c == 8) { // 退格
            if (nCount == 0) {
                continue;
            }
            putchar('\b'); // 回退一格
            putchar(' '); // 输出一个空格将原来的*隐藏
            putchar('\b'); // 再回退一格等待输入
            nCount--;
        }
        if (nCount == PWDSIZ-1) { // 最大长度为size-1
            break;
        }
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {  // 密码只可包含数字和字母
            putchar('*');  // 接收到一个字符后, 打印一个*
            strPassword += c;
            nCount++;
        }
    }
    return strPassword;
}

/**
 * [User::login 登录函数]
 * @param  strUserName [用户输入的用户名]
 * @param  strPassword [用户输入的密码]
 * @return             [正确返回TRUE]
 */
bool User::login(string strUserName, string strPassword) {   
    //fileRead();             //从文件中读取
    for (int i = 0; i < PWDNUM && i < nPwdNum; i++) {
        string tmp_username = pwd[i].username;
        string tmp_password = pwd[i].password;
        //cout << tmp_username << tmp_password << endl;
        if (strUserName==tmp_username && strPassword == tmp_password) {
            //cout << tmp_username << " " << tmp_password << endl;
            //cout << "success";
            return true;
        }
    }
    //cout << "error";
    return false;
}

/**
 * [User::signInCheck 用户名注册检查]
 * @param  strUserName [用户输入要注册的用户名]
 * @return             [description]
 */
int User::signInCheck(string strUserName) {
    if (nPwdNum >= PWDNUM) {   //密码数量大于32
        return 0;
    }
    vector<string> vUsername; //保存所有用户名
    for (int i = 0; i < PWDNUM && i < nPwdNum; ++i) {
        string tmp_username = pwd[i].username;
        //cout << tmp_username << " ";
        vUsername.push_back(tmp_username);
    }
    cout << endl;
    sort(vUsername.begin(), vUsername.end());  //去重，计算用户数量
    vUsername.erase(unique(vUsername.begin(), vUsername.end()), vUsername.end());
    for (int j = 0; j < vUsername.size(); ++j) {
        //cout << vUsername[j];
        if (strUserName == vUsername[j]) {  //说明已经存在该用户
            return -2;
        }
    }
    if (vUsername.size() >= USERNUM) {  //用户数量大于8
        return -1;
    }
    return 1;
}

/**
 * [User::addUser 增加一个用户]
 * @param  strUserName [用户名]
 * @param  strPassword [密码]
 * @return             [返回是否成功]
 */
bool User::addUser(string strUserName, string strPassword){
    FILE *fp;
    const char *bufferUsername,*bufferPassword;
    //cout << "the username's length is "<< strUserName.length() << endl;
    bufferUsername = strUserName.c_str();
    bufferPassword = strPassword.c_str();
    cout << "the buffer is " << bufferPassword << endl;
    if (fp = fopen("C:\\Users\\xujingguo\\Desktop\\file\\password.txt", "a+")) {
        fprintf(fp,"%s %s \n",bufferUsername,bufferPassword);
        return true;
    }
    else
        return false;
    fclose(fp);
}