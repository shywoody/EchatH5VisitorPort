//
//  EchatDisplayVisEvtView.h
//  EchatSDKDemo
//
//  Created by xll on 2018/6/26.
//  Copyright © 2018年 xielang. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
typedef enum : NSUInteger {
    ExpandHalfType = 0,
    ExpandFullType,
} EchatDisplayVisEvtViewExpandType;

@interface EchatURLDisplayView : UIView<WKNavigationDelegate>

///标题
@property(nonatomic,copy) NSString * title;

///标题颜色
@property(nonatomic,strong) UIColor * titleColor;

///标题栏背景色
@property(nonatomic,strong) UIColor * titleViewBgColor;

///回退按钮图片
@property(nonatomic,strong) UIImage * gobackBtnImage;

///隐藏自定义进度条
@property(nonatomic,assign) BOOL isHideProgressLayer;

///隐藏自定义回退按钮
@property(nonatomic,assign) BOOL isHideGoBackBtn;

///构造
- (instancetype)initWithUrlString:(NSString *)urlString expandType:(EchatDisplayVisEvtViewExpandType)Type;
@end
