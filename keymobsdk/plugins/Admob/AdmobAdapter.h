//
//  AdmobAdapter.h
//  platformmanager
//
//  Created by keymob.com on 15-3-15.
//  Copyright (c) 2015 keymob. All rights reserved.
//

#import <KeymobAd/BannerPlatformAdapter.h>
#import <KeymobAd/IPlatform.h>
#import <GoogleMobileAds/GADInterstitial.h>
#import <GoogleMobileAds/GADBannerView.h>
@interface AdmobAdapter : BannerPlatformAdapter <IInterstitialPlatform,GADBannerViewDelegate,GADInterstitialDelegate>

@end
