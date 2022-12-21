/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1705
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#define MAX_ROW 	5 + 1
#define MAX_COLUM 	4 + 1

volatile uint8_t last_code = 0;
volatile uint8_t key_code = 0;

const uint8_t key[MAX_COLUM][MAX_ROW] = {
	//   Y1   Y2   Y3   Y4   Y5
	{0,   0,   0,   0,   0,   0},		
	{0, '0', '1', '4', '7', 'F'},		// X1
	{0, '0', '2', '5', '8', '/'},		// X2
	{0, 'Z', '3', '6', '9', '*'},		// X3
	{0, '.', 'E', 'B', '+', '-'},		// X4
};

#define BUF_SIZE	10
char work_buf[BUF_SIZE];
char cmd_buf[BUF_SIZE];
uint8_t lock_mode = 0;
uint8_t fast_mode = 0;

uint8_t work_cur_pos = 0;
uint8_t cmd_cur_pos = 0;
//======================================================
//	buf control functions 
//======================================================
void clear_buf()
{
	int	i;
	work_cur_pos = 0;
	cmd_cur_pos  = 0;

	for (i = 0; i < BUF_SIZE; i++) {
		work_buf[i] = '0';
		cmd_buf[i]  = '0';
	}
	cmd_buf[BUF_SIZE - 1] = '\0';
	work_cur_pos = 0;
	cmd_cur_pos  = 0;
}

void add_work_buf(char key)
{
	if (work_cur_pos != BUF_SIZE) {
		work_buf[work_cur_pos++] = key;
	}
}

void add_cmd_buf(char key)
{
	if (cmd_cur_pos != BUF_SIZE - 1) {
		cmd_buf[cmd_cur_pos++] = key;
	}
}

void bs_work_buf(void)
{
	if (work_cur_pos > 0) {
		work_buf[--work_cur_pos] = '0';
	}
}

void parse_work_buf()
{
	int i, j;
	for (i = 0; i < BUF_SIZE; i++) {
		if (work_buf[i] == '.') {
			for (j = i - 3; j < i; j++) {
				if (j < 0) {
					add_cmd_buf('0');
				} else {
					add_cmd_buf(work_buf[j]);
				}
			}
			break;
		}
	}
	if (i >= BUF_SIZE) {			// '.' not found then copy all
		for (j = 0; j < BUF_SIZE; j++) {
			add_cmd_buf(work_buf[j]);
		}
	} else {						// copy after '.'
		for (j = i + 1; j < BUF_SIZE; j++) {
			if (work_buf[j] != '.') {
				add_cmd_buf(work_buf[j]);
			}
		}
	}	
}

//======================================================
//	scan_row() : scan keyboard
//======================================================
static uint8_t scan_row(int8_t col)
{
	uint8_t row = 0;

	if 		(col == 1) KEY_X1_SetLow();
	else if (col == 2) KEY_X2_SetLow();
	else if (col == 3) KEY_X3_SetLow();
	else if (col == 4) KEY_X4_SetLow();

	if (KEY_Y1_GetValue() == 0) {
		row = 1;
	} else if (KEY_Y2_GetValue() == 0) {
		row = 2;
	} else if (KEY_Y3_GetValue() == 0) {
		row = 3;
	} else if (KEY_Y4_GetValue() == 0) {
		row = 4;
	} else if (KEY_Y5_GetValue() == 0) {
		row = 5;
	}
	if 		(col == 1) KEY_X1_SetHigh();
	else if (col == 2) KEY_X2_SetHigh();
	else if (col == 3) KEY_X3_SetHigh();
	else if (col == 4) KEY_X4_SetHigh();
	return key[col][row];
}

//======================================================
//	timer_int_callback() : about 8ms timer
//======================================================
void timer_int_callback(void)
{
	uint8_t code = 0;
	static uint8_t repeat = 0;
	int8_t i;

	for (i = 1; i <= 4; i++) {
		code = scan_row(i);
		if (code != 0) break;
	}
	if (code != 0) {
		if (code == last_code) {
			repeat++;
			if (repeat == 1) {
				key_code = code;
			}
		} else {
			repeat = 0;
			last_code = code;
		}
	} else {
        repeat = 0;
        last_code = 0;
    }

    return;
}

//======================================================
//	send_cmd() : send string to uart
//======================================================
void send_cmd(char *cmd)
{
	char *p = cmd;
	LED_SetHigh();
	while(*p){
	    EUSART_Write(*p);
		p++;
	}
	LED_SetLow();
	return;
}

void send_freq()
{
	if (work_cur_pos != 0) {
		parse_work_buf();
		send_cmd("FA");
		send_cmd(cmd_buf);
	    send_cmd(";");
	}

	return;
}
//======================================================
//	decode_key() : decode key function
//======================================================
uint8_t decode_key(char key)
{
    char buf[2];
	switch(key) {
		case 'F' :					// Lock main dial
			if (lock_mode == 0) {
				lock_mode = 1;
				send_cmd("LK1;");	// Lock dial
			} else {
				lock_mode = 0;
				send_cmd("LK0;");	// unLock
			}
			clear_buf();			// clear cmd buffer
			break;
		case '/' :					// change V/M
			send_cmd("VM;");
			clear_buf();			// clear cmd buffer
			break;
		case '*' :
			if (fast_mode == 0) {
				fast_mode = 1;
				send_cmd("FS1;");
			} else {
				fast_mode = 0;
				send_cmd("FS0;");
			}
			clear_buf();			// clear cmd buffer
			break;
		case '+' :
			send_cmd("UP;");
			clear_buf();			// clear cmd buffer
			break;
		case '-' :
			send_cmd("DN;");
			clear_buf();			// clear cmd buffer
			break;
		case 'B' :
			bs_work_buf();
			break;
		case 'E' :
			send_freq();
			clear_buf();			// clear cmd buffer
			break;
        case 'Z' :
            add_work_buf('0');
            add_work_buf('0');
            add_work_buf('0');
            break;
		default :
			add_work_buf(key);
			break;
	}
	return 0;
}

//======================================================
//	setup() : setup app
//======================================================
void setup()
{
    TMR0_SetInterruptHandler(timer_int_callback);
	KEY_X1_SetHigh();
	KEY_X2_SetHigh();
	KEY_X3_SetHigh();
	KEY_X4_SetHigh();
    LED_SetLow();
	clear_buf();			// clear cmd buffer

	return;
}

//======================================================
//	main() : Main application
//======================================================
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    setup();
    while (1)
    {
        // Add your application code
		if (key_code != 0) {
			decode_key(key_code);
			//DELAY_milliseconds(100);
			key_code = 0;
		}
    }
}
/**
 End of File
*/