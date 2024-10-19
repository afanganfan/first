#include <stdio.h>  
#include <stdlib.h>  
  
// �ȽϺ���������qsort����  
int compare(const void *a, const void *b) {  
    return (*(int*)a - *(int*)b);  
}  
  
int main() {  
    int N;  
      
    // ��ȡN  
    printf("������������N: ");  
    scanf("%d", &N);  
      
    int *array = (int*)malloc(N * sizeof(int)); // ��̬�����ڴ�  
    if (array == NULL) {  
        printf("�ڴ����ʧ��\n");  
        return 1;  
    }  
      
    // ��ȡN����  
    printf("������%d�����������ÿո����:\n", N);  
    for (int i = 0; i < N; ++i) {  
        scanf("%d", &array[i]);  
    }  
      
    // �������������  
    qsort(array, N, sizeof(int), compare);  
      
    // �������������  
    printf("����������:\n");  
    for (int i = 0; i < N; ++i) {  
        printf("%d", array[i]);  
        if (i < N - 1) {  
            printf(" ");  
        }  
    }  
    printf("\n");  
      
    // �ͷŶ�̬������ڴ�  
    free(array);  
      
    return 0;  
} 
