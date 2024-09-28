# Makefile 基本语法格式：
# 目标: 依赖
# 	执行语句
clean:
	@rm -f SqList.exe SqListTest.exe

SqList:
	@echo "SqList编译中"
	@g++ SqList.cpp -o SqList.exe

# 冒号后面是依赖 如果依赖不存在 就会报错 不会执行下面的命令
# 在不希望回显的命令前加 @
SqListTest: SqListTest
	@echo "SqListTest编译中"
	@g++ SqListTest.cpp -o SqListTest.exe

# blah 目标
# 当依赖 是非C语言源文件时，只会检查其是否存在
# blahTest: a.txt
# 	echo "a.txt 存在"

# 当依赖是 C语言源代码时，就会编译，并运行这个目标下的语句
# blahTest2: b
# 	echo "b.XX 存在"

# 依赖 还可以是 目标
all: clean SqList SqListTest