#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>

#define C_DB_SERVER_IP   "localhost"
#define C_DB_SERVER_PORT 3306
#define C_DB_USERNAME    "root"
#define C_DB_PASSWORD    ""
#define C_DB_DEFAULT_DB  "blacklist"
#define MAX 128

int c_db_select(MYSQL *mysql,char *sql)
{
    if(mysql == NULL)
    {
        printf("%s",mysql_error(mysql));
        return -1;
    }
    //mysql_real_query是操作的关键 参数分别是 mysql管道,sql语句,sql语句长度
    //mysql_real_query 返回0表示成功
    if(mysql_real_query(mysql,sql,strlen(sql)))
    {
        printf("mysql_real_query : %s\n",mysql_error(mysql));
        return -2;
    }

    //把查到的数据存储在内存中
    //mysql_store_result(mysql)会返回一个MYSQL_RES类型的指针，存储查询sql语句运行的结果
    MYSQL_RES *res = mysql_store_result(mysql);
    if(res == NULL)
    {
        printf("mysql_store_result : %s",mysql_error(mysql));
        return -3;
    }
    //获取列的个数
    int rows = mysql_num_rows(res);
    //获取行的个数
    int fields = mysql_num_fields(res);
    printf("rows = %d fields = %d\n", rows, fields);

    //把结果打印
    //mysql_fetch_row() 返回一个查询结果集的数组
    MYSQL_ROW row;
    while((row = mysql_fetch_row(res)))
    {
        int i = 0;
        for (int i = 0; i < fields; i++)
        {
            printf("%s\t",row[i]);
        }
        printf("\n");
    }
    return 0;
}

int main()
{
    MYSQL mysql;
    char buf[MAX] = "select ";
    if (mysql_init(&mysql) == NULL)
    {
        printf("%s", mysql_error(&mysql));
        return -1;
    }

    if(!mysql_real_connect(&mysql,
	C_DB_SERVER_IP, C_DB_USERNAME, 
    C_DB_PASSWORD, C_DB_DEFAULT_DB, 
    C_DB_SERVER_PORT,NULL, 0))
    {
        printf("mysql_real_connect : %s\n",mysql_error(&mysql));
        return -2;
    } 
    printf("ok\n");
    return 0;

}