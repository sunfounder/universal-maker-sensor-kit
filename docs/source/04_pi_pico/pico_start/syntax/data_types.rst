.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

データ型
===========

組み込みデータ型
---------------------
MicroPythonには以下のデータ型があります：

* テキスト型: str
* 数値型: int, float, complex
* シーケンス型: list, tuple, range
* マッピング型: dict
* セット型: set, frozenset
* ブール型: bool
* バイナリ型: bytes, bytearray, memoryview

データ型の取得
-----------------------------
オブジェクトのデータ型を取得するには、 ``type()`` 関数を使用します：

.. code-block:: python

    a = 6.8
    print(type(a))

>>> %Run -c $EDITOR_CONTENT
<class 'float'>

データ型の設定
----------------------
MicroPythonでは、データ型を特に設定する必要はなく、変数に値を割り当てると自動的に決定されます。

.. code-block:: python

    x = "welcome"
    y = 45
    z = ["apple", "banana", "cherry"]

    print(type(x))
    print(type(y))
    print(type(z))

>>> %Run -c $EDITOR_CONTENT
<class 'str'>
<class 'int'>
<class 'list'>
>>> 

特定のデータ型の設定
----------------------------------

特定のデータ型を指定したい場合、次のコンストラクタ関数を使用できます：

.. list-table:: 
    :widths: 25 10
    :header-rows: 1

    *   - Example
        - Date Type
    *   - x = int(20)
        - int
    *   - x = float(20.5)
        - float
    *   - x = complex(1j)
        - complex
    *   - x = str("Hello World")
        - str
    *   - x = list(("apple", "banana", "cherry"))
        - list
    *   - x = tuple(("apple", "banana", "cherry"))
        - tuple
    *   - x = range(6)
        - range
    *   - x = dict(name="John", age=36)
        - dict
    *   - x = set(("apple", "banana", "cherry"))
        - set
    *   - x = frozenset(("apple", "banana", "cherry"))
        - frozenset
    *   - x = bool(5)
        - bool
    *   - x = bytes(5)
        - bytes
    *   - x = bytearray(5)
        - bytearray
    *   - x = memoryview(bytes(5))
        - memoryview

いくつかの結果を表示するために、いくつかの値を印刷してみます。

.. code-block:: python

    a = float(20.5)
    b = list(("apple", "banana", "cherry"))
    c = bool(5)

    print(a)
    print(b)
    print(c)

>>> %Run -c $EDITOR_CONTENT
20.5
['apple', 'banana', 'cherry']
True
>>> 

型変換
----------------
int(), float(), complex() メソッドを使用して、一つの型から別の型に変換できます。Pythonではコンストラクタ関数を使用してキャスティングを行います：

* int() - 整数リテラル、浮動小数点リテラル（小数をすべて削除）、または文字列リテラル（文字列が整数を表す場合）から整数を構築します。
* float() - 整数リテラル、浮動小数点リテラル、または文字列リテラル（文字列が浮動小数点または整数を表す場合）から浮動小数点数を構築します。
* str() - 文字列、整数リテラル、浮動小数点リテラルなど、さまざまなデータ型から文字列を構築します。

.. code-block:: python

    a = float("5")
    b = int(3.7)
    c = str(6.0)

    print(a)
    print(b)
    print(c)

注: 複素数を他の数値型に変換することはできません。
