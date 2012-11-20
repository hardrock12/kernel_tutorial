// main.c -- Defines the C-code kernel entry point, calls initialisation routines.
// Made for JamesM's tutorials 
#include "monitor.h"
#include "timer.h"

int main(struct multiboot *mboot_ptr)
{
  init_descriptor_tables();
  // All our initialisation calls will go in here.
  monitor_clear();
  monitor_write("HELLO WOOOORLD!");
  monitor_put('\n');
  monitor_write_hex(0xDEADBABE);
  monitor_write_hex(0x123F654C);
  monitor_put('\n');
  monitor_write_dec(321);
  monitor_write_dec(0);
  monitor_write_dec(2147483647);
  monitor_put('\n');

  asm volatile ("int $0x3");
  asm volatile ("int $0x4");
  asm volatile("sti");
  monitor_put('\n');
  //  asm volatile ("int $0x20");
  init_timer(1193180); // Initialise timer to 50Hz

  return 0xDEADBABE;
}
