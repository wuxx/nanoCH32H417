/*
 * app_config.h
 *
 *  Created on: Apr 28, 2025
 *      Author: TECH66
 */

#ifndef __APP_CONFIG_H
#define __APP_CONFIG_H

#include "debug.h"
#include "lwrb.h"
#include "app_uart.h"

void uart_Init(void);

void ComToIoCHubTransData(uint8_t pdev,uint8_t com);
void IoCHubToComTransData(uint8_t pdev, uint8_t com);

#endif //__APP_CONFIG_H