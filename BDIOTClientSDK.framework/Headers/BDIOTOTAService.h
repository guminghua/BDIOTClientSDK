//
//  BDIOTOTAService.h
//  BDIOTClientSDK
//
//  Created by guminghua on 15/11/11.
//  Copyright © 2015年 baidu. All rights reserved.
//

#import "BDIOTService.h"
#import "BDIOTServerErrorInfo.h"
#import "BDIOTPagingInfo.h"
#import "BDIOTHttpRequest.h"
#import "BDIOTOTAStrategyInfo.h"
#import "BDIOTOTAPackageInfo.h"

@class BDIOTErrorWrapper;

typedef void (^GetPackageInfoHandleBlock)(BDIOTErrorWrapper*  __nonnull  errorWrapper, BDIOTOTAPackageInfo*  __nullable  info);
typedef void (^CheckUpdateHandleBlock)(BDIOTErrorWrapper*  __nonnull  errorWrapper, BDIOTOTAPackageInfo*  __nullable  info);
typedef void (^UpdateHandleBlock)(BDIOTErrorWrapper*  __nonnull  errorWrapper, NSInteger taskId);
typedef void (^GetUpdateStatusHandleBlock)(BDIOTErrorWrapper*  __nonnull  errorWrapper, NSString*  __nullable  status);

@interface BDIOTOTAService : BDIOTService


/**
 *  获取package信息
 *
 *  @param packageId   packageid
 *  @param handleBlock 处理回调
 */
-(void)getPackageInfo:(NSInteger)packageId
         handleBlock:(GetPackageInfoHandleBlock  __nonnull )handleBlock;

/**
 *  检测升级信息
 *
 *  @param projectId   projectid
 *  @param version     当前版本
 *  @param handleBlock 处理回调
 */
-(void)checkUpdate:(NSInteger)projectId
           version:(NSString*  __nonnull )version
      handleBlock:(CheckUpdateHandleBlock  __nonnull )handleBlock;

/**
 *  升级
 *
 *  @param deviceUuid  设备uuid
 *  @param packageId   packageid
 *  @param expireTime  升级超时时间
 *  @param handleBlock 处理回调
 */

-(void)update:(NSString*  __nonnull )deviceUuid
    packageId:(NSInteger)packageId
   expireTime:(NSInteger)expireTime
 handleBlock:(UpdateHandleBlock  __nonnull )handleBlock;

/**
 *  查询升级状态
 *
 *  @param deviceUuid  设备uuid
 *  @param handleBlock 处理回调
 */
-(void)getUpdateStatus:(NSString*  __nonnull )deviceUuid
          handleBlock:(GetUpdateStatusHandleBlock  __nonnull )handleBlock;

@end
