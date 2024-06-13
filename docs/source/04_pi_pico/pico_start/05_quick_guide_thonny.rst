.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
Quick Guide on Thonny
==================================

.. _open_run_code_py:

コードを直接開いて実行する
---------------------------------------------

各プロジェクトで使用される特定のコードは明確に識別されています。各プロジェクトに対応するコードは、 ``universal-maker-sensor-kit-main/pico/`` ディレクトリにあります。

ただし、最初にパッケージをダウンロードし、ライブラリをアップロードする必要があります。詳細は :ref:`add_libraries_py` を参照してください。

#. コードを開く。

   例えば、 ``Lesson_01_Button_Module\01_button_module.py`` 。

   ダブルクリックすると、右側に新しいウィンドウが開きます。同時に複数のコードを開くことができます。

   .. image:: img/05_open_code.png

#. 正しいインタープリタを選択する

   Micro USBケーブルを使用してPico Wをコンピュータに接続し、「MicroPython (Raspberry Pi Pico)」インタープリタを選択します。

   .. image:: img/05_sec_inter.png

#. コードを実行する

   スクリプトを実行するには、 **現在のスクリプトを実行** ボタンをクリックするか、F5キーを押します。

   .. image:: img/05_run_it.png

   コードに印刷する必要のある情報が含まれている場合は、Shellに表示されます。そうでない場合は、次の情報だけが表示されます。

   .. code-block:: shell

      >>> %Run -c $EDITOR_CONTENT

   ThonnyにShellウィンドウが表示されていない場合は、 **表示** -> **Shell** をクリックして開きます。

   * ``%Run -c $EDITOR_CONTENT`` は、ThonnyからPico W上のMicroPythonインタープリタにスクリプトエリアの内容 - "EDITOR_CONTENT" - を実行するよう指示するコマンドです。
   * その後にメッセージが表示される場合、それは通常、MicroPythonに印刷するよう指示したメッセージか、コードのエラーメッセージです。

   .. raw:: html

      <br/>

#. 実行を停止する

   .. image:: img/05_stop_it.png

   実行中のコードを停止するには、 **バックエンドを停止/再起動** ボタンをクリックします。停止後、 **%RUN -c $EDITOR_CONTENT** コマンドは消えます。

#. 保存または名前を付けて保存

   開いている例に加えた変更は、 **Ctrl+S** を押すかThonnyの **保存** ボタンをクリックすることで保存できます。

   **ファイル** -> **名前を付けて保存** をクリックすることで、Raspberry Pi Pico W内の別ファイルとしてコードを保存できます。

   .. image:: img/05_save_as.png

   **Raspberry Pi Pico** を選択します。

   .. image:: img/05_sec_pico.png

   ファイル名と拡張子 **.py** を入力した後、**OK** をクリックします。Raspberry Pi Pico Wドライブに保存されたファイルが表示されます。

   .. image:: img/05_sec_name.png

   .. note::
       コードに名前を付ける際には、そのコードの種類を説明する名前にするのが最良です。 ``abc.py`` のような意味のない名前を付けないようにしましょう。
       コードを ``main.py`` として保存すると、電源を入れたときに自動的に実行されます。


ファイルの作成と実行
---------------------------

コードはコードセクションに直接表示されています。Thonnyにコピーして、次の手順で実行できます。

#. 新しいファイルを作成する

   Thonny IDEを開き、 **New** ボタンをクリックして新しい空のファイルを作成します。

   .. image:: img/new_file.png

#. コードをコピーする

   プロジェクトからThonny IDEにコードをコピーします。

   例えば：

   .. code:: python

      import machine
      import utime
      
      led = machine.Pin("LED", machine.Pin.OUT)
      while True:
          led.value(1)
          utime.sleep(2)
          led.value(0)
          utime.sleep(2)

   .. image:: img/05_2_copy_file.png

#. 正しいインタープリタを選択する

   Micro USBケーブルを使用してPico Wをコンピュータに接続し、右下の「MicroPython (Raspberry Pi Pico)」インタープリタを選択します。

   .. image:: img/05_2_sec_inter.png

#. コードを実行する

   **Run Current Script** をクリックするか、F5キーを押して実行します。

   このコードは、PicoのオンボードLEDを2秒ごとに点滅させるように設計されています。コードが実行されると、対応する点滅現象が観察されます。

   .. image:: img/05_2_run_it.png

#. 実行を停止する

   コードを停止するには、 **Stop/Restart backend** ボタンをクリックします。

   .. image:: img/05_2_stop_it.png

#. コードを保存する

   **Save** ボタンをクリックしてコードを保存できます。

   .. image:: img/05_2_save_code.png

   次に、Thonnyはコードの保存場所を尋ねてきます。コードを直接Picoに保存することができます。

   .. image:: img/05_sec_pico.png

   ファイル名と拡張子 .py を入力した後、OKをクリックします。

   .. image:: img/05_2_save_code_2.png

   .. note::
       コードに名前を付ける際には、そのコードの種類を説明する名前にするのが最良です。 ``abc.py`` のような意味のない名前を付けないようにしましょう。
       コードを ``main.py`` として保存すると、電源を入れたときに自動的に実行されます。

#. ファイルを開く

   保存したコードファイルを開く方法は2つあります。

   * 最初の方法は、Thonnyのツールバーにある開くアイコンをクリックすることです。プログラムを保存するときと同様に、 **this computer** または **Raspberry Pi Pico** から開くかどうかを尋ねられます。例えば、 **Raspberry Pi Pico** をクリックすると、Pico Wに保存されているすべてのプログラムのリストが表示されます。

     .. image:: img/05_2_open_file.png

   * 2つ目の方法は、 **View**-> **File** をクリックしてファイルプレビューを直接開き、対応する ``.py`` ファイルをダブルクリックして開くことです。

     .. image:: img/05_2_file_view.png
