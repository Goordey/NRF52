#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "nrf_gpio.h"


int main(void)
{

    NRF_POWER->DCDCEN |= POWER_DCDCEN_DCDCEN_Enabled;
    NRF_POWER->DCDCEN0 |= POWER_DCDCEN0_DCDCEN_Enabled;

    NRF_NVMC->CONFIG |= NVMC_CONFIG_WEN_Wen;
    while (NRF_NVMC->READY == NVMC_READY_READY_Busy){}
    NRF_UICR->REGOUT0 = UICR_REGOUT0_VOUT_3V3;
    //NRF_NVMC->CONFIG &= NVMC_CONFIG_WEN_Een;
    NRF_NVMC->CONFIG = NVMC_CONFIG_WEN_Ren << NVMC_CONFIG_WEN_Pos;
    while (NRF_NVMC->READY == NVMC_READY_READY_Busy){}

    nrf_gpio_cfg_output(NRF_GPIO_PIN_MAP(0,13));


    while (true)
    {
nrf_gpio_pin_set(NRF_GPIO_PIN_MAP(0,13));
nrf_delay_ms(500);
nrf_gpio_pin_clear(NRF_GPIO_PIN_MAP(0,13));
nrf_delay_ms(500);


    }
}
