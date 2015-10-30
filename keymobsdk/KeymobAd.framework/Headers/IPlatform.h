//
//  IBannerPlatform.h
//  platformmanager
//
//  Created by keymob.com on 15-3-15.
//  Copyright (c) 2015 keymob. All rights reserved.
//

#ifndef popstar3_IBannerPlatform_h
#define popstar3_IBannerPlatform_h

#define KM_BANNER_POSITIONS_Absolute    0
#define KM_BANNER_POSITIONS_TOP_LEFT 1
#define KM_BANNER_POSITIONS_TOP_CENTER 2
#define KM_BANNER_POSITIONS_TOP_RIGHT 3
#define KM_BANNER_POSITIONS_MIDDLE_LEFT 4
#define KM_BANNER_POSITIONS_MIDDLE_CENTER 5
#define KM_BANNER_POSITIONS_MIDDLE_RIGHT 6
#define KM_BANNER_POSITIONS_BOTTOM_LEFT 7
#define KM_BANNER_POSITIONS_BOTTOM_CENTER 8
#define KM_BANNER_POSITIONS_BOTTOM_RIGHT 9


/**  320*50 **/
#define KM_SIZE_TYPE_BANNER 0
/**  468*60 **/
#define KM_SIZE_TYPE_FULL_BANNER  1
/**  320*100 **/
#define KM_SIZE_TYPE_LARGE_BANNER 2
/**  728*90 **/
#define KM_SIZE_TYPE_LEADERBOARD 3
/**  300*250 **/
#define KM_SIZE_TYPE_MEDIUM_RECTANGLE 4
/**  160*600 **/
#define KM_SIZE_TYPE_WIDE_SKYSCRAPER 5
/**  -1*-2 **/
#define KM_SIZE_TYPE_SMART_BANNER  6

#define KM_RATE_MODEL_PRIOIRITY 0
#define KM_RATE_MODEL_WEIGHT 1



#import <UIKit/UIKit.h>

static  NSString* EVENT_ON_LOADED_SUCCESS=@"onLoadedSuccess";
static NSString* EVENT_ON_LOADED_FAIL=@"onLoadedFail";
static NSString* EVENT_ON_AD_OPENED=@"onAdOpened";
static NSString* EVENT_ON_AD_CLOSED=@"onAdClosed"; ;
static NSString* EVENT_ON_AD_CLICKED=@"onAdClicked" ;
static NSString* EVENT_ON_OTHER_EVENT=@"onOtherEvent" ;

@protocol IPlatform


-(void) initPlatformWithKey1:(NSString*) key1 withKey2:(NSString*) key2 andParam:(NSString*) param;
-(NSString*) platformName;
@end

@protocol IAppWallPlatform
-(void) loadAppWall;
-(BOOL) isAppWallReady;
-(void) showAppWallWithController:(UIViewController*) controller;
@end


@protocol IInterstitialPlatform
-(void) loadInterstitial;
-(BOOL) isInterstitialReady;
-(void) showInterstitialWithController:(UIViewController*) controller;
@end


@protocol IVideoPlatform
-(void) loadVideo;
-(BOOL) isVideoReady;
-(void) showVideoWithController:(UIViewController*) controller;
@end

@protocol IBannerPlatform
-(void) showBannerABS:(int)sizeType atX:(int)_x atY:(int)_y withController:(UIViewController*) controller;
-(void) showRelationBanner:(int)sizeType atPosition:(int)_p withOffY:(int)_y withController:(UIViewController*) controller;
-(void) removeBanner;
@end

#endif
