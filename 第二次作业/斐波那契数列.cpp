#include <stdio.h>  
  
// ��������������쳲����������е�n����  
unsigned long long fibonacci(int n);  
  
int main() {  
    int n, a;  
    // ��ȡ�������ݵ�����  
    scanf("%d", &n);  
      
    // ѭ������ÿ���������   
    for (int i = 0; i < n; i++) {  
        // ��ȡ������a  
        scanf("%d", &a);  
          
        // ���쳲����������е�a������ֵ  
        printf("%llu\n", fibonacci(a));  
    }  
      
    return 0;  
}  	
  
// �������壺����쳲����������е�n����  
unsigned long long fibonacci(int n) {  
    if (n == 1 || n == 2) {  
        return 1; // 쳲��������еĵ�1���͵�2������Ϊ1  
    } else {  
        return fibonacci(n - 1) + fibonacci(n - 2); // �ݹ����쳲�������  
    }  
}
