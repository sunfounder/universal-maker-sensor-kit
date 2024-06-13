.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

Linux/Unixユーザー向け
==========================

#. Linux/Unixシステムで**ターミナル**を見つけて開きます。

#. Raspberry Piが同じネットワークに接続されていることを確認します。次のコマンドを入力して確認します： ``ping <hostname>.local``。例：

   .. code-block::

       ping raspberrypi.local

   ネットワークに接続されている場合、Raspberry PiのIPアドレスが表示されます。

   * ターミナルが ``Ping request could not find host pi.local. Please check the name and try again.``のようなメッセージを表示する場合、入力したホスト名を再確認してください。
   * IPアドレスを取得できない場合は、Raspberry PiのネットワークまたはWiFi設定を確認してください。

#. ``ssh <username>@<hostname>.local`` または ``ssh <username>@<IP address>`` と入力してSSH接続を開始します。例：

   .. code-block::

       ssh pi@raspberrypi.local

#. 初回ログイン時にセキュリティメッセージが表示されます。続行するには ``yes`` と入力します。

   .. code-block::

       The authenticity of host 'raspberrypi.local (2400:2410:2101:5800:635b:f0b6:2662:8cba)' can't be established.
       ED25519 key fingerprint is SHA256:oo7x3ZSgAo032wD1tE8eW0fFM/kmewIvRwkBys6XRwg.
       Are you sure you want to continue connecting (yes/no/[fingerprint])?

#. 以前に設定したパスワードを入力します。セキュリティ上の理由から、パスワードは入力中に表示されません。

   .. note::
       ターミナルにパスワードの文字が表示されないのは正常です。正しいパスワードを入力してください。

#. 正常にログインできれば、Raspberry Piに接続され、次のステップに進む準備が整いました。

