# Beenos Analytics SDK for iOS

## 導入方法

同梱されているBeenosAnalytics.hとlibBeenosAnalytics.aをXCodeのプロジェクトにDrag&Drop。  
「Add to targets」の中で、SDKを利用するターゲットにチェックがついていることを確認してね。


## 使い方

まずはもらったAPI_KEYを使ってAppDelegate.mのdidFinishLaunchingWithOptionsで初期化します。


```objective-c
[[BeenosAnalytics sharedManager] bootstrap:@"YOUR_API_KEY"];
```

それ以降、イベントを飛ばしたい箇所で以下のように呼び出して下さい。

```objective-c
[[BeenosAnalytics sharedManager] track:@"hello"];
```

イベントの送信と同時にカスタムデータも送信したい場合は、以下のようにNSDictionaryを使います。

```objective-c
NSDictionary *custom_data = [NSDictionary dictionaryWithObjectsAndKeys:
                             @"world", @"hello",
                             [NSDictionary dictionaryWithObjectsAndKeys:
                              @"value1", @"sub1",
                              @"value2", @"sub2",
                              nil], @"hoge",
                             nil];

[[BeenosAnalytics sharedManager] track:@"boot"
                              custom_data:custom_data];
```

