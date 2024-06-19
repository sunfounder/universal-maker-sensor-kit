.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

Raspberry Piの設定
=================================

.. _pi_enable_i2c:

I2Cの設定
-----------------------

Raspberry PiでI2Cポートを有効にするには、以下の手順に従ってください（すでに有効になっている場合はスキップします。不明な場合は、指示に従ってください）。

1. Raspberry Piにログインし、ターミナルを開いて以下のコマンドを入力し、Raspberry Pi Software Configuration Toolにアクセスします。（SSHを使用してターミナルにアクセスすることもできます。）

   .. code-block:: 

       sudo raspi-config

   .. image:: img/configuration_01.png
       :width: 100%

   .. raw:: html

       <br/><br/>

2. **Interfacing options** に移動します。

   .. note::
      ``上``および ``下`` 矢印キーを使用して、利用可能なオプションの間でハイライト選択を移動させます。 ``右`` 矢印キーを押すと、オプションメニューを抜けて ``<Select>`` および ``<Finish>`` ボタンに移動します。 ``左`` を押すと、再びオプションに戻ります。代わりに、 ``Tab`` キーを使用してこれらの間を切り替えることもできます。

   .. image:: img/configuration_02.png
       :width: 100%

   .. raw:: html

       <br/><br/>

3. **I2C** を選択します。

   .. image:: img/configuration_03.png
       :width: 100%

   .. raw:: html

       <br/><br/>

4. **<Yes>** を選択してI2Cインターフェースを有効にし、次に **<Ok>** を選択します。

   .. image:: img/configuration_04.png
       :width: 100%

   .. raw:: html

       <br/><br/>

5. **<Finish>** を選択してRaspberry Pi Software Configuration Toolを終了します。

   .. image:: img/configuration_05.png
       :width: 100%

   .. raw:: html

       <br/><br/>

6. 以下のコマンドを使用して、接続されたI2Cデバイスのアドレスを確認します。

   .. code-block:: 

       i2cdetect -y 1      

   .. image:: img/configuration_06.png
       :width: 100%

   接続されているI2Cデバイスのアドレスが表示されます。

   .. image:: img/configuration_07.png
       :width: 100%

   .. raw:: html

       <br/><br/>



.. _pi_enable_1wire:

1-Wireの設定
-----------------------

Raspberry Piで1-Wireポートを有効にするには、以下の手順に従ってください（すでに有効になっている場合はスキップします。不明な場合は、指示に従ってください）。

1. Raspberry Piにログインし、ターミナルを開いて以下のコマンドを入力し、Raspberry Pi Software Configuration Toolにアクセスします。（SSHを使用してターミナルにアクセスすることもできます。）

   .. code-block:: 

       sudo raspi-config

   .. image:: img/configuration_08.png
       :width: 100%

   .. raw:: html

       <br/><br/>

2. **Interfacing options** に移動します。

   .. note::
      ``上``および ``下`` 矢印キーを使用して、利用可能なオプションの間でハイライト選択を移動させます。 ``右`` 矢印キーを押すと、オプションメニューを抜けて ``<Select>`` および ``<Finish>`` ボタンに移動します。 ``左`` を押すと、再びオプションに戻ります。代わりに、 ``Tab`` キーを使用してこれらの間を切り替えることもできます。

   .. image:: img/configuration_09.png
       :width: 100%

   .. raw:: html

       <br/><br/>

3. **1-Wire** を選択します。

   .. image:: img/configuration_10.png
       :width: 100%

   .. raw:: html

       <br/><br/>

4. **<Yes>** を選択して1-Wireインターフェースを有効にし、次に **<Ok>** を選択します。

   .. image:: img/configuration_11.png
       :width: 100%

   .. raw:: html

       <br/><br/>

5. **<Finish>** を選択してRaspberry Pi Software Configuration Toolを終了します。

   .. image:: img/configuration_12.png
       :width: 100%

   .. raw:: html

       <br/><br/>

6. **<yes>** を選択してRaspberry Piを再起動します。

   .. image:: img/configuration_13.png
       :width: 100%

   .. raw:: html

       <br/><br/>

