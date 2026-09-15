# C-EASY-1：C语言入门  题解

特别提示：下划线部分及特别注释部分使用了ai工具



## Part 1  了解C语言配置文件

1. 什么是GCC，什么是MinGW？它的作用是什么？

   **<u>GCC是一种优点多多，被广泛使用的编译器，也是大多数Unix系统的标准编译器。而MinGW类似于Windows平台上的GCC。它们可以将带代码翻译成计算机硬件可直接执行的机器码或可执行文件，并提供多级代码优化以提高运行效率。</u>**

   

2. *''c_cpp_properties.json'' ''launch.json'' ''tasks.json'*'这三个文件分别有什么作用？

   <u>**1. *c_cpp_properties.json*保障<mark>代码理解与提示</mark>，用于配置C/C++语言服务器的编译环境，使VScode能正确识别项目中的变量，结构体等，从而提供智能提示和代码检查功能。**</u>

   <u>**2. *launch.json*控制<mark>调试行为</mark>，定义了调试会话参数，控制调试器的行为。**</u>  	

   <u>**3. *tasks.json*定义<mark>构建任务</mark>,如编译，清理，运行等自动化操作。**</u>		



3. 为什么要在编译器内下载C语言的插件，插件的作用又是什么？

   **<u>插件可以提供智能<mark>代码感知</mark>（识别C语言语法，标准库函数等）；<mark>调试</mark>支持（允许进行可视化调试）；构建与<mark>编译</mark>设置（使编译器正确解析项目结构）；<mark>跨平台兼容</mark>（字面意思）。</u>**



（全注释了一下）

```json
{
    // 使⽤ IntelliSense 了解相关属性。
    // 悬停以查看现有属性的描述。
    // 欲了解更多信息，请访问: https://go.microsoft.com/fwlink/?linkid=830387     "version": "0.2.0",
    "configurations": [
        {
            "name": "gcc.exe - ⽣成和调试活动⽂件",  // 该调试任务的名字，启动调试时会在待选列表中显⽰
            "type": "cppdbg",  //配置类型，cppdbg表示使用C/C++
            "request": "launch",  //launch表示启动程序
            "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",            "args": [],
            //要运行的文件的完整路径，这里指当前目录下同名但后缀为exe的文件，args是命令行参数，这里是空数组
            "stopAtEntry": false,  //如果设置为true，程序在main入口处暂停
            "cwd": "${workspaceFolder}",  //程序运行时的工作目录，常设置为当前文件所在目录
            "environment": [],  //添加的环境变量
            "externalConsole": false,  //true为外部控制台，false为内部终端
            "MIMode": "gdb",  //连接的调试器为gdb
            "miDebuggerPath": "c",  //gdb调试器的完整路径
            "setupCommands": [
                {
                    "description": "为 gdb 启⽤整⻬打印",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "C/C++: gcc.exe build active file"  // 调试前的预执⾏任务，这⾥的值是tasks.json⽂件中对应的编译任务，也就是调试前需要先编译
        }
    ]
}
```



![image-20260914224219032](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20260914224219032.png)

为了做出这个东西......我从下午开始配环境，终于在晚上十点半成功输出了。。。不过确实加深了一些对launch的理解。

过程中遇到了各种奇奇怪怪的困难，比如mingw为什么下不了，一开始忘记用管理员账号，launchjson找不到，找到了launch却不知道添加哪一个配置，program和miDebuggerPath没有改，忘了mingw安装在E盘填了个C:/，排查错误时急眼了把task都改了，以及不知道会运行到launch.exe，激情肘击杀毒软件，和最后外置终端没有getchar导致的闪退。

急头白脸地一个小时一个小时地排查问题很折磨人，感觉要疯掉了，甚至有点想过自己是不是不太适合这个专业。。。好在最后成功了。

非常感谢各位微光的前辈们对我遇到的问题的耐心帮助。以及”心有微光，不惧黑暗“的口号在那种时候真的，真的很有力量。





## Part 2 C语言基础

1. 变量类型？

   <u>**变量是用于引计算机内存地址的占位符，其简化了程序的操作和处理，使程序具备灵活性和强大的逻辑控制能力。**</u>

   **存放年龄应该用整数型（翁恺说直接用int就好，当然char也不是不行）；存放单词应该用指针（char*），或者strcpy进数组。**

   

2. 数组的起始与边界？

   **数组首元素下标从0开始，超出范围会导致数组越界，数组越界会把越界的”元素“的地址写到一些”不能写“的地方（比如系统内存和只读数据区）导致程序崩溃，非常可怕（确信）。**

   

3. 流程控制 - 循环结构？

   **for结构为`for(初始化;条件判断;迭代更新){循环体}`。进入for循环时先做初始化，然后判断条件（条件判断式不为0），之后进行迭代更新并进入循环体，循环体做完（没有遇到break）的话返回条件判断，成立则继续，循环往复······**

   **while结构为`while(条件判断){循环体}`。看起来比for简单一点但是格式上往往不太好看······其他什么的和for差不多。**

   **do while为先执行一次循环体再做条件判断看要不要继续，格式上更难看了······**

   ```c
   int sum = 0;
       for(int i = 1; i < 11; i++){sum+=i;}
   ```

   ```c
   int sum = 0；
   while(i++<10){sum+=i;}
   ```

4. 流程控制 - 逻辑表达式？

   **算术运算中运算对象是数值型，结果也是一个数。逻辑运算中运算对象是任意类型（会被视为 bool 类型），输出结果是bool值（1代表true，0代表false）**

   **&&（与）：都为1才为1，否则为0**

   **||（或）：有一个是1就是1，否则为0**

   **！（非）：1转0，0转1**

   **运算顺序：非 > 与 > 或**



**个人信息打印系统如下（仅有注释部分涉及ai）：**

```c
#include <stdio.h>
#include <stdlib.h>
int main() {
    s.0m("chcp 65001"); // 不用这个发现出现了奇怪的繁体字，这个可以把控制台编码切换为UTF-8
    int i= 0,j=0,k=0;
    char name[50] ={'\0'} ;
    printf("请输入你的年龄：");.0.0.0
    scanf("%d", &i);
    printf("请输入你的名字：");
    scanf("%49s", name);//此处ai建议限制位数,防止溢出
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
    while(getchar() != '\n'); // 此处用于清理\n,询问ai后得知
    getchar(); // 防止闪退
    return 0;
}
```





## Part 3 函数

1. **排序程序已单独上传。**

   

2. 猜函数结果？

   **换了个寂寞（），因为上传函数中的是形参（仅发生了值的传递），函数中定义的参数在函数结束后就被清理了，所以各种意义上的压根没换过来，应该在下一份作业里用指针实现。**

























