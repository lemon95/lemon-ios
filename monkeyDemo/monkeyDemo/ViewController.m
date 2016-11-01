//
//  ViewController.m
//  monkeyDemo
//
//  Created by weisong on 16/4/8.
//  Copyright © 2016年 lemon95. All rights reserved.
//

#import "ViewController.h"
#import <LemonSDK/LemonSDK.h>
#import "EntranceViewController.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UITextField *phoneView;
@property (weak, nonatomic) IBOutlet UITextField *nickNameView;

//@property (nonatomic, strong) testmonkey *test;
- (IBAction)btnClick:(id)sender;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    self.phoneView.layer.borderWidth = 1;
    self.phoneView.layer.borderColor = [[UIColor lightGrayColor] CGColor];
    self.nickNameView.layer.borderWidth = 1;
    self.nickNameView.layer.borderColor = [[UIColor lightGrayColor] CGColor];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)btnClick:(id)sender {
    
//    [NMRegisterSDK loadViewController:self];
    NSLog(@"%@--%@",self.phoneView.text, self.nickNameView.text);
    NSString *headUrl = @"http://tupian.lemon95.com:8088/Pictures/LemonUsers/2016-09-13/1473754962836.jpg";
    //登录成功时调用，用于同步用户
    [NMRegisterSDK checkAndUpdateUserWithMobile:self.phoneView.text nickName:self.nickNameView.text faceUrl:headUrl success:^(BOOL checkSuccess, NSError *error) {
        if (checkSuccess) {
            NSLog(@"success");
        } else {
            NSLog(@"error");
        }
    }];
    
    EntranceViewController *vc = [[EntranceViewController alloc] init];
    vc.modalTransitionStyle = UIModalTransitionStyleCrossDissolve;
    [self presentViewController:vc animated:YES completion:nil];
}

@end
