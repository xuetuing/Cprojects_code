
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

// ����ʱ����λ��ms
float timediff(struct timeval *begin, 
        struct timeval *end){
    int n;
    // �ȼ�������ʱ���������΢��
    n = ( end->tv_sec - begin->tv_sec ) * 1000000
        + ( end->tv_usec - begin->tv_usec );

    // ת��Ϊ���뷵��
    return (float) (n / 1000);
}

int main(void){
    struct timeval begin, end;

    gettimeofday(&begin, 0);

    // �����ó������һ��
    printf("do something here...");
    sleep(1);

    gettimeofday(&end, 0);

    printf("running time : %fms\n", timediff(&begin, &end));

    return 0;
}
