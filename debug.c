#include "hobos/debug.h"


void debug_led_on(int c)
{
	int led = 12; //fallback

	if (!gpio_base)
		init_gpio();

	if (c == RED)
		led = 17;
	if (c == BLUE)
		led = 27;
	else if (c == GREEN)
		led = 22;

	set_gpio_func(led, 1);
	set_gpio_val(led);
}
