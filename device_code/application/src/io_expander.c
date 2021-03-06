/*
 * io_expander.c
 *
 *  Created on: Nov 12, 2017
 *      Author: jaxc
 */

#include "stm32f4xx_hal.h"
#include "i2c.h"

const uint16_t device_addr = 0b01000000;

I2C_HandleTypeDef *i2c_handle;

void init_io_expander(void){
    return;
    i2c_handle = get_i2c_handle();
    uint8_t config_data = 0xFF;
    HAL_StatusTypeDef HAL_error;
    if ((HAL_error = HAL_I2C_Mem_Write(i2c_handle,device_addr, 0x00, 0x1, &config_data, 1, 1000)) != HAL_OK){
        _Error_Handler(__FILE__, __LINE__);
    }
    config_data = 0xFF;
    if ((HAL_error = HAL_I2C_Mem_Write(i2c_handle,device_addr, 0x02, 0x1, &config_data, 1, 1000)) != HAL_OK){
        _Error_Handler(__FILE__, __LINE__);
    }
    config_data = 0xFF;
    if ((HAL_error = HAL_I2C_Mem_Write(i2c_handle,device_addr, 0x06, 0x1, &config_data, 1, 1000)) != HAL_OK){
        _Error_Handler(__FILE__, __LINE__);
    }
    config_data = 0xFF;
    if ((HAL_error = HAL_I2C_Mem_Write(i2c_handle,device_addr, 0x00, 0x1, &config_data, 1, 1000)) != HAL_OK){
        _Error_Handler(__FILE__, __LINE__);
    }
}

uint32_t read_io_pins(void){
    return 0;
    uint32_t pinvalues;
    uint8_t io_read;
    HAL_StatusTypeDef HAL_error;
    if ((HAL_error =  HAL_I2C_Mem_Read(i2c_handle,device_addr, 0x09, 0x1, &io_read, 1,1000)) == HAL_ERROR){
        _Error_Handler(__FILE__, __LINE__);
    }

    pinvalues = (uint32_t) io_read;
    return pinvalues;
}


