/*
 * app_uart.h
 *
 *  Created on: Sep 9, 2022
 *      Author: TECH66
 */

#ifndef __APP_UART_H
#define __APP_UART_H

#include "debug.h"
#include "lwrb.h"
#include "fifo.h"

typedef struct
{
	uint8_t status;		/* send state */
	lwrb_t* tx_fifo;	/* sennd fifo */
	lwrb_t* rx_fifo;	/* recv fifo */
	uint8_t *dmarx_buf;	/* dma recv buffer */
	uint16_t dmarx_buf_size;/* dma recv buffer size*/
    uint8_t *dmatx_buf;	/* dma send buffer */
	uint16_t dmatx_buf_size;/* dma send buffer size */
	uint16_t last_dmarx_size;/* dma recv data size,last  */
}uart_device_t;

#define com_cfg                                      0
#define COMNUM										(1)


#define DEFAULT_BAUDRATE_3 921600


#define UART_TX_BUF_SIZE           (8*1024)
#define UART_RX_BUF_SIZE           (8*1024)
#define	UART_DMA_RX_BUF_SIZE		2048
#define	UART_DMA_TX_BUF_SIZE		2048


#define UART3_CFG_EN	1


#define DEV_UART3	0



void uart3_init(uint32_t baudrate);
void uart3_dmatx_config(uint8_t *mem_addr, uint32_t mem_size);
void uart3_dmarx_config(uint8_t *mem_addr, uint32_t mem_size);
void USART3_DMASendCmd(uint8_t* pbuf,uint16_t buflen);

void uart_dmarx_done_isr (uint8_t uart_id);
void uart_dmarx_half_done_isr (uint8_t uart_id);
void uart_dmarx_idle_isr (uint8_t uart_id);
void uart_dmatx_done_isr(uint8_t uart_id);
void uart_poll_dma_tx(uint8_t uart_id);


// void ComTransDataTEST (uint8_t pdev, uint8_t uart_id);
#endif /* __APP_UART_H */