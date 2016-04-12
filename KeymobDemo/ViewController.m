#import "ViewController.h"
#import "AdListener.h"
#import <KeymobAd/KeymobAd.h>
@interface ViewController ()
{
}
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [AdManager sharedInstance].controller=self;
    [AdManager sharedInstance].listener=[[AdListener alloc]init];
   // [self configAdFromFile];
    
    [self configAdFromKeymobService];
      [[AdManager sharedInstance] showRelationBanner:KM_SIZE_TYPE_FULL_BANNER atPosition:KM_BANNER_POSITIONS_BOTTOM_CENTER withOffY:0 withController:self];
    //[[AdManager sharedInstance] loadInterstitial];
}
-(void) configAdFromKeymobService{
    [[AdManager sharedInstance] configWithKeymobService:@"1" isTesting:YES];//if you are debugging ,set auto cache no
}
-(void) configAdFromFile{
    NSError* error;
    NSString* file= [[NSBundle mainBundle] pathForResource:@"ads" ofType:@"json"];
    NSString *textFileContents =[NSString stringWithContentsOfFile:file encoding:NSUTF8StringEncoding error:&error];
    NSLog(@"---------%@",textFileContents);
    [[AdManager sharedInstance] configWithJSON:textFileContents];
}
-(IBAction)onClickButton:(id)sender{
    [[AdManager sharedInstance] showRelationBanner:KM_SIZE_TYPE_BANNER atPosition:KM_BANNER_POSITIONS_TOP_CENTER withOffY:0 withController:self];
}
-(IBAction)onClickHide:(id)sender{
        [[AdManager sharedInstance] removeBanner];
}
-(IBAction)onClickInterstitial:(id)sender{
    [AdManager sharedInstance].controller=self;
        if([[AdManager sharedInstance] isInterstitialReady]){
            [[AdManager sharedInstance] showInterstitialWithController:self];
        }else{
            [[AdManager sharedInstance] loadInterstitial];
        }
}
-(IBAction)onClickAppWall:(id)sender{
        if([[AdManager sharedInstance] isAppWallReady]){
            [[AdManager sharedInstance] showAppWallWithController:self];
        }else{
            [[AdManager sharedInstance] loadAppWall];
        }
}
-(IBAction)onClickVideo:(id)sender{
        if([[AdManager sharedInstance] isVideoReady]){
            [[AdManager sharedInstance] showVideoWithController:self];
        }else{
            [[AdManager sharedInstance] loadVideo];
        }
}
-(IBAction)onClickABSBanner:(id)sender{
        [[AdManager sharedInstance] showBannerABS:KM_SIZE_TYPE_LEADERBOARD atX:0 atY:280 withController:self];
}
-(IBAction)onClickGame:(id)sender{
    UIStoryboard *gameStroyBoard=[UIStoryboard storyboardWithName:@"Game" bundle:nil];
    UIViewController *gameController=[gameStroyBoard instantiateViewControllerWithIdentifier:@"game"];
    [self presentViewController:gameController animated:YES completion:nil];
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
