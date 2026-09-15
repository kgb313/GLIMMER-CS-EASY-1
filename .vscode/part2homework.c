#include <stdio.h>
#include <stdlib.h>
int main() {
    system("chcp 65001"); // 不用这个发现出现了乱码
    int i= 0,j=0,k=0;
    char name[50] ={'\0'} ;
    printf("请输入你的年龄：");
    scanf("%d", &i);
    printf("请输入你的名字：");
    scanf("%49s", name);
    while(1)
    {
    printf("你的年龄是：%d\n", i);
    printf("你的名字是：%s\n", name); 
    j++;
    printf("这是第%d次打印, 按0继续打印，按1退出\n", j);
    scanf("%d", &k);
    if(k==1) {break;}
    }
    printf("已打印%d次", j);
    while(getchar() != '\n'); // 此处用于清理/n,询问ai后得知
    getchar(); // 防止闪退
    return 0;
}