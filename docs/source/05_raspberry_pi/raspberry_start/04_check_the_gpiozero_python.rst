.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

``GPIO Zero``の確認
=================================

``GPIO Zero``はRaspberry PiのGPIOピンを制御するためのモジュールです。このパッケージは、Raspberry PiのGPIOを制御するための使いやすいクラスや関数を提供します。例やドキュメントについては、https://gpiozero.readthedocs.io/en/latest/ をご覧ください。

最新のRaspberry Pi OSには、デフォルトでGPIO Zeroが含まれています。インストールを確認するには、ターミナルを開いて以下を入力します：

.. code-block::

    python

.. image:: img/zero_01.png
    :width: 100%


次に、Python CLI内で ``import gpiozero`` と入力します。エラーが表示されなければ、GPIO Zeroが正常にインストールされています。

.. code-block::

    import gpiozero

.. image:: img/zero_02.png
    :width: 100%


Python CLIを終了したい場合は、以下を入力します：

.. code-block::

    exit()

.. image:: img/zero_03.png
    :width: 100%


