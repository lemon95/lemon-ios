//
//  LoginViewController.m
//  monkeyDemo
//
//  Created by weisong on 16/5/18.
//  Copyright © 2016年 lemon95. All rights reserved.
//

#import "LoginViewController.h"
#import <LemonSDK/LemonSDK.h>

@interface LoginViewController ()

@end

@implementation LoginViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}
- (IBAction)loginBtnClick:(id)sender {
    //app使用过程中登录后同步用户
    [NMRegisterSDK checkAndUpdateUserWithMobile:@"15171494569" nickName:@"nn" faceUrl:@"" success:^(BOOL checkSuccess, NSError *error) {
        if (checkSuccess) {
            NSLog(@"success");
            //回到柠檬影视页面
            [NMRegisterSDK dismissWithViewController:self];
        } else {
            NSLog(@"error");
        }
    }];
    
//    [self dismissViewControllerAnimated:YES completion:nil];
}
- (IBAction)cancelBtnClick:(id)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
