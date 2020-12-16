#include <stdio.h>

typedef int jmp_buf[9]; // {0:ebx, 1:ecx, 2:edx, 3:esi, 4:edi, 5:esp, 6:ebp, 7:eflags, 8:ret}

jmp_buf jmpbuf;


__declspec(naked)
int setjmp(jmp_buf env) {
    __asm {
    push ebp        //保存上一个函数的基地址，将ebp压入到oldebp
    mov ebp, esp    //将ebp更新为自己的栈帧基址
    sub esp, 0x40   //为局部变量开辟存储区
    push esi        //保存源索引寄存器
    push ebx        //基地址寄存器

    mov eax, 0      //返回值为0
    mov ebx, [ebp + 8] // env 基址

    //保存现场
    mov [ebx], eax      //保存返回值
    mov [ebx+4], ecx    //保存计数器
    mov [ebx+8], edx    //保存
    mov [ebx+12], esi   //保存源索引寄存器
    mov [ebx+16], edi   //保存目标索引寄存器

    // 提取 esp（指向 ret 返回地址）
    lea esi, [ebp+4]    //取ebp的地址
    mov [ebx+20], esi

    // 提取真实 ebp
    mov esi, [ebp]
    mov [ebx+24], esi


    // 保存 eflags
    pushfd
    mov esi, [esp]
    add esp, 4
    mov[ebx + 28], esi

    // 保存返回地址，栈帧基址 + 4 的位置指向的值
    mov esi, [ebp + 4]
    mov [ebx + 32], esi

    pop ebx
    pop esi
    mov esp, ebp
    pop ebp
    ret
    }
}


// {0:ebx, 1:ecx, 2:edx, 3:esi, 4:edi, 5:esp, 6:ebp, 7:eflags, 8:ret}
__declspec(naked)
void longjmp(jmp_buf env, int val) {
    __asm {
    mov eax, [esp + 8] // val
    mov ebx, [esp + 4] // env

    // 恢复 ecx, edx, edi
    mov ecx, [ebx + 4]
    mov edx, [ebx + 8]
    mov edi, [ebx + 16]

    // 恢复 eflags
    sub esp, 4
    mov esi, [ebx + 28]
    mov [esp], esi
    popfd

    // 恢复 esp , ebp
    mov ebp, [ebx + 24]
    mov esp, [ebx + 20]

    // 构造返回地址
    mov esi, [ebx + 32]
    mov [esp], esi

    // 恢复 esi
    mov esi, [ebx + 12]

    mov ebx, [ebx] // 恢复 ebx

    ret
    }
}

void doSomething() {
    int n = 0;
    scanf("%d", &n);
    if (n == 100) {
        longjmp(jmpbuf, 1);
    }

    if (n == 200) {
        longjmp(jmpbuf, 2);
    }

}

int global = 100;

int main() {

    int res = 0;
    if ((res = setjmp(jmpbuf)) != 0) {
        printf("hello! res = %d\n", res);
    }


    while (1) {
        doSomething();
    }
}