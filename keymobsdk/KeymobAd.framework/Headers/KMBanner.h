//
//  KMBanner.h
//  KeymobDemo
//
//  Created by keymob on 15-4-30.
//  Copyright (c) 2015年 keymob. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "KMBannerDelegate.h"


@class KMRequest;
@class KMResponse;

@interface KMBanner : UIView <UIWebViewDelegate,NSURLSessionDelegate>

@property (strong,nonatomic )  id <KMBannerDelegate> delegate;
@property(nonatomic,strong) KMResponse *response;
@property(nonatomic,strong) KMRequest *request;
@property(nonatomic,strong) UIWebView *bannerWebView;
-(void) setBannerSize:(CGSize) size;
- (void) loadAd;
-(void) doINIT;
-(void) displayAdContent;
-(BOOL) isBannerLoaded;
@end
