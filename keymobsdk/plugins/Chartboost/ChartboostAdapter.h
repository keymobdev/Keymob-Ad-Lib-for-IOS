//
//  ChartboostAdapter.h
//  platformmanager
//
//  Created by keymob.com on 15-3-15.
//  Copyright (c) 2015 keymob. All rights reserved.
//
#import <KeymobAd/PlatformAdapter.h>
#import <KeymobAd/IPlatform.h>
#import "ChartboostAdapter.h"
//#import "PlatformAdapter.h"
//#import "IPlatform.h"
#import <Chartboost/Chartboost.h>
//#import "Chartboost.h"

@interface ChartboostAdapter : PlatformAdapter <IInterstitialPlatform,IVideoPlatform,IAppWallPlatform,ChartboostDelegate>

@end
