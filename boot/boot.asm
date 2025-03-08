section .text
global _start

[BITS 16]
[ORG 0x7c00]
_start:
  cli
  mov sp, 0x0540 ; init a 64 bytes 16bits stack (32 elements)

  mov ah, 0x42 ; read second boot part from disk
  mov dl, 0x80
  mov si, dap
  mov bx, 0x0000
  mov es, bx
  int 13H

  mov ah, 0x00
  mov al, 0x03 ; text mode
  int 10H

  mov ah, 0x01 ; hide cursor
  mov ch, 0xFF
  mov cl, 0x00
  int 10H

pe:
  lgdt [gdt_gdtr_limit]

  mov eax, cr0
  or al, 0x1
  mov cr0, eax
  jmp 0x08:pe32

[BITS 32]
pe32:
  mov ax, 0x0010
  mov ds, ax
  mov es, ax
  mov fs, ax
  mov gs, ax
  mov ax, 0x0018
  mov ss, ax
  jmp 0x08:0x7e00

times (436 - ($ - $$)) db 0x00

section .data
gdt_gdtr_limit dw 0x0027 
gdt_gdtr_addr_low dd 0x00007dbe
gdt_gdtr_addr_high dd 0x00000000
gdt_null dq 0x0000000000000000
gdt_code0 dq 0x0048980000000000
gdt_data0 dq 0x0048920000000000
gdt_stack0 dq 0x00409607ffff1000
gdt_user dq 0x0020e00000000000
dap db 0x10
dap_res db 0x00
dap_sec dw 0x0004
dap_buf dw 0x7e00
dap_off dw 0x0000
lba1 dd 0x00000001
lba2 dd 0x00000000
data_end dd 0x0007EFFF ; data region end
data_start dd 0x00000000 ; data region start

eob1 db 0x55
eob2 db 0xAA