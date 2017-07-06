#include <iostream>
#include "fileSys.h"

using namespace std;
int main() {
    //以下是登录模块测试
    User userLogin;
    string strUserName,strPassword;
    cout << "please input input your username:";
    cin >> strUserName;
    cout << "please input your password:";
    strPassword = userLogin.inputPassword();
    cout << endl;
    int loginResult = userLogin.login(strUserName,strPassword);
    //cout << "your input is " << strUserName << strPassword <<"length is " << sizeof(strPassword)<<endl;
    if(loginResult == true){
        cout << "login success,welcome " << strUserName << endl;
    }
    else
        cout << "login error,please check your username and password";
    system("pause");
    //以下是注册模块实现
    /*string strSignInUserName; //输入一个想注册的用户名
    cout << "please input your username:";
    cin >> strSignInUserName;
    User newUser;
    int result=newUser.signInCheck(strSignInUserName);
    if(result ==1){
        string firstInputPassword,secondInputPassword;
        cout << "please input your password:";
        firstInputPassword = newUser.inputPassword();
        cout << "please input your password again:";
        secondInputPassword = newUser.inputPassword();
        cout << "the second input password is "<< secondInputPassword << endl;
        if( firstInputPassword == secondInputPassword){
           if (newUser.addUser(strSignInUserName,firstInputPassword))
               cout << "success";
               //此处进行超级块的更新操作
            else
               cout << "error";
        } else {
            cout << "you have input different password";
        }
    } else if(result == 0){
        cout << "password number > 32";
    } else if(result == -1){
        cout << "username > 8";
    } else if(result == -2){
        cout << "this username already exits";
    }
    */
}