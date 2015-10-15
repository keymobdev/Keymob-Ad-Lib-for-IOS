//
//  BaiduAdapter.h
//  BaiduAdapter
//
//  Created by keymob on 15-7-14.
//  Copyright (c) 2015年 keymob. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <KeymobAd/IPlatform.h>
#import <KeymobAd/BannerPlatformAdapter.h>
#import "BaiduMobAdView.h"
#import "BaiduMobAdInterstitialDelegate.h"
#import "BaiduMobAdVideoView.h"
@interface BaiduAdapter : BannerPlatformAdapter <IInterstitialPlatform,IVideoPlatform,BaiduMobAdVideoDelegate,BaiduMobAdInterstitialDelegate,BaiduMobAdViewDelegate>

@end
