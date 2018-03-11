// Target Options -> Debug -> ST-Link Debugger Settings -> Flash Download tab
// Right click in projct tree on Target 1
// Options for Target 'Target 1'...
// Tab Debug
// Use: ST-Link Debugger
// Setting
// ST-Link/V2
// Flash Download
// Erase Sectors
// Program
// Verify
// Reset and Run


// Port F, LEDs on R 3, G 2, B 1
// 0x400F.E000, 0x608, RCGC (Gate clock register), bit 5
// 0x4002.5000, 0x400, DIR Port Direction
// 0x4002.5000, 0x51C, DEN Digital enable
// 0x4002.5000, 0x3FC, DATA

// Discovery F4 STM32F407VG
// LED Orange LD3 PD13 1=on
// LED Green  LD4 PD12 1=on
// LED Red    LD5 PD14 1=on
// LED Blue   LD6 PD15 1=on
// User Button    PA0  1=pressed
// Reference Manual
// GPIO, Page 268
// Page 281
// GPIOx_MODER   0x00 configuration register (I/O direction) [1:0] 00: Input (reset state), 01: General purpose output mode
// GPIOx_OTYPER  0x04 configuration register = 0: Output push-pull (reset state), 1: Output open-drain
// GPIOx_OSPEEDR 0x08 configuration register [B:A] = 00: Low speed, 01: Medium speed, 10: High speed, 11: Very high speed
// GPIOx_PUPDR   0x0C configuration register (pull-up/pull-down) [1:0] 00: No pull-up, pull-down, 01: Pull-up, 10: Pull-down, 11: Reserved
// GPIOx_AFRL    0x20 alternate function selection register
// GPIOx_AFRH    0x24 alternate function selection register
// GPIOx_LCKR    0x1C locking mechanism register (freeze the above GPIO control registers)
// GPIOx_IDR     0x10 input data register (read-only)
// GPIOx_ODR     0x14 output data register (read/write)
// GPIOx_BSRR    0x18 bit set/reset register (atomic bitwise read/modify accesses), BSRR(i) set, BSRR(i+SIZE) reset
// GPIOD 0x40020C00 - 0x40020FFF
// GPIOD_SPEEDR GPIO port output speed register

#define GPIOD_MODER 	0x40020C00U
#define GPIOD_OTYPER 	0x40020C04U
#define GPIOD_OSPEEDR 0x40020C08U
#define GPIOD_PUPDR 	0x40020C0CU
#define GPIOD_AFRL 		0x40020C20U
#define GPIOD_AFRH 		0x40020C24U
#define GPIOD_LCKR 		0x40020C1CU
#define GPIOD_IDR 		0x40020C10U
#define GPIOD_ODR 		0x40020C14U
#define GPIOD_BSRR  	0x40020C18U

#define TM_GPIO_Mode_IN 0x00
#define TM_GPIO_Mode_OUT 0x01
#define TM_GPIO_Mode_AF 0x02
#define TM_GPIO_Mode_AN 0x03
#define TM_GPIO_OType_PP 0x00
#define TM_GPIO_OType_OD 0x01
#define TM_GPIO_Speed_Low 0x00
#define TM_GPIO_Speed_Medium 0x01
#define TM_GPIO_Speed_Fast 0x02
#define TM_GPIO_Speed_High 0x03
#define TM_GPIO_PuPd_NOPULL 0x00
#define TM_GPIO_PuPd_UP 0x01
#define TM_GPIO_PuPd_DOWN 0x03

#define LED_R 0x02U
#define LED_G 0x04U
#define LED_B 0x08U

int main()
{
	unsigned int *pt;

	// GPIOD_MODER
	pt = (unsigned int *) GPIOD_MODER;	// GPIOx_MODER
	*pt |= 0x55000000U;	// Set bit 01010101 00000000 00000000 00000000

	pt = (unsigned int *) GPIOD_OTYPER;	// GPIOx_OTYPER
	*pt &= 0x00U;	 // Clear bits, make PP

	pt = (unsigned int *) GPIOD_OSPEEDR;	// GPIOx_OSPEEDR
	*pt &= 0x00U;	 // Clear bits, make Low speed

	pt = (unsigned int *) GPIOD_PUPDR;	// GPIOx_PUPDR
	*pt &= 0x00U;	 // Clear bits, make No pull-up

	pt = (unsigned int *) GPIOD_ODR;	// GPIOx_ODR
	*pt |= 0xF0000000U;	 // Set bits, lit LEDs
	
//	pt = (unsigned int *) GPIOD_BSRR;	// GPIOx_ODR
//	*pt |= 0xF0000000U;	 // Set bits, lit LEDs
	
	
/*	
	// RCGC: set bit 5, wake up port F
	pt = (unsigned int *) 0x400FE608U;	// usigned U
	*pt |= 0x20U;	// Set bit 5 0b 00000000 00000000 00000000 00100000
	
	// DIR: set bits 1,2,3, set as outputs
	pt = (unsigned int *) 0x40025400U;	// usigned U
	*pt |= 0x0EU;	// Set bit 5 0b 00000000 00000000 00000000 00001110
	
	// DEN: set bit 5, wake up port F
	pt = (unsigned int *) 0x4002551CU;	// usigned U
	*pt |= 0x0EU;	// Set bit 5 0b 00000000 00000000 00000000 00001110
	
	// DATA: set bit 5, wake up port F
	pt = (unsigned int *) 0x400253FCU;	// usigned U
	*pt |= LED_R;	// Set bit 5 0b 00000000 00000000 00000000 00000000
*/	
	while (1) {
		
	}
}
