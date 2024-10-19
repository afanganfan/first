#include <stdio.h>  
  
// 函数声明：计算斐波那契数列中第n个数  
unsigned long long fibonacci(int n);  
  
int main() {  
    int n, a;  
    // 读取测试数据的组数  
    scanf("%d", &n);  
      
    // 循环处理每组测试数据   
    for (int i = 0; i < n; i++) {  
        // 读取正整数a  
        scanf("%d", &a);  
          
        // 输出斐波那契数列中第a个数的值  
        printf("%llu\n", fibonacci(a));  
    }  
      
    return 0;  
}  	
  
// 函数定义：计算斐波那契数列中第n个数  
unsigned long long fibonacci(int n) {  
    if (n == 1 || n == 2) {  
        return 1; // 斐波那契数列的第1个和第2个数都为1  
    } else {  
        return fibonacci(n - 1) + fibonacci(n - 2); // 递归计算斐波那契数  
    }  
}
