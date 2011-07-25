#include <gc/gc.h>
#include <string.h>
#include <pinocchio.h>

long plus(long left, long right);
long minus(long left, long right);
tObject smaller(long left, long right);

void cache_and_call()
{
    // Fetch the calling instruction pointer (stack-stored ip)
    __asm("mov 0(%rsp), %eax");
    // Calculate the offset of the actual code pointer
    __asm("mov %r10, %rdx");
    __asm("sub %eax, %edx");
    // Overwrite the 4-byte call-target offset with the method
    __asm("movl %edx, -4(%eax)");
    // Calculate the location of the literal in the frame
    __asm("lea -5(%eax), %edx");
    __asm("movl -9(%eax), %eax");
    __asm("cltq");
    __asm("add %rax, %rdx");
    // Calculate the class
    // If tagged integer, store the SmallInteger class
    __asm("bt $0, %rdi");
    __asm("jae not_tagged");
    __asm("mov %0, %%rax"::"r"(&SmallInteger));
    __asm("mov %rax, (%rdx)");
    // __asm("int3");
    __asm("jmp *%r10");
    // If not tagged, store the class of the receiver
__asm("not_tagged:");
    __asm("mov -8(%rdi), %rdx");
    __asm("mov %rdx, (%rax)");
    __asm("jmp *%r10");
}

void invoke_error(void* msg, void* receiver)
{
    printf("Lookup of msg %p failed on %p\n", msg, receiver);
    __asm("int3");
}

void invoke() {
    __asm("cmp $0x611b38, %rax");
    __asm("mov $plus, %r10");
    __asm("je cache_and_call");

    __asm("cmp $21, %rax");
    __asm("mov $minus, %r10");
    __asm("je cache_and_call");

    __asm("cmp $11, %rax");
    __asm("mov $smaller, %r10");
    __asm("je cache_and_call");

    __asm("mov %rdi, %rsi");
    __asm("mov %rax, %rdi");
    __asm("call invoke_error");
}

long * closureNew(int size) {
    long * c = GC_MALLOC( 2*sizeof(long*) + size*sizeof(long*) );
    printf( "- new closure at: %p\n", c+2 );
    c[0] = 77;
    return c + 2;
}

long * remoteArrayNew(int size) {
    long * c = GC_MALLOC( 2*sizeof(long*) + size*sizeof(long*) );
    printf( "- new array at: %p\n", c+2 );
    return c + 2;
}

void closureValue() {
    //if its not a closure then jmp to invoke
    __asm("bt $0, %rdi");
    __asm("jnae invoke");
    __asm("cmp $77, -0x10(%rdi)");
    __asm("jne invoke");
    //load code-pointer from the closure-object
    __asm("mov (%rdi), %rax");
    __asm("jmpq *%rax");
}

long plus(long left, long right)
{
//    printf( "plus: %p + %p\n", left, right );
    if (ARE_INTS(left, right)) {
        return (left ^ 1) + right;
    }
    PINOCCHIO_FAIL("Ints expected");
}

long minus(long left, long right)
{
//    printf( "minus: %p - %p\n", left, right );
    if (ARE_INTS(left, right)) {
        return (left - right) | 1;
    }
    PINOCCHIO_FAIL("Ints expected");
}

long bitShift(long self, long bits)
{
//    printf( "minus: %p - %p\n", left, right );
    if (ARE_INTS(self, bits)) {
        
        return ENC_INT(DEC_INT(self)<<DEC_INT(bits));
    }
    PINOCCHIO_FAIL("Ints expected");
}


tObject smaller(long left, long right)
{
    // printf( "smaller: %d < %d\n", left, right );
    if (ARE_INTS(left, right)) {
    // we don't need to remove the tag since it will end up being the same order.
        // printf( "smaller: %d < %d\n", left, right );
        return left < right ? &true : &false;
    }
    PINOCCHIO_FAIL("Ints expected");
}


tObject smallerEqual(long left, long right)
{
    // printf( "smaller: %d < %d\n", left, right );
    if (ARE_INTS(left, right)) {
    // we don't need to remove the tag since it will end up being the same order.
        // printf( "smaller: %d < %d\n", left, right );
        return left <= right ? &true : &false;
    }
    PINOCCHIO_FAIL("Ints expected");
}

tObject print(tObject receiver, tSymbol msg) {
    print_symbol(msg);
    printf("\n");
    return receiver;
}