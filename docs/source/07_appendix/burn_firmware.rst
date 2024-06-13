.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _burn_firmware:

ESP8266モジュールのATファームウェアを再書き込みする方法
=====================================================


R3でファームウェアを書き込む
---------------------------------------

**1. 回路を構築する**

  ESP8266とSunFounder R3ボードを接続します。

  .. image:: img/esp8266_connect_esp8266.png
      :width: 800

**2. ファームウェアの書き込み**

* **Windows**を使用している場合、以下の手順に従ってファームウェアを書き込みます。

  #. ファームウェアと書き込みツールをダウンロードします。

     * :download:`ESP8266 Firmware <https://raw.githubusercontent.com/sunfounder/ultimate-sensor-kit/main/iot_project/esp8266_firmware.zip>`

  #. 解凍後、以下の4つのファイルが表示されます。

     .. .. image:: img/bat_firmware.png
 
     * ``BAT_AT_V1.7.1.0_1M.bin``: ESP8266モジュールに書き込むファームウェア。
     * ``esptool.exe``: Windows用のコマンドラインユーティリティ。
     * ``install_r3.bat``: Windowsシステム用のコマンドパッケージ。このファイルをダブルクリックすると、ファイル内のすべてのコマンドが実行されます。
     * ``install_r4.bat``: ``install_r3.bat``と同様ですが、UNO R4ボード専用です。

  #. ``install_r3.bat``をダブルクリックしてファームウェアの書き込みを開始します。以下のプロンプトが表示されたら、ファームウェアが正常にインストールされたことを示します。

     .. image:: img/esp8266_install_firmware.png

     .. note::
         書き込みが失敗した場合は、以下の点を確認してください。

         * ESP8266モジュールをリセットするには、ESP8266アダプタのRSTをGNDに挿入し、その後に取り外します。
         * 配線が正しいかどうかを確認してください。
         * コンピュータがボードを正しく認識しているか、ポートが占有されていないことを確認してください。
         * install.batファイルを再度開いてください。

* **Mac OS**システムを使用している場合、以下の手順に従ってファームウェアを書き込みます。

  #. 以下のコマンドを使用してEsptoolをインストールします。EsptoolはPythonベースのオープンソースで、EspressifチップのROMブートローダーと通信するためのプラットフォーム非依存のユーティリティです。

     .. code-block::

         python3 -m pip install --upgrade pip
         python3 -m pip install esptool

  #. Esptoolが正しくインストールされている場合、``python3 -m esptool``を実行すると[usage: esptool]のようなメッセージが表示されます。

  #. ファームウェアをダウンロードします。

     * :download:`ESP8266 Firmware <https://raw.githubusercontent.com/sunfounder/ultimate-sensor-kit/main/iot_project/esp8266_firmware.zip>`

  #. 解凍後、以下の3つのファイルが表示されます。

     .. image:: img/esp8266_bat_firmware.png

     * ``BAT_AT_V1.7.1.0_1M.bin``: ESP8266モジュールに書き込むファームウェア。
     * ``esptool.exe``: Windows用のコマンドラインユーティリティ。
     * ``install_r3.bat``: Windowsシステム用のコマンドパッケージ。
     * ``install_r4.bat``: ``install_r3.bat``と同様ですが、UNO R4ボード専用です。
  #. ターミナルを開き、``cd``コマンドを使用してダウンロードしたファームウェアフォルダに移動し、次のコマンドを実行して既存のファームウェアを消去し、新しいファームウェアを書き込みます。

     .. code-block::

         python3 -m esptool --chip esp8266 --before default_reset erase_flash
         python3 -m esptool --chip esp8266 --before default_reset write_flash 0 "BAT_AT_V1.7.1.0_1M.bin"

  #. 以下のプロンプトが表示されたら、ファームウェアが正常にインストールされたことを示します。

     .. image:: img/esp8266_install_firmware_macos.png

     .. note::
         書き込みが失敗した場合は、以下の点を確認してください。

         * ESP8266モジュールをリセットするには、ESP8266アダプタのRSTをGNDに挿入し、その後に取り外します。
         * 配線が正しいかどうかを確認してください。
         * コンピュータがボードを正しく認識しているか、ポートが占有されていないことを確認してください。
         * install.batファイルを再度開いてください。

**3. テスト**

#. 元の配線に基づいて、IO1を3V3に接続します。

   .. image:: img/esp8266_connect_esp826612.png
       :width: 800

#. 右上の虫眼鏡アイコン（シリアルモニター）をクリックし、ボーレートを **115200** に設定すると、ESP8266モジュールに関する情報が表示されます。

   .. image:: img/esp8266_test_firmware_1.png

   .. note::

       * ``ready``が表示されない場合は、ESP8266モジュールをリセットして（RSTをGNDに接続）、シリアルモニターを再度開いてみてください。

#. **NEWLINE ドロップダウンボックス**をクリックし、ドロップダウンオプションから ``both NL & CR`` を選択し、 ``AT`` と入力します。OKと返されれば、ESP8266がR3ボードと正常に接続されたことを意味します。

   .. image:: img/esp8266_test_firmware_2.png

これで、:ref:`config_esp8266`に従って、ESP8266モジュールの動作モードとボーレートを設定することができます。



R4でファームウェアを書き込む
---------------------------------------

**1. 回路を構築する**

ESP8266とArduino UNO R4ボードを接続します。

    .. image:: img/esp8266_faq_at_burn_bb.jpg
        :width: 800

