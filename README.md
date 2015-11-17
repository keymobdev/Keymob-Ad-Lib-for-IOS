### Keymob is a simple lib to manage ad 
Keymob can be very easy to use management  various advertising platforms in application, including which platform ad impressions, the proportion of each platform, setting priorities.<br/>
Support admob, chartboost, inmobi.mmedia, amazon, iad, baidu and other common advertising platform, more  platforms will been supported.<br/>
Support rich forms of advertising, including the popular  banner  a variety of sizes, rect ads, Interstitial ads, video ads, More APP Ad.<br/>
Ad config can been managed in  www.keymob.com ,  modify and adjust easy, you can config keymob with json format file , and then put it in  the project or on the website.<br/>




## Usage

### 1. Download and install the library files
To show ads on mobile application which needs to  added ad library in the application, the current version of Keymob advertisement  library is 20150801 . Keymob library is an ios project, most of it are  general ios project files, the following resources are Keymob related resources.
* README.md keymob English quickly integrate document
* README_ios_zh.md keymob Chinese quickly integrate document
* keymobsdk\KeymobAd.framework keymob core libraries
* keymobsdk\plugins keymob supported third-part platform SDK librarys<br/>
Without having to add a separate code for each platform after add keymob sdk.

Adding advertising management library  steps
* Right-click the xcode project, open the properties, select "Add File to Project" menu, add the directory "keymobsdk" to the Xcode project 
* Add Other Linker Flags value -fore_load
Other Linker Flags value which added items in the build tab -fore_load<br/>
Such as the use of Admob and Inmobi need to add the following items. Suppose "$ (SRCROOT) / keymobsdk / plugins / Admob" is the library path

```
-force_load $ (SRCROOT) /keymobsdk/plugins/Admob/libAdmobAdapter.a
-force_load $ (SRCROOT) /keymobsdk/plugins/inmobi/libInmobiAdapter.a
```
Note: If you do not add -force_load, will not show ads, log out message" not support platform"

### 2.Add Code

#### a.add import
```
	#import <KeymobAd/KeymobAd.h>
```
Before using keymob, first import keymob related header files. Most of the core classes in <KeymobAd/KeymobAd.h> header, so you can import all at once. 
  
####  b.Setup and initialize keymob
```
[AdManager sharedInstance].controller=self;
[AdManager sharedInstance].listener=[[AdListener alloc] init];
```
Set advertising display container and advertising event delegate, the first parameter is the context controller, the second argument is advertising delegate.
Then set up ad ID information of each advertising platform, there are two settings Keymob advertising messages ways, by json profile settings file
```
[[AdManager sharedInstance] configWithJSON: textFileContents];
```
Configuration parameters advertising json file format, you can find a  configuration file templates later.

Or by www.keymob.com service
```
[[AdManager sharedInstance] configWithKeymobService: @ "1" isTesting: YES]; // if you are debugging, set no if you are publish
```
The first parameter is the application ID, obtained from the www.keymob.com, the second parameter test mode,set  NO when release your app.



#### c. Display banner advertising
```
	[[AdManager sharedInstance] showRelationBanner:KM_SIZE_TYPE_BANNER atPosition:KM_BANNER_POSITIONS_TOP_CENTER withOffY:0 withController:self];
```
The above means that displays the standard banner ad at the bottom of the device . The first parameter is the ad size, the type size can be const named BANNER_SIZE_XXX, including the standard banner, rectange banner, smart banner and so on.<br/>
  Other banner size outside  standard size(320*50) may have  small differences in the different platforms, run to see the effects.<br/>
  The second parameter is the position of the banner displayed,  the value const of each position is  name BANNER_POSITIONS_XXX,including the top left, top center, top right-hand and so on ,9 kinds of common position total.<br/>
  The third parameter is offsetY, i.e., the relative positional deviation, e.g., on the bottom of the application, the upward offset 80 pixels, that is, the effect of the above code. If you want to stick to the bottom of the application, set the offsetY 0.<br/>
 
####  d. display banner at Fixed location
```	
	[[AdManager sharedInstance] showBannerABS:KM_SIZE_TYPE_BANNER atX:60 atY:40 withController:self];
```
The above code is display standard banner at point(0,200)<br/>
     Although the relative positioning to meet the needs of the majority of advertising location settings, but to meet the needs of some special position, keymob provides absolute fixed position display banner advertising api.<br/>
     The first parameter is the size of the banner, the second argument and third parameters are the position x and y values of banner.<br/>

####  e. Hide banne ad
```	
	[[AdManager sharedInstance] removeBanner];
```
   "removeBanner" hidden banner advertising, but advertising will not be destroyed so show can be quickly presented to the user next time. Some advertising platform will continue to  load ad after hidden , so the event will dispatched also.<br/>
    
