keymob 是一个简单易用的广告管理库。
使用keymob能非常方便的管理应用中各个广告平台的广告，包括展示哪些平台的广告，各个平台的比例，优先顺序等。
支持admob,baidu,chartboost,inmobi.mmedia,amazon,iad,广点通，adcolony等常用广告平台，后面会根据大家的反馈加入更多的常见平台的支持。
广告形式支持丰富，包括各种尺寸的banner广告，方块广告，全屏广告，视频广告，应用墙广告等当前流行的广告。
开发者可以通过www.keymob.com 远程配置管理各个广告平台的广告ID
也可以使用时把各个平台的广告ID和比例优先级顺序等信息按json格式配置，初始化keymob库 ，json配置文件可以放项目里，自己的网站服务器或者第三方管理平台服务器。

交流群：310513042

使用方法

1.下载安装库文件
要在手机应用里面展示广告需要在应用里面添加广告管理库，Keymob广告管理库目前的版本是20150801 下载解压后可以看到ios工程的目录结构，大部分是常规的ios工程文件和目录，下面资源是Keymob管理库相关的。 下载广告管理库
README.md keymob 英文快速集成文档
README_ios_zh.md keymob 中文快速集成文档
keymobsdk
KeymobAd.framework keymob 核心库
plugins keymob 支持的各个平台的SDK库
除上面下载的资源外，使用keymob官方支持的平台，无需再单独添加各个平台的代码


添加使用广告管理库需要下面几步骤
右击xcode工程，打开属性，选择"添加文件到工程" 菜单，把keymobsdk目录添加到Xcode工程中
在build tab下 Other Linker Flags 值里面添加 -fore_load 项
例如使用了Admob平台和Inmobi平台需要添加如下项。$(SRCROOT)/keymobsdk/plugins/Admob 是库路径，根据自己保存Keymob SDK的路径调整。

	-force_load $(SRCROOT)/keymobsdk/plugins/Admob/libAdmobAdapter.a
	-force_load $(SRCROOT)/keymobsdk/plugins/inmobi/libInmobiAdapter.a

注意：如果不加-force_load将看不到第三方广告，提示not support platform


2.添加 代码
  a.添加引用

	#import <KeymobAd/KeymobAd.h>

    使用keymob前，先import keymob的相关头文件。keymob的大部分核心类在<KeymobAd/KeymobAd.h>文件中，所以可以一次全部引入。
  
 b.设置和初始化各个广告平台信息

	[[AdManager sharedInstance] setController:self andListener:[[AdListener alloc]init]];

	设置广告显示的容器和广告事件处理代理，第一个参数是controller上下文，第二个参数是广告处理代理类
	然后再设置各个广告平台的广告ID信息，设置Keymob广告信息有俩种方法，通过json配置文件设置

	[[AdManager sharedInstance] configWithJSON:textFileContents];
        参数是json格式的广告信息配置文件，具体样式可以参考后面的配置文件模板

	或者通过www.keymob.com服务器端配置信息设置广告

	[[AdManager sharedInstance] configWithKeymobService:@"1" isTesting:YES];//if you are debugging ,set no if you are publish 

	第一个参数是应用ID，从www.keymob.com 获得，第二个参数设置是否当前为测试模式，发布的时候改成NO

 c. banner广告的展示 

	[[AdManager sharedInstance] showRelationBanner:BANNER_SIZE_BANNER atPosition:BANNER_POSITIONS_BOTTOM_CENTER withOffY:80];

    上面的意思是在设备的底部显示显示标准banner广告。
    第一个参数是广告尺寸，尺寸是以BANNER_SIZE_XXX命名的常量列表，包括标准banner，方块，smart banner等。
    标准banner之外的其他banner尺寸根据平台不同有细微的差别，具体效果可以运行观察。
    第二个参数是广告条展示的位置，包括顶端靠左，顶端居中，顶端靠右等等9种常见位置，各个位置的值是以BANNER_POSITIONS_XXX命名的常量。
    第三个参数是offsetY，即相对位置偏移，例如放在应用的底端，向上偏移80个像素，就是上面的代码效果。如果要贴到应用最底端，则偏移为0.
 
 d. 固定位置展示banner
	
	[[AdManager sharedInstance] showBannerABS:BANNER_SIZE_BANNER atX:10 atY:200];

    上面是在x 10,y 200位置展示标准banner
    虽然相对定位能满足大部分的广告位置设置需求，但为满足某些特殊位置的需要，keymob提供了绝对固定位置展示banner广告的接口。
    第一个参数是banner的尺寸，同相对广告尺寸，第二个参数和第三个参数分别是广告位置的x和y值

 e. 隐藏banne广告
	
	[[AdManager sharedInstance] removeBanner];

    removeBanner会隐藏广告，但是广告并不会销毁，这样再次展示时能迅速的展示给用户。有些广告平台会在隐藏后继续加载广告，在AdEventListener里面还会收到抛出的事件。
    
 f. 全屏广告的加载和展示

	[[AdManager sharedInstance] loadInterstitial];

   加载全屏广告，广告加载成功后不会自动展示，这样能更好的控制全屏广告在合适的时机展示给用户，
   如果要在加载成功时立即展示可以在 eventlistener的 onLoadedSuccess事件中调用showInterstitial展示广告。

	[[AdManager sharedInstance] showInterstitial];

   展示全屏广告，调用showInterstitial后广告会立即出现。但是请保证广告已经加载完成。

	[[AdManager sharedInstance] isInterstitialReady]

   检查全屏广告是否加载完成了。如果广告没有加载完成直接调用showInterstitial会发生不可预料的事件，有的广告平台可能会导致应用奔溃。
   所以每次展示前都需要判断是否加载完成。整体就是下面的样子。

   	if([[AdManager sharedInstance] isInterstitialReady]){
		[[AdManager sharedInstance] showInterstitial];
	}

