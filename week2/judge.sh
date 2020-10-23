#! /bin/bash

#通过wget下载源程序fibonacci.c到根目录
wget raw.githubusercontent.com/TYH-tyh/paperChecking/master/fibonacci.c
#编译源代码
cc fibonacci.c
./a. out
#输出结果
echo "测试成功！"

