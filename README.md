# keymob is an easy-to-use offline advertising management library
Keymob is used to  manage  ad advertising platforms of mobile applications, including ad impressions which platforms, the proportion of each platform, and other priorities.<br/>
Support admob, chartboost, inmobi.mmedia, amazon, iad by default,other common advertising platform will been  supported based on  feedback.<br/>
Support rich forms of advertising, including the current popular advertising banner with variety of sizes, rectange ads, Interstitial ads, video ads, more-app ad.<br/>
Config the ad ID , proportion, rate in json format , initialize keymob library. And then  use as a single platform.<br/>
json profile can put in their own web server or third-party management platform server.<br/>
Free choice of storage location and loading configuration files, avoid configuration file failed to load resulting in loss of revenue, but also to avoid third-party management platform, resulting in reduced revenue confusion.<br/>



## Usage

### 1. Download and install the library files
  Download keymob library KeymobAd.framework,  add it to the library path of android project<br/>
  Download advertising platform libraries, keymob supports many platforms, but only need to add your own advertising platform library used to xcode project.<br/>
   The following are the library files of each advertising platform<br/>
   * admob： GoogleMobileAds.framework<br/>
   * amazon:  AmazonAd.framework,AmazonInsightsSDK.framework<br/>
   * chartboost: cbsdk<br/>
   * mmedia：  MillennialMedia.framework,SpeechKit.framework<br/>
   * inmobi:  immobi<br/>

### 2.Add Code

#### a.add import
```
	#import <KeymobAd/KeymobAd.h>
```
Before using keymob, first import keymob related header files. Most of the core classes in <KeymobAd/KeymobAd.h> package, so you can import all at once. 
  
####  b.Setup and initialize keymob
```
	adapter=[[AdManager alloc ]initWith:self andListener:[[AdEventListener alloc]init]];
	[adapter configWithJSON:textFileContents];
```
The first parameter  is context controller, it as necessary, and can not be null.<br/>
  The second parameter is the config info of each platform in json string format,json format reference template.<br/>
  The third parameter is event listener of advertising,witch is a class that implements interface IAdEventListener, if you do not want to deal with advertising events, you can set it to null.<br/>

#### c. Display banner advertising
```
	[adapter showRelationBanner:BANNER_SIZE_BANNER atPosition:BANNER_POSITIONS_BOTTOM_CENTER withOffY:80];
```
The above means that displays the standard banner ad at the bottom of the device . The first parameter is the ad size, the type size can be const named BANNER_SIZE_XXX, including the standard banner, rectange banner, smart banner and so on.<br/>
  Other banner size outside  standard size(320*50) may have  small differences in the different platforms, run to see the effects.<br/>
  The second parameter is the position of the banner displayed,  the value const of each position is  name BANNER_POSITIONS_XXX,including the top left, top center, top right-hand and so on ,9 kinds of common position total.<br/>
  The third parameter is offsetY, i.e., the relative positional deviation, e.g., on the bottom of the application, the upward offset 80 pixels, that is, the effect of the above code. If you want to stick to the bottom of the application, set the offsetY 0.<br/>
 
####  d. display banner at Fixed location
```	
	[adapter showBannerABS:BANNER_SIZE_BANNER atX:10 atY:200];
```
The above code is display standard banner at point(0,200)<br/>
     Although the relative positioning to meet the needs of the majority of advertising location settings, but to meet the needs of some special position, keymob provides absolute fixed position display banner advertising api.<br/>
     The first parameter is the size of the banner, the second argument and third parameters are the position x and y values of banner.<br/>

####  e. Hide banne ad
```	
	[adapter removeBanner];
```
   "removeBanner" hidden banner advertising, but advertising will not be destroyed so show can be quickly presented to the user next time. Some advertising platform will continue to  load ad after hidden , so the event will dispatched also.<br/>
    
####  f. Load and display full-screen ads
```
	[adapter loadInterstitial];
```
   Load Interstitial ads, does not automatically show after load successfully, this can better control Interstitial ad at the right time to show to the user,<br/>
    If you want to show immediate after load,just handler onLoadedSuccess  in eventListener and call showInterstitial.<br/>