**2. R4に以下のコードをアップロード**

.. code-block:: Arduino

    void setup() {
        Serial.begin(115200);
        Serial1.begin(115200);
    }

    void loop() {
        if (Serial.available()) {      // If anything comes in Serial (USB),
            Serial1.write(Serial.read());   // read it and send it out Serial1 (pins 0 & 1)
        }
            if (Serial1.available()) {     // If anything comes in Serial1 (pins 0 & 1)
            Serial.write(Serial1.read());   // read it and send it out Serial (USB)
        }
    }

**3. ファームウェアの書き込み**

* **Windows**を使用している場合、以下の手順に従ってファームウェアを書き込みます。

  #. ファームウェアと書き込みツールをダウンロードします。

     * :download:`ESP8266 Firmware <https://raw.githubusercontent.com/sunfounder/ultimate-sensor-kit/main/iot_project/esp8266_firmware.zip>`

  #. 解凍後、以下の4つのファイルが表示されます。

     .. .. image:: img/bat_firmware.png
 
     * ``BAT_AT_V1.7.1.0_1M.bin``: ESP8266モジュールに書き込むファームウェア。
     * ``esptool.exe``: Windows用のコマンドラインユーティリティ。
     * ``install_r3.bat``: Windowsシステム用のコマンドパッケージ。このファイルをダブルクリックすると、ファイル内のすべてのコマンドが実行されます。
     * ``install_r4.bat``: ``install_r3.bat``と同様ですが、UNO R4ボード専用です。

  #. ``install_r4.bat``をダブルクリックしてファームウェアの書き込みを開始します。以下のプロンプトが表示されたら、ファームウェアが正常にインストールされたことを示します。

     .. image:: img/esp8266_install_firmware.png

     .. note::
         書き込みに失敗した場合、以下の点を確認してください。

         * ESP8266モジュールをリセットするには、ESP8266アダプタのRSTをGNDに接続し、その後に取り外します。
         * 配線が正しいかどうかを確認してください。
         * コンピュータがボードを正しく認識しているか、ポートが占有されていないことを確認してください。
         * install.batファイルを再度開いてください。

* **Mac OS**システムを使用している場合、以下の手順に従ってファームウェアを書き込みます。

  #. 以下のコマンドを使用してEsptoolをインストールします。EsptoolはPythonベースのオープンソースで、EspressifチップのROMブートローダーと通信するためのプラットフォーム非依存のユーティリティです。

     .. code-block::

         python3 -m pip install --upgrade pip
         python3 -m pip install esptool

  #. Esptoolが正しくインストールされている場合、 ``python3 -m esptool`` を実行すると[usage: esptool]のようなメッセージが表示されます。

  #. ファームウェアをダウンロードします。

     * :download:`ESP8266 Firmware <https://raw.githubusercontent.com/sunfounder/ultimate-sensor-kit/main/iot_project/esp8266_firmware.zip>`

  #. 解凍後、以下の4つのファイルが表示されます。

     .. .. image:: img/bat_firmware.png

     * ``BAT_AT_V1.7.1.0_1M.bin``: ESP8266モジュールに書き込むファームウェア。
     * ``esptool.exe``: Windows用のコマンドラインユーティリティ。
     * ``install_r3.bat``: Windowsシステム用のコマンドパッケージ。
     * ``install_r4.bat``: ``install_r3.bat``と同様ですが、UNO R4ボード専用です。


  #. ターミナルを開き、``cd``コマンドを使用してダウンロードしたファームウェアフォルダに移動し、次のコマンドを実行して既存のファームウェアを消去し、新しいファームウェアを書き込みます。

     .. code-block::

         python3 -m esptool --chip esp8266 --before no_reset_no_sync erase_flash
         python3 -m esptool --chip esp8266 --before no_reset_no_sync write_flash 0 "BAT_AT_V1.7.1.0_1M.bin"

  #. 以下のプロンプトが表示されたら、ファームウェアが正常にインストールされたことを示します。

     .. image:: img/esp8266_install_firmware_macos.png

     .. note::
         書き込みに失敗した場合、以下の点を確認してください。

         * ESP8266モジュールをリセットするには、ESP8266アダプタのRSTをGNDに接続し、その後に取り外します。
         * 配線が正しいかどうかを確認してください。
         * コンピュータがボードを正しく認識しているか、ポートが占有されていないことを確認してください。
         * install.batファイルを再度開いてください。

**4. テスト**

#. 元の配線に基づいて、IO1を3V3に接続します。

   .. image:: img/esp8266_faq_at_burn_check_bb.jpg
       :width: 800

#. 右上の虫眼鏡アイコン（シリアルモニター）をクリックし、ボーレートを **115200** に設定すると、ESP8266モジュールに関する情報が表示されます。

   .. image:: img/esp8266_test_firmware_1.png

   .. note::

       * ``ready``が表示されない場合は、ESP8266モジュールをリセットして（RSTをGNDに接続）、シリアルモニターを再度開いてみてください。

#. **NEWLINE ドロップダウンボックス**をクリックし、ドロップダウンオプションから ``both NL & CR`` を選択し、 ``AT`` と入力します。OKと返されれば、ESP8266がR4ボードと正常に接続されたことを意味します。

   .. image:: img/esp8266_test_firmware_2.png

これで、:ref:`esp8266_start`に従って、ESP8266モジュールの動作モードとボーレートを設定することができます。
