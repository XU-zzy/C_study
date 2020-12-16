// test2.c
// 编译方式：gcc test2.c
#include <unistd.h>
#include <stdio.h>

void fun() {
  while(1) {
    printf("Hello, I'm fun!\n");
    sleep(1);
  }
}

int main() {
  int stack[64] = {0};
  stack[63] = (int)fun;
  // 新栈的栈顶指针
  int new_esp = (int)(stack+63);

  __asm__ (
      "mov %0, %%esp\n\t" 
      "ret\n\t"
      ::"m"(new_esp));
  /* 上面的这段内联汇编翻译成 x86 汇编是这样的：
      mov esp, new_esp 切换栈顶指针
      ret 返回
  */
  return 0;
}