g. 视频广告的加载和展示

	[[AdManager sharedInstance] loadVideo];

   加载视频广告，广告加载成功后不会自动展示，这样能更好的控制视频广告在合适的时机展示给用户，
   如果要在加载成功时立即展示可以在 eventlistener的 onLoadedSuccess事件中调用showVideo展示广告。

	[[AdManager sharedInstance] showVideo];

   展示视频广告，调用showVideo后广告会立即出现。但是请保证广告已经加载完成。

	[[AdManager sharedInstance] isVideoReady]

   检查视频广告是否加载完成了。如果广告没有加载完成直接调用showVideo会发生不可预知的事件，如有的广告平台可能会导致奔溃。
   所以每次展示前都需要判断是否加载完成。片段如下面的样子。

   	if([[AdManager sharedInstance] isVideoReady]){
		[[AdManager sharedInstance] showVideo];
	}

h. 应用墙广告的加载和展示

	[[AdManager sharedInstance] loadAppWall];

   加载应用墙广告，广告加载成功后不会自动展示，这样能更好的控制应用墙广告在合适的时机展示给用户，
   如果要在加载成功时立即展示可以在 eventlistener的 onLoadedSuccess事件中调用showAppWall展示广告。

	[[AdManager sharedInstance] showAppWall];

   展示应用墙广告，调用showAppWall后广告会立即出现。但是请保证应用墙广告已经加载完成。

	[[AdManager sharedInstance] isAppWallReady]

   检查应用墙广告是否加载完成了。如果广告没有加载完成直接调用showAppWall会发生不可预知的事件，如有的广告平台可能会导致奔溃。
   所以每次展示前都需要判断是否加载完成。片段如下面的样子。

   	if([[AdManager sharedInstance] isAppWallReady]){
		[[AdManager sharedInstance] showAppWall];
	}


3.广告平台配置文件模板

	{
		"isTesting":true,//是否是测试模式
		"rateModel":1,//广告平台排序规则，0表示priority是权重，各个平台按比例显示广告，1表示priority是顺序，各个平台按顺序展示广告
		"platforms":[
		{"class":"AdmobAdapter","priority":90,"key1":"ca-app-pub-xxx/xxx","key2":"ca-app-pub-xxx/xxx"},//admob 平台 ,key1 banner ID，key2全屏id
		{"class":"BaiduAdapter","priority":10,"key1":"appid","key2":"bannerid","param":"Interstitial ID"},//baidu ssp platform,key1 应用id，key2横幅id，param全屏id或者是json字符串{"interstitialID":"interstitial ID","videoID":" video ID"}
		{"class":"AmazonAdapter","priority":20,"key1":"xxx"},//amazon 平台 ,key1 appkey
		{"class":"ChartboostAdapter","priority":40,"key1":"xxx","key2":"xxx"},//chartboost 平台 ,key1 appID，key2 signature 
		{"class":"InmobiAdapter","priority":50,"key1":"property id","key2":"banner id","key3":"interstitial id"},//inmobi 平台 ,key1 appid 
		{"class":"IadAdapter","priority":50},//iad 平台 ,android上会被自动忽略
		{"class":"KeymobAdapter","priority":50,"key1":"appid"},//keymob.com 自售广告，交叉推广需要
		{"class":"GDTAdapter","priority":10,"key1":"appid","key2":"banner id","param":"Interstitial ID"},//广点通广告配置param Interstitial id or json string {"interstitialID":"interstitial ID","appWallID":" appWall ID"}
		{"class":"AdcolonyAdapter","priority":10,"key1":"appid","key2":"zone interstitia","param":"video zone"},//Adcolony配置
		{"class":"MMediaAdapter","priority":10,"key1":"xxx","key2":"xxx"}//mmedia 平台 ,key1 banner ID，key2全屏id
		]
	}

priority会根据ratemodel不同而成为比重或者排序号,class表示平台实现,不能修改。


项目地址 https://github.com/keymobdev/Keymob-Ad-Lib-for-IOS <br/>
android home https://github.com/keymobdev/keymob