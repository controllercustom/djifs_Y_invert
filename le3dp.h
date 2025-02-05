/*
MIT License

Copyright (c) 2025 controllercustom@myyahoo.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
// Logitech Extreme 3D Pro flight joystick *****************************
// Flight sim joystick HID report layout
// Large joystick X, Y, Z (twist) axes
// 8 way hat switch
// 12 buttons (6 on the stick, 6 on the base)
// throttle slider
typedef struct __attribute__ ((packed)) {
  uint32_t x : 10;      // 0..512..1023
  uint32_t y : 10;      // 0..512..1023
  uint32_t hat : 4;
  uint32_t twist : 8;   // 0..127..255
  uint8_t front_trigger : 1;
  uint8_t side_trigger : 1;
  uint8_t button_3 : 1;
  uint8_t button_4 : 1;
  uint8_t button_5 : 1;
  uint8_t button_6 : 1;
  uint8_t button_7 : 1;
  uint8_t button_8 : 1;
  uint8_t slider;       // 0..255
  uint8_t button_9 : 1;
  uint8_t button_10 : 1;
  uint8_t button_11 : 1;
  uint8_t button_12 : 1;
  uint8_t filler   : 4;
} LE3DP_Report_t;

typedef struct {
  LE3DP_Report_t report;
  const uint16_t USB_VID = 0x046d;
  const uint16_t USB_PID = 0xc215;
  uint8_t dev_addr;
  uint8_t instance;
  uint8_t report_len;
  bool connected = false;
  bool available = false;
  bool debug = false;
} LE3DP_state_t;

void print_LE3DP_controls(volatile LE3DP_state_t *LE3DP) {
  DBG_printf("X:%d,Y:%d,Z:%d,dpad:%d,", LE3DP->report.x, LE3DP->report.y,
      LE3DP->report.twist, LE3DP->report.hat);
  DBG_printf("slider:%d,", LE3DP->report.slider);
  if (LE3DP->report.front_trigger) DBG_print("Front trigger,");
  if (LE3DP->report.side_trigger) DBG_print("Side Trigger,");
  if (LE3DP->report.button_3) DBG_print("Button 3,");
  if (LE3DP->report.button_4) DBG_print("Button 4,");
  if (LE3DP->report.button_5) DBG_print("Button 5,");
  if (LE3DP->report.button_6) DBG_print("Button 6,");
  if (LE3DP->report.button_7) DBG_print("Button 7,");
  if (LE3DP->report.button_8) DBG_print("Button 8,");
  if (LE3DP->report.button_9) DBG_print("Button 9,");
  if (LE3DP->report.button_10) DBG_print("Button 10,");
  if (LE3DP->report.button_11) DBG_print("Button 11,");
  if (LE3DP->report.button_12) DBG_print("Button 12");
  DBG_println();
}
