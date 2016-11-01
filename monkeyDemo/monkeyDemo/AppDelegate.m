//
//  AppDelegate.m
//  monkeyDemo
//
//  Created by weisong on 16/4/8.
//  Copyright © 2016年 lemon95. All rights reserved.
//

#import "AppDelegate.h"
#import <VenvyVideoSDK/VenvyVideoSDK.h>
#import <LemonSDK/LemonSDK.h>
#import "LoginViewController.h"
#import "PayViewController.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    //注册appkey和渠道key，向柠檬方运营获取
    [NMRegisterSDK registerSdkWithAppKey:@"lemon_yz_sdkf" secretKey:@"dd53189e094440ddafba6baa6cdf5b92"];
    //设置播放器的APPKey，必须要设置的，通过运营部想柠檬方运营获取
    [VenvyVideoSDK setAppKey:@"NJgVo3B8-"];
    
    //设置 登录页面， 用于跳转登录
    [NMRegisterSDK loginViewController:[LoginViewController class]];
    //设置 选择支付方式页面， 用于调用支付时跳转
    [NMRegisterSDK payViewController:[PayViewController class]];
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
