/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "user.h"

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void)
{
    /* PORT Setup */
    TRISA = 0x07, TRISB = 0x00, TRISC = 0x20;
    PORTA = 0x00, PORTB = 0x00, PORTC = 0x00;
    WPUA = 0x00;
    
    ANSELA = 0x00;    
    
    /*
     * FOSC = 64MHz
     * 16MIPS, ~62.5ns/instruction          
     */
#if 1    
    /* ECCP Config for RC5 */
    PIE1bits.CCP1IE = 0;    
    CCP1CONbits.CCP1M = 0x05;   //enable compare on RC5, capture every rising edge, ~16ms between edges
    
    //T3CONbits.T3CCP1 = 1;       //set timer3 as timer for ECCP1
    //T3CONbits.T3CKPS = 0x03;    // set pre-scale to 1/8th Pre-scale, ~2e6 clock, 500ns/tick. ~33ms of counting
    
    //Clear and re-enable interrupts
    PIR1bits.CCP1IF = 0;
    PIE1bits.CCP1IE = 1;
    
    //PIR2bits.TMR3IF = 0;
    //PIE2bits.TMR3IE = 1;
    
    /* Configure Interrupts */
    INTCONbits.PEIE = 1;        
    INTCONbits.GIE = 1;
#endif
    
    //https://ww1.microchip.com/downloads/en/appnotes/01473a.pdf - USE TIMER3, CCP method on page 10
                
}

