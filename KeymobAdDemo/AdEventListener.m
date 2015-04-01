//
//  AdEventListener.m
//  platformmanager
//
//  Created by keymob.com on 15-3-15.
//  Copyright (c) 2015 keymob. All rights reserved.
//

#import "AdEventListener.h"

@implementation AdEventListener
- (void)onLoadedSuccess:(int) adtype withAdapter:(id<IPlatform>)adapter andData:(id)error{
    NSLog(@"AdEventListener---------onLoadSuccess  %@ adtype:%d %@",[adapter platformName],adtype,error);
    if(adtype==AD_TYPES_INTERSTITIAL){
        id<IInterstitialPlatform> platform=(id<IInterstitialPlatform>)adapter;
        [platform showInterstitial];
    }
}
- (void)onLoadedFail:(int) adtype withAdapter:(id<IPlatform>)adapter andData:(id)error{
     NSLog(@"AdEventListener--------onLoadedFail  %@ adtype:%d %@",[adapter platformName],adtype,error);
}
- (void)onAdOpened:(int) adtype withAdapter:(id<IPlatform>)adapter andData:(id)error{
     NSLog(@"AdEventListener-------onAdOpened  %@ adtype:%d %@",[adapter platformName],adtype,error);
}
- (void)onAdClosed:(int) adtype withAdapter:(id<IPlatform>)adapter andData:(id)error{
     NSLog(@"AdEventListener-------onAdClosed  %@ adtype:%d %@",[adapter platformName],adtype,error);
}
- (void)onAdClicked:(int) adtype withAdapter:(id<IPlatform>)adapter andData:(id)error{
     NSLog(@"AdEventListener------onAdClicked  %@ adtype:%d %@",[adapter platformName],adtype,error);
}
- (void)onOtherEvent:(int) adtype withAdapter:(id<IPlatform>)adapter andData:(id)error eventName:(NSString*)_eventName{
     NSLog(@"AdEventListener--------onOtherEvent  %@ adtype:%d %@  ename:%@",[adapter platformName],adtype,error,_eventName);
}
@end
