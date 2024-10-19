#include <stdio.h>  
#include <stdlib.h>  
  
// 比较函数，用于qsort排序  
int compare(const void *a, const void *b) {  
    return (*(int*)a - *(int*)b);  
}  
  
int main() {  
    int N;  
      
    // 读取N  
    printf("请输入正整数N: ");  
    scanf("%d", &N);  
      
    int *array = (int*)malloc(N * sizeof(int)); // 动态分配内存  
    if (array == NULL) {  
        printf("内存分配失败\n");  
        return 1;  
    }  
      
    // 读取N个数  
    printf("请输入%d个正整数，用空格隔开:\n", N);  
    for (int i = 0; i < N; ++i) {  
        scanf("%d", &array[i]);  
    }  
      
    // 对数组进行排序  
    qsort(array, N, sizeof(int), compare);  
      
    // 输出排序后的数组  
    printf("排序后的数组:\n");  
    for (int i = 0; i < N; ++i) {  
        printf("%d", array[i]);  
        if (i < N - 1) {  
            printf(" ");  
        }  
    }  
    printf("\n");  
      
    // 释放动态分配的内存  
    free(array);  
      
    return 0;  
} 
