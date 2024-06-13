.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _install_os:

Raspberry Pi OSをSDカードに書き込む
========================================

**ステップ1**

Raspberry Piチームは、Mac OS、Ubuntu 18.04、Windowsに対応したユーザーフレンドリーなグラフィカルSDカード書き込みツールを提供しています。これが最も便利なオプションで、多くのユーザーにとって、自動的にOSイメージをダウンロードしてSDカードにインストールします。

ダウンロードページにアクセスしてください：https://www.raspberrypi.org/software/。お使いのオペレーティングシステム用の **Raspberry Pi Imager** を選択します。ダウンロードが完了したら、開いてインストールを開始します。

.. image:: img/installing_01.png
    :align: center

.. raw:: html

    <br/>

**ステップ2**

インストーラーを起動すると、OSがセキュリティ警告を表示する場合があります。例えば、Windowsではこのメッセージが表示されることがあります：

.. image:: img/installing_02.png
    :align: center

.. raw:: html

    <br/>

この警告が表示された場合は、 **詳細情報** をクリックし、次に **実行** を選択します。画面の指示に従って、Raspberry Pi Imagerのインストールを完了します。


**ステップ3**

Imagerのインストールが完了したら、 **Raspberry Pi Imager** アイコンをクリックするか、 ``rpi-imager`` を実行してアプリケーションを開きます。

.. image:: img/installing_03.png
    :align: center

.. raw:: html

    <br/>

**ステップ4**

**Choose device**をクリックし、リストからRaspberry Piモデルを選択します。

.. image:: img/installing_04.png
    :align: center

.. raw:: html

    <br/>

**ステップ5**

次に、 **Choose OS** をクリックして、インストールするオペレーティングシステムを選択します。

.. image:: img/installing_05.png
    :align: center

.. raw:: html

    <br/>

**ステップ6**

microSDカードなどの希望するストレージ媒体を外部または内蔵のSDカードリーダーに挿入します。次に、"Choose Storage"をクリックしてデバイスを選択します。

.. note:: 

   **複数のデバイスが接続されている場合、正しいストレージデバイスを選択するようにしてください**。容量で区別できることが多いです。不明な場合は、他のデバイスを切断してください。 **選択したストレージデバイスにシステムをインストールすると、すべてのデータが消去されることに注意してください。**

.. image:: img/installing_06.png
    :align: center

.. raw:: html

    <br/>

**ステップ7**

**NEXT**ボタンを押し、 **EDIT SETTINGS** を選択して、OSカスタマイズページにアクセスします。

.. image:: img/installing_07.png
    :align: center

.. raw:: html

    <br/>


**ステップ8**

**ホスト名**を設定します。

.. note::

   ホスト名オプションは、Raspberry PiがmDNSを使用してネットワークにブロードキャストするホスト名を定義します。Raspberry Piをネットワークに接続することで、他のデバイスが ``<hostname>.local`` または ``<hostname>.lan`` を使用して相互作用できるようになります。

.. image:: img/installing_08.png
    :align: center

.. raw:: html

    <br/>

Raspberry Piの管理者アカウントの **ユーザー名** と **パスワード** を設定します。

.. note::
   Raspberry Piにはデフォルトのパスワードが設定されていないため、必ず設定してください。また、ユーザー名を個別に設定することも可能です。

.. image:: img/installing_09.png
    :align: center

.. raw:: html

    <br/>

ネットワークの **SSID** と **パスワード** を入力してワイヤレスLANを設定します。

.. note::

   "Wireless LAN country"を設定するには、あなたの国の2文字の|link_alpha2_code|を使用してください。

.. image:: img/installing_10.png
    :align: center

.. raw:: html

    <br/>

**ステップ9**

**SERVICES**ページに移動し、 **SSHオプションを有効にする** を選択してSSHを有効にし、「Use password authentication」を選択します（初心者に推奨）。変更を適用するには **Save** をクリックします。

.. image:: img/installing_11.png
    :align: center

.. raw:: html

    <br/>

**ステップ10**

**Yes**ボタンをクリックします。

.. image:: img/installing_12.png
    :align: center

.. raw:: html

    <br/>

**ステップ11**

SDカードにファイルが含まれている場合は、永久に失われないようにバックアップを検討してください。バックアップが不要な場合は、 **Yes** をクリックします。

.. image:: img/installing_13.png
    :align: center

.. raw:: html

    <br/>

**ステップ12**

書き込みプロセスが完了すると、以下のウィンドウが表示されます。書き込みプロセスには時間がかかり、SDカードの読み書き性能によって異なりますので、しばらくお待ちください。

.. image:: img/installing_14.png
    :align: center

.. raw:: html

    <br/>

