#
# PCF8591 Analog GPIO Port Expand
#
# AUTHOR:  Renzo Mischianti
# Website: www.mischianti.org
# VERSION: 0.0.3
#
#
# Porting of PCF8591 library for Arduino
# https://www.mischianti.org/2019/01/03/pcf8591-i2c-analog-i-o-expander/
#
#            +---------------+
#  AIN0 (1)  | * 1    U   16 |  VDD
#  AIN1 (2)  | * 2        15 |  AOUT
#  AIN2 (3)  | * 3        14 |  VREF
#  AIN3 (4)  | * 4        13 |  AGND
#    A0 (5)  | * 5        12 |  EXT
#    A1 (6)  | * 6        11 |  OSC
#    A2 (7)  | * 7        10 |  SCL
#   VSS (8)  | * 8         9 |  SDA
#            +---------------+
#
# AIN0: Analog input channel 0
# AIN1: Analog input channel 1
# AIN2: Analog input channel 2
# AIN3: Analog input channel 3
# A0: Address input 0
# A1: Address input 1
# A2: Address input 2
# VSS: Ground
# SDA: Serial data line (I2C)
# SCL: Serial clock line (I2C)
# OSC: Oscillator output
# EXT: External trigger input
# AGND: Analog ground
# VREF: Voltage reference input
# AOUT: Analog output
# VDD: Power supply
#
# 7 6 5 4 3 2 1 0
# 0 X X X 0 X X X
#   | | |   | | |
#   A B B   C D D
#
# 0 1 0 0 0 1 0 0
#
# A 0 D/A inactive
#   1 D/A active
#
# B 00 single ended inputs
#   01 differential inputs
#   10 single ended and differential
#   11 two differential inputs
#
# C 0 no auto inc
#   1 auto inc
#
# D 00 select channel 0
#   01 select channel 1
#   10 select channel 2
#   11 select channel 3
#
# The MIT License (MIT)
#
# Copyright (c) 2017 Renzo Mischianti www.mischianti.org All right reserved.
#
# You may copy, alter and reuse this code in any way you like, but please leave
# reference to www.mischianti.org in your comments if you redistribute this code.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#


import utime
from machine import I2C, Pin

AIN0 = CHANNEL0 = 0b00000000
AIN1 = CHANNEL1 = 0b00000001
AIN2 = CHANNEL2 = 0b00000010
AIN3 = CHANNEL3 = 0b00000011


class PCF8591:
    AIN0 = CHANNEL0 = 0b00000000
    AIN1 = CHANNEL1 = 0b00000001
    AIN2 = CHANNEL2 = 0b00000010
    AIN3 = CHANNEL3 = 0b00000011

    AUTOINCREMENT_READ = 0b00000100

    SINGLE_ENDED_INPUT = 0b00000000
    TREE_DIFFERENTIAL_INPUT = 0b00010000
    TWO_SINGLE_ONE_DIFFERENTIAL_INPUT = 0b00100000
    TWO_DIFFERENTIAL_INPUT = 0b00110000

    ENABLE_OUTPUT = 0b01000000
    DISABLE_OUTPUT = 0b00000000

    OUTPUT_MASK = 0b01000000

    def __init__(self, address, i2c=None, i2c_id=0, sda=None, scl=None):
        self._last_operation = None
        if i2c:
            self._i2c = i2c
        elif sda and scl:
            self._i2c = I2C(i2c_id, scl=Pin(scl), sda=Pin(sda))
        else:
            raise ValueError('Either i2c or sda and scl must be provided')

        self._address = address
        self._output_status = self.DISABLE_OUTPUT  # default
        # self._output_status = self.ENABLE_OUTPUT  # default

    def begin(self):
        if self._i2c.scan().count(self._address) == 0:
            # raise OSError('PCF8591 not found at I2C address {:#x}'.format(self._address))
            return False
        else:
            return True

    def _get_operation(self, auto_increment=False, channel=AIN0, read_type=SINGLE_ENDED_INPUT):
        # print('auto_increment: {}, channel: {}, read_type: {}, self._output_status {}'.format(auto_increment, channel, read_type, self._output_status))
        return 0 | (self._output_status & self.OUTPUT_MASK) | read_type | \
                                                                (self.AUTOINCREMENT_READ if auto_increment else 0) | \
                                                                channel

    def _write_operation(self, operation):
        if operation != self._last_operation:
            # print('operation: {}'.format(bin(operation) if operation is not None else 'None'))
            # print('_last_operation: {}'.format(bin(self._last_operation) if self._last_operation else 'None'))

            self._i2c.writeto(self._address, bytearray([operation]))
            utime.sleep_ms(1)
            self._i2c.readfrom(self._address, 1)
            self._last_operation = operation

    def analog_read_all(self, read_type=SINGLE_ENDED_INPUT):
        # operation = self.AUTOINCREMENT_READ | read_type | (self._output_status & self.OUTPUT_MASK)
        # operation = self.AUTOINCREMENT_READ | self.OUTPUT_MASK
        # self._i2c.writeto(self._address, bytearray([operation]))
        # utime.sleep_ms(1)
        # self._i2c.readfrom(self._address, 1)

        self._output_status = self.ENABLE_OUTPUT
        operation = self._get_operation(auto_increment=True)
        self._write_operation(operation)

        # data = self._i2c.readfrom(self._address, 4)
        data = []
        data.append(int.from_bytes(self._i2c.readfrom(self._address, 1), 'big'))
        data.append(int.from_bytes(self._i2c.readfrom(self._address, 1), 'big'))
        data.append(int.from_bytes(self._i2c.readfrom(self._address, 1), 'big'))
        data.append(int.from_bytes(self._i2c.readfrom(self._address, 1), 'big'))

        return int(data[0]), int(data[1]), int(data[2]), int(data[3])

    def analog_read(self, channel, read_type=SINGLE_ENDED_INPUT) :
        # operation = channel | read_type | (self._output_status & self.OUTPUT_MASK)
        # self._i2c.writeto(self._address, bytearray([operation]))
        # utime.sleep_ms(1)
        # self._output_status = self.DISABLE_OUTPUT
        operation = self._get_operation(auto_increment=False, channel=channel, read_type=read_type)
        self._write_operation(operation)

        data = self._i2c.readfrom(self._address, 2)
        return data[0] if self._output_status == self.ENABLE_OUTPUT else data[1]

    def voltage_read(self, channel, reference_voltage=3.3):
        voltage_ref = reference_voltage
        ana = self.analog_read(channel, self.SINGLE_ENDED_INPUT)
        return ana * voltage_ref / 255

    def voltage_write(self, value, reference_voltage=3.3):
        ana = value * 255 / reference_voltage
        self.analog_write(ana)

    def analog_write(self, value):
        if value > 255 or value < 0:
            Exception('Value must be between 0 and 255')

        self._output_status = self.ENABLE_OUTPUT
        self._last_operation = None
        self._i2c.writeto(self._address, bytearray([self.ENABLE_OUTPUT, value]))

    def disable_output(self):
        self._output_status = self.DISABLE_OUTPUT

        self._i2c.writeto(self._address, bytearray([self.DISABLE_OUTPUT]))
