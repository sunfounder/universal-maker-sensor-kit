from machine import Pin
import ds1302
import time

# Initialize DS1302 RTC with specific GPIO pins
ds = ds1302.DS1302(Pin(5), Pin(18), Pin(19))  # (clk, dio, cs)

# Get current datetime from DS1302
ds.date_time()

# Set DS1302 datetime to 2024-01-01 Monday 00:00:00
ds.date_time([2024, 1, 1, 1, 0, 0, 0])  # (year,month,day,weekday,hour,minute,second)

# Set seconds to 10
ds.second(10)

# Continuously display current datetime every half second
while True:
    print(ds.date_time())
    time.sleep(0.5)
