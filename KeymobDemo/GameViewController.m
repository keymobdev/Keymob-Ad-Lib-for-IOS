//
//  GameViewController.m
//  KeymobDemo
//
//  Created by zhouyingke on 15/10/29.
//  Copyright © 2015年 keymob. All rights reserved.
//

#import "GameViewController.h"
#import <KeymobAd/KeymobAd.h>
@interface GameViewController ()

@end

@implementation GameViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    NSLog(@"gameController %@",self);
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
-(IBAction)onClickBack:(id)sender{
    [self dismissViewControllerAnimated:YES completion:nil];
    //[self dismissModalViewControllerAnimated:YES];
}
-(IBAction)onClickShowBanner:(id)sender{
    [[AdManager sharedInstance] showRelationBanner:KM_SIZE_TYPE_BANNER atPosition:KM_BANNER_POSITIONS_BOTTOM_CENTER withOffY:0 withController:self];
}
-(IBAction)onClickHide:(id)sender{
    [[AdManager sharedInstance] removeBanner];
}
-(IBAction)onClickInterstitial:(id)sender{
    [AdManager sharedInstance].controller=self;
        if([[AdManager sharedInstance]  isInterstitialReady]){
            [[AdManager sharedInstance] showInterstitialWithController:self];
        }else{
            [[AdManager sharedInstance]  loadInterstitial];
        }
    
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
