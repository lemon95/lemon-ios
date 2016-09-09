# Lemon Video iOS SDK 
## 简介
该SDK中包含 lemonsdk、pptvsdk、libTVEngine、VenvyVideoSDK 四个SDK（libTVEngine、VenvyVideoSDK这两个是zip压缩文件，需要解压），SDK接入说明文档，monkeyDemo 是一个SDK接入的demo，可以运行查看SDK接入效果。
## 接入环境要求及配置
* 设备要求：iPhone 4S以上；系统要求：iOS7.0以上。运行环境：支持真机运行。
* 添加所需支持库：将 LemonSDK_v1.0.0 中的SDK导入到项目中，添加下面所列依赖库<br>
  `libc++.1.tbd`,
  `libiconv.tbd`,
  `libz.tbd`,
  `libxml2.tbd`,
  `libsqlite3.0.tbd`,
  `libstdc++.6.tbd`,
  `libstdc++.tbd`,
  `libbz2.tbd`,
  `libobjc.A.tbd`,
  `CoreTelephony.framework`,
  `SystemConfiguration.framework`,
  `OpenGLES.framework`,
  `QuartzCore.framework`,
  `Accelerate.framework`,
  `AudioToolbox.framework`,
  `CoreAudio.framework`,
  `MediaPlayer.framework`,
  `AdSupport.framework`,
  `AVFoundation.framework`,
  `CoreMedia.framework`,
  `WebKit.framework`,
  `MobileCoreServices.framework`,
  `Security.framework`,
  `CoreMotion.framework`,
  `CFNetwork.framework`,
  `CoreGraphics.framework`,
  `CoreText.framework`,
  `CoreLocation.framework`,
  `UIKit.framework`
* Other Linker Flags 设置为 –ObjC
* Info.plist中需要添加View controller-based status bar appearance，值为NO
* 不能使用bitcode，设置为no
* 在info plist中增加以下字段以便可以发送http请求:<br>
    `<key>NSAppTransportSecurity</key> <dict>`<br>
    `<key>NSAllowsArbitraryLoads</key><true/> </dict>`

##  接入方法
* 初始化SDK：联系柠檬运营提供相应的APP包名申请渠道key：SecretKey ，应用key：AppKey,播放器的key:vvAppKey;
在工程的AppDelegate.m 文件中引入头文件
```objectivec
  #import <VenvyVideoSDK/VenvyVideoSDK.h><br>
  #import <LemonSDK/LemonSDK.h>
  ```
      配置申请的相关key:
```objectivec
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
      //Override point for customization after application launch.
      ……
      [NMRegisterSDK registerSdkWithAppKey:@"应用key" secretKey:@"渠道key"];//设置AppKey 和 SecretKey
      [VenvyVideoSDK setAppKey:@"NJgVo3B8-"];//设置vvAppKey

      [NMRegisterSDK loginViewController:[LoginViewController class]];// 传入登录注册页的类名

      ……

      return YES;

}
```
* SDK的使用
  在app登录成功后调用柠檬的同步用户接口，传入用户手机号、昵称、头像路径，如果是游客，可传空值。
  引入头文件  `#import <LemonSDK/LemonSDK.h> `
  ```objectivec
  ……

    [NMRegisterSDK checkAndUpdateUserWithMobile:@“手机号” nickName:@“昵称” faceUrl:@“头像” success:^(BOOL checkSuccess, NSError *error) {        //手机号、昵称是必填的
        if (checkSuccess) {
            NSLog(@"success");
        } else {
            NSLog(@"error");
        }
    }];

    ……
  ```
  进入柠檬影视模块主页，在柠檬影视模块入口处调用方法：
  ```objectivec
  ……

    [NMRegisterSDK loadViewController:self];

  ……
  ```

## 用到的第三方框架及版本
AFNetworking-3.0.4以上、MJExtension-3.0.10以上、MJRefresh-3.1.0以上、SDWebImage-3.7.5以上、MBProgressHUD<br>影视模块内部有用到友盟统计进行统计相关数据，需要导入友盟SDK，当前用到的版本是v4.0.4。
