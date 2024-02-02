from machine import Pin, PWM
import time

motor_a = PWM(Pin(26), freq=1000)
motor_b = PWM(Pin(27), freq=1000)

# turn on motor
motor_a.duty_u16(0)
motor_b.duty_u16(65535)  # speed(0-65535)

time.sleep(5)

# turn off motor
motor_a.duty_u16(0)
motor_b.duty_u16(0)
