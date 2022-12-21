/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1705
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set KEY_Y5 aliases
#define KEY_Y5_TRIS                 TRISAbits.TRISA0
#define KEY_Y5_LAT                  LATAbits.LATA0
#define KEY_Y5_PORT                 PORTAbits.RA0
#define KEY_Y5_WPU                  WPUAbits.WPUA0
#define KEY_Y5_OD                   ODCONAbits.ODA0
#define KEY_Y5_ANS                  ANSELAbits.ANSA0
#define KEY_Y5_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define KEY_Y5_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define KEY_Y5_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define KEY_Y5_GetValue()           PORTAbits.RA0
#define KEY_Y5_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define KEY_Y5_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define KEY_Y5_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define KEY_Y5_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define KEY_Y5_SetPushPull()        do { ODCONAbits.ODA0 = 0; } while(0)
#define KEY_Y5_SetOpenDrain()       do { ODCONAbits.ODA0 = 1; } while(0)
#define KEY_Y5_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define KEY_Y5_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set KEY_Y4 aliases
#define KEY_Y4_TRIS                 TRISAbits.TRISA1
#define KEY_Y4_LAT                  LATAbits.LATA1
#define KEY_Y4_PORT                 PORTAbits.RA1
#define KEY_Y4_WPU                  WPUAbits.WPUA1
#define KEY_Y4_OD                   ODCONAbits.ODA1
#define KEY_Y4_ANS                  ANSELAbits.ANSA1
#define KEY_Y4_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define KEY_Y4_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define KEY_Y4_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define KEY_Y4_GetValue()           PORTAbits.RA1
#define KEY_Y4_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define KEY_Y4_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define KEY_Y4_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define KEY_Y4_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define KEY_Y4_SetPushPull()        do { ODCONAbits.ODA1 = 0; } while(0)
#define KEY_Y4_SetOpenDrain()       do { ODCONAbits.ODA1 = 1; } while(0)
#define KEY_Y4_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define KEY_Y4_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set KEY_Y3 aliases
#define KEY_Y3_TRIS                 TRISAbits.TRISA2
#define KEY_Y3_LAT                  LATAbits.LATA2
#define KEY_Y3_PORT                 PORTAbits.RA2
#define KEY_Y3_WPU                  WPUAbits.WPUA2
#define KEY_Y3_OD                   ODCONAbits.ODA2
#define KEY_Y3_ANS                  ANSELAbits.ANSA2
#define KEY_Y3_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define KEY_Y3_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define KEY_Y3_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define KEY_Y3_GetValue()           PORTAbits.RA2
#define KEY_Y3_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define KEY_Y3_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define KEY_Y3_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define KEY_Y3_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define KEY_Y3_SetPushPull()        do { ODCONAbits.ODA2 = 0; } while(0)
#define KEY_Y3_SetOpenDrain()       do { ODCONAbits.ODA2 = 1; } while(0)
#define KEY_Y3_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define KEY_Y3_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set KEY_Y2 aliases
#define KEY_Y2_PORT                 PORTAbits.RA3
#define KEY_Y2_WPU                  WPUAbits.WPUA3
#define KEY_Y2_GetValue()           PORTAbits.RA3
#define KEY_Y2_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define KEY_Y2_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)

// get/set KEY_X4 aliases
#define KEY_X4_TRIS                 TRISAbits.TRISA4
#define KEY_X4_LAT                  LATAbits.LATA4
#define KEY_X4_PORT                 PORTAbits.RA4
#define KEY_X4_WPU                  WPUAbits.WPUA4
#define KEY_X4_OD                   ODCONAbits.ODA4
#define KEY_X4_ANS                  ANSELAbits.ANSA4
#define KEY_X4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define KEY_X4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define KEY_X4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define KEY_X4_GetValue()           PORTAbits.RA4
#define KEY_X4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define KEY_X4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define KEY_X4_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define KEY_X4_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define KEY_X4_SetPushPull()        do { ODCONAbits.ODA4 = 0; } while(0)
#define KEY_X4_SetOpenDrain()       do { ODCONAbits.ODA4 = 1; } while(0)
#define KEY_X4_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define KEY_X4_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS                 TRISAbits.TRISA5
#define LED_LAT                  LATAbits.LATA5
#define LED_PORT                 PORTAbits.RA5
#define LED_WPU                  WPUAbits.WPUA5
#define LED_OD                   ODCONAbits.ODA5
#define LED_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LED_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LED_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LED_GetValue()           PORTAbits.RA5
#define LED_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LED_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LED_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONAbits.ODA5 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONAbits.ODA5 = 1; } while(0)

