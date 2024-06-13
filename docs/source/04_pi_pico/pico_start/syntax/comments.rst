.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
コメント
=============

コード内のコメントはコードの理解を助け、全体を読みやすくし、テスト中に一部のコードをコメントアウトして、その部分が実行されないようにします。

単一行コメント
----------------------------

MicroPythonの単一行コメントは # で始まり、行の終わりまでのテキストがコメントとして扱われます。コメントはコードの前後に配置できます。

.. code-block:: python

    print("hello world") #This is a annotationhello world

>>> %Run -c $EDITOR_CONTENT
hello world

コメントは必ずしもコードを説明するためのテキストである必要はありません。コードの一部をコメントアウトしてMicroPythonがそのコードを実行しないようにすることもできます。

.. code-block:: python

    #print("Can't run it！")
    print("hello world") #This is a annotationhello world

>>> %Run -c $EDITOR_CONTENT
hello world

複数行コメント
------------------------------

複数行にわたるコメントを記述する場合、複数の # 記号を使用できます。

.. code-block:: python

    #This is a comment
    #written in
    #more than just one line
    print("Hello, World!")

>>> %Run -c $EDITOR_CONTENT
Hello, World!

または、期待される動作とは異なるかもしれませんが、複数行の文字列をコメントの代わりに使用することもできます。

MicroPythonは変数に割り当てられていない文字列リテラルを無視するため、コード内に複数行の文字列（三重引用符）を追加し、その中にコメントを入れることができます。

.. code-block:: python

    """
    This is a comment
    written in
    more than just one line
    """
    print("Hello, World!")

>>> %Run -c $EDITOR_CONTENT
Hello, World!

文字列が変数に割り当てられていない限り、MicroPythonはそれを無視し、複数行コメントとして扱います。
