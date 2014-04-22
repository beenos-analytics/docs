# BEENOS Analyticsで初めてのイベントをトラックする

## イベントとは？
ユーザーがサービスを利用する際に行う様々な行動やサービス内での出来事です。
主な例として、ページの閲覧、ボタンやリンクのクリックなど、サイトやアプリ内でのユーザーの動作に紐づきます。

例えば、e-コマースサービスで、ユーザーが商品をカートに入れる際に行うボタンクリックを「カートイン」と言うイベントで定義できます。この場合「カートイン」はイベント名となります。

## イベントをトラックするってどういうこと？
分析をする為にイベントをBEENOS Analyticsに送って記録する事です。


## 今すぐトラッキングタグを張ってみよう
トラックしたいイベントが起こるHTMLページの<head>部分の一番下に（</head>の真上）
に以下のスクリプトをコピー＆ペーストし、ページ内のイベントをトラック出来る様にします。

###スクリプト
```
<script>
      function(w, d, o, e, f){ w['BAObject'] = o; w[o] = {}; w[o].track = w[o].track || function() { (w[o].q = w[o].q || []).push(arguments) }; w[o].init = w[o].init || function(t) { w[o].k = t; }; e = d.createElement('script'), e.type = 'text/javascript'; f = d.getElementsByTagName('script')[0]; e.async = 1; e.src = ('https:' === w.location.protocol ? 'https:' : 'http:') + '//#{@hostname}/ba.minified.js'; f.parentNode.insertBefore(e, f)})(window, document, 'BeenosAnalytics');
      (function() { BeenosAnalytics.init('<b><font color='green'>YOUR_TOKEN</font></b>'); })();
</script>
```

ページ内では、この位置に入れて下さい
```
<!DOCTYPE HTML>
<html lang="en-US">
  <head>
    <title>トップページ</title>
　　<script>
      function(w, d, o, e, f){ w['BAObject'] = o; w[o] = {}; w[o].track = w[o].track || function() { (w[o].q = w[o].q || []).push(arguments) }; w[o].init = w[o].init || function(t) { w[o].k = t; }; e = d.createElement('script'), e.type = 'text/javascript'; f = d.getElementsByTagName('script')[0]; e.async = 1; e.src = ('https:' === w.location.protocol ? 'https:' : 'http:') + '//#{@hostname}/ba.minified.js'; f.parentNode.insertBefore(e, f)})(window, document, 'BeenosAnalytics');
      (function() { BeenosAnalytics.init('<b><font color='green'>YOUR_TOKEN</font></b>'); })();
    </script>
  <head>
  <body>
  ...
  </body>
</html>
```

<b><font color='green'>YOUR_TOKEN</font></b>の部分は予め登録時にお送りしましたAPIトークンに書き換えて下さい。

これでページ内のイベントをトラックする準備ができました。次にイベントのトラッキングを行います。

イベントは、ほんの数行のjavaScriptでBEENOS Analyticsに送る事が出来ます。
BeenosAnalytics.trackの関数をイベント名と任意のプロパティを指定して呼び出す事によってBEENOS Analyticsに送られます。

