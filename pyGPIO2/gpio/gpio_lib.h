/*
 * 
 * This file is part of pyGPIO2.
 * gpio_lib.h is python GPIO extension.
 * 
 * Copyright (c) 2014 Stefan Mavrodiev @ OLIMEX LTD, <support@olimex.com> 
 * 
 * pyGPIO2 is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 

 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 * by chow add: author :duxingkei chow email :277563381@qq.com https://github.com/duxingkei33/orangepi_PC_gpio_pyH3
 *
 */

#ifndef _GPIO_LIB_H_
#define _GPIO_LIB_H_

#define SW_PORTC_IO_BASE 0x01c20800


#define SUNXI_GPIO_A	0
#define SUNXI_GPIO_B	1
#define SUNXI_GPIO_C	2
#define SUNXI_GPIO_D	3
#define SUNXI_GPIO_E	4
#define SUNXI_GPIO_F	5
#define SUNXI_GPIO_G	6
//by chow  add 
#define SUNXI_GPIO_H	7
#define SUNXI_GPIO_I		8
#define SUNXI_GPIO_J	9
#define SUNXI_GPIO_K	10
#define SUNXI_GPIO_L	11
#define SUNXI_GPIO_M	12
#define SUNXI_GPIO_N	13
#define SUNXI_GPIO_O	14


struct sunxi_gpio {
    unsigned int cfg[4];
    unsigned int dat;
    unsigned int drv[2];
    unsigned int pull[2];
};

/* gpio interrupt control */
struct sunxi_gpio_int {
    unsigned int cfg[3];
    unsigned int ctl;
    unsigned int sta;
    unsigned int deb;
};

struct sunxi_gpio_reg {
    struct sunxi_gpio gpio_bank[9];
    unsigned char res[0xbc];
    struct sunxi_gpio_int gpio_int;
};

#define GPIO_BANK(pin)	((pin) >> 5)
#define GPIO_NUM(pin)	((pin) & 0x1F)

#define GPIO_CFG_INDEX(pin)	(((pin) & 0x1F) >> 3)
#define GPIO_CFG_OFFSET(pin)	((((pin) & 0x1F) & 0x7) << 2)

#define GPIO_PUL_INDEX(pin)	(((pin) & 0x1F )>> 4) 
#define GPIO_PUL_OFFSET(pin)	(((pin) & 0x0F) << 1)

/* GPIO bank sizes */
#define SUNXI_GPIO_A_NR		(32)
#define SUNXI_GPIO_B_NR		(32)
#define SUNXI_GPIO_C_NR		(32)
#define SUNXI_GPIO_D_NR		(32)
#define SUNXI_GPIO_E_NR		(32)
#define SUNXI_GPIO_F_NR		(32)
#define SUNXI_GPIO_G_NR		(32)
//BY CHOW add
#define SUNXI_GPIO_H_NR		(32)
#define SUNXI_GPIO_I_NR		(32)
#define SUNXI_GPIO_J_NR		(32)
#define SUNXI_GPIO_K_NR		(32)
#define SUNXI_GPIO_L_NR		(32)
#define SUNXI_GPIO_M_NR		(32)
#define SUNXI_GPIO_N_NR		(32)
#define SUNXI_GPIO_O_NR		(32)
//


#define SUNXI_GPIO_NEXT(__gpio) ((__gpio##_START)+(__gpio##_NR)+0)

enum sunxi_gpio_number {
    SUNXI_GPIO_A_START = 0,
    SUNXI_GPIO_B_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_A), //32
    SUNXI_GPIO_C_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_B), //64
    SUNXI_GPIO_D_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_C), //96
    SUNXI_GPIO_E_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_D), //128
    SUNXI_GPIO_F_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_E), //160
    SUNXI_GPIO_G_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_F), //192
// BY CHOW  ADD
    SUNXI_GPIO_H_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_G), //224	
    SUNXI_GPIO_I_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_H), //256
   SUNXI_GPIO_J_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_I), //288	
    SUNXI_GPIO_K_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_J), //320
    SUNXI_GPIO_L_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_K), //352
    SUNXI_GPIO_M_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_L), //384
    SUNXI_GPIO_N_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_M), //448
    SUNXI_GPIO_O_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_N), //448+32


};

/* SUNXI GPIO number definitions */
#define SUNXI_GPA(_nr) (SUNXI_GPIO_A_START + (_nr))
#define SUNXI_GPB(_nr) (SUNXI_GPIO_B_START + (_nr))
#define SUNXI_GPC(_nr) (SUNXI_GPIO_C_START + (_nr))
#define SUNXI_GPD(_nr) (SUNXI_GPIO_D_START + (_nr))
#define SUNXI_GPE(_nr) (SUNXI_GPIO_E_START + (_nr))
#define SUNXI_GPF(_nr) (SUNXI_GPIO_F_START + (_nr))
#define SUNXI_GPG(_nr) (SUNXI_GPIO_G_START + (_nr))
#define SUNXI_GPH(_nr) (SUNXI_GPIO_H_START + (_nr))
#define SUNXI_GPI(_nr) (SUNXI_GPIO_I_START + (_nr))
//add by chow
#define SUNXI_GPJ(_nr) (SUNXI_GPIO_J_START + (_nr))
#define SUNXI_GPK(_nr) (SUNXI_GPIO_K_START + (_nr))
#define SUNXI_GPL(_nr) (SUNXI_GPIO_L_START + (_nr))
#define SUNXI_GPM(_nr) (SUNXI_GPIO_M_START + (_nr))
#define SUNXI_GPN(_nr) (SUNXI_GPIO_N_START + (_nr))
#define SUNXI_GPO(_nr) (SUNXI_GPIO_O_START + (_nr))



/* GPIO pin function config */
#define SUNXI_GPIO_INPUT (0)
#define SUNXI_GPIO_OUTPUT (1)
#define SUNXI_GPIO_PER (2)

#define SUNXI_PULL_NONE (0)
#define SUNXI_PULL_UP (1)
#define SUNXI_PULL_DOWN (2)

extern int sunxi_gpio_input(unsigned int pin);
extern int sunxi_gpio_init(void);
extern int sunxi_gpio_set_cfgpin(unsigned int pin, unsigned int val);
extern int sunxi_gpio_get_cfgpin(unsigned int pin);
extern int sunxi_gpio_output(unsigned int pin, unsigned int val);
extern int sunxi_gpio_pullup(unsigned int pin, unsigned int pull);


extern unsigned int SUNXI_PIO_BASE;
#endif // _GPIO_LIB_H_ 
