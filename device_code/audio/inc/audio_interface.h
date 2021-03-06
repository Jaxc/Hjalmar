/*
 * audio_interface.h
 *
 *  Created on: Nov 26, 2017
 *      Author: jaxc
 */

#ifndef INC_AUDIO_INTERFACE_H_
#define INC_AUDIO_INTERFACE_H_

#define DAC_MAX_VALUE 0x7FFF
#define DAC_MIN_VALUE 0x8000

void init_audio_output(void);
//void add_to_audio_buffer(int16_t *audio_buffer, uint32_t buf_len);
void mono_to_stereo (uint16_t *stereo_samples, float *mono_samples, uint16_t n_sample_mono);
void send_audio(void);


#endif /* INC_AUDIO_INTERFACE_H_ */
