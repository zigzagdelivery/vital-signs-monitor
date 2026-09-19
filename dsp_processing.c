#include "dsp_processing.h"

static uint32_t last_beat_time = 0;
static uint32_t last_rr_interval = 0;

void DSP_Init(void) {
    last_beat_time = 0;
    last_rr_interval = 0;
}

uint16_t DSP_FilterSignal(uint16_t raw_adc_value) {
    static uint16_t buffer[4] = {0};
    static uint8_t index = 0;
    
    buffer[index] = raw_adc_value;
    index = (index + 1) % 4;
    
    uint32_t sum = 0;
    for(uint8_t i = 0; i < 4; i++) {
        sum += buffer[i];
    }
    return (uint16_t)(sum / 4);
}

HeartStatus_t DSP_DetectArrhythmia(uint16_t filtered_value, uint32_t current_time_ms) {
    static bool peak_detected = false;
    HeartStatus_t status = HEART_STATUS_NORMAL;

    if (filtered_value > SIGNAL_THRESHOLD && !peak_detected) {
        peak_detected = true;
        
        if (last_beat_time > 0) {
            uint32_t rr_interval = current_time_ms - last_beat_time;
            
            if (last_rr_interval > 0) {
                int32_t diff = (int32_t)rr_interval - (int32_t)last_rr_interval;
                if (diff > 200 || diff < -200) { 
                    status = HEART_STATUS_ARRHYTHMIA;
                }
            }
            last_rr_interval = rr_interval;
        }
        last_beat_time = current_time_ms;
    } 
    else if (filtered_value < (SIGNAL_THRESHOLD - 200)) {
        peak_detected = false;
    }

    return status;
}