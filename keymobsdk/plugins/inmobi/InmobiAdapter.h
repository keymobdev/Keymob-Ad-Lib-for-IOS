//
//  InmobiAdapter.h
//  platformmanager
//
//  Created by keymob.com on 15-3-15.
//  Copyright (c) 2015 keymob. All rights reserved.
//
#import <KeymobAd/BannerPlatformAdapter.h>
//#import "BannerPlatformAdapter.h"
#import "IMInterstitialDelegate.h"
#import "IMBannerDelegate.h"
@interface InmobiAdapter : BannerPlatformAdapter <IInterstitialPlatform,IMInterstitialDelegate,IMBannerDelegate>

@end
