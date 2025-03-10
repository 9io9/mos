ENTRY(loader_main)

SECTIONS 
{
  . = 0x7e00;

  .text : AT(0x0) {
    *(.text)
  }

  PROVIDE(etext = .);

  .rodata : {
    *(.rodata)
  }

  PROVIDE(erodata = .);

  .data : {
    *(.data)
  }

  PROVIDE(edata = .);

  /DISCARD/ : {
    *(.eh_frame .note.GNU-stack)
  } 
}