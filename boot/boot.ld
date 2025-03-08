ENTRY(loader_main)

SECTIONS 
{
  . = 0x7e00;

  .text : AT(0x0) {
    *(.text)
  }

  PROVIDE(etext = .);

  /DISCARD/ : {
    *(.eh_frame .note.GNU-stack)
  } 
}