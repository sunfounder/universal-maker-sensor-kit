.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _install_blinka:

``Adafruit_Blinka``（CircuitPython）のインストール - 任意
==========================================================

高度なモジュールを使用するために、``Adafruit_Blinka``ライブラリを使用することをお勧めします。これはCircuitPython環境の主要なコンポーネントです。Blinkaの特長は、CircuitPython用に書かれたコードをRaspberry PiなどのLinuxコンピュータ上でシームレスかつ簡単に実行できることです。

このライブラリを使用することで、BMP280、VL53L0X、OLEDなどの複雑なモジュールの利用が簡単になり、プロジェクト開発プロセスが効率化されます。CircuitPythonを使えば、ハードウェアの知識がなくても、堅牢なアプリケーションの作成に集中できるようになります。

さらに、大規模なサポートコミュニティや学習・開発を支援するさまざまなリソースの恩恵を受けることができます。

ここでは、Adafruit_Blinkaのインストールプロセスを簡単に説明し、プロジェクトにすぐに取り掛かれるようにします。


Raspberry PiとPythonのアップデート
----------------------------------------------

Blinkaをインストールする前に、以下のコマンドを使用してRaspberry PiとPythonのバージョンを最新にしてください：

.. code-block:: bash

   sudo apt-get update
   sudo apt-get upgrade


仮想環境のセットアップ
----------------------------------------------

Bookworm（OSバージョン）からは、 ``pip`` を使用してインストールされるパッケージは ``venv`` を使用してPython仮想環境にインストールする必要があります。仮想環境は、システムのPythonに影響を与えずにサードパーティモジュールをインストールできる安全なコンテナです。

以下のコマンドは、ユーザーディレクトリ（ ``~`` ）に「env」ディレクトリを作成し、仮想Python環境を設定します。

.. code-block:: bash
   
   cd ~
   python -m venv env --system-site-packages

Raspberry Piを再起動するたびに仮想環境をアクティブにする必要があります。アクティブにするには：

.. code-block:: bash

   source env/bin/activate

プロンプトの先頭に(env)が付くようになり、システムPythonではなく、仮想環境内のPythonを使用していることがわかります。ここで行った変更はシステムPythonには影響を与えませんし、新しいモジュールをインストールしても問題はありません。

.. image:: img/07_activate_env.png

仮想環境を非アクティブにするには、 ``deactivate`` を使用しますが、今はアクティブのままにしておいてください。

自動インストール
-----------------------

仮想環境がアクティブになっている場合（ターミナルコマンドの先頭に ``(env)`` が表示されます）、以下のコードを順番に実行してください。このコードはadafruitが提供するインストールスクリプトを実行し、残りのインストールステップを自動的に完了します。

.. code-block:: bash

   pip3 install --upgrade adafruit-python-shell
   wget https://raw.githubusercontent.com/adafruit/Raspberry-Pi-Installer-Scripts/master/raspi-blinka.py
   sudo -E env PATH=$PATH python3 raspi-blinka.py

実行には数分かかる場合があります。終了すると、再起動するかどうか尋ねられます。Enterを押して直接再起動するか、後で再起動したい場合は「n」と入力してからEnterを押します。準備ができたら、手動でRaspberry Piを再起動してください。

.. image:: img/07_after_install_blinka.png

再起動後、接続が切れます。数分後に再接続できます。



Blinkaテスト
-----------------------

``blinkatest.py``という新しいファイルをnanoまたはお好みのテキストエディタで作成し、以下の内容を入力します：

.. code-block:: python

   import board
   import digitalio
   import busio
   
   print("Hello blinka!")
   
   # Try to great a Digital input
   pin = digitalio.DigitalInOut(board.17)
   print("Digital IO ok!")
   
   # Try to create an I2C device
   i2c = busio.I2C(board.SCL, board.SDA)
   print("I2C ok!")
   
   # Try to create an SPI device
   spi = busio.SPI(board.SCLK, board.MOSI, board.MISO)
   print("SPI ok!")
   
   print("done!")

コードを実行する前に、blinkaがインストールされた仮想Python環境がアクティブになっていることを確認してください：

.. code-block:: bash

   source ~/env/bin/activate

次に、コマンドラインで以下のコマンドを実行します：

.. code-block:: bash

   python blinkatest.py

デジタルI/O、I2C、およびSPIがすべて正常に動作することを示す以下の出力が表示されるはずです。

.. image:: img/07_check_blinka.png


参考文献
-----------------------

- |link_adafruit_blinka_guide|

- |link_python_on_raspberry_pi|