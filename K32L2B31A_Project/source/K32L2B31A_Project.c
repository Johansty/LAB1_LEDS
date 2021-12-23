/*! @file : K32L2B31A_Project.c
 * @author  Ernesto Andres Rincon Cruz
 * @version 0.0.000
 * @date    23/08/2021
 * @brief   Funcion principal main
 * @details
 *			v0.0.000	Proyecto base creado usando MCUXpresso
 *
 *
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "K32L2B31A.h"
#include "fsl_debug_console.h"
#include <limits.h>
#include <float.h>

#include <iot_sdk_peripherals_leds.h>
#include <iot_sdk_peripherals_light.h>
#include "iot_sdk_peripherals_buttons.h"
#include "iot_sdk_peripheral_temperature.h"

#include "iot_sdk_ irq_lptimer0.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define TIEMPO  1000000
/*******************************************************************************
 * Private Prototypes
 ******************************************************************************/
void delay(void);
/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Local vars
 ******************************************************************************/

/*******************************************************************************
 * Private Source Code
 ******************************************************************************/

void delayLedVerde(void)
    {
        volatile uint32_t i = 0;
        for (i = 0; i < TIEMPO; i++)
        {
            __asm("NOP"); /* delay */
        }
    }


int main(void) {

	uint8_t c=0;
	uint8_t j=1;
	uint8_t i=0;


    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    /* Activa LPTMR0 para que iniciar contador y posterior IRQ cada 1 segundo*/
    LPTMR_StartTimer(LPTMR0);



    while(1) {

    	encenderLedVerde();
    	delayLedVerde();
    	apagarLedVerde();
    	delayLedVerde();

    	i++;

    	if(j==1 && i==10){

    	    		encenderLedRojo();
    	    		i=0;
    	    	    c=1;
    	    	    j=0;
    	    	}


    	if(c==1 && i==10){
    	    	apagarLedRojo();
    	    	i=0;
    	    	j=1;
    	    	c=0;

    	}



    }



    return 0 ;
}
