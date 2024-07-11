#include <stdio.h> 
#include <string.h> 
 
unsigned long long factorial(int n) { 
    if (n == 0 || n == 1) 
        return 1; 
    return n * factorial(n - 1); 
} 
 
unsigned long long countAnagrams(char *word) { 
    int len = strlen(word); 
    int freq[256] = {0};  
 
    for (int i = 0; i < len; i++) { 
        freq[(int)word[i]]++; 
    } 
 
    unsigned long long totalPermutations = factorial(len); 
 
    for (int i = 0; i < 256; i++) { 
        if (freq[i] > 1) { 
            totalPermutations /= factorial(freq[i]); 
        } 
    } 
 
    return totalPermutations; 
} 
 
int main() { 
    char word[15]; 
     
    printf("Введіть слово: "); 
    scanf("%s", word); 
 
    printf("Кількість анаграм: %llu\n", countAnagrams(word)); 
 
    return 0; 
}