####  f. Load and display full-screen ads
```
	[[AdManager sharedInstance] loadInterstitial];
```
   Load Interstitial ads, does not automatically show after load successfully, this can better control Interstitial ad at the right time to show to the user,<br/>
    If you want to show immediate after load,just handler onLoadedSuccess  in eventListener and call showInterstitial.<br/>
```
	[[AdManager sharedInstance] showInterstitial];
```
   Display Interstitial advertising, ads will appear immediately after the call showInterstitial. However, please ensure that advertising has finished loading.
```
	[[AdManager sharedInstance] isInterstitialReady]
```
   Check the Interstitial ad is loaded complete. If call showInterstitial directly when an ad  has not finished loading unpredictable events will occur, som advertising platform could lead to crash.<br/>
    So make sure the Interstitial is ready before every show.Below is the overall look.
```
   	if([[AdManager sharedInstance] isInterstitialReady]){
		[[AdManager sharedInstance] showInterstitialWithController:self];
	}
```

#### g. Load and display video ads
```
	[[AdManager sharedInstance] loadVideo];
```
  Load video ads, does not automatically show after load successfully, this can better control video ad at the right time to show to the user,<br/>
    If you want to show immediate after load,just handler onLoadedSuccess  in eventListener and call showVideo.
```
	[[AdManager sharedInstance] showVideo];
```
   Display video ads, ads will appear immediately after the call showVideo. However, please ensure that advertising has finished loading.
```
	[[AdManager sharedInstance] isVideoReady]
```
  Check the video ad is loaded complete. If call showVideo directly when an ad  has not finished loading unpredictable events will occur, some advertising platform could lead to crash.<br/>
    So make sure the video is ready before every show.Below is the overall look.
```
   	if([[AdManager sharedInstance] isVideoReady]){
		[[AdManager sharedInstance] showVideoWithController:self];
	}
```
####  h. Application load and display more app advertising
```
	[[AdManager sharedInstance] loadAppWall];
```
   Load more app ads, does not automatically show after load successfully, this can better control video ad at the right time to show to the user,<br/>
    If you want to show immediate after load,just handler onLoadedSuccess  in eventListener and call showAppWall.
```
	[[AdManager sharedInstance] showAppWall];
```
   Display more app ads, ads will appear immediately after the call showAppWall. However, please ensure that advertising has finished loading.
```
	[[AdManager sharedInstance] isAppWallReady]
```
   Check the More App ad is loaded complete. If call showAppWall directly when an ad  has not finished loading unpredictable events will occur, some advertising platform could lead to crash.<br/>
    So make sure the More App is ready before every show.Below is the overall look.
```
   	if([[AdManager sharedInstance] isAppWallReady]){
		[[AdManager sharedInstance] showAppWallWithController:self];
	}
```

### 3.Advertising platform configuration file template
```
	{
		"isTesting":true,//Whether it is in test mode
		"rateModel":1,//0 said priority is  represents the weight of each platform ,1 said the priority is the order of each platform to display ads
		"platforms":[
		{"class":"AdmobAdapter","priority":10,"key1":"ca-app-pub-xxx/xxx","key2":"ca-app-pub-xxx/xxx"},//admob  ,key1 banner ID，key2 Interstitial id
		{"class":"BaiduAdapter","priority":10,"key1":"apid","key2":"banner id","param":"{\"interstitialID\":\"interstitial ID\",\"videoID\":\"video ID\"}"},//baidu platform,param is a json string.remove video ID key value for ios
		{"class":"AmazonAdapter","priority":10,"key1":"xxx"},//amazon ,key1 appkey
		{"class":"ChartboostAdapter","priority":10,"key1":"xxx","key2":"xxx"},//chartboost ,key1 appID，key2 signature
		{"class":"InmobiAdapter","priority":10,"key1":"xxx","key2":"","param":" interstitial placement"},//inmobi ,key1 appid ,key2 banner placement,param interstitial placement
		{"class":"IadAdapter","priority":10,"key1":"appid"},//iad ,will be automatically ignored on android
		{"class":"GDTAdapter","priority":10,"key1":"appid","key2":"banner id", "param":"{\"interstitialID\":\"7030704170355254\",\"appWallID\":\"3090704100853287\"}"},//gdt platform
		{"class":"AdcolonyAdapter","priority":10,"key1":"appid","key2":"zone interstitia","param":"video zone"},//adcolony platform
		{"class":"MMediaAdapter","priority":10,"key1":"banner id","key2":"Interstitial id"}//mmedia ,key1 banner apID，key2 Interstitial apid
		]
	}
```
Depending rate model priority will become the sort number or proportion.All keyName in config can not been modified."class" is platform implement can not be modified<br/>


project home https://github.com/keymobdev/Keymob-Ad-Lib-for-IOS <br/>
android home https://github.com/keymobdev/keymob
wiki:https://github.com/keymobdev/Keymob-Ad-Lib-for-IOS/wiki/Common-Error-and-Solutions
qq group :310513042