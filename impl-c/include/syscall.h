#pragma once
#include "exception.h"
#include "stddef.h"
void syscall_routing(int num, struct trap_frame *);

// define syscall numbers
#define SYS_GETPID 1
#define SYS_UART_READ 2
#define SYS_UART_WRITE 3
#define SYS_EXEC 4
#define SYS_EXIT 5

void sys_getpid(struct trap_frame *);
void sys_uart_write(struct trap_frame *);
void sys_uart_read(struct trap_frame *);