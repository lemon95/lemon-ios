//
//  NMRegisterSDK.h
//  LemonSDK
//
//  Created by weisong on 16/4/11.
//  Copyright © 2016年 lemon95. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NMRegisterSDK : NSObject

extern NSString *payOrderNotification;

//注册sdk
+ (void)registerSdkWithAppKey:(NSString *)appKey secretKey:(NSString *)secretKey;
/**
 *  检查更新用户
 *
 *  @param mobile   手机号
 *  @param nickName 用户昵称
 *  @param face     用户头像
 *  @param success  回调
 */
+ (void)checkAndUpdateUserWithMobile:(NSString *)mobile nickName:(NSString *)nickName faceUrl:(NSString *)face success:(void(^)(BOOL checkSuccess, NSError *error))success;

//跳转登录注册页面
+ (void)loginViewController:(Class)loginVC;
//返回影视页面
+ (void)dismissWithViewController:(UIViewController *)viewController;

/**
 *  present 进入影视模块
 *
 *  @param presentController present ViewController
 */
+ (void)loadViewController:(UIViewController *)presentController;

//跳转到支付页面
+ (void)payViewController:(Class)payVC;
//获取订单信息
+ (id)getOrderInfo;
//支付成功调用
+ (void)payState:(BOOL)state;

@end
