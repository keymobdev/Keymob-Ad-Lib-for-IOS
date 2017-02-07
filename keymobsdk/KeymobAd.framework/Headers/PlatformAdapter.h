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
@interface PlatformAdapter : NSObject <IPlatform,NSURLSessionDelegate>{
    
    NSString* key1;
    NSString* key2;
    NSString* paramString;
}
@property (nonatomic, retain) id<IAdEventListener> listener;
@property (nonatomic,assign) BOOL isTesting;
//@property  UIViewController* controller;
-(void) resetKeys:(NSString*)_key1 withKey2:(NSString*) _key2 withKey3:(NSString*) _key3 withMD:(int) md5;
@end
