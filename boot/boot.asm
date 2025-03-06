section .text
org 0x7c00
global _start

[bits 32]
_start:
  cli
  mov esp, 0x540
disk_load:
  mov ah, 0x00
  mov al, 0x03
  int 10H ; set text VGA mode

  mov ah, 0x02
  mov al, 0x01 ; read n sector (n = 1 for now)
  mov ch, 0x00 ; c
  mov cl, 0x02 ; s (read second sector)
  mov dh, 0x00 ; h
  xor bx, bx
  mov es, bx
  mov bx, 0x7e00
  int 13H

  mov ah, 0x9
  mov al, 'S'
  mov bh, 0
  mov bl, 0x0F
  mov cx, 1
  int 10H

  mov ax, 0x3
  mov ss, ax
  mov ax, 0x2
  mov ds, ax
  lgdt [gdt_gdtr_limit]
  mov eax, cr0
  or al, 0x1
  mov cr0, eax
  
  call 0x1:0x200
  hlt ; never be here

times (396 - ($ - $$)) db 0x00

section .data
gdt_gdtr_limit dw 0x0027 
gdt_gdtr_addr_low dd 0x00007d96
gdt_gdtr_addr_hight dd 0x00000000
gdt_null dq 0x0000000000000000
gdt_code0 dq 0x004796007e008200
gdt_data0 dq 0x000f92000000ffff
gdt_stack0 dq 0x00c09607ffff1000
gdt_user dq 0x0020e00000000000
pt1_sec_type db 0x80 
pt1_start_head db 0x00
pt1_cs dw 0x0000
pt1_sys_id db 0x00
pt1_endh db 0x00
pt1_end_cs dw 0x0000
pt1_lba: dd 0x00000001
pt1_sec_len: dd 0x00000001
pt2 dq 0x0000000000000000, 0x0000000000000000 
pt3 dq 0x0000000000000000, 0x0000000000000000
pt4 dq 0x0000000000000000, 0x0000000000000000
eob1 db 0x55
eob2 db 0xAA