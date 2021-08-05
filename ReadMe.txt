/*
   这个项目主要目的是从笔试面试遇到的题目出发，
   通过一系列相关题目的联系，掌握同一类型的题目解法
   避免从遇到-->会做-->遗忘-->再遇到类似题-->又不会做的恶性循环
*/
注意事项：
      1. .vscode文件夹是我自己vs code的编译和调试的json设置，如需运行代码，要根据本机的编译器位置等做相应更改
使用方法：
      1. 在主机1，2上分别配置好git，将ssh公钥保存到自己的github账号
      2. 每次更改完成通过git push将本地修改提交到github
      3. 另一台主机通过git fetch origin master同步远程代码
      4. 通过git log -p master..origin/master比较本地的master分支和origin/master分支的区别
      5. 通过git merge origin/master进行合并
      6. git的使用场景及流程参考博文：https://blog.csdn.net/muser_/article/details/97280708
      7. github的快速入门参考教程：https://www.runoob.com/w3cnote/git-guide.html
目前更新系列：
      1. 2021-07-20，ValidString：利用栈解决字符串中括号匹配的问题（起源：字节跳动QoE质量算法工程师面试）
      2. 2021-07-21，MonoStack： 利用单调栈解决寻找最近的最大/小数的问题（起源：Acwing单调栈的学习）
