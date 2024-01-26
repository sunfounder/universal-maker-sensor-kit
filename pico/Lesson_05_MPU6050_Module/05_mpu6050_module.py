# Import libraries
from imu import MPU6050
from machine import I2C, Pin
import time

# Initialize I2C for MPU6050
i2c = I2C(0, sda=Pin(20), scl=Pin(21), freq=400000)  # I2C bus 0, SDA pin 20, SCL pin 21, 400kHz

# Create MPU6050 object
mpu = MPU6050(i2c)

# Main loop to read and print sensor data
while True:
    # Print accelerometer data (x, y, z)
    print("-" * 50)
    print("x: %s, y: %s, z: %s" % (mpu.accel.x, mpu.accel.y, mpu.accel.z))
    time.sleep(0.1)

    # Print gyroscope data (x, y, z)
    print("X: %s, Y: %s, Y: %s" % (mpu.gyro.x, mpu.gyro.y, mpu.gyro.z))
    time.sleep(0.1)

    # Delay between readings
    time.sleep(0.5)
