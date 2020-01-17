//
//  EchatVideoModel.h
//  EchatVisitorPort
//
//  Created by mac on 2019/12/23.
//  Copyright © 2019 mac. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface EchatVideoModel : NSObject
///标识
@property(nonatomic,copy) NSString * identityKey;
@property(nonatomic,copy) NSString * clientFileId;

///远程播放地址
@property(nonatomic,copy) NSString * url;

///下载地址
@property(nonatomic,copy) NSString * downloadUrl;

///本地地址
@property(nonatomic,copy) NSString * localVideoPath;

///文件名
@property(nonatomic,copy) NSString * fileName;

@end

NS_ASSUME_NONNULL_END
