#ifndef __SUNXI_GPIO_H__
#define __SUNXI_GPIO_H__

#include <inttypes.h>

enum {
	GPIO_INPUT		  = 0,
	GPIO_OUTPUT		  = 1,
	GPIO_PERIPH_MUX2  = 2,
	GPIO_PERIPH_MUX3  = 3,
	GPIO_PERIPH_MUX4  = 4,
	GPIO_PERIPH_MUX5  = 5,
	GPIO_PERIPH_MUX6  = 6,
	GPIO_PERIPH_MUX7  = 7,
	GPIO_PERIPH_MUX8  = 8,
	GPIO_PERIPH_MUX14 = 14,
	GPIO_DISABLED	  = 0xf,
};

#define PORTB			 0
#define PORTC			 1
#define PORTD			 2
#define PORTE			 3
#define PORTF			 4
#define PORTG			 5
#define SUNXI_GPIO_PORTS (PORTG + 1)

enum gpio_pull_t {
	GPIO_PULL_UP   = 0,
	GPIO_PULL_DOWN = 1,
	GPIO_PULL_NONE = 2,
};

typedef uint32_t gpio_t;
#define PIO_NUM_IO_BITS 5

#define GPIO_PIN(x, y) (((uint32_t)(x << PIO_NUM_IO_BITS)) | y)

typedef struct {
	gpio_t	pin;
	uint8_t mux;
} gpio_mux_t;

void sunxi_gpio_init(gpio_t pin, unsigned int cfg);
void sunxi_gpio_write(gpio_t pin, int value);
int	 sunxi_gpio_read(gpio_t pin);
void sunxi_gpio_set_pull(gpio_t pin, enum gpio_pull_t pull);
void sunxi_gpio_set_drive_lvl(const gpio_t pin, uint8_t lvl);

#endif
