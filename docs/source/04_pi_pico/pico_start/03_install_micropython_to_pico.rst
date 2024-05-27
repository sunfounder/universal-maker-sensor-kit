.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _install_micropython_on_pico:

Install MicroPython on Your Pico
==========================================


Now come to install MicroPython into Raspberry Pi Pico, Thonny IDE provides a very convenient way for you to install it with one click.

.. note::
    You can also use the |link_micropython_pi| provided by Raspberry Pi official by dragging and dropping an ``rp2_pico_xxxx.uf2`` file into Raspberry Pi Pico.



#. Open Thonny IDE.

   .. image:: img/set_pico1.png

#. Press and hold the **BOOTSEL** button and then connect the Pico to computer via a Micro USB cable. Release the **BOOTSEL** button after your Pico is mount as a Mass Storage Device called **RPI-RP2**.

   .. image:: img/bootsel_onboard.png
      :width: 70%
      :align: center

   .. raw:: html

      <br/>

#. In the bottom right corner, click the interpreter selection button and select **Install Micropython**.

   .. note::
      If your Thonny does not have this option, please update to the latest version.

   .. image:: img/set_pico2.png

#. In the **Target volume** section, the volume of the Pico you just plugged in will automatically appear. In the **variant** section, select **Raspberry Pi.Pico/Pico H**. Select the latest version in the version dropdown menu.

   .. image:: img/set_pico3.png

#. Click the **Install** button, wait for the installation to complete.

   .. image:: img/set_pico4.png


#. Congratulations, now your Raspberry Pi Pico is ready to go.

   .. image:: img/set_pico5.png