#1. 前言：
	百度IoT iOS SDK封装了百度物联网平台的相关接口，给开发者接入百度物联网平台，开发iOS客户端App提供标准接口。开发者使用SDK之前需要在百度物联网平台申请开发者账号，并且创建App。
#2. 概述
##2.1 SDK功能概述
		SDK包含SDK管理，账户管理，设备管理，OTA升级，智能场景.
		SDK包含设备绑定、设备控制、设备信息获取、设备解绑以及OTA升级等接口，方便开发者在App开发过程中对设备进行相关操作。SDK包含一个原型App开发者可以通过在原型App的基础上开发自己的App，也可以参照原型App开发自己的App。
##2.2 名词解释
		名词				说明
		AppKey			开发者在IoT开发平台申请的账号后创建应用后会生成对应的AppKey
		SecretKey		开发者在IoT开发平台申请的账号后创建应用后会生成对应的SecretKey
		Access_Token	表示用户身份的Token,调用各类App时需要，用户登录授权后可获得
		HttpCode		调用网络请求接口Http状态码
		ResponseCode	调用网络请求接口时内部状态码
		Message			调用网络请求时对应ResponseCode的状态信息

##2.3 通用结构体定义
###2.3.1 错误结构体
			typedef NS_ENUM(NSInteger, BDIoTError) {
				BDIoTErrorOk = 0,//成功
				BDIoTErrorLocalError,//本地调用过程出错
				BDIoTErrorHttpError,//http请求出错
				BDIoTErrorServerError// Iot服务端返回错误
			};
			
			typedef NS_ENUM(NSInteger, BDIOTLocalError) {
				BDIOTLocalErrorTokenNil = 0
			};
			
			@interface BDIoTErrorWrapper : NSObject<NSCopying>
			@property (nonatomic, assign) BDIoTError errorType;
			@property (nonatomic, assign) BDIOTLocalError   localErrorCode; //本地错误代码，暂时未用。
			@property (nonatomic, copy) NSString*  __nullable localErrorMessage;//本地错误信息。
			@property (nonatomic, assign) NSString*  __nonnull  serverErrorCode;//服务器错误代码
			@property (nonatomic, copy) NSString*  __nonnull serverErrorMessage;//服务器错误信息
			@end

调用示例

			if errorWrapper.errorType == BDIoTError.Ok {
				
				//调用成功
			}else{
				//调用失败。
				//根究errorType的值判断错误错误类别。
				
			}
###2.3.2 分页结构
			public class BDIoTPagingInfo : NSObject {
			    public var start: Int //分页起始
			    public var limit: Int //每页总数，最大100
			    public var total: Int //总数
			}
			说明：
			在返回数组类型的数据时，比如：/todo 请求的参数中需要带希望请求的分页（如果为空，默认未起始为0，每页100）,返回的回调中也会有获得的分页信息。

#3 SDK管理
##3.1 获取SDK实例
		let iot = BDIoTSDKManager.sharedInstance()
##3.2 配置app信息
		iot.setAppInfo(kAppKey)
*说明：请求之前必须要配置好。
##3.3 设置log等级
		iot.setLogLevel(BDIOTLogLevelAll)
*说明：默认是BDIOTLogLevelAll
##3.4 分别获取各项服务
		//获取帐号服务
		let accountService = iot.accountService
		//获取设备服务
		let deviceService = iot.deviceService
		//获取智能场景服务
		let aiService = iot.AIService
		//获取ota升级服务
		let otaService = iot.OTAService
##3.6 获取和设置用户登录token
		let token = iot.token //获取token
*说明：登录完成后SDK内部都会自动设置好新的token，调用退出接口会自动清空token。

#4 账户服务
##4.1 获取账户服务
		let accountService = iot.accountService
##4.2 回调类型定义
		public typealias GetAccountInfoHandleBlock = (BDIoTErrorWrapper, BDIoTAccountInfo?) -> Void
##4.3 接口
	  	/**
	     *  登录接口，调用后会弹出百度登录webview。要求outViewController的navigationcontroller存在。
	     *
	     *  @param outViewController 外部viewcontroller
	     *  @param state             oauth2 中的state字段
	     */
	    public func login(outViewController: UIViewController, state: String)

	    /**
	     *  退出登录接口
	     */
	    public func logout()

	    /**
	     *  获取账户信息。需要提前设置BDIoTSDKManager.token变量。
	     *
	     *  @param handleBlock 接收回调。
	     */
	    public func getAccountInfo(handleBlock: GetAccountInfoHandleBlock)

#5 设备服务

##5.1 获取设备服务
		let deviceService = iot.deviceService
##5.2 回调类型定义
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

##5.3 接口
		
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
		



#6 OTA服务
##6.1 获取OTA服务		
		let otaService = iot.OTAService
##6.2 回调类型
		typedef void (^GetPackageInfoHandleBlock)(BDIoTErrorWrapper*  __nonnull  errorWrapper, BDIoTOTAPackageInfo*  __nullable  info);
		typedef void (^CheckUpdateHandleBlock)(BDIoTErrorWrapper*  __nonnull  errorWrapper, BDIoTOTAPackageInfo*  __nullable  info);
		typedef void (^UpdateHandleBlock)(BDIoTErrorWrapper*  __nonnull  errorWrapper, NSInteger taskId);
		typedef void (^GetUpdateStatusHandleBlock)(BDIoTErrorWrapper*  __nonnull  errorWrapper, NSString*  __nullable  status);

##6.3 接口

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

#7 智能场景服务
##7.1 获取智能场景服务
		let aiService = iot.AIService
##7.2 回调类型
##7.3 接口
#8. 集成指南
	下载framework，合入xcode工程即可。
