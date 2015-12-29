//
//  BDIOTDeviceService.h
//  BDIOTClientSDK
//
//  Created by guminghua on 15/11/11.
//  Copyright © 2015年 baidu. All rights reserved.
//

#import "BDIOTService.h"
#import "BDIOTServerErrorInfo.h"
#import "BDIOTPagingInfo.h"
#import "BDIOTHttpRequest.h"
#import "BDIOTDeviceInfo.h"
#import "BDIOTTaskInfo.h"
#import "BDIOTDeviceBindInfo.h"
#import "BDIOTAIInfo.h"
#import "BDIOTTaskStatus.h"
#import "BDIOTTaskInfo.h"
#import "BDIOTDeviceData.h"
#import "BDIOTErrorWrapper.h"
//接口声明
/*--------------------------------------------------------设备管理相关------------------------------------------------------------------------------*/
typedef void (^GetDeviceInfoHandleBlock)(BDIOTErrorWrapper*  __nonnull  errorWrapper, BDIOTDeviceInfo*  __nullable  info);
typedef void (^GetDeviceInfoByTokenHandleBlock)(BDIOTErrorWrapper*  __nonnull  errorWrapper, BDIOTDeviceInfo*  __nullable  info);
typedef void (^SetDeviceNameHandleBlock)(BDIOTErrorWrapper*  __nonnull  errorWrapper, BDIOTDeviceInfo*  __nullable  info);
typedef void (^GetBindDevicesHandleBlock)(BDIOTErrorWrapper*  __nonnull  errorWrapper, BDIOTPagingInfo*  __nonnull  pagingInfo, NSArray<BDIOTDeviceInfo*>*  __nullable  infos);
typedef void (^BindDeviceHandleBlock)(BDIOTErrorWrapper*  __nonnull  errorWrapper, BDIOTDeviceBindInfo*  __nullable  info);
typedef void (^UnBindDeviceHandleBlock)(BDIOTErrorWrapper*  __nonnull  errorWrapper, BDIOTDeviceBindInfo*  __nullable  info);


/*--------------------------------------------------------设备控制相关------------------------------------------------------------------------------*/
typedef void (^GetProjectResourceHandleBlock)(BDIOTErrorWrapper*  __nonnull  errorWrapper, BDIOTAIInfo*  __nullable  info);
typedef void (^GetDeviceResourceHandleBlock)(BDIOTErrorWrapper*  __nonnull  errorWrapper, BDIOTAIInfo*  __nullable  info);
typedef void (^ControlDeviceHandleBlock)(BDIOTErrorWrapper*  __nonnull  errorWrapper, BDIOTTaskInfo* __nullable info);
typedef void (^GetTaskStatusHandleBlock)(BDIOTErrorWrapper*  __nonnull  errorWrapper, BDIOTTaskStatus*  __nullable  taskStatus);
typedef void (^GetDeviceTasksHandleBlock)(BDIOTErrorWrapper*  __nonnull  errorWrapper, BDIOTPagingInfo*  __nonnull  pagingInfo, NSArray<BDIOTTaskInfo*>*  __nullable  infos);
typedef void (^GetTaskInfoHandleBlock)(BDIOTErrorWrapper*  __nonnull  errorWrapper, BDIOTTaskInfo*  __nullable  info);
typedef void (^GetDeviceOnlineHandleBlock)(BDIOTErrorWrapper*  __nonnull  errorWrapper, NSString* __nonnull deviceUuid, BOOL info);



/*--------------------------------------------------------设备数据相关------------------------------------------------------------------------------*/
typedef void (^GetDeviceHistoryDataHandleBlock)(BDIOTErrorWrapper*  __nonnull  errorWrapper, BDIOTPagingInfo*  __nonnull  pagingInfo, NSArray<BDIOTDeviceData*>*  __nullable  infos);



@interface BDIOTDeviceService : BDIOTService

/*--------------------------------------------------------设备管理相关------------------------------------------------------------------------------*/
/**
 *  获取设备信息（设备在线状态取心跳状态）
 *
 *  @param deviceUuid  设备uuid
 *  @param handleBlock 处理回调
 */
-(void)getDeviceInfo:(NSString*  __nonnull )deviceUuid
        handleBlock:(GetDeviceInfoHandleBlock  __nonnull )handleBlock;

/**
 *  获取设备信息（实时获取设备在线状态）
 *
 *  @param deviceUuid  设备uuid
 *  @param expireTime  超时时间
 *  @param handleBlock 处理回调
 */
-(void)getDeviceInfoWithRealtimeOnline:(NSString*  __nonnull )deviceUuid
				   expireTime:(NSInteger)expireTime
		 handleBlock:(GetDeviceInfoHandleBlock  __nonnull )handleBlock;



/**
 *  在未绑定之前获取设备信息.在用户绑定设备前如果需要展示设备信息，调用此接口。
 *
 *  @param deviceUuid  deviceUuid
 *  @param deviceToken deviceToken
 *  @param handleBlock 处理回调
 */
-(void)getDeviceInfoByToken:(NSString*  __nonnull )deviceUuid
				deviceToken:(NSString* __nonnull )deviceToken
				handleBlock:(GetDeviceInfoByTokenHandleBlock  __nonnull )handleBlock;

/**
 *  为设备设置备注名
 *
 *  @param deviceUuid  设备uuid
 *  @param name        备注名
 *  @param handleBlock 处理回调
 */
-(void)setDeviceName:(NSString*  __nonnull )deviceUuid
                name:(NSString*  __nonnull )name
        handleBlock:(SetDeviceNameHandleBlock  __nonnull )handleBlock;

