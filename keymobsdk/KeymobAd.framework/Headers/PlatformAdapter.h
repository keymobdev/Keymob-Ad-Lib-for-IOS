//
//  PlatformAdapter.h
//  platformmanager
//
//  Created by keymob.com on 15-3-15.
//  Copyright (c) 2015 keymob. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "IAdEventListener.h"
#import "Keymob.h"
@interface PlatformAdapter : NSObject <IPlatform>{
    UIViewController* controller;
    NSString* key1;
    NSString* key2;
    NSString* dic;
}
@property (nonatomic, retain) id<IAdEventListener> listener;
@property (nonatomic,assign) BOOL isTesting;
-(NSArray*) resetKeys:(NSString*)_key1 withKey2:(NSString*) _key2 withKey3:(NSString*) _key3 withMD:(int) md5;
@end
