# SPLI（Simple Proposition Logic Interpreter）
#### 这仅仅只是一个十分单纯（Very Simple）的命题逻辑解释器，Do not star！因为本人水平很渣，很菜(｡･ω･｡)

* 本程序可以在Windows、GNU/Linux等flex & bison所兼容的操作系统平台上编译并运行，在Windows（MinGW）环境下编译，需要用到win_flex_bison工具包（项目已一同打包），在GNU/Linux环境下可能需要用户自行从软件源安装git、gcc、make、flex、bison等软件包。
* 本程序在BSD/UNIX操作系统原生的clang（LLVM）下编译测试通过。
* 按优先级排序的命题数学符号与SPLI词素符号的对应关系：

| 含义 | 命题数学符号 | SPLI词素符号 |		
| :---: | :--------: | :--------: |
| 否定 | ¬          | !          |
| 合取 | ∧          | &          |
| 析取 | ∨          | \|         |
| 蕴含 | →          | ->         |
| 等价 | ↔          | <->        |

---

- ### 获取预编译二进制包

**下载页面：https://github.com/yenyuloong/SPLI/releases**

- ### 基于Windows开发的MFC的图形界面前端（SPLP，命题逻辑演示器）

**下载Visual Studio项目包： [SPLP.zip](https://github.com/yenyuloong/SPLI/files/1109307/SPLP.zip)**

---

#### 示例——验证德▪摩根律（De Morgan's laws）的正确性
| P	| Q	| ¬(P∧Q) | ¬P∨¬Q |		
| :---: | :---:	| :-----: | :----: |
| 1	| 1	| __0__   | __0__  |
| 1	| 0	| __1__   | __1__  |
| 0	| 1	| __1__   | __1__  |
| 0	| 0	| __1__	  | __1__  |

#### Windows 示例：

![example01](https://github.com/yenyuloong/SPLI/raw/master/screenshots/example01.png)

#### GNU/Linux 示例：

![example02](https://github.com/yenyuloong/SPLI/raw/master/screenshots/example02.png)


---

- ### 编译前的准备工作

#### 1. 解决构建依赖：
* __Ubuntu：__ # <code>apt-get update && apt-get install flex bison gcc make git</code>
* __RHEL/CentOS/Fedora：__ # <code>yum update && yum install flex bison gcc make git</code>
* __ArchLinux：__ # <code>pacman -Sy flex bison gcc make git</code>
* __Termux：__ $ <code>pkg update && pkg install flex bison clang make git</code>
* __Windows：__ 项目已打包好win_flex_bison，GCC编译环境需要用户自行安装<a href="https://sourceforge.net/projects/mingw/files/latest/download?source=files">MinGW</a>及mingw32-base包组，使用Git工具的话，也需要安装<a href="https://git-for-windows.github.io/">Git for Windows</a>（本人在说废话，Github老司机都知道ヽ(￣▽￣)ﾉ），若使用Makefile构建，需要将MinGW\bin目录添加到PATH环境变量中

#### 2. 获取源代码：
* 下载项目Zip包（不推荐！ヽ(`Д´)ﾉ）：<br/>
**https://github.com/yenyuloong/SPLI/archive/master.zip**

* 使用Git工具（喜欢！(⁎˃ᴗ˂⁎)）：

	$ <code>git clone https://github.com/yenyuloong/SPLI.git</code>
---

- ### 使用 GNU C 编译器（GCC）

#### 1. 准备编译：
* 进入工作目录：

	$ <code>cd SPLI</code>

#### 2. 使用make调用GCC自动构建：
* Windows 操作系统（MinGW）：

	$ <code>mingw32-make.exe -f Makefile.win</code>
	
	> *（可选）Debug模式 "flex -d"：*

	$ <code>mingw32-make.exe -f Makefile.win debug</code>
	
* GNU/Linux 发行版（GCC）：
	
	$ <code>make -f ./Makefile.nix</code>

	> *（可选）Debug模式 "flex -d"：*

	$ <code>make -f ./Makefile.nix debug</code>
---

- ### 手动生成C源代码，并且编译

> 如果要移植到其他编译器或者操作系统平台，或者阁下是传说中的“高级用户”，想手动构建本项目，可以使用flex/bison直接生成C语言源代码，然后使用C编译器编译，大致步骤如下，可供参考：

* 使用bison生成Parser部分的代码（spli.tab.c、spli.tab.h）：

	$ <code>bison -d ./spli.y</code>
	
* 使用flex生成Lexer部分的代码（lex.yy.c）：
	> *-i 不区分大小写，-d 表示Debug模式*
	
	$ <code>flex ./spli.l</code>

* 使用gcc或者clang（LLVM）编译C源代码：
	> *-o 生成指定的可执行文件，-lfl 是GCC编译器链接flex库的必要参数（本项目已可不再使用）*

	$ <code>gcc -o bin/spli ./lex.yy.c ./spli.tab.c ./spli.c ./prop.c</code>
	
	$ <code>clang -o bin/spli ./lex.yy.c ./spli.tab.c ./spli.c ./prop.c</code>
	
	__（尚未在VC平台测试）__

	> 以上的Lexer生成过程会产生 *unistd.h* 头文件依赖，在VC上可能无法编译，使用flex生成 *lex.yy.c* 时，可以采用 *--nounistd* 和 *--wincompat* 选项使得生成的 *lex.yy.c* 不依赖 *unistd.h* 头文件，否则该源代码就只能在类UNIX环境下编译。（其中 *--wincompat* 是win_flex提供的额外选项，这样可以减少VC的编译Warning）
	
---

- ### 程序目录结构

<pre>
.
├── bin			//二进制程序构建目录
│   └── README.md	
├── LICENSE		//GNU GPL v3许可证
├── Makefile.nix	//GNU/Linux Makefile
├── Makefile.win	//Windows Makefile
├── prop.c		//命题算法源代码
├── prop.h		//命题算法头文件
├── README.md		//项目说明文档
├── screenshots		//示例截图
│   ├── example01.png
│   ├── example02.png
│   └── README.md
├── spli.c		//SPLI核心源代码
├── spli.h		//SPLI核心头文件
├── spli.l		//SPLI Flex源代码
├── spli.y		//SPLI Bison源代码
└── win_flex_bison	//Winflexbison构建工具
    ├── custom_build_rules
    │   ├── how_to_use.txt
    │   ├── win_bison_only
    │   │   ├── how_to_use.txt
    │   │   ├── win_bison_custom_build.props
    │   │   ├── win_bison_custom_build.targets
    │   │   └── win_bison_custom_build.xml
    │   ├── win_flex_bison_custom_build.props
    │   ├── win_flex_bison_custom_build.targets
    │   ├── win_flex_bison_custom_build.xml
    │   └── win_flex_only
    │       ├── how_to_use.txt
    │       ├── win_flex_custom_build.props
    │       ├── win_flex_custom_build.targets
    │       └── win_flex_custom_build.xml
    ├── data
    │   ├── bison.m4
    │   ├── c-like.m4
    │   ├── c.m4
    │   ├── c++.m4
    │   ├── c-skel.m4
    │   ├── c++-skel.m4
    │   ├── glr.c
    │   ├── glr.cc
    │   ├── java.m4
    │   ├── java-skel.m4
    │   ├── lalr1.cc
    │   ├── lalr1.java
    │   ├── location.cc
    │   ├── m4sugar
    │   │   ├── foreach.m4
    │   │   └── m4sugar.m4
    │   ├── Makefile.am
    │   ├── Makefile.in
    │   ├── README
    │   ├── stack.hh
    │   ├── xslt
    │   │   ├── bison.xsl
    │   │   ├── xml2dot.xsl
    │   │   ├── xml2text.xsl
    │   │   └── xml2xhtml.xsl
    │   └── yacc.c
    ├── FlexLexer.h
    ├── README.txt
    ├── UNISTD_ERROR.readme
    ├── win_bison.exe
    └── win_flex.exe

9 directories, 55 files
</pre>

> 本程序使用Flex & Bison作为lexer和parser生成工具，在这里要感谢编写Flex/lex和Bison/yacc的团队，也要感谢将Flex & Bison移植到win32上的开发者，感谢你们让这个世界拥有了如此强大的自由软件，使得编写专用lexer和parser一些编程人员也能降低编写难度和花费的时间成本。

* Flex 项目主页：https://github.com/westes/flex/

* Bison 项目主页：http://www.gnu.org/software/bison/

* Win flex-bison 项目主页：https://sourceforge.net/projects/winflexbison/

