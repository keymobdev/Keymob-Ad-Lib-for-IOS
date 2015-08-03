//
//  PlatformConfigItem.h
//  platformmanager
//
//  Created by keymob.com on 15-3-15.
//  Copyright (c) 2015 keymob. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "IAdEventListener.h"
#import "PlatformAdapter.h"
@interface PlatformConfigItem : NSObject
@property(nonatomic,copy)  NSString* adapterName;
@property(nonatomic,assign) int rate;
@property(nonatomic,copy)  NSString*  key1;
@property(nonatomic,copy)  NSString*  key2;
@property(nonatomic,retain)  NSString*  param;

//@property(nonatomic,retain)  NSArray* adTypes;
@property(nonatomic,retain) PlatformAdapter* adapter;

-(void)initPlatform:(NSString*)_platformName withRate:(int) _rate withKey1:(NSString*) _key1 withKey2:(NSString*) _key2  withParam:(NSString*) _dic ;
@end
