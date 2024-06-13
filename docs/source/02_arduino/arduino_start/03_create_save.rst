.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

スケッチの作成、開く、または保存方法
=======================================

#. Arduino IDEを初めて開くか新しいスケッチを作成すると、このようなページが表示されます。Arduino IDEは「スケッチ」と呼ばれる新しいファイルを作成します。

   .. image:: img/sp221014_173458.png

   これらのスケッチファイルには通常、作成日が分かる一時的な名前が付けられます。``sketch_oct14a.ino``は10月14日の最初のスケッチを意味し、``.ino``はこのスケッチのファイル形式です。

#. 次に、新しいスケッチを作成してみましょう。以下のコードをArduino IDEにコピーして、元のコードを置き換えてください。

   .. image:: img/create1.png

   .. code-block:: Arduino

       void setup() {
           // put your setup code here, to run once:
           pinMode(13,OUTPUT); 
       }

       void loop() {
           // put your main code here, to run repeatedly:
           digitalWrite(13,HIGH);
           delay(500);
           digitalWrite(13,LOW);
           delay(500);
       }

#. ``Ctrl+S``を押すか、 **File** -> **Save**をクリックします。スケッチはデフォルトで ``C:\Users\{your_user}\Documents\Arduino`` に保存されます。名前を変更するか、新しい保存場所を見つけることができます。

   .. image:: img/create2.png

#. 保存が成功すると、Arduino IDEの名前が更新されていることがわかります。

   .. image:: img/create3.png

次のセクションに進んで、この作成したスケッチをArduinoボードにアップロードする方法を学んでください。
