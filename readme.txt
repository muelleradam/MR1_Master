This code is for the master of the MR1.

Currently a ESP32 is used as the master. Only requirements are that the master needs to be faster than the
BLE-Nodes, so the serialFlush function does not loop continuously. There also must be two serial ports available.

The data of two BLE-Nodes is getting read and echoed to the uart of the master so it can be displayed on a pc.
Two rgb-led-strips with 3 leds each roughly display the rssi.

In further development a motor shall be controlled according to the rssi.