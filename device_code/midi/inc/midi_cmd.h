/*
 * midi_cmd.h
 *
 *  Created on: Nov 5, 2017
 *      Author: jaxc
 */

#ifndef INC_MIDI_CMD_H_
#define INC_MIDI_CMD_H_

#include "error_codes.h"
#include "stm32f4xx_hal.h"

HAL_StatusTypeDef transmit_midi_message(uint8_t *message, uint16_t size);
HAL_StatusTypeDef start_midi_receive(void);
HAL_StatusTypeDef receive_first_midi_byte(void);
uint8_t get_midi_tx_state (void);
void set_midi_tx_state (uint8_t state);
uint8_t get_midi_rx_state (void);
void set_midi_rx_state (uint8_t state);
void handle_midi_int(void);
void handle_midi(void *midi_rx_byte);

#endif /* INC_MIDI_CMD_H_ */
