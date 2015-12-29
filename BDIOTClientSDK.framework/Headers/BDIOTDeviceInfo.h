//
//  BDIOTDeviceInfo.h
//  BDIOTClientSDK
//
//  Created by guminghua on 15/11/10.
//  Copyright © 2015年 baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

#define BDIOTDeviceStatusEnumError @"ERROR"
#define BDIOTDeviceStatusEnumOnline @"ONLINE"
#define BDIOTDeviceStatusEnumOffline @"OFFLINE"
#define BDIOTDeviceStatusEnumDeleted @"DELETED"
#define BDIOTDeviceStatusEnumUnactivated @"UNACTIVATED"


#define BDIOTDeviceNetTypeEnumEthernet @"ETHERNET"
#define BDIOTDeviceNetTypeEnumWifi @"WIFI"
#define BDIOTDeviceNetTypeEnumBluetooth @"BLUETOOTH"

@interface BDIOTDeviceInfo : NSObject

@property (nonatomic, assign) NSInteger id;

@property (nonatomic, copy) NSString *deviceUuid;

@property (nonatomic, copy) NSString *status;

@property (nonatomic, strong) NSDate *activateTime;

@property (nonatomic, assign) NSInteger osVersionId;

@property (nonatomic, strong) NSDate *updateTime;

@property (nonatomic, copy) NSString *osVersion;

@property (nonatomic, assign) NSInteger deviceBatchId;

@property (nonatomic, copy) NSString *bindToken;

@property (nonatomic, strong) NSDate *createTime;

@property (nonatomic, assign) NSInteger projectId;

@property (nonatomic, copy) NSString *province;

@property (nonatomic, copy) NSString *city;

@property (nonatomic, copy) NSString *name;

@property (nonatomic, copy) NSString *projectName;

@property (nonatomic, copy) NSString *seriesName;

@property (nonatomic, copy) NSString *accountUuid;

@property (nonatomic, copy) NSString *type;
@end
