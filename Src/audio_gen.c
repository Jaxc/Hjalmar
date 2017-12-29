/*
 * audio_gen.c
 *
 *  Created on: Nov 26, 2017
 *      Author: jaxc
 */

#include <stdint.h>
#include <stdlib.h>

#include "audio_gen.h"
#include "audio_interface.h"
#include "i2s.h"
#include "math.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

uint32_t sample_per_sec;
audio_wave_type_t wave_type = WAVE_NONE;
uint32_t wave_period;
uint32_t sample_position;
int16_t last_value;
int16_t SQ_MAX = 0;

int pulse_pos = 2;

void audio_gen_sqr_start(float freq, uint8_t level)
{
    I2S_HandleTypeDef *i2s_handle = get_i2s_handle();
    sample_per_sec = i2s_handle->Init.AudioFreq;
    wave_type = WAVE_SQUARE;
    wave_period = 44; //sample_per_sec / freq;
    sample_position = 0;
    last_value = (INT16_MIN / (128 - level))+1;

}

void fetch_next_audio_buffer(uint16_t *audio_samples, uint16_t n_sample)
{
    switch (wave_type){
    case WAVE_SQUARE:
        for(int i = 0; i < n_sample; i++){
            if (sample_position >= (wave_period / 2)){
                audio_samples[i] = 0x7F00;
                if (sample_position >= wave_period) {
                    sample_position = 0;
                }
                else {
                    sample_position++;
                }
            }
            else{
                sample_position++;
                audio_samples[i] = 0x8000;
            }

        }
        break;
    case WAVE_SAW:
        for(int i = 0; i < n_sample; i++) {
            if (sample_position >= 0xFFFF){
                sample_position = 0;
            }
            else{
                sample_position++;
            }
            audio_samples[i] = (int16_t)sample_position;
        }
        break;

    case WAVE_PULSE:
        for(int i = 0; i < n_sample; i++) {
            if(i % 2 == 0) {
                continue;
            }
            if (sample_position >= wave_period) {
                sample_position = 0;
            }
            else {
                sample_position++;
            }

            if (i == pulse_pos) {
                audio_samples[i] = 0xF;
            }
            else {
                audio_samples[i] = 0;
            }
        }
        break;

    case WAVE_SINE:
        for(int i = 0; i < n_sample; i++) {
            if (sample_position >= wave_period){
                sample_position = 0;
            }
            else{
                sample_position++;
            }

            audio_samples[i] = (int16_t) 0xFF * sin(2 * M_PI * sample_position / wave_period);
        }
        break;

    default:
        break;
    }

    return;
}
