//
//  GTDAdapter.h
//  GTDAdapter
//
//  Created by keymob on 15-8-10.
//  Copyright (c) 2015年 keymob. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GDTMobBannerView.h"
#import "GDTMobInterstitial.h"
#import <KeymobAd/KeymobAd.h>
#import <KeymobAd/BannerPlatformAdapter.h>
@interface GDTAdapter : BannerPlatformAdapter <IInterstitialPlatform,GDTMobBannerViewDelegate,GDTMobInterstitialDelegate>

@end
