#[no_mangle]
pub extern "C" fn main_kernel_function() {
    let vga_mem = 0xB8000 as *mut u8;
    let message = b"Welcome to RIFT OS";

    for (i, &byte) in message.iter().enumerate() {
        unsafe {
            vga_mem.add(i * 2).write_volatile(byte);
            vga_mem.add(i * 2 + 1).write_volatile(0x07);
        }
    }
}
