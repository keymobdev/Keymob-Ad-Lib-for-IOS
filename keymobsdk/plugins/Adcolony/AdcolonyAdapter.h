//
//  AdcolonyAdapter.h
//  AdcolonyAdapter
//
//  Created by keymob on 15-8-10.
//  Copyright (c) 2015年 keymob. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <KeymobAd/KeymobAd.h>
#import <AdColony/AdColony.h>
@interface AdcolonyAdapter : PlatformAdapter <IInterstitialPlatform,IVideoPlatform,AdColonyDelegate,AdColonyAdDelegate>

@end
