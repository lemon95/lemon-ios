//
//  PPTVAccountSdk.h
//  PPTVSdkDemo
//
//  Created by pptv on 16/6/20.
//  Copyright © 2016年 PPTV. All rights reserved.
//

#import <Foundation/Foundation.h>


@protocol PPTVAccountDelegate <NSObject>

@optional

- (void)phoneGetCodeSuccess;
- (void)phoneGetCodeFailed:(NSString *)message;

- (void)phoneRegisterSuccess;
- (void)phoneRegisterFailed:(NSString *)message;

- (void)phoneLoginSuccessWithVipInfo:(BOOL)yesOrNo;
- (void)phoneLoginFailed:(NSString *)message;

@end


@interface PPTVAccountSdk : NSObject

@property (nonatomic, weak) id <PPTVAccountDelegate> delegate;

/* 根据手机号码发送验证码 */
- (void)sendCodeWithPhoneNum:(NSString *)phoneNum;

/* 用户注册 */
- (void)registerWithPhoneNum:(NSString *)phoneNum password:(NSString *)password code:(NSString *)code;

/* 用户登陆 */
- (void)loginWithPhoneNum:(NSString *)phoneNum password:(NSString *)password tunnel:(NSString *)tunnel;


@end
