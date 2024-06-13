.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
1.2 Blynkの設定
==========================

#. `BLYNK <https://blynk.io/>`_ にアクセスし、 **START FREE** をクリックします。

   .. image:: img/sp220607_142551.png
        :width: 90%

   .. raw:: html

      <br/><br/>

#. メールアドレスを入力してアカウントを登録します。

   .. image:: img/sp220607_142807.png
        :width: 70%
        :align: center

   .. raw:: html

      <br/>

#. メールアドレスに届いたメールを確認し、アカウント登録を完了させます。

   .. image:: img/sp220607_142936.png
    :width: 90%

   .. raw:: html

      <br/><br/>

#. 登録後、 **Blynk Tour** が表示されます。これを読んでBlynkの基本情報を学びましょう。

   .. image:: img/sp220607_143244.png
    :width: 90%

   .. raw:: html

      <br/><br/>

#. 次に、この **Quick Start** でテンプレートとデバイスを作成する必要があります。 **Let's go** をクリックします。

   .. image:: img/sp220607_143608.png
    :width: 90%

   .. raw:: html

      <br/><br/>  

#. ハードウェアと接続タイプを選択します。

   .. image:: img/sp20220614173218.png
    :width: 90%

   .. raw:: html

      <br/><br/>

#. ここで準備する必要のあるIDEが示されています。 **Arduino IDE** をお勧めします。

   .. image:: img/sp20220614173454.png
    :width: 90%

   .. raw:: html

      <br/><br/>

#. ここでは追加する必要のあるライブラリが表示されていますが、推奨されているライブラリには問題があるため、手動で他のライブラリを追加する必要があります（後で説明します）。ここでは **Next** をクリックして、新しいテンプレートとデバイスを作成します。

   .. image:: img/sp20220614173629.png
    :width: 90%

   .. raw:: html

      <br/><br/>

#. 次のステップは関連するコードをアップロードし、ボードをBlynkに接続することですが、先ほど提供されたライブラリに問題があるため、再度他のライブラリを追加する必要があります。ここで **Cancel** をクリックして**Quick Start**を停止します。

   .. image:: img/sp20220614174006.png
    :width: 90%

   .. raw:: html

      <br/><br/>

#. **Search**ボタンをクリックすると、先ほど作成した新しいデバイスが表示されます。

   .. image:: img/sp20220614174410.png
    :width: 90%

   .. raw:: html

      <br/><br/>

#. この **Quickstart Device** にアクセスし、 **Device Info** をクリックすると、 **Device info** ページに ``TEMPLATE_ID`` 、 ``DEVICE_NAME`` 、 ``AUTH_TOKEN`` が表示されます。これらは後でコピーする必要があります。

   .. image:: img/sp20220614174721.png
    :width: 90%
