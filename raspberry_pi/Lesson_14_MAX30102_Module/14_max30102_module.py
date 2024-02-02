from heartrate_monitor import HeartRateMonitor
import time

# Print a message indicating the sensor is starting
print('sensor starting...')

# Set the duration for which the sensor data will be read (in seconds)
duration = 30

# Initialize the HeartRateMonitor object
# Set print_raw to False to avoid printing raw data
# Set print_result to True to print the calculated results
hrm = HeartRateMonitor(print_raw=False, print_result=True)

# Start the heart rate sensor
hrm.start_sensor()

try:
    time.sleep(duration)
except KeyboardInterrupt:
    print('keyboard interrupt detected, exiting...')

# Stop the sensor after the duration has elapsed
hrm.stop_sensor()

# Print a message indicating the sensor has stopped
print('sensor stopped!')
