#include <stddef.h>
#include "hobos/lib/stdlib.h"
#include "hobos/kstdio.h"
#include "hobos/mmio.h"
#include "hobos/timer.h"
#include "hobos/smp.h"

extern int setup_stack(void);

/* I'm alive */
void heartbeat(void)
{
	run_process((uint64_t) setup_stack, 1);
	run_process((uint64_t) setup_stack, 2);
	run_process((uint64_t) setup_stack, 3);
}

void main()
{
	get_rpi_version();
	mmio_init();
	init_console();

	struct timer t;
	init_timer(&t);
	kprintf("timer: %d\n", t.read_timer32(1, &t));
	kprintf("timer: %d\n", t.read_timer32(1, &t));

	heartbeat();

	while (1) {
		//start shell here
	}

}
