//
//  Keymob.h
//  KeymobDemo
//
//  Created by keymob on 15-4-30.
//  Copyright (c) 2015年 keymob. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMBanner.h"
#import "KMBannerDelegate.h"
#import "KMInterstitial.h"
#import "KMInterstitialDelegate.h"
//#define KEYMOB_SDK_VERSION @"1.0.0"
#define KM_HTML_TEXT @"<html><head><meta charset=\"utf-8\"/><meta name=\"viewport\" content=\"user-scalable=no initial-scale=1.0\" /><style type=\"text/css\">        * {    margin: 0;    padding: 0;    border: 0;    outline: 0;    vertical-align: baseline;    background: transparent;    overflow:hidden;    -webkit-touch-callout: none;    -webkit-user-select: none;    -webkit-text-size-adjust: none; }      html,body { height: 100%; margin: 0;          }    a:link { text-decoration: none;}   div { width:100%; min-height:100%; text-align: center; color:white;   background-color:#0c77bd;} .default { background-color:silver;          }      .resized { background-color:grey;          }  </style></head><body style=\"margin:0;padding:0;border:0;overflow:hidden;-webkit-user-select: none;-webkit-text-size-adjust: none;\">"
#define KM_DEFAULT_HTML_TEXT @"<a href='http://www.keymob.com'><div align='center'>Keymob.com  manage ad in mobile app<br/>this is default offline ad</div></a></body></html>"

#define KM_AD_RESULT_HTML @"html"
#define KM_AD_RESULT_ERROR @"error"
#define KM_AD_RESULT_NO_AD @"noad"
#define KM_AD_RESULT_ALLHTML @"allhtml"

#define KM_AD_TYPES_BANNER 0
#define KM_AD_TYPES_INTERSTITIAL 1
#define KM_AD_TYPES_APPWALL 2
#define KM_AD_TYPES_VIDEO 3

#define KM_SIZE_320x50  CGSizeMake(320, 50)
#define KM_SIZE_320x100  CGSizeMake(320, 100)
#define KM_SIZE_300x250  CGSizeMake(300, 250)
#define KM_SIZE_468x60  CGSizeMake(468, 60)
#define KM_SIZE_728x90  CGSizeMake(728, 90)
#define KM_SIZE_120x600  CGSizeMake(120, 600)

@interface Keymob : NSObject
@property(nonatomic,copy) NSString* appID;
//@property(nonatomic,copy) NSString* webRoot;
@property(nonatomic,copy) NSString* requestPath;
@property(nonatomic,copy) NSString* configPath;
@property(nonatomic,copy) NSString* reportPath;
@property(nonatomic,copy) NSString* sdkVersion;
-(void)setWebRoot:(NSString*)_webRoot;
-(NSString*) webRoot;
+ (Keymob*)sharedInstance ;
@end
