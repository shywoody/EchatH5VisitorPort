//
//  EchatSubscribeMsgModel.h
//  EchatVisitorPort
//
//  Created by mac on 2020/1/15.
//  Copyright © 2020 mac. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, EchatSubscribeMsgType){
    EchatSubscribePositionMsgType = 1 << 0,
};

@interface EchatSubscribeMsgModel : NSObject
@property(nonatomic,copy) NSString * title;
@property(nonatomic,copy) NSString * content;
@property(nonatomic,assign) EchatSubscribeMsgType type;
@end

NS_ASSUME_NONNULL_END
