//
//  AdListener.m
//  KeymobDemo
//
//  Created by keymob.com on 15-5-21.
//  Copyright (c) 2015年 keymob. All rights reserved.
//

#import "AdListener.h"

@implementation AdListener 
- (void)onLoadedSuccess:(int) adtype withAdapter:(id<IPlatform>)adapter andData:(id)error{
    if(KM_AD_TYPES_INTERSTITIAL==adtype){
       [[AdManager sharedInstance] showInterstitial];
    }
    NSLog(@"onLoadedSuccess %@  %d",[adapter platformName],adtype);
}
- (void)onLoadedFail:(int) adtype withAdapter:(id<IPlatform>)adapter andData:(id)error{
     NSLog(@"onLoadedFail %@ %@ %d",error,[adapter platformName],adtype);
}
- (void)onAdOpened:(int) adtype withAdapter:(id<IPlatform>)adapter andData:(id)error{
    NSLog(@"onAdOpened %@ %@ %d",error,[adapter platformName],adtype);
}
- (void)onAdClosed:(int) adtype withAdapter:(id<IPlatform>)adapter andData:(id)error{
    NSLog(@"onAdClosed %@ %@ %d",error,[adapter platformName],adtype);
}
- (void)onAdClicked:(int) adtype withAdapter:(id<IPlatform>)adapter andData:(id)error{
    NSLog(@"onAdClicked %@ %@ %d",error,[adapter platformName],adtype);
}
- (void)onOtherEvent:(int) adtype withAdapter:(id<IPlatform>)adapter andData:(id)error eventName:(NSString*)_eventName{
    NSLog(@"onOtherEvent %@ %@ %d",error,[adapter platformName],adtype);
}
@end
