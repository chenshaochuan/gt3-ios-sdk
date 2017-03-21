//
//  GT3Error.h
//  GTViewManager
//
//  Created by NikoXu on 8/16/16.
//  Copyright © 2016 Geetest. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, GT3ErrorType) {
    /** 用户中断验证导致 */
    GT3ErrorTypeUser,
    /** 服务端返回错误 */
    GT3ErrorTypeServer,
    /** 内部网络抛出错误类型 */
    GT3ErrorTypeNetWorking,
    /** 内部浏览器抛出的错误类型 */
    GT3ErrorTypeWebView,
    /** 从前端库抛出的错误类型 */
    GT3ErrorTypeJavaScript,
    /** 内部解码错误类型 */
    GT3ErrorTypeDecode,
    /** 未知错误类型 */
    GT3ErrorTypeUnknown
};

/**
 *  极验封装的NSError
 */
@interface GT3Error : NSError

/** 发生错误时接收到的元数据, 没有数据则为nil */
@property (nonatomic, readonly, strong) NSData * _Nullable metaData;
/** 极验的额外错误信息 */
@property (nonatomic, readonly, strong) NSString * gtDescription;

/** 原始的error */
@property (nonatomic, readonly, strong) NSError * _Nullable originalError;

/** 
 *  通过提供的详细的参数初始化GT3Error
 *  @seealso NSError
 */
+ (instancetype)errorWithDomainType:(GT3ErrorType)type code:(NSInteger)code userInfo:(nullable NSDictionary *)dict withGTDesciption:(NSString *)description;
/** 
 *  基于提供的NSError封装成GT3Error
 *  @seealso NSError
 */
+ (instancetype)errorWithDomainType:(GT3ErrorType)type originalError:(NSError *)originalError withGTDesciption:(NSString *)description;

@end

NS_ASSUME_NONNULL_END
