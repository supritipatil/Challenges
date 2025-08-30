#include <stdio.h>
long long int gcd(long long int a, long long int b)
{
  while (b)
  {
    long long int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}
long long int lcm(long long int a, long long int b)
{
  if (a == 0 || b == 0)
  {
    return 0;
  }
  return (a / gcd(a, b)) * b;
}
int main()
{
  long long int N, M;
  N = 4;
  M = 6;
  printf("Input: N = %lld, M = %lld\n", N, M);
  printf("Output: %lld\n\n", lcm(N, M));
  N = 5;
  M = 10;
  printf("Input: N = %lld, M = %lld\n", N, M);
  printf("Output: %lld\n\n", lcm(N, M));
  N = 7;
  M = 3;
  printf("Input: N = %lld, M = %lld\n", N, M);
  printf("Output: %lld\n\n", lcm(N, M));
  N = 1;
  M = 987654321;
  printf("Input: N = %lld, M = %lld\n", N, M);
  printf("Output: %lld\n\n", lcm(N, M));
  N = 123456;
  M = 789012;
  printf("Input: N = %lld, M = %lld\n", N, M);
  printf("Output: %lld\n\n", lcm(N, M));
  N = 100;
  M = 100;
  printf("Input: N = %lld, M = %lld\n", N, M);
  printf("Output: %lld\n\n", lcm(N, M))
  return 0;
}
