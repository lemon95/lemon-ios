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
