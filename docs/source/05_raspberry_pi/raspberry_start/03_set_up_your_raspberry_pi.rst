.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _set_up_your_raspberry_pi:

Raspberry Piのセットアップ
============================

スクリーンがある場合
-------------------------

スクリーンがあれば、Raspberry Piの操作が簡単になります。

**必要なコンポーネント**

* いずれかのRaspberry Pi   
* 1 * 電源アダプター
* 1 * Micro SDカード
* 1 * スクリーン用電源アダプター
* 1 * HDMIケーブル
* 1 * スクリーン
* 1 * マウス
* 1 * キーボード

#. Raspberry Pi OSをセットアップしたSDカードをRaspberry Piの底面にあるmicro SDカードスロットに挿入します。

#. マウスとキーボードを接続します。

#. スクリーンをRaspberry PiのHDMIポートに接続し、スクリーンがコンセントに差し込まれ、電源が入っていることを確認します。

   .. note::
   
      Raspberry Pi 4を使用する場合、スクリーンをHDMI0（電源ポートに最も近い）に接続する必要があります。

#. 電源アダプターを使用してRaspberry Piに電源を供給します。数秒後、Raspberry Pi OSのデスクトップが表示されます。

   .. image:: img/set_up_01.png
       :align: center
   
   .. raw:: html
   
       <br/>

#. Raspberry Piシステムでウェブブラウザーを起動し、このチュートリアルページにアクセスできます。これにより、指示をコピーしてターミナルで実行するのが便利です。

   .. image:: img/set_up_02.png
       :align: center
   
.. raw:: html
   
   <br/>

.. _no_screen:

スクリーンがない場合
--------------------------

モニターがない場合、リモートでRaspberry Piにログインできます。

**必要なコンポーネント**

* いずれかのRaspberry Pi   
* 1 * 電源アダプター
* 1 * Micro SDカード

SSHコマンドを使用してRaspberry PiのBashシェルにアクセスできます。BashシェルはLinuxのデフォルトインターフェースであり、Unix/Linuxシステム上でシンプルなコマンドでほとんどのタスクを実行できます。

Raspberry Piにコマンドラインを使いたくない場合、リモートデスクトップ機能を利用して専用のスクリーンなしでRaspberry Piのデスクトップ環境を操作できます。

各システムの詳細なチュートリアルは以下を参照してください。


.. toctree::
   :maxdepth: 1

   03_a_remote_macosx
   03_b_remote_windows
   03_c_remote_linux

