
#ifndef KeymobDemo_KMBannerDelegate_h
#define KeymobDemo_KMBannerDelegate_h
@class KMBanner;
@protocol KMBannerDelegate <NSObject>

@optional

- (void)onBannerLoaded:(KMBanner*)banner;

- (void)onBannerView:(KMBanner *)banner didFailToReceiveAdWithError:(NSString *)error;

- (void)onBannerViewPresent:(KMBanner *)banner;

- (void)onBannerTouched:(KMBanner *)banner;

@end

#endif
