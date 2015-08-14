#import "ViewController.h"
#import "AdListener.h"
#import <KeymobAd/KeymobAd.h>
@interface ViewController ()
{
    AdManager* adManager;
    
}
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
//    [Keymob sharedInstance].webRoot=@"http://192.168.0.100/";
    adManager=[AdManager sharedInstance];

    [adManager setController:self andListener:[[AdListener alloc]init]];
   // [self configAdFromFile];
    
       [self configAdFromKeymobService];
}
-(void) configAdFromKeymobService{
    [adManager configWithKeymobService:@"1" isTesting:YES];//if you are debugging ,set auto cache no
}
-(void) configAdFromFile{
    NSError* error;
    NSString* file= [[NSBundle mainBundle] pathForResource:@"ads" ofType:@"json"];
    NSString *textFileContents =[NSString stringWithContentsOfFile:file encoding:NSUTF8StringEncoding error:&error];
    NSLog(@"---------%@",textFileContents);
    [adManager configWithJSON:textFileContents];
}
-(IBAction)onClickButton:(id)sender{
    if(adManager!=nil){
        [adManager showRelationBanner:KM_SIZE_TYPE_BANNER atPosition:KM_BANNER_POSITIONS_TOP_CENTER withOffY:0];
    }
}
-(IBAction)onClickHide:(id)sender{
    if(adManager!=nil){
        [adManager removeBanner];
    }
}
-(IBAction)onClickInterstitial:(id)sender{
    if(adManager!=nil){
        if([adManager isInterstitialReady]){
            [adManager showInterstitial];
        }else{
            [adManager loadInterstitial];
        }
    }
}
-(IBAction)onClickAppWall:(id)sender{
    if(adManager!=nil){
        if([adManager isAppWallReady]){
            [adManager showAppWall];
        }else{
            [adManager loadAppWall];
        }
    }
}
-(IBAction)onClickVideo:(id)sender{
    if(adManager!=nil){
        if([adManager isVideoReady]){
            [adManager showVideo];
        }else{
            [adManager loadVideo];
        }
    }
}
-(IBAction)onClickABSBanner:(id)sender{
    if(adManager!=nil){
        [adManager showBannerABS:KM_SIZE_TYPE_BANNER atX:60 atY:40];
    }
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
