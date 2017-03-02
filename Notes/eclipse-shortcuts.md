###11.03_Java开发工具(Eclipse的视窗和视图概述)(了解)
* A:视窗  每一个基本的窗体被称为视窗
	* PackageExplorer  显示项目结构，包，类，及资源
	* Outline   显示类的结构，方便查找，识别，修改
	* Console  程序运行的结果在该窗口显示
	* Hierarchy 显示Java继承层次结构，选中类后F4
* B:视图  是由某些视窗的组合而成的
	* Java视图
	* Debug视图

###11.04_Java开发工具(Eclipse工作空间的基本配置)(掌握)
* D:字体大小及颜色
	* a:Java代码区域的字体大小和颜色：
		* window -- Preferences -- General -- Appearance -- Colors And Fonts --Java修改 -- Java Edit Text Font
	* b:控制台
		* window -- Preferences -- General -- Appearance -- Colors And Fonts -- Debug -- Console font
	* c:其他文件
		* window -- Preferences -- General -- Appearance -- Colors And Fonts -- Basic -- Text Font
* G:取消悬浮提示
	* window -- Preferences -- Java--Editor--Hovers。右边将Combined Hover勾去掉。
	* 这样代码的悬浮框就不会自动出现了。如果想看提示，将光标悬浮在代码上，按F2即可。
 
###11.05_Java开发工具(Eclipse中内容辅助键的使用)(掌握)
* A:Alt+/ 起提示作用
* B:main+alt+/,syso+alt+/,给出其他提示
* C:补充输出语句,选中需要输出的部分,alt+/选择最后一项即可
* C:定义自己的alt + /
	* windows--perference-Java-Editor-Templates--New

###11.06_Java开发工具(Eclipse中快捷键的使用)(掌握)
* A:新建 ctrl + n
* B:格式化  ctrl+shift+f
* C:导入包  ctrl+shift+o 
* D:注释  ctrl+/,ctrl+shift+/,ctrl+shift+\
* E:代码上下移动 选中代码alt+上/下箭头
* F:查看源码  选中类名(F3或者Ctrl+鼠标点击)
* G:查找具体的类 ctrl + shift + t
* H:查找具体类的具体方法 ctrl + o
* I:给建议 ctrl+1,根据右边生成左边的数据类型,生成方法
* J:删除代码 ctrl + d
* K:抽取方法alt + shift + m 
* L:改名alt + shift + r 
* 

###11.07_Java开发工具(Eclipse中如何提高开发效率)(掌握)
* alt + shift + s
* A:自动生成构造方法
* B:自动生成get/set方法

###11.08_Java开发工具(Eclipse中一个标准学生类及其测试)(掌握)
* A:案例演示
	* 用Eclipse实现标准学生类及其测试

###11.09_Java开发工具(Eclipse中接口抽象类具体类代码体现)(掌握)
* A:案例演示
	* 用Eclipse实现接口抽象类具体类代码

###11.10_Java开发工具(Eclipse中如何生成jar包并导入到项目中)(了解)
* A:jar是什么?
	* jar是多个class文件的压缩包。
* B:jar有什么用?
	* 用别人写好的东西	
* C:打jar包
	* 选中项目--右键--Export--Java--Jar--自己指定一个路径和一个名称--Finish
* D:导入jar包
	* 复制到项目路径下并添加至构建路径。


###11.11_Java开发工具(Eclipse中如何删除项目和导入项目)(掌握)
* A:删除项目
	* 选中项目 – 右键 – 删除
		* 从项目区域中删除
		* 从硬盘上删除
* B:导入项目
	* 在项目区域右键找到import
	* 找到General，展开，并找到
	* Existing Projects into Workspace
	* 点击next,然后选择你要导入的项目
	* 注意：这里选择的是项目名称

###11.12_Java开发工具(Eclipse中断点调试的基本使用)(了解)
* A:Debug的作用
	* 调试程序
	* 查看程序执行流程
* B:如何查看程序执行流程		
	* 什么是断点：
		* 就是一个标记，从哪里开始。
		
	* 如何设置断点：
		* 你想看哪里的程序，你就在那个有效程序的左边双击即可。
		
	* 在哪里设置断点：
		* 哪里不会点哪里。
		* 目前：我们就在每个方法的第一条有效语句上都加。
		
	* 如何运行设置断点后的程序：
		* 右键 -- Debug as -- Java Application
		
	* 看哪些地方：
		* Debug：断点测试的地方
			* 在这个地方，记住F6，或者点击也可以。一次看一行的执行过程。
		* Variables：查看程序的变量变化
		* ForDemo：被查看的源文件
		* Console：控制台
		
	* 如何去断点：
		* a:再次双击即可
		* b:找到Debug视图，Variables界面，找到Breakpoints，并点击，然后看到所有的断点，最后点击那个双叉。

###11.13_Java开发工具(Eclipse查看Java中参数传递问题)(了解)
* A:断点演示
	* 断点查看Java中参数传递问题

###11.14_常见对象(API概述)(了解)
* A:API(Application Programming Interface) 
	* 应用程序编程接口
* B:Java API
	* 就是Java提供给我们使用的类，这些类将底层的实现封装了起来，
	* 我们不需要关心这些类是如何实现的，只需要学习这些类如何使用。

###11.15_常见对象(Object类的概述)(了解)
* A:Object类概述
	* 类层次结构的根类
	* 所有类都直接或者间接的继承自该类
* B:构造方法
	* public Object()
	* 回想面向对象中为什么说：
	* 子类的构造方法默认访问的是父类的无参构造方法

###11.16_常见对象(Object类的hashCode()方法)(了解)
* A:案例演示
	* public int hashCode()
	* a:返回该对象的哈希码值。默认情况下，该方法会根据对象的地址来计算。
	* b:不同对象的，hashCode()一般来说不会相同。但是，同一个对象的hashCode()值肯定相同。

###11.17_常见对象(Object类的getClass()方法)(在反射的时候掌握)
* A:案例演示
	* public final Class getClass()
	* a:返回此 Object 的运行时类。
	* b:可以通过Class类中的一个方法，获取对象的真实类的全名称。	
		* public String getName()

###11.18_常见对象(Object类的toString()方法)(掌握)
* A:案例演示
	* public String toString()
	* a:返回该对象的字符串表示。
* 
		
		public Stirng toString() {
			return name + "," + age;
		}
	* b:它的值等于： 
		* getClass().getName() + "@" + Integer.toHexString(hashCode()) 
	* c:由于默认情况下的数据对我们来说没有意义，一般建议重写该方法。
* B:最终版
	* 自动生成

###11.19_常见对象(Object类的equals()方法)(掌握)
* A:案例演示
	* a:指示其他某个对象是否与此对象“相等”。 
	* b:默认情况下比较的是对象的引用是否相同。
	* c:由于比较对象的引用没有意义，一般建议重写该方法。

###11.20_常见对象(==号和equals方法的区别)(掌握)
* ==是一个比较运算符号,既可以比较基本数据类型,也可以比较引用数据类型,基本数据类型比较的是值,引用数据类型比较的是地址值
* equals方法是一个方法,只能比较引用数据类型,所有的对象都会继承Object类中的方法,如果没有重写Object类中的equals方法,equals方法和==号比较引用数据类型无区别,重写后的equals方法比较的是对象中的属性

###11.21_day11总结
* 把今天的知识点总结一遍。
