.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
Arduinoプログラムの構造
===========================

新しいスケッチファイルを見てみましょう。いくつかのコード行が含まれていますが、実際には「空」のスケッチです。このスケッチを開発ボードにアップロードしても何も起こりません。

.. code-block:: C

    void setup() {
    // put your setup code here, to run once:

    }

    void loop() {
    // put your main code here, to run repeatedly:

    }

もし ``setup()`` と ``loop()`` を削除してスケッチを本当に ``blank`` のファイルにすると、検証を通過しないことがわかります。これらは人体の骨格に相当し、欠かせないものです。

スケッチ作成時に、まず ``setup()`` が実行され、その中のコード（ ``{}`` 内のコード）がボードの電源が入るかリセットされた後に一度だけ実行されます。 ``loop()`` はメインの機能を記述するために使われ、 ``setup()`` が実行された後に繰り返し実行されます。

setup()とloop()をより理解するために、4つのスケッチを使ってみましょう。これらの目的は、ArduinoのオンボードLEDを点滅させることです。各実験を順に実行し、その具体的な効果を記録してください。

* スケッチ1: オンボードLEDを連続的に点滅させる。

.. code-block:: C
    :emphasize-lines: 8,9,10,11

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

* スケッチ2: オンボードLEDを一度だけ点滅させる。

.. code-block:: C
    :emphasize-lines: 4,5,6,7

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

    void loop() {
        // put your main code here, to run repeatedly:
    }

* スケッチ3: オンボードLEDを一度ゆっくり点滅させた後、速く点滅させる。

.. code-block:: C
    :emphasize-lines: 4,5,6,7,12,13,14,15

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(1000);
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }    

* スケッチ4: エラーを報告する。

.. code-block:: C
    :emphasize-lines: 6,7,8,9

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
    }

    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);

    void loop() {
        // put your main code here, to run repeatedly:
    }    

これらのスケッチを使って、 ``setup-loop`` のいくつかの特徴をまとめることができます。

* ``loop()``はボードの電源が入ると繰り返し実行されます。
* ``setup()``はボードの電源が入ると一度だけ実行されます。
* ボードの電源が入ると、まず ``setup()`` が実行され、その後 ``loop()`` が実行されます。
* コードは ``setup()`` または ``loop()`` の ``{}`` 内に記述する必要があり、このフレームワーク外に記述するとエラーになります。

.. note::  
    ``digitalWrite(13,HIGH)``のようなステートメントはオンボードLEDを制御するために使用され、詳細は後の章で説明します。

