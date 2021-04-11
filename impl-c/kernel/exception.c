#include "uart.h"

void dumpState() {
  unsigned long esr, elr, spsr;
  asm volatile("mrs %0, esr_el1 \n" : "=r"(esr) :);
  asm volatile("mrs %0, elr_el1 \n" : "=r"(elr) :);
  asm volatile("mrs %0, spsr_el1    \n" : "=r"(spsr) :);

  uart_printf("--------------------\n");
  uart_printf("SPSR: %x\n", spsr);
  uart_printf("ELR: %x\n", elr);
  uart_printf("ESR: %x\n", esr);
  uart_printf("--------------------\n");
}
void exception_handler() {
  dumpState();
  uart_println("exception handle!!");
}