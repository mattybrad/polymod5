#include <stdio.h>
#include "pico/stdlib.h"
#include "Audio.h"
#include "Patchbay.h"

#include "modules/VCO.h"
#include "modules/IO.h"

Audio audio;
Patchbay patchbay;

// Synth modules
VCO vco;
IO io;

int main()
{
    stdio_init_all();
    audio.init();

    printf("Hello, Polymod!\n");

    // Map physical patchbay connections to module inputs/outputs
    patchbay.setSocket(0, vco.getSocket(VCO::FREQ_IN));
    patchbay.setSocket(1, vco.getSocket(VCO::SQUARE_OUT));
    patchbay.setSocket(2, vco.getSocket(VCO::SAW_OUT));
    patchbay.setSocket(3, io.getSocket(IO::MAIN_AUDIO_IN));

    int dacIntervalUs = audio.dacIntervalUs();
    int16_t testSample = 0;
    while (true) {
        while(audio.samplesRequired()) {
            testSample += 25;
            if (testSample > 8192) {
                testSample = -8192;
            }
            audio.queueSample(testSample, testSample);
        }
        audio.update();
    }
}
