import pyfirmata
import time

board = pyfirmata.Arduino('/dev/tty.usbmodem14201')

MX_LINE = 10
MX_COL = 10

LED_COUNT = MX_COL * MX_LINE

