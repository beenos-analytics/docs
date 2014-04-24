# Android用SDK

## ビルド方法

教えない。


## 導入方法

- プロジェクトのlibs以下にBeenosAnalytics.jarを配置。

### 初期化（アプリ起動時に実行）

getInstanceの引数には、そのときのContextを指定して下さい。起動時ならばMainActivityになるはず。

```java
BeenosAnalytics sdk = BeenosAnalytics.getInstance(this);
sdk.bootstrap("YOUR_API_KEY");
```

## イベントの送信

イベント名だけ送信したい場合。

```java
BeenosAnalytics sdk = BeenosAnalytics.getInstance(this);
sdk.track("YOUR_EVENT_NAME");
```

イベント名以外のデータも送信したい場合はこちら。

```java
BeenosAnalytics sdk = BeenosAnalytics.getInstance(this);
sdk.track("YOUR_EVENT_NAME", new JSONObject().put("hello", "world"));
```
