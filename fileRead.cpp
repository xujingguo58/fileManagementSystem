//
// Created by xujingguo on 17-7-4.
//

#include <iostream>
#include <fstream>
using namespace std;

int fileRead() {
    char buffer[512];
    ifstream in("/home/xujingguo/Desktop/fileManagementSystem/output.txt");
    while (!in.eof())
    {
        in.read(buffer,510);
        cout << buffer << "/over" <<endl;
    }
    FILE *fp;
    if(fp = fopen("/home/xujingguo/Desktop/fileManagementSystem/output.txt","r"))
        while (!feof(fp)) {
            if (fgets(buffer, 512, fp) != NULL) {
                printf("%s ",buffer);
            }
        }
}