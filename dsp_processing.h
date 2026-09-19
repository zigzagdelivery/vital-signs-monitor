#ifndef DSP_PROCESSING_H
#define DSP_PROCESSING_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNAL_THRESHOLD 2000

typedef enum {
    HEART_STATUS_NORMAL,
    HEART_STATUS_ARRHYTHMIA
} HeartStatus_t;

void DSP_Init(void);
uint16_t DSP_FilterSignal(uint16_t raw_adc_value);
HeartStatus_t DSP_DetectArrhythmia(uint16_t filtered_value, uint32_t current_time_ms);

#endif