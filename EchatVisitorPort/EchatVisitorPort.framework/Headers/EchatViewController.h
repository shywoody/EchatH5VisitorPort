//
//  EchatViewController.h
//  EchatSDKDemo
//
//  Created by xll on 2018/3/30.
//  Copyright © 2018年 xielang. All rights reserved.
//

#import <UIKit/UIKit.h>
@class Echat_accessConditions;
@class EchatVideoModel;

typedef void(^VisEvtCallBack)(NSString * data);
@interface EchatViewController : UIViewController

/*设置navigationItem图片,传入imageName
 如果要同时设置UIControlStateHighlighted图片 预备两张名为图片 A 与 A_highlighted*/
@property(nonatomic,copy) NSString * leftItemImageName;///leftItemImageName
@property(nonatomic,copy) NSString * rightItemImageName;///rightItemImageName

///默认为YES,控制器内部设置了Navigation左右item,分别为返回和对话关闭功能按钮
@property(nonatomic, assign) BOOL defaultNavigationItemVisualable;

///自定义地图控制器
@property(nonatomic,strong) UIViewController *  mapLoaderViewController;

///自定义图库控制器
@property(nonatomic,strong) UIViewController * imagePickerLoaderViewController;

///图文消息如果type是custom则会返回字段供开发者自己去操作
@property (nonatomic,copy) VisEvtCallBack visEvtCallBackblock;


///构造函数
-(instancetype)initWithAccess:(Echat_accessConditions *)access;

/**
 * @brief 打开链接方法
 * @param info url参数包含地址和类型
 */
-(void)echat_OpenUrl:(NSDictionary * )info;
//---------------------------------------------------------------------自定义接口 
/**
 * @brief 图片预览功能接管
 * @param dict 预览图片信息
 */
-(void)echat_PreviewImages:(NSDictionary *)dict;

/**
 * @brief 地理位置发送控制器接管
 */
-(void)echat_openMap;

/**
 * @brief 视频播放接管
 * @param model  可能是fileUrl也可能是远程地址
 */
-(void)echat_bridge4playVideo:(EchatVideoModel *)model;

/**
 * @brief 相机接管
 */
-(void)echat_camera;

/**
 * @brief 相册接管
 */
-(void)echat_imagePicker;

/**
 * @brief 打开链接
 * @param  info 地址参数
 * @return 返回yes是开发者接管,返回no是SDK接管
 */
-(BOOL)echat_OpenLink:(NSDictionary *)info;

//--------------------------------------------------------------------上传

/**
 * @brief 上传图片
 * @param images images为UIImage数组
 */
-(void)echat_upLoadImages:(NSArray<UIImage*>*)images;

/**
 * @brief 上传gif
 * @param asset 为PHAsset或是ALAsset资源
 */
-(void)echat_upLoadGif:(id)asset;

/**
 * @brief 视频
 * @param  coverImage 为视频封面图片
 * @param  asset 为PHAsset或是ALAsset资源
 */
-(void)echat_upLoadVideoWithCoverImage:(UIImage *)coverImage andVideoAsset:(id)asset;


/**
 * @brief 切换路由
 * @param echatTag 路由名称
 */
-(void)startOtherRouteChat:(NSString *)echatTag;

/**
* @brief 控制器返回,当在聊天页面时候默认设置naviBarLeftItem为页面返回按钮执行此方法,defaultNavigationItemVisualable为NO时可以自己定义naviBarItem去调用此返回方法
*/
-(void)back;


/**
* @brief 关闭当前对话
*/
-(void)echat_endConversationComplete:(dispatch_block_t)complete failure:(dispatch_block_t)fail;



@end


