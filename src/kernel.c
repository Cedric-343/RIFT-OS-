void boot_message(void) {
    volatile char* VGA_MEM = (volatile char*)0xB8000;
    const char* message = "Welcome to RIFT OS";
    
    for (int i = 0; message[i] != '\0'; i++) {
        VGA_MEM[i * 2] = message[i];
        VGA_MEM[i * 2 + 1] = 0x07;
    }
}
void main_kernel_function(void) {
    __asm__ __volatile__ (
    "ldr r0, =0x20000000 \n\t"  
    "ldr r1, =0x20001000 \n\t"  
    "movs r2, #0         \n\t"  

    "1:                  \n\t"  
    "cmp r0, r1          \n\t"  
    "bhs 2f              \n\t"  
    "str r2, [r0], #4    \n\t"  
    "b 1b                \n\t"  
    "2:                  \n\t"  
    : 
    : 
    : "r0", "r1", "r2", "cc", "memory"
);
}

void accelerated_network_interface_card() {
    //put your code here for fast pure script running in languages like C++ or evern Ocaml
    
}

void sys_exit(void) {

}

void* syscall_table[] = {
    [0] = sys_exit,
    [1] = sys_write,
    [2] = sys_read,
}


/////FOR THE TIME BEING THE ASM VOLATILE CODE WAS MADE BY AI THIS WILL CHANGE IN FUTURE COMMITS (for prototyping)/////
