.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _cpn_esp32_wroom_32e:

ESP32 WROOM 32E
=================

The ESP32 WROOM-32E is a versatile and powerful module built around Espressif's ESP32 chipset. It offers dual-core processing, integrated Wi-Fi and Bluetooth connectivity, and boasts a wide range of peripheral interfaces. Known for its low-power consumption, the module is ideal for IoT applications, enabling smart connectivity and robust performance in compact form factors.

.. image:: img/esp32_wroom_32e.png
    :width: 60%
    :align: center


Key features include:

* **Processing Power**: It's equipped with a dual-core Xtensa® 32-bit LX6 microprocessor, offering scalability and flexibility.
* **Wireless Capabilities**: With integrated 2.4 GHz Wi-Fi and dual-mode Bluetooth, it's perfectly suited for applications demanding stable wireless communication.
* **Memory & Storage**: It comes with ample SRAM and high-performance flash storage, catering to user programs and data storage needs.
* **GPIO**: Offering up to 38 GPIO pins, it supports a variety of external devices and sensors.
* **Low Power Consumption**: Multiple power-saving modes are available, making it ideal for battery-powered or energy-efficient scenarios.
* **Security**: Integrated encryption and security features ensure user data and privacy are well-protected.
* **Versatility**: From simple household appliances to complex industrial machinery, the WROOM-32E delivers consistent, efficient performance.

In summary, the ESP32 WROOM-32E not only offers robust processing capabilities and diverse connectivity options but also boasts an array of features making it a preferred choice in the IoT and smart device sectors.

* |link_esp32_datasheet|

.. _esp32_pinout:

Pinout Diagram
-------------------------

The ESP32 has some pin usage limitations due to various functionalities sharing certain pins. When designing a project, it's a good practice to carefully plan the pin usage and cross-check for potential conflicts to ensure proper functioning and avoid issues.


.. image:: img/esp32_pinout.jpg
    :width: 100%
    :align: center

Here are some of the key restrictions and considerations:

* **ADC1 and ADC2**: ADC2 cannot be used when WiFi or Bluetooth is active. However, ADC1 can be used without any restrictions.
* **Bootstrapping Pins**: GPIO0, GPIO2, GPIO5, GPIO12, and GPIO15 are used for bootstrapping during the boot process. Care should be taken not to connect external components that could interfere with the boot process on these pins.
* **JTAG Pins**: GPIO12, GPIO13, GPIO14, and GPIO15 can be used as JTAG pins for debugging purposes. If JTAG debugging is not required, these pins can be used as regular GPIOs.
* **Touch Pins**: Some pins support touch functionalities. These pins should be used carefully if you intend to use them for touch sensing.
* **Power Pins**: Some pins are reserved for power-related functions and should be used accordingly. For example, avoid drawing excessive current from power supply pins like 3V3 and GND.
* **Input-only Pins**: Some pins are input-only and should not be used as outputs.


.. _esp32_strapping:

Strapping Pins
--------------------------

ESP32 has five strapping pins:

.. list-table::
    :widths: 5 15
    :header-rows: 1

    *   - Strapping Pins
        - Description
    *   - IO5
        - Defaults to pull-up, the voltage level of IO5 and IO15 affects the Timing of SDIO Slave.
    *   - IO0
        - Defaults to pull-up, if pulled low, it enters download mode.
    *   - IO2
        - Defaults to pull-down, IO0 and IO2 will make ESP32 enter download mode.
    *   - IO12(MTDI)
        - Defaults to pull-down, if pulled high, ESP32 will fail to boot up normally.
    *   - IO15(MTDO)
        - Defaults to pull-up, if pulled low, debug log will not be visible. Additionally, the voltage level of IO5 and IO15 affects the Timing of SDIO Slave.


Software can read the values of these five bits from register "GPIO_STRAPPING". During the chip's system reset release (power-on-reset, RTC watchdog reset and brownout reset), the latches of the strapping pins sample the voltage level as strapping bits of "0" or "1", and hold these bits until the chip is powered down or shut down. The strapping bits configure the device's boot mode, the operating voltage of VDD_SDIO and other initial system settings.

Each strapping pin is connected to its internal pull-up/pull-down during the chip reset. Consequently, if a strapping pin is unconnected or the connected external circuit is high-impedance, the internal weak pull-up/pull-down will determine the default input level of the strapping pins.

To change the strapping bit values, users can apply the external pull-down/pull-up resistances, or use the host MCU's GPIOs to control the voltage level of these pins when powering on ESP32.

After reset release, the strapping pins work as normal-function pins.
Refer to following table for a detailed boot-mode configuration by strapping pins.

.. image:: img/esp32_strapping.png
   :width: 100%
   :align: center

* FE: falling-edge, RE: rising-edge
* Firmware can configure register bits to change the settings of "Voltage of Internal LDO (VDD_SDIO)" and "Timing of SDIO Slave", after booting.
* The module integrates a 3.3 V SPI flash, so the pin MTDI cannot be set to 1 when the module is powered up.