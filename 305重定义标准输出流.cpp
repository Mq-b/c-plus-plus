#include <stdio.h>
#include<Windows.h>
int main() {
    FILE* fp = NULL;
    const char* filename = "output.log";

    fp = freopen(filename, "w+", stdout);       //标准输出重定向到文件output.log
    if (NULL == fp)
    {
        fprintf(stderr, "error redirecting stdout\n");
        exit(1);
    }
    system("netstat -ano");//显示进程
    printf("6666666666666666666");
    fclose(fp);
}
//不管是system还是printf全部显示到了文件中