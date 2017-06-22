# SPLI（Simple Proposition Logic Interpreter）
#### 这仅仅只是一个十分单纯（Very Simple）的命题逻辑解释器，Do not star！因为本人水平很渣，很菜(｡･ω･｡)

* 本程序可以在Windows、GNU/Linux等flex & bison所兼容的操作系统平台上编译并运行，在Windows（MinGW）环境下编译，需要用到win_flex_bison工具包（项目已一同打包），在GNU/Linux环境下可能需要用户自行从软件源安装git、gcc、make、flex、bison等软件包。
* 本程序在BSD/UNIX操作系统原生的clang（LLVM）下编译测试通过。
---
- ### 编译前的准备工作

#### 1. 解决构建依赖：
* __Ubuntu：	#__ <code>apt-get update && apt-get install flex bison gcc make git</code>
* __RHEL/CentOS/Fedora:	 #__ <code>yum update && yum install flex bison gcc make git</code>
* __ArchLinux： #__ <code>pacman -Sy flex bison gcc make git</code>
* __Termux： $__ <code>pkg update && pkg install flex bison clang make git</code>
* __Windows：__ 项目已打包好win_flex_bison，GCC编译环境需要用户自行安装<a href="https://sourceforge.net/projects/mingw/files/latest/download?source=files">MinGW</a>及mingw32-base包组，使用Git工具的话，也需要安装<a href="https://git-for-windows.github.io/">Git for Windows</a>（本人在说废话，Github老司机都知道ヽ(￣▽￣)ﾉ），若使用Makefile构建，需要将MinGW\bin目录添加到PATH环境变量中
#### 2. 获取源代码：
* 下载项目Zip包（不推荐！ヽ(`Д´)ﾉ）：<br/>
**<a href="https://github.com/longyanyu-cs/SPLI/archive/master.zip">https://github.com/longyanyu-cs/SPLI/archive/master.zip</a>**

* 使用Git工具（喜欢！(⁎˃ᴗ˂⁎)）：

	__$__ <code>git clone https://github.com/longyanyu-cs/SPLI.git</code>
---
- ### 自动构建项目
#### 1. 编译之前：
* 进入工作目录：

	__$__ <code>cd SPLI</code>

#### 2. 使用make自动构建：
* Windows 操作系统（MinGW）：

	__$__ <code>mingw32-make.exe -f Makefile.win</code>
	
	> *（可选）Lexer Debug模式 "flex -d"：*

	__$__ <code>mingw32-make.exe -f Makefile.win debug</code>
	
* GNU/Linux 发行版（GCC）：
	
	__$__ <code>make -f ./Makefile.nix</code>

	> *（可选）Lexer Debug模式 "flex -d"：*

	__$__ <code>make -f ./Makefile.nix debug</code>
---
- ### 手动生成C源代码，并且编译
> *如果要移植到其他编译器或者操作系统平台，或者阁下是传说中的“高级用户”，想手动构建本项目，可以使用flex/bison直接生成C语言源代码，然后使用C编译器编译，大致步骤如下，可供参考：*

* 使用bison生成Parser部分的代码（spli.tab.c、spli.tab.h）：

	__$__ <code>bison -d ./spli.y</code>
	
* 使用flex生成Lexer部分的代码（lex.yy.c）：
	> *-i 不区分大小写，-d 表示Debug模式*
	
	__$__ <code>flex ./spli.l</code>

* 使用gcc或者clang（LLVM）编译C源代码：
	> *-o 生成指定的可执行文件，-lfl 是GCC编译器链接flex库的必要参数*

	__$__ <code>gcc -o bin/spli ./lex.yy.c ./spli.tab.c ./spli.c ./prop.c -lfl</code>
	
	__$__ <code>clang -o bin/spli ./lex.yy.c ./spli.tab.c ./spli.c ./prop.c</code>
	
	__（尚未在VC平台测试）__
	
---















> *本程序使用Flex & Bison作为lexer和parser生成工具，在这里要感谢编写Flex/lex和Bison/yacc的团队，也要感谢将Flex & Bison移植到win32上的开发者，感谢你们让这个世界拥有了如此强大的自由软件，使得编写专用lexer和parser一些编程人员也能降低编写难度和花费的时间成本。*
