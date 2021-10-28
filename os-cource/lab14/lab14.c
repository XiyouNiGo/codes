#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int A;
int B = 0;
int C = 2;
static int D;
static int E = 0;
static int F = 4;
static int G = 5;
static char H = 6;

int main(int argc, char *argv[]) {
  int a;
  int b = 0;
  int c = 2;
  static int d;
  static int e = 0;
  static int f = 4;
  static int g = 5;
  char char1[] = "abcde";
  char *cptr = "123456";
  int *heap = malloc(sizeof(int) * 4);

  printf("PID is :%d\n\n", getpid());
  printf("int A　　A_addr = %p\n", &A);
  printf("int B=0　　B_addr = %p\n", &B);
  printf("int C=2　　C_addr = %p\n", &C);
  printf("static int D　　D_addr = %p\n", &D);
  printf("static int E=0　　E_addr = %p\n", &E);
  printf("static int F=4　　F_addr = %p\n", &F);
  printf("const int G=0　　G_addr = %p\n", &G);
  printf("const char H=0　　H_addr = %p\n", &H);
  printf("\n");
  printf("int a　　a_addr = %p", &a);
  printf("int b=0　　b_addr = %p", &b);
  printf("int c=2　　c_addr = %p", &c);
  printf("static int d　　d_addr = %p", &d);
  printf("static int e=0　　e_addr = %p", &e);
  printf("static int f=4　　f_addr = %p", &f);
  printf("const int g=5　　g_addr = %p", &g);
  printf("\n");
  printf("char char1[] = 'abcde'\t\t\tchar1_addr = %p", char1);
  printf("char char1[]= 'abcde'\t\t\t	&char1_addr = %p", &char1);
  printf("*char *cptr = '1'\t\t\t cptr_addr =%p", &cptr);
  printf("value of the cptr\t\t\tcptr_value = 0x%p\n", cptr);
  printf("value of %p\t\t\tvalue_0x%p = %d\n", cptr, cptr, *cptr);
  printf("int* heap = malloc(sizeof(int)*4)\theap__addr = %p\n", heap);
  printf("int* heap = malloc(sizeof(int)*4)\theap__addr = %p\n", &heap);
  pause();
  free(heap);
  return 0;
}