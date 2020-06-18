/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 4 Jun 2020
 * @brief 'Hello World' in Assembler (asm code embedded in C)
 *
 * Compile with: gcc -o hello-asm hello-asm.c
 *
 * @see https://jameshfisher.com/2018/02/20/c-inline-assembly-hello-world/
 */

int main(void) {
  register int    syscall_no  asm("rax") = 1;
  register int    arg1        asm("rdi") = 1;
  register char*  arg2        asm("rsi") = "hello, world!\n";
  register int    arg3        asm("rdx") = 14;
  asm("syscall");
  return 0;
}
