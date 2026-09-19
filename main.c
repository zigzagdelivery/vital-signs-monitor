#include <stdio.h>
#include "dsp_processing.h"

int main(void) {
    DSP_Init();
    uint32_t time_ms = 0;

    uint16_t simulated_adc_samples[5] = {1000, 1500, 2200, 1800, 1000};

    for (int i = 0; i < 5; i++) {
        uint16_t raw = simulated_adc_samples[i];
        uint16_t filtered = DSP_FilterSignal(raw);
        HeartStatus_t result = DSP_DetectArrhythmia(filtered, time_ms);

        time_ms += 100;
    }

    return 0;
}