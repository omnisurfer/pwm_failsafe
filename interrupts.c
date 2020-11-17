/******************************************************************************/
/*Files to Include                                                            */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

/******************************************************************************/
/* Interrupt Routines                                                         */
/******************************************************************************/

/* Baseline devices don't have interrupts. Note that some PIC16's 
 * are baseline devices.  Unfortunately the baseline detection macro is 
 * _PIC12 */
#ifndef _PIC12

void __interrupt() isr(void)
{
    /* This code stub shows general interrupt handling.  Note that these
    conditional statements are not handled within 3 seperate if blocks.
    Do not use a seperate if block for each interrupt flag to avoid run
    time errors. */

#if 1
    
    //See Section 13.2  CCPR1H:CCPR1L
    
    /* TODO Add interrupt routine code here. */

    /* Determine which flag generated the interrupt */
    if(PIR1bits.CCP1IF)
    {                                  
        int16_t temp;
        temp = CCPR1H << 4;
        temp += CCPR1L;
                
        PORTBbits.RB5 = 1;        
        
        PIR1bits.CCP1IF=0; /* Clear Interrupt Flag */
    }
    /*
    else if(PIR2bits.TMR3IF)
    {
        PORTBbits.RB6 = 1;
        
        PIR2bits.TMR3IF = 0;
    }
    */
    else
    {
        /* Unhandled interrupts */
    }    

#endif

}
#endif


