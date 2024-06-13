.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _remote_windows:

Windowsユーザー
=======================

Windowsユーザーの場合、Windows PowerShellを使用してRaspberry Piにリモートログインできます。

#. キーボードの ``windows`` + ``R``ショートカットキーを押して **ファイル名を指定して実行**プログラムを開きます。入力ボックスに **powershell**と入力します。

   .. image:: img/windows_01.png
       :align: center

#. ``ping <hostname>.local``を入力して、Raspberry Piが同じネットワークにあるか確認します。

   .. code-block:: shell

       ping raspberrypi.local

   .. image:: img/windows_02.png
       :width: 550
       :align: center

   * ターミナルが ``Ping request could not find host <hostname>.local``と表示した場合、Raspberry Piがネットワークに接続できていない可能性があります。ネットワークを確認してください。
   * それでも ``<hostname>.local``にpingが通らない場合、:ref:`get_ip`を参照し、` `ping <IP address>``を試してください。（例： ``ping 192.168.6.116``）
   * "Reply from <IP address>: bytes=32 time<1ms TTL=64" のような複数のプロンプトが表示された場合、コンピュータがRaspberry Piにアクセスできることを意味します。

   .. raw:: html

      <br/>

#. ``ssh <username>@<hostname>.local``（または ``ssh <username>@<IP address>``）を入力します。

   .. code-block:: shell

       ssh pi@raspberrypi.local


#. 次のようなメッセージが表示される場合があります。

   .. code-block::

       The authenticity of host 'raspberrypi.local (192.168.6.116)' can't be established.
       ECDSA key fingerprint is SHA256:7ggckKZ2EEgS76a557cddfxFNDOBBuzcJsgaqA/igz4.
       Are you sure you want to continue connecting (yes/no/[fingerprint])? 

   「yes」と入力します。

#. 設定したパスワードを入力します。（例： ``raspberry``）

   .. note::
       パスワードを入力している際、ウィンドウに文字が表示されないのは正常です。正しいパスワードを入力してください。

#. これでRaspberry Piに接続できましたので、次のステップに進みます。

   .. image:: img/windows_03.png
       :width: 550
       :align: center

.. _windows_remote_desktop:

リモートデスクトップ
------------------

コマンドウィンドウを使用してRaspberry Piにアクセスすることに満足できない場合、リモートデスクトップ機能を使用してGUIでRaspberry Piのファイルを簡単に管理することもできます。



ここでは、 `VNC® Viewer <https://www.realvnc.com/en/connect/download/viewer/>`_を使用します。


**VNCサービスを有効にする**

システムにはVNCサービスがインストールされていますが、デフォルトでは無効になっています。設定で有効にする必要があります。

#. 次のコマンドを入力します：

   .. raw:: html

       <run></run>

   .. code-block:: shell 

       sudo raspi-config


#. キーボードの下矢印キーを押して **3** **Interfacing Options**を選択し、 **Enter** キーを押します。

   .. image:: img/windows_04.png
       :align: center

#. 次に**VNC**を選択します。

   .. image:: img/windows_05.png
       :align: center

#. キーボードの矢印キーを使って **<Yes>** -> **<OK>** -> **<Finish>**を選択し、設定を完了します。

   .. image:: img/windows_06.png
       :align: center

**VNCにログインする**

#. パーソナルコンピュータに `VNC Viewer <https://www.realvnc.com/en/connect/download/viewer/>`_をダウンロードしてインストールする必要があります。

#. インストールが完了したら、VNC Viewerを開きます。次に、ホスト名またはIPアドレスを入力し、Enterキーを押します。

   .. image:: img/windows_07.png
       :align: center

#. Raspberry Piの名前とパスワードを入力し、 **OK** をクリックします。

   .. image:: img/windows_08.png
       :align: center

#. これでRaspberry Piのデスクトップが表示されます。

   .. image:: img/windows_09.png
       :align: center
