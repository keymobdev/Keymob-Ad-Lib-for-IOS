//
//  KMFullViewController.h
//  KeymobDemo
//
//  Created by keymob on 15-5-4.
//  Copyright (c) 2015年 keymob. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "KMBanner.h"
#import "KMInterstitialDelegate.h"
@interface KMInterstitial : UIViewController <KMBannerDelegate>
@property (nonatomic, strong) UIButton *interstitialSkipButton;
@property (nonatomic,strong) KMBanner *banner;
@property (strong,nonatomic )  id <KMInterstitialDelegate> delegate;
-(void) loadAd;
- (void) showAd:(UIViewController*) controller;
-(BOOL) isLoaded;
@end
