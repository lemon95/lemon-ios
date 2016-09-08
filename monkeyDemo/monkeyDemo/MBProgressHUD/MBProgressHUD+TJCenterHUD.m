//
//  MBProgressHUD+TJCenterHUD.m
//  TJELife
//
//  Created by 宋欣鑫 on 15/12/10.
//  Copyright © 2015年 lemon95. All rights reserved.
//

#import "MBProgressHUD+TJCenterHUD.h"

@implementation MBProgressHUD (TJCenterHUD)
+(void)setUpCenterHUDWithText:(UIView *)view text:(NSString *)text
{
    MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:view animated:YES];
    //只显示文字
    hud.mode = MBProgressHUDModeText;
    
    hud.detailsLabelText = text;
    hud.labelFont = [UIFont systemFontOfSize:12];
    //相对view中心点y方向上的偏移
    hud.yOffset = 0.f;
    //各元素与背景框边缘的间距
    hud.margin = 10.f;
    //背景框的圆角半径
    hud.cornerRadius = 4.f;
    
    [hud removeFromSuperViewOnHide];
    [hud hide:YES afterDelay:2.0];

}

+ (void)setUpBottomHUDWithView:(UIView *)view text:(NSString *)text
{
    MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:view animated:YES];
    //只显示文字
    hud.mode = MBProgressHUDModeText;
    
    hud.labelText = text;
    hud.labelFont = [UIFont systemFontOfSize:14];
    //相对view中心点y方向上的偏移
    hud.yOffset = view.center.y / 2.f;
    //各元素与背景框边缘的间距
    hud.margin = 10.f;
    //背景框的圆角半径
    hud.cornerRadius = 4.f;
    
    [hud removeFromSuperViewOnHide];
    [hud hide:YES afterDelay:2.0];
}

@end
