# BEENOS Analyticsで初めてのイベントをトラックする

## イベントとは？
ユーザーがサービスを利用する際に行う様々な行動やサービス内での出来事です。
主な例として、ページの閲覧、ボタンやリンクのクリックなど、サイトやアプリ内でのユーザーの動作に紐づきます。

例えば、e-コマースサービスで、ユーザーが商品をカートに入れる際に行うボタンクリックを「カートイン」と言うイベントで定義できます。この場合「カートイン」はイベント名となります。

## イベントをトラックするってどういうこと？
分析をする為にイベントをBEENOS Analyticsに送って記録する事です。


## 今すぐトラッキングタグを張ってみよう
トラックしたいイベントが起こるHTMLページの\<head>部分の一番下に（\</head>の真上）に以下のスクリプトをコピー＆ペーストし、ページ内のイベントをトラック出来る様にします。

###スクリプト
```
<script>
  (function(w, d, o, e, f){w['BAObject'] = o;w[o] = {};w[o].track = w[o].track || function() { (w[o].q = w[o].q || []).push(arguments) };w[o].init = w[o].init || function(t) { w[o].k = t; };e = d.createElement('script');e.type = 'text/javascript';e.async = 1;e.src = ("https:" === w.location.protocol ? "https:" : "http:") + '//api.beenos-analytics.com/ba.minified.js';f = d.getElementsByTagName('script')[0];f.parentNode.insertBefore(e, f)})(window, document, 'BeenosAnalytics');
  (function() {BeenosAnalytics.init('YOUR_TOKEN');})();
</script>
```

ページ内では、この位置に入れて下さい
```
<!DOCTYPE HTML>
<html lang="en-US">
  <head>
    <title>トップページ</title>
　　<script>
      (function(w, d, o, e, f){w['BAObject'] = o;w[o] = {};w[o].track = w[o].track || function() { (w[o].q = w[o].q || []).push(arguments) };w[o].init = w[o].init || function(t) { w[o].k = t; };e = d.createElement('script');e.type = 'text/javascript';e.async = 1;e.src = ("https:" === w.location.protocol ? "https:" : "http:") + '//api.beenos-analytics.com/ba.minified.js';f = d.getElementsByTagName('script')[0];f.parentNode.insertBefore(e, f)})(window, document, 'BeenosAnalytics');
      (function() {BeenosAnalytics.init('YOUR_TOKEN');})();
    </script>
  </head>
  <body>
  ...
  </body>
</html>
```

<b><font color='green'>YOUR_TOKEN</font></b>の部分は予め登録時にお送りしましたAPIトークンに書き換えて下さい。

これでページ内のイベントをトラックする準備ができました。次にイベントのトラッキングを行います。

###トラッキング
イベントは、ほんの数行のjavaScriptでBEENOS Analyticsに送る事が出来ます。
BeenosAnalytics.trackの関数をイベント名と任意のプロパティを指定して呼び出す事によってBEENOS Analyticsに送られます。

呼び出しのタグは以下の様な形になります
```
BeenosAnalytics.track("イベント名", {
  "プロパティ１": プロパティ１の値,
  "プロパティ２": プロパティ２の値,
  ...
});
```

実際の値を入れた例
```
BeenosAnalytics.track("カートイン", {
  "カテゴリー": ”靴”,
  "ブランド名" : "addidas"
});
```

上記例の”靴”や”addidas”の値の代わりにjavaScriptの変数を入れることも可能です
注：現在プロパティの値は10個程までの上限を付けるとより見やすく表示されます。
```
BeenosAnalytics.track("カートイン", {
  "カテゴリー": category,
  "ブランド名" : brand_name
});
```

プロパティを指定せずにイベントを送る事も出来ます。
```
BeenosAnalytics.track("詳細を見る");
```

ボタンクリック時にイベントを送る例
```
$("#detailsBtn").on("click", function(e) {
  BeenosAnalytics.track("詳細を見る")
});
```

ページ閲覧時にイベントを送る場合はタグを、先ほど入れたスクリプトの下に置きます。
```
<html lang="en-US">
  <head>
    <title>トップページ</title>
　　<script>
      (function(w, d, o, e, f){w['BAObject'] = o;w[o] = {};w[o].track = w[o].track || function() { (w[o].q = w[o].q || []).push(arguments) };w[o].init = w[o].init || function(t) { w[o].k = t; };e = d.createElement('script');e.type = 'text/javascript';e.async = 1;e.src = ("https:" === w.location.protocol ? "https:" : "http:") + '//api.beenos-analytics.com/ba.minified.js';f = d.getElementsByTagName('script')[0];f.parentNode.insertBefore(e, f)})(window, document, 'BeenosAnalytics');
      (function() {BeenosAnalytics.init('YOUR_TOKEN');})();

      BeenosAnalytics.track("トップページ閲覧")
    </script>
  </head>
  <body>
  ...
  </body>
</html>
```
