//
// Created by xujingguo on 17-7-5.
//


#ifndef FILEMANAGEMENTSYSTEM_FILESYS_H
#define FILEMANAGEMENTSYSTEM_FILESYS_H

#endif //FILEMANAGEMENTSYSTEM_FILESYS_H



#define BLOCKSIZ  //512  每块大小
#define SYSOPENFILE //40  系统打开文件表最大项数
#define DIRNUM  128  //每个目录所包含的最大目录项数（文件数）
#define DIRSIZ  14  //每个目录项名字部分所占字节数，另加i节点号2个字节
#define PWDSIZ   12  //口令字
#define PWDNUM   32  //最多可设32个口令登录
#define NOFILE  20  //每个用户最多可打开20个文件，即用户打开文件表最大项数
#define NADDR 10  //每个i节点最多指向10块，addr[0]~addr[9]
#define NHINO  128  //共128个Hash链表，提供索引i节点
#define USERNUM  10  //最多允许10个用户登录
#define DINODESIZ  32 //每个磁盘i节点所占字节
#define DINODEBLK  32 // 所有磁盘i节点共占32个物理块
#define FILEBLK  512  //共有512个目录文件物理块
#define NICFREE  50  //超级块中空闲块数组的最大项数
#define NICINOD  50  //超级块中空闲i节点的最大项数
#define DINODESTART //2*BLOCKSIZ  i节点起始地址
#define DATASTART //(2+DINODEBLK)*BLOCKSIZ 目录、文件区起始地址

//用户结构
typedef struct tagTUSER{
    unsigned short u_mode;			//用户类别
    unsigned short u_uid;            // 用户ID
    unsigned short u_gid;           //   用户组ID
    unsigned short u_ofile[NOFILE]; //  用户打开文件表
};
//用户密码
typedef struct tag_TPWD{
    unsigned short u_mode;  //用户类别1，2，3
    unsigned short u_uid;    //用户id  2
    unsigned short u_gid;    //用户组id  2
    char  username[18];	//用户名
    char password[10];   //密码
};