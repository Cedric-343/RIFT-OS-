void boot_message(void) {
    volatile char* VGA_MEM = (volatile char*)0xB8000;
    const char* message = "Welcome to RIFT OS";
    
    for (int i = 0; message[i] != '\0'; i++) {
        VGA_MEM[i * 2] = message[i];
        VGA_MEM[i * 2 + 1] = 0x07;
    }
}
void main_kernel_function(void) {



}

void sys_exit(void) {
    


}

void* syscall_table[] = {
    [0] = sys_exit
    [1] = sys_write
    [2] = sys_read
}
