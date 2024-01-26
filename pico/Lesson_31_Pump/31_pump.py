from machine import Pin, PWM
import time

pump_a = PWM(Pin(26), freq=1000)
pump_b = PWM(Pin(27), freq=1000)

# turn on pump
pump_a.duty_u16(0)
pump_b.duty_u16(65535)  # speed(0-65535)

time.sleep(5)

# turn off pump
pump_a.duty_u16(0)
pump_b.duty_u16(0)