// get/set KEY_Y1 aliases
#define KEY_Y1_TRIS                 TRISCbits.TRISC0
#define KEY_Y1_LAT                  LATCbits.LATC0
#define KEY_Y1_PORT                 PORTCbits.RC0
#define KEY_Y1_WPU                  WPUCbits.WPUC0
#define KEY_Y1_OD                   ODCONCbits.ODC0
#define KEY_Y1_ANS                  ANSELCbits.ANSC0
#define KEY_Y1_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define KEY_Y1_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define KEY_Y1_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define KEY_Y1_GetValue()           PORTCbits.RC0
#define KEY_Y1_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define KEY_Y1_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define KEY_Y1_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define KEY_Y1_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define KEY_Y1_SetPushPull()        do { ODCONCbits.ODC0 = 0; } while(0)
#define KEY_Y1_SetOpenDrain()       do { ODCONCbits.ODC0 = 1; } while(0)
#define KEY_Y1_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define KEY_Y1_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set KEY_X1 aliases
#define KEY_X1_TRIS                 TRISCbits.TRISC1
#define KEY_X1_LAT                  LATCbits.LATC1
#define KEY_X1_PORT                 PORTCbits.RC1
#define KEY_X1_WPU                  WPUCbits.WPUC1
#define KEY_X1_OD                   ODCONCbits.ODC1
#define KEY_X1_ANS                  ANSELCbits.ANSC1
#define KEY_X1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define KEY_X1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define KEY_X1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define KEY_X1_GetValue()           PORTCbits.RC1
#define KEY_X1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define KEY_X1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define KEY_X1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define KEY_X1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define KEY_X1_SetPushPull()        do { ODCONCbits.ODC1 = 0; } while(0)
#define KEY_X1_SetOpenDrain()       do { ODCONCbits.ODC1 = 1; } while(0)
#define KEY_X1_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define KEY_X1_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set KEY_X2 aliases
#define KEY_X2_TRIS                 TRISCbits.TRISC2
#define KEY_X2_LAT                  LATCbits.LATC2
#define KEY_X2_PORT                 PORTCbits.RC2
#define KEY_X2_WPU                  WPUCbits.WPUC2
#define KEY_X2_OD                   ODCONCbits.ODC2
#define KEY_X2_ANS                  ANSELCbits.ANSC2
#define KEY_X2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define KEY_X2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define KEY_X2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define KEY_X2_GetValue()           PORTCbits.RC2
#define KEY_X2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define KEY_X2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define KEY_X2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define KEY_X2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define KEY_X2_SetPushPull()        do { ODCONCbits.ODC2 = 0; } while(0)
#define KEY_X2_SetOpenDrain()       do { ODCONCbits.ODC2 = 1; } while(0)
#define KEY_X2_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define KEY_X2_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set KEY_X3 aliases
#define KEY_X3_TRIS                 TRISCbits.TRISC3
#define KEY_X3_LAT                  LATCbits.LATC3
#define KEY_X3_PORT                 PORTCbits.RC3
#define KEY_X3_WPU                  WPUCbits.WPUC3
#define KEY_X3_OD                   ODCONCbits.ODC3
#define KEY_X3_ANS                  ANSELCbits.ANSC3
#define KEY_X3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define KEY_X3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define KEY_X3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define KEY_X3_GetValue()           PORTCbits.RC3
#define KEY_X3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define KEY_X3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define KEY_X3_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define KEY_X3_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define KEY_X3_SetPushPull()        do { ODCONCbits.ODC3 = 0; } while(0)
#define KEY_X3_SetOpenDrain()       do { ODCONCbits.ODC3 = 1; } while(0)
#define KEY_X3_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define KEY_X3_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSC5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/