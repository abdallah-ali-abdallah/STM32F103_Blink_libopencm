#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/systick.h>


int main(void) {
    rcc_periph_clock_enable(RCC_GPIOB);
    gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO0);

    while(1) {
        gpio_set(GPIOB, GPIO0);
        for (int i = 0; i < 1000000; ++i) __asm__("nop");
        gpio_clear(GPIOB, GPIO0);
        for (int i = 0; i <  500000; ++i) __asm__("nop");
    }
}
