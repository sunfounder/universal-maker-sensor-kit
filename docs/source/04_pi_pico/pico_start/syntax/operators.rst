.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

演算子
============

演算子は、変数や値に対する操作を実行するために使用されます。

* :ref:`Arithmetic operators` （算術演算子）
* :ref:`Assignment operators` （代入演算子）
* :ref:`Comparison operators` （比較演算子）
* :ref:`Logical operators` （論理演算子）
* :ref:`Identity operators` （同一性演算子）
* :ref:`Membership operators` （メンバーシップ演算子）
* :ref:`Bitwise operators` （ビット演算子）

算術演算子
----------------------
算術演算子を使用して、一般的な数学的操作を行うことができます。

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - 演算子
        - 名前
    *   - ``+``
        - 加算
    *   - ``-``
        - 減算
    *   - ``*``
        - 乗算
    *   - ``/``
        - 除算
    *   - ``%``
        - 剰余
    *   - ``**``
        - 累乗
    *   - ``//``
        - 切り捨て除算




.. code-block:: python

    x = 5
    y = 3

    a = x + y
    b = x - y
    c = x * y
    d = x / y
    e = x % y
    f = x ** y
    g = x // y

    print(a)
    print(b)
    print(c)
    print(d)
    print(e)
    print(f)
    print(g)

>>> %Run -c $EDITOR_CONTENT
8
2
15
1.666667
2
125
1
8
2
15
>>> 
代入演算子
---------------------

代入演算子は、変数に値を割り当てるために使用されます。

.. list-table:: 
    :widths: 10 30 30
    :header-rows: 1

    *   - 演算子
        - 例
        - 同じ意味
    *   - ``=``
        - a = 6
        - a =6
    *   - ``+=``
        - a += 6
        - a = a + 6
    *   - ``-=``
        - a -= 6
        - a = a - 6
    *   - ``*=``
        - a \*= 6
        - a = a * 6
    *   - ``/=``
        - a /= 6
        - a = a / 6
    *   - ``%=``
        - a %= 6
        - a = a % 6
    *   - ``**=``
        - a \*\*= 6
        - a = a ** 6
    *   - ``//=``
        - a //= 6
        - a = a // 6
    *   - ``&=``
        - a &= 6
        - a = a & 6
    *   - ``|=``
        - a \|= 6
        - a = a | 6
    *   - ``^=``
        - a ^= 6
        - a = a ^ 6
    *   - ``>>=``
        - a >>= 6
        - a = a \>\> 6
    *   - ``<<=``
        - a <<= 6
        - a = a << 6



.. code-block:: python

    a = 6

    a *= 6
    print(a)

>>> %Run test.py
36
>>> 

比較演算子
------------------------
比較演算子は、2つの値を比較するために使用されます。

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - 演算子
        - 名称
    *   - ``==``
        - 等しい
    *   - ``!=``
        - 等しくない
    *   - ``<``
        - より小さい
    *   - ``>``
        - より大きい
    *   - ``>=``
        - 以上
    *   - ``<=``
        - 以下


.. code-block:: python

    a = 6
    b = 8

    print(a > b)

>>> %Run test.py
False
>>> 

**a** が **b** より小さいため、**False** が返されます。

論理演算子
-----------------------

論理演算子は、条件文を組み合わせるために使用されます。

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - 演算子
        - 説明
    *   - ``and``
        - 両方の文が真の場合にTrueを返します
    *   - ``or``
        - いずれかの文が真の場合にTrueを返します
    *   - ``not``
        - 結果を反転させ、結果が真の場合はFalseを返します

.. code-block:: python

    a = 6
    print(a > 2 and a < 8)

>>> %Run -c $EDITOR_CONTENT
True
>>> 

同一性演算子
------------------------

同一性演算子は、オブジェクトが等しいかどうかではなく、実際に同じオブジェクトかどうか、つまり同じメモリ位置にあるかどうかを比較するために使用されます。

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - 演算子
        - 説明
    *   - ``is``
        - 両方の変数が同じオブジェクトである場合にTrueを返します
    *   - ``is not``
        - 両方の変数が同じオブジェクトでない場合にTrueを返します

.. code-block:: python

    a = ["hello", "welcome"]
    b = ["hello", "welcome"]
    c = a

    print(a is c)
    # returns True because z is the same object as x

    print(a is b)
    # returns False because x is not the same object as y, even if they have the same content

    print(a == b)
    # returns True because x is equal to y

>>> %Run -c $EDITOR_CONTENT
True
False
True
>>> 
メンバーシップ演算子
----------------------
メンバーシップ演算子は、シーケンスがオブジェクトに存在するかどうかをテストするために使用されます。

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - 演算子
        - 説明
    *   - ``in``
        - 指定された値のシーケンスがオブジェクト内に存在する場合にTrueを返します
    *   - ``not in``
        - 指定された値のシーケンスがオブジェクト内に存在しない場合にTrueを返します

.. code-block:: python

    a = ["hello", "welcome", "Goodmorning"]

    print("welcome" in a)

>>> %Run -c $EDITOR_CONTENT
True
>>> 

ビット演算子
------------------------

ビット演算子は、（バイナリ）数値を比較するために使用されます。

.. list-table:: 
    :widths: 10 20 50
    :header-rows: 1

    *   - 演算子
        - 名前
        - 説明
    *   - ``&``
        - AND
        - 両方のビットが1の場合に各ビットを1に設定します
    *   - ``|``
        - OR
        - 2つのビットのうち1つが1の場合に各ビットを1に設定します
    *   - ``^``
        - XOR
        - 2つのビットのうち1つだけが1の場合に各ビットを1に設定します
    *   - ``~``
        - NOT
        - すべてのビットを反転させます
    *   - ``<<``
        - ゼロフィル左シフト
        - 右からゼロを押し込み、左端のビットを切り捨てて左にシフトします
    *   - ``>>``
        - 符号付き右シフト
        - 左から左端のビットのコピーを押し込み、右端のビットを切り捨てて右にシフトします

.. code-block:: python

    num = 2

    print(num & 1)
    print(num | 1)
    print(num << 1)

>>> %Run -c $EDITOR_CONTENT
0
3
4
>>>