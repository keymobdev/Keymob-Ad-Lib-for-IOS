//
//  KMInterstitialDelegate.h
//  KeymobDemo
//
//  Created by keymob on 15-5-5.
//  Copyright (c) 2015年 keymob. All rights reserved.
//

#ifndef KeymobDemo_KMInterstitialDelegate_h
#define KeymobDemo_KMInterstitialDelegate_h
@class KMInterstitial;
@protocol KMInterstitialDelegate <NSObject>

@optional

- (void)onInterstitialLoaded:(KMInterstitial*)interstitial;

- (void)onInterstitialView:(KMInterstitial *)interstitial didFailToReceiveAdWithError:(NSString *)error;

- (void)onInterstitialViewPresent:(KMInterstitial *)interstitial;

- (void)onInterstitialTouched:(KMInterstitial *)interstitial;

- (void)onInterstitialClosed:(KMInterstitial *)interstitial;

@end

#endif
