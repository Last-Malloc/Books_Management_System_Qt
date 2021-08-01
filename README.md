

[github仓库地址](https://github.com/Last-Malloc/Books_Management_System_Qt)

[csdn文章地址](https://blog.csdn.net/qq_42283621/article/details/119304661)

# 1. 前言

​	本项目是作者在大二时的C++课程设计项目，水平一般，希望和大家一起学习和讨论。

​	本文章只对项目做简要的介绍，详细代码 ppt 生成测试数据的代码 将放在github中。

​	代码需要使用visual studio + qt插件打开；生成测试数据程序为纯C++，可以用code::blocks打开运行，当然你也可以直接使用里面的book.txt。

# 2. 项目简介

该系统基于C++和Qt5进行开发，用于不同权限的用户管理、维护和使用书籍、用户、借阅等数据信息。

**需求分析**

管理员：
   图书的增删改查;   图书的借阅、归还;   图书的借阅和逾期查询；   人员的增删改查;    个人信息修改；

用户：
   图书查询；   个人图书借阅和逾期查询；   图书续借；   个人信息修改；

**使用者**
   普通用户 普通管理员 最高管理员

**功能模块图**

![image-20210801220532128](https://img-blog.csdnimg.cn/img_convert/5c77e8e2615c86db55ac6ea54aaeeb6a.png)

**流程图**

![image-20210801220608121](https://img-blog.csdnimg.cn/img_convert/d708139d5d15443835d7b7dc622b9ab9.png)

**UML图**

![image-20210801220631892](https://img-blog.csdnimg.cn/img_convert/4710e811a091ae989d107855aa9d7352.png)

# 3. 系统界面

![image-20210801220717359](https://img-blog.csdnimg.cn/img_convert/928b8112f27e36adbf8f4d680eb6d093.png)

![image-20210801220730100](https://img-blog.csdnimg.cn/img_convert/9707524410871ca80e15499f6135e864.png)

![image-20210801220739906](https://img-blog.csdnimg.cn/img_convert/40975b631ae57325410a639be182575c.png)

![image-20210801220750761](https://img-blog.csdnimg.cn/img_convert/8361d6250fc213d44971764afb8db733.png)

![image-20210801220801797](https://img-blog.csdnimg.cn/img_convert/7c5cd8f6956aa018ffab005e3e573641.png)

![image-20210801220812980](https://img-blog.csdnimg.cn/img_convert/ac76ccdefd319d6c418585d6b0c49c60.png)

![image-20210801220822477](https://img-blog.csdnimg.cn/img_convert/65616ab63e4d23738f00cb79c555a4a8.png)

![image-20210801220831722](https://img-blog.csdnimg.cn/img_convert/41942f2d9a959b257220c8f5c8fbd45d.png)

![image-20210801220841090](https://img-blog.csdnimg.cn/img_convert/10e17b4f50a0a2a35e319e4ec23b1fe2.png)

![image-20210801220848345](https://img-blog.csdnimg.cn/img_convert/c7503c57435fb586da14cd7f264a0b1d.png)