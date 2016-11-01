//
//  PayViewController.m
//  monkeyDemo
//
//  Created by weisong on 16/10/31.
//  Copyright © 2016年 lemon95. All rights reserved.
//

#import "PayViewController.h"
#import <LemonSDK/NMRegisterSDK.h>

@interface PayViewController ()

@end

@implementation PayViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    
    //获取订单信息(订单号)
    NSDictionary *orderInfo = [NMRegisterSDK getOrderInfo];
    NSLog(@"%@", orderInfo);
    
    UIButton *successBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    successBtn.backgroundColor = [UIColor redColor];
    [successBtn setTitle:@"支付成功" forState:UIControlStateNormal];
    [successBtn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [successBtn addTarget:self action:@selector(paySuccess) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:successBtn];
    successBtn.frame = CGRectMake(20, 80, self.view.frame.size.width - 40, 50);
    
    UIButton *cancelBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    cancelBtn.backgroundColor = [UIColor redColor];
    [cancelBtn setTitle:@"取消支付" forState:UIControlStateNormal];
    [cancelBtn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [cancelBtn addTarget:self action:@selector(payCancel) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:cancelBtn];
    cancelBtn.frame = CGRectMake(20, CGRectGetMaxY(successBtn.frame) + 40, self.view.frame.size.width - 40, 50);
    
}

- (void)paySuccess
{
    //支付成功返回状态（一定要调用）
    [NMRegisterSDK payState:YES];
    [self dismissViewControllerAnimated:YES completion:nil];
    
}

- (void)payCancel
{
    //支付失败或取消支付返回状态（一定要调用）
    [NMRegisterSDK payState:NO];
    
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
