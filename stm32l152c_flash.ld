/* Entry Point */
ENTRY(reset)
/* Specify the memory areas */
MEMORY {
    flash (rx) : org = 0x08000000, len = 256K
    ram (rwx)  : org = 0x20000000, len = 32k
}
/* Define output sections */
SECTIONS {
    . = ORIGIN(flash);
    .text :
    {
        *(.vectors) /* Vector table */
        *(.vectors.*) /* Any extra device vectors */
        *(.text) /* Program code */
        *(.rodata) /* Read only data */
        *(.rodata*)
        __text_end = .;
    } >flash

    /*
     * This is the initialized data section
     * The program executes knowing that the data is in the ram
     * but the loader puts the initial values in the flash (inidata).
     * One task of "startup" is to copy the initial values from flash to ram.
     */
    .data :
    {
        /* This is used by the startup in order to initialize the .data secion */
        PROVIDE (__data_start = .);
        *(.data)
        *(.data.*)
        . = ALIGN(4);
        /* This is used by the startup in order to initialize the .data secion */
        PROVIDE (__data_end = .);
    } >ram AT >flash

    .bss :
    {
        PROVIDE(__bss_start = .);
        *(.bss)
        *(COMMON)
        . = ALIGN(4);
        PROVIDE(__bss_end = .);
    } >ram

    . = ALIGN(4);

    _stack_start = .;

}

_end = .;
/* Provide stack end address */
PROVIDE(_estack = ORIGIN(ram) + LENGTH(ram) - 4); 
