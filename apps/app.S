/*
 * (C) 2022, Cornell University
 * All rights reserved.
 */

/* Author: Yunhao Zhang
 * Description: initialize the stack pointer for the application
 */
        .section .text
        .global _enter
_enter:
        li sp,0x80002000
        call main
        call exit
