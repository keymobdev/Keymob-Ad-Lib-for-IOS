//
//  BannerPlatformAdapter.h
//  platformmanager
//
//  Created by keymob.com on 15-3-15.
//  Copyright (c) 2015 keymob. All rights reserved.
//

#import "PlatformAdapter.h"
#import "Keymob.h"
@interface BannerPlatformAdapter : PlatformAdapter <IBannerPlatform>
{
    UIView* bannerView;
    int lastBannerType;
//  NSArray *usedConstraints;
}
-(CGSize) bannerSize:(int)bannerType;
- (void) initBanner:(int) sizeType withController:(UIViewController*) controller;
-(void) sendRequest:(int) sizeType;
- (void) addAdView:(UIView*)v toParent:(UIView*) pview atPosition:(int) position  offX:(int)_x offY:(int)_y ;
@end
