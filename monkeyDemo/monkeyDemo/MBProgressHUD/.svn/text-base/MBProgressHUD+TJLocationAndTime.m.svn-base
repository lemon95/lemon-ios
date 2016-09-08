//
//  MBProgressHUD+TJLocationAndTime.m
//  TJELife
//
//  Created by 宋欣鑫 on 15/12/17.
//  Copyright © 2015年 lemon95. All rights reserved.
//

#import "MBProgressHUD+TJLocationAndTime.h"

@implementation MBProgressHUD (TJLocationAndTime)
+(void)setUpCenterHUDWithText:(UIView *)view text:(NSString *)text location:(CGFloat)location time:(CGFloat)time
{
    MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:view animated:YES];
    //只显示文字
    hud.mode = MBProgressHUDModeText;
    
    hud.labelText = text;
    hud.labelFont = [UIFont systemFontOfSize:12];
    //相对view中心点y方向上的偏移
    hud.yOffset = location;
    //各元素与背景框边缘的间距
    hud.margin = 10.f;
    //背景框的圆角半径
    hud.cornerRadius = 4.f;
    
    [hud removeFromSuperViewOnHide];
    [hud hide:YES afterDelay:time];

}
@end
