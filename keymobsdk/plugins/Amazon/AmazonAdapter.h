//
//  AmazonAdapter.h
//  platformmanager
//
//  Created by keymob.com on 15-3-15.
//  Copyright (c) 2015 keymob. All rights reserved.
//
#import <KeymobAd/BannerPlatformAdapter.h>
//#import "BannerPlatformAdapter.h"
#import <AmazonAd/AmazonAdView.h>
#import <AmazonAd/AmazonAdRegistration.h>
#import <AmazonAd/AmazonAdOptions.h>
#import <AmazonAd/AmazonAdInterstitial.h>
@interface AmazonAdapter : BannerPlatformAdapter <IInterstitialPlatform,AmazonAdViewDelegate,AmazonAdInterstitialDelegate>

@end
