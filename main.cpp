/* SDT-example-sensor-neo6m
 * 
 * Copyright (c) 2018 Sigma Delta Technologies Inc.
 * 
 * MIT License
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#include "mbed.h"

/* Serial */
#define BAUDRATE 9600
Serial serial_pc(USBTX, USBRX, BAUDRATE);

/* DigitalOut */
#define LED_ON      0
#define LED_OFF     1
DigitalOut do_ledRed(LED_RED, LED_OFF);
DigitalOut do_ledGreen(LED_GREEN, LED_OFF);
DigitalOut do_ledBlue(LED_BLUE, LED_OFF);

/* Sensor */
#define BAUDRATE_NEO6M 9600
Serial serial_neo6m(UART0_TX, UART0_RX, BAUDRATE_NEO6M);

unsigned char dataBuf[255] = {'\0',};

int main(void) {
    serial_pc.printf("< Sigma Delta Technologies Inc. >\n\r");

    while(true) {
        // serial_pc.printf("LED Toggle\n");
        do_ledBlue = !do_ledBlue;
        wait(1);                // 1sec

        serial_neo6m.read(dataBuf, sizeof(dataBuf), NULL);
        serial_pc.printf("dataBuf = %s\n", dataBuf);
        serial_pc.printf("-------------------------------------------\n");
    }

    return 0;
}
