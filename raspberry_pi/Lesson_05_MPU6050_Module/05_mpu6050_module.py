# Import the mpu6050 class and sleep function from respective modules.
from mpu6050 import mpu6050
from time import sleep

# Initialize the MPU-6050 sensor with the I2C address 0x68.
sensor = mpu6050(0x68)

# Infinite loop to continuously read data from the sensor.
while True:
    # Retrieve accelerometer data from the sensor.
    accel_data = sensor.get_accel_data()
    # Retrieve gyroscope data from the sensor.
    gyro_data = sensor.get_gyro_data()
    # Retrieve temperature data from the sensor.
    temp = sensor.get_temp()

    # Print accelerometer data.
    print("Accelerometer data")
    print("x: " + str(accel_data['x']))
    print("y: " + str(accel_data['y']))
    print("z: " + str(accel_data['z']))

    # Print gyroscope data.
    print("Gyroscope data")
    print("x: " + str(gyro_data['x']))
    print("y: " + str(gyro_data['y']))
    print("z: " + str(gyro_data['z']))

    # Print the temperature in Celsius.
    print("Temp: " + str(temp) + " C")

    # Pause for 0.5 seconds before the next read cycle.
    sleep(0.5)
