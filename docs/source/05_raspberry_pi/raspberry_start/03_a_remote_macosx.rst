.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _remote_macosx:

Mac OS Xユーザー
==========================

Macユーザーにとって、Raspberry Piデスクトップに直接アクセスするには、コマンドラインよりもVNCを使用する方が便利です。Raspberry Pi側でVNCを有効にした後、Finderを介して設定したアカウントのパスワードを入力することでアクセスできます。

この方法では、MacとRaspberry Pi間の通信が暗号化されないことに注意してください。
通信は家庭やビジネスネットワーク内で行われるため、保護されていなくても問題はありません。
ただし、気になる場合は、 `VNC® Viewer <https://www.realvnc.com/en/connect/download/viewer/>`_などのVNCアプリケーションをインストールすることができます。

また、仮のモニター（テレビ）、マウス、キーボードを使用してRaspberry Piデスクトップを直接開き、VNCを設定することも便利です。
もしそれができない場合でも、SSHコマンドを使用してRaspberry PiのBashシェルを開き、コマンドを使ってVNCを設定することができます。

* :ref:`have_temp_monitor`
* :ref:`no_temp_monitor`


.. _have_temp_monitor:

仮のモニター（またはテレビ）を持っていますか？
---------------------------------------------------------------------

#. モニター（またはテレビ）、マウス、およびキーボードをRaspberry Piに接続し、電源を入れます。図の番号に従ってメニューを選択します。

   .. image:: img/mac_01.png
       :align: center

#. 次の画面が表示されます。 **インターフェース** タブで **VNC** を**有効**に設定し、 **OK** をクリックします。

   .. image:: img/mac_02.png
       :align: center

#. 画面の右上にVNCアイコンが表示され、VNCサーバーが起動します。

   .. image:: img/mac_03.png
       :align: center

#. **VNC**アイコンをクリックしてVNCサーバーウィンドウを開き、右上の **メニュー** ボタンをクリックして**オプション**を選択します。

   .. image:: img/mac_04.png
       :align: center

#. 次の画面が表示され、オプションを変更することができます。

   .. image:: img/mac_05.png
       :align: center

   **暗号化**を **オフにする** 、 **認証** を **VNCパスワード** に設定します。

#. **OK**ボタンをクリックすると、パスワード入力画面が表示されます。Raspberry Piのパスワードと同じもの、または別のパスワードを使用できますので、入力して **OK** をクリックします。

   .. image:: img/mac_06.png
       :align: center

   これでMacから接続する準備が整いました。モニターを取り外しても問題ありません。

**ここからはMac側の操作です。**

#. Finderのメニューから **サーバに接続** を選択します。右クリックで開くことができます。

   .. image:: img/mac_07.png
       :align: center

#. ``vnc://<username>@<hostname>.local``（または ``vnc://<username>@<IP address>`` ）を入力します。入力後、 **接続** をクリックします。

   .. image:: img/mac_08.png
       :align: center

#. パスワードを要求されるので、入力してください。

   .. image:: img/mac_09.png
       :align: center

#. Raspberry Piのデスクトップが表示され、Macから操作できるようになります。

   .. image:: img/mac_10.png
       :align: center



.. _no_temp_monitor:

仮のモニター（またはテレビ）がない場合
---------------------------------------------------------------------------

* SSHコマンドを使用してRaspberry PiのBashシェルを開くことができます。
* BashはLinuxの標準デフォルトシェルです。
* シェル自体は、ユーザーがUnix/Linuxを使用する際のコマンド（命令）です。
* 必要な操作のほとんどはシェルを通じて行うことができます。
* Raspberry Pi側の設定が完了したら、Macの**Finder**を使用してRaspberry Piのデスクトップにアクセスできます。


#. ``ssh <username>@<hostname>.local``と入力してRaspberry Piに接続します。

   .. code-block:: shell

       ssh pi@raspberrypi.local

   .. image:: img/mac_11.png


#. 初回ログイン時にのみ、以下のメッセージが表示されるので、 **yes** と入力します。

   .. code-block::

       The authenticity of host 'raspberrypi.local (2400:2410:2101:5800:635b:f0b6:2662:8cba)' can't be established.
       ED25519 key fingerprint is SHA256:oo7x3ZSgAo032wD1tE8eW0fFM/kmewIvRwkBys6XRwg.
       This key is not known by any other names
       Are you sure you want to continue connecting (yes/no/[fingerprint])?


#. Raspberry Piのパスワードを入力します。入力したパスワードは表示されないため、間違えないよう注意してください。

   .. code-block::

       pi@raspberrypi.local's password: 
       Linux raspberrypi 5.15.61-v8+ #1579 SMP PREEMPT Fri Aug 26 11:16:44 BST 2022 aarch64

       The programs included with the Debian GNU/Linux system are free software;
       the exact distribution terms for each program are described in the
       individual files in /usr/share/doc/*/copyright.

       Debian GNU/Linux comes with ABSOLUTELY NO WARRANTY, to the extent
       permitted by applicable law.
       Last login: Thu Sep 22 12:18:22 2022
       pi@raspberrypi:~ $ 


#. VNCを使用してMacからログインできるようにRaspberry Piを設定します。最初のステップは、次のコマンドを実行してオペレーティングシステムを更新することです。

   .. code-block:: shell

       sudo apt update
       sudo apt upgrade


   ``Do you want to continue? [Y/n]``と表示されたら、 ``Y`` と入力します。

   更新が完了するまでに時間がかかる場合があります。（その時点での更新の量に依存します。）


#. **VNCサーバー**を有効にするために、次のコマンドを入力します。

   .. code-block:: shell

       sudo raspi-config


#. 次の画面が表示されます。キーボードの矢印キーで **3 Interface Options** を選択し、 **Enter** キーを押します。

   .. image:: img/mac_12.png
       :align: center

#. 次に**VNC**を選択します。

   .. image:: img/mac_13.png
       :align: center

#. キーボードの矢印キーを使って **<Yes>** -> **<OK>** -> **<Finish>**を選択し、設定を完了します。

   .. image:: img/mac_14.png
       :align: center

#. VNCサーバーが起動したので、Macから接続するための設定を変更しましょう。

   すべてのユーザーアカウントのプログラムに対してパラメータを指定するには、 ``/etc/vnc/config.d/common.custom``を作成します。

   .. code-block:: shell

       sudo nano /etc/vnc/config.d/common.custom

   ``Authentication=VncAuthenter``を入力した後、 ``Ctrl+X`` -> ``Y`` -> ``Enter``を押して保存して終了します。

   .. image:: img/mac_15.png
       :align: center

#. さらに、MacからVNCでログインするためのパスワードを設定します。Raspberry Piのパスワードと同じもの、または別のパスワードを使用できます。

   .. code-block:: shell

       sudo vncpasswd -service

#. 設定が完了したら、変更を適用するためにRaspberry Piを再起動します。

   .. code-block:: shell

       sudo reboot

#. Finderのメニューから **サーバに接続** を選択します。右クリックで開くことができます。

   .. image:: img/mac_16.png
       :align: center

#. ``vnc://<username>@<hostname>.local``（または ``vnc://<username>@<IP address>``）を入力します。入力後、 **接続** をクリックします。

   .. image:: img/mac_17.png
       :align: center

#. パスワードを要求されるので、入力してください。

   .. image:: img/mac_18.png
       :align: center

#. Raspberry Piのデスクトップが表示され、Macから操作できるようになります。

   .. image:: img/mac_19.png
       :align: center