```
	[adapter showInterstitial];
```
   Display Interstitial advertising, ads will appear immediately after the call showInterstitial. However, please ensure that advertising has finished loading.
```
	[adapter isInterstitialReady]
```
   Check the Interstitial ad is loaded complete. If call showInterstitial directly when an ad  has not finished loading unpredictable events will occur, som advertising platform could lead to crash.<br/>
    So make sure the Interstitial is ready before every show.Below is the overall look.
```
   	if([adapter isInterstitialReady]){
		[adapter showInterstitial];
	}
```

#### g. Load and display video ads
```
	[adapter loadVideo];
```
  Load video ads, does not automatically show after load successfully, this can better control video ad at the right time to show to the user,<br/>
    If you want to show immediate after load,just handler onLoadedSuccess  in eventListener and call showVideo.
```
	[adapter showVideo];
```
   Display video ads, ads will appear immediately after the call showVideo. However, please ensure that advertising has finished loading.
```
	[adapter isVideoReady]
```
  Check the video ad is loaded complete. If call showVideo directly when an ad  has not finished loading unpredictable events will occur, some advertising platform could lead to crash.<br/>
    So make sure the video is ready before every show.Below is the overall look.
```
   	if([adapter isVideoReady]){
		[adapter showVideo];
	}
```
####  h. Application load and display more app advertising
```
	[adapter loadAppWall];
```
   Load more app ads, does not automatically show after load successfully, this can better control video ad at the right time to show to the user,<br/>
    If you want to show immediate after load,just handler onLoadedSuccess  in eventListener and call showAppWall.
```
	[adapter showAppWall];
```
   Display more app ads, ads will appear immediately after the call showAppWall. However, please ensure that advertising has finished loading.
```
	[adapter isAppWallReady]
```
   Check the More App ad is loaded complete. If call showAppWall directly when an ad  has not finished loading unpredictable events will occur, some advertising platform could lead to crash.<br/>
    So make sure the More App is ready before every show.Below is the overall look.
```
   	if([adapter isAppWallReady]){
		[adapter showAppWall];
	}
```

### 3.Advertising platform configuration file template
```
	{
		"isTesting":true,//Whether it is in test mode
		"rateModel":1,//0 said rate is  represents the weight of each platform ,1 said the rate is the order of each platform to display ads
		"platforms":[
		{"adapter":"AdmobAdapter","rate":90,"key1":"ca-app-pub-xxx/xxx","key2":"ca-app-pub-xxx/xxx","types":[0,1]},//admob  ,key1 banner ID，key2 Interstitial id
		{"adapter":"AmazonAdapter","rate":20,"key1":"xxx","types":[0,1]},//amazon ,key1 appkey
		{"adapter":"ChartboostAdapter","rate":40,"key1":"xxx","key2":"xxx","types":[1,2,3]},//chartboost ,key1 appID，key2 signature
		{"adapter":"InmobiAdapter","rate":50,"key1":"xxx","types":[0,1]},//inmobi ,key1 appid 
		{"adapter":"IadAdapter","rate":50,"types":[0,1]},//iad ,will be automatically ignored on android
		{"adapter":"MMediaAdapter","rate":50,"key1":"xxx","key2":"xxx","types":[0,1]}//mmedia ,key1 banner apID，key2 Interstitial apid
		]
	}
```
Depending rate model rate will become the sort number or proportion.All keyName in config can not been modified."adapter" can not be modified and "types" can not be modified. "adapter", said platform implement, types indicates that the platform supports the type of ad.<br/>
Using the platform of you  choice, delete unused platform. You can also add your own platforms, then config in the list. Create your own advertising platform extensions tutorials will gradually improve later.<br/>

project home https://github.com/keymobdev/-Keymob-Ad-Lib-for-IOS
android home https://github.com/keymobdev/Ad-Network-Mediation-lib-for-android