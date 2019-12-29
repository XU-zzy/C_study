#include<stdio.h>

__attribute__((section("INIT_VAR"))) int global_init_var = 88;
__attribute__((section("UNINIT_VAR"))) int global_uninit_var;

extern char _binary_zzy_1_png_start;
extern char _binary_zzy_1_png_end;
extern char _binary_zzy_1_png_size; 


extern char INIT_VAR;

void func1( int i ){
    printf(" %d \n",i);
}

int main(void){
    static int static_var = 85;
    static int static_var_2;
    static int static_var_3 = 0;

    int a = 1;
    int b;
    func1(static_var + static_var_2 + a + b);
    printf("_binary_test_png_start %#lx\n",(unsigned long)&_binary_zzy_1_png_start);
    printf("_binary_test_png_end %#lx\n",(unsigned long)&_binary_zzy_1_png_end);
    /* printf("_binary_test_png_size %ld\n",(unsigned long)&_binary_zzy_1_png_end - (unsigned long)&_binary_zzy_1_png_start); */
    printf("_binary_test_png_size %#lx\n",(unsigned long)&_binary_zzy_1_png_size);
    printf("INIT_VAR %#lx\n",(unsigned long)&INIT_VAR);

    return 0;
}
