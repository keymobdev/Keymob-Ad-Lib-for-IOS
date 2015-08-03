//
//  IAdListener.h
//  platformmanager
//
//  Created by keymob.com on 15-3-15.
//  Copyright (c) 2015 keymob. All rights reserved.
//

#import "IPlatform.h"

#ifndef popstar3_IAdListener_h
#define popstar3_IAdListener_h
@protocol IAdEventListener
@required
- (void)onLoadedSuccess:(int) adtype withAdapter:(id<IPlatform>)adapter andData:(id)error;
- (void)onLoadedFail:(int) adtype withAdapter:(id<IPlatform>)adapter andData:(id)error;
- (void)onAdOpened:(int) adtype withAdapter:(id<IPlatform>)adapter andData:(id)error;
- (void)onAdClosed:(int) adtype withAdapter:(id<IPlatform>)adapter andData:(id)error;
- (void)onAdClicked:(int) adtype withAdapter:(id<IPlatform>)adapter andData:(id)error;
- (void)onOtherEvent:(int) adtype withAdapter:(id<IPlatform>)adapter andData:(id)error eventName:(NSString*)_eventName;
@end
#endif
