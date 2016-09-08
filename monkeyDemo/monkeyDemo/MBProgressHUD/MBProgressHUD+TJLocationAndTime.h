//
//  MBProgressHUD+TJLocationAndTime.h
//  TJELife
//
//  Created by 宋欣鑫 on 15/12/17.
//  Copyright © 2015年 lemon95. All rights reserved.
//

#import "MBProgressHUD.h"

@interface MBProgressHUD (TJLocationAndTime)
+(void)setUpCenterHUDWithText:(UIView *)view text:(NSString *)text location:(CGFloat )location time:(CGFloat )time;
@end
