.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

How to create, open or Save the Sketch?
=======================================


#. When you open the Arduino IDE for the first time or create a new sketch, you will see a page like this, where the Arduino IDE creates a new file for you, which is called a "sketch".

   .. image:: img/sp221014_173458.png

   These sketch files have a regular temporary name, from which you can tell the date the file was created. ``sketch_oct14a.ino`` means October 14th first sketch, ``.ino`` is the file format of this sketch.

#. Now let's try to create a new sketch. Copy the following code into the Arduino IDE to replace the original code.


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

#. Press ``Ctrl+S`` or click **File** -> **Save**. The Sketch is saved in: ``C:\Users\{your_user}\Documents\Arduino`` by default, you can rename it or find a new path to save it.

   .. image:: img/create2.png

#. After successful saving, you will see that the name in the Arduino IDE has been updated.

   .. image:: img/create3.png

Please continue with the next section to learn how to upload this created sketch to your Arduino board.