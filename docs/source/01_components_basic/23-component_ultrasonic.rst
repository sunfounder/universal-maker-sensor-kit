.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _cpn_ultrasonic:

Ultrasonic Sensor Module (HC-SR04)
=====================================

.. image:: img/23_ultrasonic.png
    :width: 350
    :align: center

.. raw:: html

   <br/>

The Ultrasonic Module(HC-SR04) is a sensor that can measure distances between 2cm and 400cm using ultrasonic waves. It is commonly used in robotics and automation projects to detect objects and measure distances. The module consists of an ultrasonic transmitter and receiver, which work together to send and receive ultrasonic waves.


.. _cpn_ultrasonic_principle:

Principle
---------------------------
The module includes ultrasonic transmitters, receiver and control circuit. The basic principles are as follows:

#. Use an IO flip-flop to process a high level signal of at least 10us.

#. The module automatically sends eight 40khz and detects if there is a pulse signal return.

#. If the signal returns, passing the high level, the high output IO duration is the time from the transmission of the ultrasonic wave to the return of it. Here, test distance = (high time x sound speed (340 m / s) / 2.

The timing diagram is shown below. 

.. image:: img/23_ultrasonic_principle.png

You only need to supply a short 10us pulse for the trigger input to start the ranging, and then the module
will send out an 8 cycle burst of ultrasound at 40 kHz and raise its
echo. You can calculate the range through the time interval between
sending trigger signal and receiving echo signal.

.. note::
    It is recommended to use measurement cycle over 60ms in order to prevent signal collisions of
    trigger signal and the echo signal.


Formula: 
    - us / 58 = centimeters 
    - us / 148 = inch
    - distance = high level time \* speed of sound (340m/s) / 2; 



Example
---------------------------
* :ref:`uno_lesson23_ultrasonic` (Arduino UNO)
* :ref:`esp32_lesson23_ultrasonic` (ESP32)
* :ref:`pico_lesson23_ultrasonic` (Raspberry Pi Pico)
* :ref:`pi_lesson23_ultrasonic` (Raspberry Pi)

* :ref:`uno_lesson37_trashcan` (Arduino UNO)

* :ref:`esp32_trashcan` (ESP32)