void main_kernel_function(void) {
    volatile char* VGA_MEM = (volatile char*)0xB8000;
    const char* message = "Welcome to RIFT OS";
    
    for (int i = 0; message[i] != '\0'; i++) {
        VGA_MEM[i * 2] = message[i];
        VGA_MEM[i * 2 + 1] = 0x07;
    }
}

