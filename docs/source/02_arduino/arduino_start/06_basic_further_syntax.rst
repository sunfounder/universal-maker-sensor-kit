.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

スケッチの書き方のルール
================================

友達にライトをつけてもらうように頼む場合、「ライトをつけて。」や「ライトオン、兄弟。」など、どんな言い方でもできます。

しかし、Arduinoボードに何かをさせたい場合は、Arduinoプログラムの書き方のルールに従ってコマンドを入力する必要があります。

この章では、Arduino言語の基本ルールを説明し、自然言語をコードに翻訳する方法を理解する手助けをします。

もちろん、これは慣れるまでに時間がかかるプロセスであり、初心者にとって最もエラーが発生しやすい部分でもありますので、間違えることがあっても大丈夫です。何度か試してみてください。


セミコロン ``;``
-----------------

手紙を書くときに各文の最後にピリオドを書くように、Arduino言語ではコマンドの終わりを示すために``;``を使用します。

おなじみの「オンボードLEDの点滅」の例を取り上げます。正常なスケッチは次のようになります。

例:

.. code-block:: C

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

次に、以下の二つのスケッチを見て、それらが実行される前にArduinoに正しく認識されるかどうかを考えてみましょう。

スケッチA:

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH)
        delay(500)
        digitalWrite(13,LOW)
        delay(500)
    }

スケッチB:

.. code-block:: C
    :emphasize-lines: 8,9,10,11,12,13,14,15,16

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
    }
    
    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,
    HIGH);  delay
        (500
        );
        digitalWrite(13,
        
        LOW);
                delay(500)
        ;
    }

結果は、 **Sketch A** はエラーを報告し、 **Sketch B** は実行されます。

* **スケッチA**のエラーは ``;`` が欠けていることで、見た目は正常ですが、Arduinoはそれを読み取ることができません。
* **スケッチB**は見た目が不自然ですが、実際にはインデント、改行、および文のスペースはArduinoプログラムには存在しないため、Arduinoコンパイラには例と同じように見えます。

しかし、**スケッチB**のようにコードを書かないでください。通常、人間がコードを書いて見ますので、自分を困らせないようにしましょう。


中括弧 ``{}``
------------------

``{}``はArduinoプログラミング言語の主要な構成要素であり、必ずペアで出現しなければなりません。
より良いプログラミングの習慣として、左中括弧を入力した後にすぐに右中括弧を入力し、中括弧の間にカーソルを移動してステートメントを挿入することをお勧めします。


コメント ``//``
---------------

コメントはコンパイラが無視するスケッチの一部です。通常、プログラムの動作を他の人に伝えるために使用されます。

コード行に二つのスラッシュを連続して書くと、コンパイラは行の終わりまでの部分を無視します。

新しいスケッチを作成すると、二つのコメントが付いてきますが、これら二つのコメントを削除してもスケッチには何の影響もありません。

.. code-block:: C
    :emphasize-lines: 2,7

    void setup() {
        // put your setup code here, to run once:

    }

    void loop() {
        // put your main code here, to run repeatedly:

    }


コメントはプログラミングで非常に便利で、以下にいくつかの一般的な使用例を示します。

* 使用例A: このコードの部分が何をするかを自分や他人に伝える。

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); //Set pin 13 to output mode, it controls the onboard LED
    }

    void loop() {
        digitalWrite(13,HIGH); // Activate the onboard LED by setting pin 13 high
        delay(500); // Status quo for 500 ms
        digitalWrite(13,LOW); // Turn off the onboard LED
        delay(500);// Status quo for 500 ms
    }
* スケッチB:一時的にいくつかの文を無効にして（削除せずに）、必要に応じてコメントを解除することで、再度書き直す手間を省くことができます。これは、コードのデバッグやプログラムのエラーを特定しようとする際に非常に便利です。


.. code-block:: C
    :emphasize-lines: 3,4,5,6

    void setup() {
        pinMode(13,OUTPUT);        
        // digitalWrite(13,HIGH);
        // delay(1000);
        // digitalWrite(13,LOW);
        // delay(1000);
    }
    
    void loop() {
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }
.. note:: 
    ショートカット ``Ctrl+/`` を使用すると、コードを素早くコメントアウトまたはコメント解除することができます。

コメント ``/**/` `
------------------

コメントとして ``//`` と同じですが、このタイプのコメントは複数行にわたることができます。コンパイラが ``/*`` を読み取ると、 ``*/`` に出会うまでそれ以降のすべてを無視します。

例1:

.. code-block:: C
    :emphasize-lines: 1,8,9,10,11

    /* Blink */

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        /*
        The following code will blink the onboard LED
        You can modify the number in delay() to change the blinking frequency
        */
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }


``#define``
--------------

これは便利なC++ツールです。

.. code-block:: C

    #define identifier token-string

コンパイラが ``identifier`` を読み取ると、自動的に ``token-string`` に置き換えます。これは通常、定数の定義に使用されます。

例として、コードの可読性を向上させるためにdefineを使用したスケッチを紹介します。

.. code-block:: C
    :emphasize-lines: 1,2

    #define ONBOARD_LED 13
    #define DELAY_TIME 500

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
        delay(DELAY_TIME); 
        digitalWrite(ONBOARD_LED,LOW); 
        delay(DELAY_TIME);
    }

コンパイラには、実際には次のように見えます。

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }

``identifier``が置き換えられ、プログラム内には存在しないことがわかります。
したがって、使用する際にはいくつかの注意点があります。

1. ``token-string``は手動でのみ変更可能であり、プログラム内で算術により他の値に変換することはできません。

2. ``;``などの記号の使用を避けてください。例えば。

.. code-block:: C
    :emphasize-lines: 1

    #define ONBOARD_LED 13;

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
    }

コンパイラは次のように認識し、エラーとして報告されます。

.. code-block:: C
    :emphasize-lines: 2,6

    void setup() {
        pinMode(13;,OUTPUT); 
    }

    void loop() {
        digitalWrite(13;,HIGH); 
    }

.. note:: 
    ``#define``の命名規則として、変数と混同しないように ``identifier`` を大文字にすることをお勧めします。
