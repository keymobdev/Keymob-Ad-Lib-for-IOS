//
//  ViewController.m
//  platformmanager
//
//  Created by keymob.com on 15-3-15.
//  Copyright (c) 2015 keymob. All rights reserved.
//

#import "ViewController.h"

#import <KeymobAd/KeymobAd.h>
#import "AdEventListener.h"
@interface ViewController (){
    AdEventListener* listener;
    AdManager* adapter;
}

@end

@implementation ViewController
- (void)viewDidLoad {
    [super viewDidLoad];
    NSError* error;
    NSString* file= [[NSBundle mainBundle] pathForResource:@"ads" ofType:@"json"];
    NSString *textFileContents =[NSString stringWithContentsOfFile:file encoding:NSUTF8StringEncoding error:&error];
    
    adapter=[[AdManager alloc ]initWith:self andListener:[[AdEventListener alloc]init]];
    [adapter configWithJSON:textFileContents];
}

-(IBAction)onClickBanner:(id)sender{
    if([adapter conformsToProtocol:@protocol(IBannerPlatform)]){
        id<IBannerPlatform> banner=(id<IBannerPlatform>)adapter;
        [banner showRelationBanner:BANNER_SIZE_BANNER atPosition:BANNER_POSITIONS_TOP_RIGHT withOffY:0];
    }
}
-(IBAction)onClickBottomBanner:(id)sender{
    if([adapter conformsToProtocol:@protocol(IBannerPlatform)]){
        id<IBannerPlatform> banner=(id<IBannerPlatform>)adapter;
        [banner showRelationBanner:BANNER_SIZE_BANNER atPosition:BANNER_POSITIONS_BOTTOM_CENTER withOffY:50];
    }
}
-(IBAction)onClickABS:(id)sender{
    if([adapter conformsToProtocol:@protocol(IBannerPlatform)]){
        id<IBannerPlatform> banner=(id<IBannerPlatform>)adapter;
        [banner showBannerABS:BANNER_SIZE_BANNER atX:10 atY:200];
    }
}
-(IBAction)onClickFull:(id)sender{
    if([adapter conformsToProtocol:@protocol(IInterstitialPlatform)]){
        id<IInterstitialPlatform> platform=(id<IInterstitialPlatform>)adapter;
        if([platform isInterstitialReady]){
            [platform showInterstitial];
        }else{
            [platform loadInterstitial];
        }
    }
}
-(IBAction)onClickMore:(id)sender{
    if([adapter conformsToProtocol:@protocol(IAppWallPlatform)]){
        id<IAppWallPlatform> platform=(id<IAppWallPlatform>)adapter;
        if([platform isAppWallReady]){
            [platform showAppWall];
        }else{
            [platform loadAppWall];
        }
    }
}
-(IBAction)onClickVideo:(id)sender{
    if([adapter conformsToProtocol:@protocol(IVideoPlatform)]){
        id<IVideoPlatform> platform=(id<IVideoPlatform>)adapter;
        if([platform isVideoReady]){
            [platform showVideo];
        }else{
            [platform loadVideo];
        }
    }
}
-(IBAction)onClickHide:(id)sender{
    if([adapter conformsToProtocol:@protocol(IBannerPlatform)]){
        id<IBannerPlatform> banner=(id<IBannerPlatform>)adapter;
        [banner removeBanner];
    }
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
@end
