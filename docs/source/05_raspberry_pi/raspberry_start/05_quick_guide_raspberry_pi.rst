.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

コードのダウンロードと実行方法
=================================

コードをRaspberry Piにダウンロードする
-------------------------------------

コードをダウンロードする前に、例示されたコードは最新バージョンの **Raspberry Pi OS**でのみテストされていることをご理解ください。ダウンロード方法は2つあります。

Raspberry Piに直接画面を接続せずにアクセスしている場合は、リモートアクセスオプションを利用することを検討してください。詳細なガイダンスについては、:ref:`no_screen`の指示を参照してください。


**方法1: Git Cloneを使用（推奨）**

1. Raspberry Piにログインし、ターミナルを開いてホームディレクトリ（ ``~`` ）に移動します。（SSHを使用してターミナルにアクセスすることもできます。）

   .. code-block:: bash

      cd ~

   .. image:: img/quick_guide_01.png
       :width: 100%

   .. note::

      ディレクトリを変更するには ``cd`` コマンドを使用します。ここでの ``~/`` はホームディレクトリを示します。

2. GitHubリポジトリをクローンします。

   .. code-block:: bash

      git clone https://github.com/sunfounder/universal-maker-sensor-kit.git

   .. image:: img/quick_guide_02.png
       :width: 100%
   
   .. raw:: html

      <br/><br/>

3. ファイルマネージャーを使用して、ダウンロードしたコードファイルにアクセスします。

   .. image:: img/quick_guide_03.png
       :width: 100%

**方法2: GitHubから直接コードをダウンロード**

1. ウェブブラウザーを開き、https://github.com/sunfounder/universal-maker-sensor-kit にアクセスし、ダウンロードボタンをクリックします。

   .. image:: img/quick_guide_04.png

2. ダウンロードが完了したら、 ``File Manager > Downloads`` でコードファイルを見つけ、それを ``/home/pi`` ディレクトリに解凍します。

   .. image:: img/quick_guide_05.png

3. ``/home/pi``ディレクトリに移動して、解凍されたコードファイルにアクセスします。

   .. image:: img/quick_guide_06.png


コードの開き方と実行方法
------------------------

各プロジェクトのコードは、それぞれのコードセクションで見つけることができます。また、提供されたコードディレクトリにもコードがあります。例えば、 ``universal-maker-sensor-kit/raspberry_pi/`` には、レッスン1のコードが ``01_button_module.py`` という名前であります。

以下にPythonコードを実行する2つの方法を示します：

**方法1: Geanyを使用**

1. コードファイルをダブルクリックして開きます。

   .. image:: img/quick_guide_07.png

   あるいは、ファイルを右クリックして **Open With...** を選択します。

   .. image:: img/quick_guide_08.png

   **Programming > Geany Programmer's Editor**を選び、 **OK** をクリックします。

   .. image:: img/quick_guide_09.png

   コードが表示され、編集や確認ができます。

   .. image:: img/quick_guide_10.png

2. ウィンドウで**Run**をクリックすると、次の内容が表示されます。
   
   .. image:: img/quick_guide_11.png

3. 実行を停止するには、右上のXボタンをクリックしてウィンドウを閉じるか、Ctrl+Cを入力してプログラムを終了します。
   
   .. image:: img/quick_guide_12.png

**方法2: ターミナルを使用**

1. Raspberry Piにログインし、ターミナルを開いてホームディレクトリ（ ``~`` ）に移動します。（SSHを使用してターミナルにアクセスすることもできます。）

   .. code-block::

      cd ~/universal-maker-sensor-kit/raspberry_pi/

   .. image:: img/quick_guide_13.png

   .. note::
       ``cd``コマンドを使用して実験のコードディレクトリに移動します。

2. コードを実行します：

   .. code-block::

      python3 Lesson_01_Button_Module/01_button_module.py

   .. image:: img/quick_guide_14.png

3. コードを実行すると、ボタンが押されているかどうかが出力されます。

   .. image:: img/quick_guide_15.png

4. ``Lesson_01_Button_Module/01_button_module.py``ファイルを編集するには、 ``Ctrl + C`` を押してコードを停止します。その後、以下のコマンドでファイルを開きます：

   .. code-block::

      nano Lesson_01_Button_Module/01_button_module.py

   .. image:: img/quick_guide_16.png

5. ``nano``はテキストエディタです。このコマンドで ``nano Lesson_01_Button_Module/01_button_module.py``が開きます。

   .. image:: img/quick_guide_17.png

6. nanoを終了するには、 ``Ctrl+X`` を押します。変更を加えた場合、保存するかどうかのプロンプトが表示されます。 ``Y`` （はい）を選んで保存し、 ``N`` （いいえ）を選んで破棄します。 ``Enter`` を押して確定し、終了します。変更を確認するには、 ``nano Lesson_01_Button_Module/nano 01_button_module.py``でファイルを再度開きます。

   .. image:: img/quick_guide_18.png