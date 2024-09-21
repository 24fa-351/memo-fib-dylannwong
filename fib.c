#include <stdio.h>
#include <stdlib.h>

unsigned long long cache[102] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
extern unsigned long long fib_r_core(int n);
extern unsigned long long fib_i_core(int n);

unsigned long long fib_i(int n) {
   if(cache[n] != -1) {
      return cache[n];
   }

   cache[n] = fib_i_core(n);
   return cache[n];
}

unsigned long long fib_i_core(int n) {

      unsigned long long num1 = 0;
      unsigned long long  num2 = 1;
      unsigned long long  sum = 1;

   if(n == 1) {
      return 0;
   } else {
      for(int i = 0; i < n - 1; ++i) {
         if(i + 2 == n) {
            return sum;
         }
         sum = num1 + num2;
         num1 = num2;
         num2 = sum;
      }
   }
   
}


unsigned long long fib_r(unsigned long long n) {
   if(n == 0) {
      return 0;
   }
   if(n == 1) {
     return 1;
   }

   if (cache[n] != -1) {
      return cache[n];
   }

   cache[n] = fib_r_core(n);

   return cache[n];
   
}
unsigned long long fib_r_core(int n) {

   if (n == 0) {
      return 0;
   }
   if (n == 1) {
      return 1;
   }

   return fib_r(n - 1) + fib_r(n - 2);
}

int main(int argc, char *argv[]) {
   int n = atoi(argv[1]);
   if(argv[2] == "r"){
      printf("%lld",fib_r(n-1));
   }
   if(argv[2]) {
      printf("%lld",fib_i(n));
   }
      
   return 0;
}


