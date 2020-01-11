
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

// 计算时间差，单位：ms
float timediff(struct timeval *begin, 
        struct timeval *end){
    int n;
    // 先计算两个时间点相差多少微秒
    n = ( end->tv_sec - begin->tv_sec ) * 1000000
        + ( end->tv_usec - begin->tv_usec );

    // 转化为毫秒返回
    return (float) (n / 1000);
}

int main(void){
    struct timeval begin, end;

    gettimeofday(&begin, 0);

    // 这里让程序挂起一秒
    printf("do something here...");
    sleep(1);

    gettimeofday(&end, 0);

    printf("running time : %fms\n", timediff(&begin, &end));

    return 0;
}
