//
//  BDIOTOTAPackageInfo.h
//  BDIOTClientSDK
//
//  Created by guminghua on 15/11/10.
//  Copyright © 2015年 baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BDIOTOTAPackageInfo : NSObject

@property (nonatomic, assign) NSInteger id;

@property (nonatomic, copy) NSString *desc;

@property (nonatomic, copy) NSString *coapDownloadUri;

@property (nonatomic, assign) NSInteger osVersionId;

@property (nonatomic, copy) NSString *fileId;

@property (nonatomic, copy) NSString *osVersion;

@property (nonatomic, copy) NSString *httpDownloadUri;

@property (nonatomic, assign) NSInteger size;

@property (nonatomic, copy) NSDate *createTime;

@property (nonatomic, assign) NSInteger projectId;

@property (nonatomic, copy) NSString *md5;

@property (nonatomic, copy) NSString *status;

@property (nonatomic, copy) NSDate *updateTime;

@end
