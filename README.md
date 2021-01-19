# LogStatistics
本软件可以分析Tomcat服务器的“localhost_access_日期”日志，按要求从中提取时、分、秒三个字段，并按要求从时、分、秒三个维度统计http请求数，最终生成CSV文件，存储为C:\\data.csv。
具体使用方法如下：打开CMD窗口，进入LogStatistics运行程序目录，运行命令如下：
LogStatistics Tomcat [-h|-m|-s] 日志路径
“-h”表示按时统计，“-m”表示按分统计，“-s”表示按秒统计，
比如：
LogStatistics Tomcat -h C:\\localhost_access_log.2018-05-05.txt

若服务器采用的是非Tomcat，可以在开发完相应的统计模块后自行加入本软件并完成编译。

注：
本软件由江苏有线苏州分公司石鑫鹏开发，本软件所有源码不可用于任何商业目的，任何转发请标明作者和来源。若有疑问，可邮件联系：kelehaier@126.com
