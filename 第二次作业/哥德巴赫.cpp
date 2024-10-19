#include <stdio.h>  
#include <stdbool.h>  
#include <stdlib.h>  
#include <string.h>  
  
// 判断一个数是否为质数  
bool is_prime(int num) {  
    if (num <= 1) return false;  
    if (num == 2 || num == 3) return true;  
    if (num % 2 == 0 || num % 3 == 0) return false;  
    for (int i = 5; i * i <= num; i += 6) {  
        if (num % i == 0 || num % (i + 2) == 0) return false;  
    }  
    return true;  
}  
  
// 生成小于等于limit的质数列表  
int* generate_primes(int limit, int *prime_count) {  
    bool *is_prime_array = (bool*)calloc((limit + 1), sizeof(bool));  
    int *primes = (int*)malloc((limit + 1) * sizeof(int));  
    int count = 0;  
  
    for (int i = 2; i <= limit; ++i) {  
        is_prime_array[i] = true;  
    }  
  
    for (int i = 2; i * i <= limit; ++i) {  
        if (is_prime_array[i]) {  
            for (int j = i * i; j <= limit; j += i) {  
                is_prime_array[j] = false;  
            }  
        }  
    }  
  
    for (int i = 2; i <= limit; ++i) {  
        if (is_prime_array[i]) {  
            primes[count++] = i;  
        }  
    }  
  
    *prime_count = count;  
    free(is_prime_array);  
    return primes;  
}  
  
// 验证哥德巴赫猜想  
void verify_goldbach_conjecture(int N) {  
    if (N % 2 != 0 || N < 4) {  
        printf("输入必须是一个大于等于4的偶数。\n");  
        return;  
    }  
  
    int limit = N / 2;   
    int prime_count;  
    int *primes = generate_primes(limit, &prime_count);  
  
    for (int even_num = 4; even_num <= N; even_num += 2) {  
        bool found = false;  
        for (int i = 0; i < prime_count; ++i) {  
            int complement = even_num - primes[i];  
            if (complement >= primes[i] && is_prime(complement)) {   
                printf("%d = %d + %d\n", even_num, primes[i], complement);  
                found = true;  
                break;   
            }  
        }  
        if (!found) {  
            printf("未找到哥德巴赫分解：%d\n", even_num);  
        }  
    }  
  
    free(primes);  
}  
  
int main() {  
    int N;  
    printf("请输入一个大于等于4的偶数N: ");  
    scanf("%d", &N);  
  
    verify_goldbach_conjecture(N);  
  
    return 0;  
}
