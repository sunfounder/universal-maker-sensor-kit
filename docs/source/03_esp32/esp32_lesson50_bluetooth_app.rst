.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _esp32_iot_bluetooth_app:

レッスン50: Androidアプリケーション - ArduinoとBluetoothを使用したRGB LED操作
==================================================================================

このプロジェクトの目的は、Bluetooth技術を使用してスマートフォンを介してRGB LEDの色を操作できるAndroidアプリケーションを開発することです。

このAndroidアプリケーションは、MIT App Inventor 2と呼ばれる無料のウェブベースのプラットフォームを利用して構築されます。このプロジェクトは、Arduinoとスマートフォンのインターフェースについて学ぶ絶好の機会を提供します。


**必要なコンポーネント**

このプロジェクトでは、以下のコンポーネントが必要です。

一式を購入するのが便利です。リンクはこちらです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

以下のリンクから個別に購入することもできます。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - COMPONENT INTRODUCTION
        - PURCHASE LINK

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_rgb`
        - \-

**1. Androidアプリケーションの作成**

Androidアプリケーションは、|link_appinventor|として知られる無料のウェブアプリケーションを使用して作成されます。
MIT App Inventorは、シンプルなドラッグアンドドロップ機能を持ち、簡単なアプリケーションを作成できるため、Android開発の優れた出発点となります。

さあ、始めましょう。

#. ログインページはこちらです：http://ai2.appinventor.mit.edu。MIT App Inventorに登録するにはGoogleアカウントが必要です。

#. ログイン後、 **Projects** -> **Import project (.aia) from my computer**に移動します。その後、 ``esp32-starter-kit-main\c\codes\iot_10_bluetooth_app_inventor``のパスにある ``control_rgb_led.aia``ファイルをアップロードします。

   .. image:: img/10_ble_app_inventor1.png

#. ``.aia``ファイルをアップロードすると、 **MIT App Inventor**ソフトウェアにアプリケーションが表示されます。これは事前に構成されたテンプレートです。このテンプレートを修正することもできますが、その前に以下の手順を通じて **MIT App Inventor**の使い方に慣れてください。

   .. image:: img/10_ble_app_inventor2.png

#. **MIT App Inventor**には、 **Designer**と **Blocks**の2つの主要なセクションがあります。

   .. image:: img/10_ble_app_inventor3.png

#. **Designer**セクションでは、ボタン、テキスト、画面を追加したり、アプリケーションの全体的な外観を変更したりできます。

   .. image:: img/10_ble_app_inventor2.png
   

#. 次に、 **Blocks**セクションがあります。 **Blocks**セクションでは、アプリケーションのためのカスタム関数を作成できます。

   .. image:: img/10_ble_app_inventor5.png

#. スマートフォンにアプリケーションをインストールするには、 **Build**タブに移動します。

   .. image:: img/10_ble_app_inventor6.png

   * ``.apk``ファイルを生成できます。このオプションを選択すると、 ``.apk`` ファイルをダウンロードするかQRコードをスキャンしてインストールするかを選択できるページが表示されます。インストールガイドに従ってアプリケーションのインストールを完了してください。
   * このアプリを **Google Play**や他のアプリマーケットにアップロードする場合は、``.aab``ファイルを生成できます。


**2. コードのアップロード**

#. 回路を組み立てます。

   .. image:: img/Lesson_28_RGB_LED_Module_esp32_bb.png

#. 次に、USBケーブルを使ってESP32をコンピュータに接続します。

#. ``universal-maker-sensor-kit\esp32\Lesson_50_Bluetooth_app_inventor``ディレクトリにある ``Lesson_50_Bluetooth_app_inventor.ino``ファイルを開くか、Arduino IDEにコードをコピーします。

   .. raw:: html

      <iframe src=https://create.arduino.cc/editor/sunfounder01/07622bb5-31eb-4a89-b6f2-085f3332051f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. 適切なボード（ **ESP32 Dev Module**）とポートを選択した後、 **Upload**ボタンをクリックします。

**3. アプリとESP32の接続**

事前に作成したアプリケーションがスマートフォンにインストールされていることを確認してください。

#. まず、スマートフォンで **Bluetooth** を有効にします。

   .. image:: img/10_ble_mobile1.png
      :width: 500
      :align: center

#. スマートフォンの **Bluetooth設定** に移動し、 **ESP32RGB** を見つけます。

   .. image:: img/10_ble_mobile2.png
      :width: 500
      :align: center

#. クリック後、ポップアップウィンドウで **ペア** リクエストに同意します。

   .. image:: img/10_ble_mobile3.png
      :width: 500
      :align: center

#. 最近インストールした **Control_RGB_LED** アプリを開きます。

   .. image:: img/10_ble_mobile4.png
      :align: center

#. アプリ内で **Bluetooth接続** をクリックして、アプリとESP32の接続を確立します。

   .. image:: img/10_ble_mobile5.png
      :width: 500
      :align: center

#. 表示される ``xx.xx.xx.xx.xx.xx ESP32RGB``を選択します。コード内で ``SerialBT.begin("ESP32RGB");``を変更した場合は、設定した名前を選択します。

   .. image:: img/10_ble_mobile6.png
      :width: 500
      :align: center

#. 長時間待ってもデバイス名が表示されない場合、このアプリが周囲のデバイスをスキャンする許可を持っていない可能性があります。この場合、設定を手動で調整する必要があります。

   * アプリアイコンを長押しして **アプリ情報** をクリックします。別の方法でこのページにアクセスできる場合は、それに従ってください。

      .. image:: img/10_ble_mobile8.png
         :width: 500
         :align: center

   * **権限**ページに移動します。

      .. image:: img/10_ble_mobile9.png
         :width: 500
         :align: center

   * **近くのデバイス**を見つけ、 **常に許可** を選択してこのアプリが近くのデバイスをスキャンできるようにします。

      .. image:: img/10_ble_mobile10.png
         :width: 500
         :align: center

   * これで、アプリを再起動し、ステップ5と6を繰り返してBluetoothに正常に接続します。

#. 接続が成功すると、自動的にメインページに戻り、接続が表示されます。これで、RGB値を調整し、 **Change Color** ボタンを押してRGBディスプレイの色を変更できます。

   .. image:: img/10_ble_mobile7.png
      :width: 500
      :align: center
