#include "mbed.h"
#include "grove_tsl.h"

Serial pc(USBTX, USBRX);
I2C i2c(I2C_SDA, I2C_SCL);

GroveTSL2561 tsl(i2c);

int main() {
    pc.baud(115200);

    tsl.init();

    while (true) {
        wait(2);

        pc.printf("Visible lux: %lu\r\n", tsl.readVisibleLux());
    }
}