/**
 *  获取已绑定设备列表
 *
 *  @param pagingInfo  分页信息，如果为空，默认起始为0，每页为100
 *  @param handleBlock 处理回调
 */
-(void)getBindDevices:(BDIOTPagingInfo* __nullable )pagingInfo
		  handleBlock:(GetBindDevicesHandleBlock  __nonnull )handleBlock;

/**
 *  获取已绑定设备列表（实时获取设备在线状态）
 *
 *  @param pagingInfo  分页信息
 *  @param expireTime  超时
 *  @param handleBlock 处理回调
 */
-(void)getBindDevicesWithRealtimeOnline:(BDIOTPagingInfo* __nullable )pagingInfo
				   expireTime:(NSInteger)expireTime
		  handleBlock:(GetBindDevicesHandleBlock  __nonnull )handleBlock;
/**
 *  绑定设备
 *
 *  @param deviceUuid  设备uuid
 *  @param deviceToken 设备绑定token
 *  @param handleBlock 接收回调
 */
-(void)bindDevice:(NSString*  __nonnull )deviceUuid
      deviceToken:(NSString*  __nonnull )deviceToken
     handleBlock:(BindDeviceHandleBlock  __nonnull )handleBlock;

/**
 *  解除绑定
 *
 *  @param deviceUuid  设备uuid
 *  @param handleBlock 处理回调
 */
-(void)unBindDevice:(NSString*  __nonnull )deviceUuid
       handleBlock:(UnBindDeviceHandleBlock  __nonnull )handleBlock;


/*--------------------------------------------------------设备控制相关------------------------------------------------------------------------------*/

/**
 *  获取project resource
 *
 *  @param projectId   projectid
 *  @param handleBlock 处理回调
 */
-(void)getProjectResource:(NSInteger)projectId
			  handleBlock:(GetProjectResourceHandleBlock  __nonnull )handleBlock;

/**
 *  获取设备自描述服
 *
 *  @param deviceUuid  设备uuid
 *  @param handleBlock 处理回调
 */
-(void)getDeviceResource:(NSString*  __nonnull )deviceUuid
			 handleBlock:(GetDeviceResourceHandleBlock  __nonnull )handleBlock;

/**
 *  控制设备
 *
 *  @param deviceUuids 设备uuid
 *  @param protocol    protocol，BDIOTDeviceResourceProtocolCoap，BDIOTDeviceResourceProtocolHttp两种。
 *  @param method      method，BDIOTDeviceResourceMethodGet，BDIOTDeviceResourceMethodPut两种。
 *  @param name        自描述符中resource的name字段
 *  @param content     如果是put方法，要设置的值放在这里
 *  @param expireTime  超时时间
 *  @param handleBlock 处理回调。成功后接收到的回调是taskid，需要通过getTaskInfo去轮训任务状态。
 */

-(void)controlDevice:(NSArray<NSString*>*  __nonnull )deviceUuids
		   protocol_:(NSString*  __nonnull )protocol
			  method:(NSString*  __nonnull )method
				name:(NSString*  __nonnull )name
			 content:(NSObject*  __nonnull )content
		  expireTime:(NSInteger)expireTime
		 handleBlock:(ControlDeviceHandleBlock  __nonnull )handleBlock;

/**
 *  获取任务状态
 *
 *  @param taskId      taskid
 *  @param handleBlock 处理回调
 */
-(void)getTaskStatus:(NSInteger)taskId
		 handleBlock:(GetTaskStatusHandleBlock  __nonnull )handleBlock;

/**
 *  查询某台设备上正在进行的任务
 *
 *  @param deviceUuid  设备uuid
 *  @param handleBlock 处理回调
 */
-(void)getDeviceTasks:(NSString*  __nonnull )deviceUuid
		   pagingInfo:(BDIOTPagingInfo* __nullable )pagingInfo
		  handleBlock:(GetDeviceTasksHandleBlock  __nonnull )handleBlock;

/**
 *  获取任务状态
 *
 *  @param deviceUuid  设备uuid
 *  @param taskId      control接口调用成功后返回的taskid
 *  @param tryInterval 如果taskid返回表明任务正在进行中，接口会轮询，直到任务结束，这个字段设置轮询间隔。
 *  @param handleBlock 处理回调。
 */

-(void)getTaskInfo:(NSString*  __nonnull )deviceUuid
			taskId:(NSInteger)taskId
	   tryInterval:(NSTimeInterval)tryInterval
	   handleBlock:(GetTaskInfoHandleBlock  __nonnull )handleBlock;


-(void)getDeviceOnline:(NSString*  __nonnull )deviceUuid
	   expireTime:(NSInteger)expireTime
	   handleBlock:(GetDeviceOnlineHandleBlock  __nonnull )handleBlock;
/*--------------------------------------------------------设备数据相关------------------------------------------------------------------------------*/
/**
 *  获取设备历史数据
 *
 *  @param deviceUuid  设备uuid
 *  @param propertyKey 要获取的字段
 *  @param startTime   开始时间
 *  @param endTime     结束时间
 *  @param handleBlock 处理回调
 */
-(void)getDeviceHistoryData:(NSString*  __nonnull )deviceUuid
				propertyKey:(NSString*  __nonnull )propertyKey
				  startTime:(NSDate*  __nonnull )startTime
					endTime:(NSDate*  __nonnull )endTime
			pagingInfo:(BDIOTPagingInfo* __nullable )pagingInfo
				handleBlock:(GetDeviceHistoryDataHandleBlock  __nonnull )handleBlock;



@end
