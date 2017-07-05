#include <iostream>
#include "log.cpp"
using namespace std;

int main() {
    //以下为登录测试程序段
    string strUsername; //
    string strInputPassword;
    cout << "please input your username: ";
    cin >> strUsername;
    cout << strUsername;
    cout << "please input your password:";
    strInputPassword = inputPassword();
    cout << strInputPassword;
}