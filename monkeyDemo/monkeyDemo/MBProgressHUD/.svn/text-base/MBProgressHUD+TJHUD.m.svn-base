//
//  MBProgressHUD+TJHUD.m
//  TJELife
//
//  Created by weisong on 15/12/1.
//  Copyright (c) 2015年 lemon95. All rights reserved.
//

#import "MBProgressHUD+TJHUD.h"

@implementation MBProgressHUD (TJHUD)

+ (void)setUpHUDWithText:(UIView *)view text:(NSString *)text
{
    MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:view animated:YES];
    //只显示文字
    hud.mode = MBProgressHUDModeText;
    
    hud.labelText = text;
    hud.labelFont = [UIFont systemFontOfSize:12];
    //相对view中心点y方向上的偏移
    hud.yOffset = 170.f;
    //各元素与背景框边缘的间距
    hud.margin = 10.f;
    //背景框的圆角半径
    hud.cornerRadius = 4.f;
    
    [hud removeFromSuperViewOnHide];
    [hud hide:YES afterDelay:2.0];
}

@end
