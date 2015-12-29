//
//  BDIOTAIInfo.h
//  BDIOTClientSDK
//
//  Created by guminghua on 15/11/10.
//  Copyright © 2015年 baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

#define BDIOTDeviceResourceTypeBool @"bool"
#define BDIOTDeviceResourceTypeInt @"int"
#define BDIOTDeviceResourceTypeDouble @"double"
#define BDIOTDeviceResourceTypeString @"string"

#define BDIOTDeviceResourceMethodGet @"GET"
#define BDIOTDeviceResourceMethodPut @"PUT"

#define BDIOTDeviceResourceProtocolCoap @"COAP"
#define BDIOTDeviceResourceProtocolHttp @"HTPP"

@class BDIOTAIReport,BDIOTAIResources,BDIOTAIPattern;
@interface BDIOTAIInfo : NSObject

@property (nonatomic, copy) NSString *__nonnull version;

@property (nonatomic, strong) NSArray<BDIOTAIResources *> * __nonnull resources;

@property (nonatomic, strong) NSArray<BDIOTAIReport *> * __nonnull report;

@end
@interface BDIOTAIReport : NSObject

@property (nonatomic, copy) NSString * __nonnull name;

@property (nonatomic, copy) NSString * __nonnull type;

@property (nonatomic, copy) NSString * __nullable desc;

@end

@interface BDIOTAIResources : NSObject

@property (nonatomic, strong) NSString * __nonnull name;

@property (nonatomic, strong) NSArray<NSString *> * __nonnull method;

@property (nonatomic, strong) NSArray<NSString *> * __nullable protocol ;

@property (nonatomic, strong) BDIOTAIPattern * __nullable pattern;

@property (nonatomic, copy) NSString * __nonnull label;

@property (nonatomic, copy) NSString * __nonnull type;

@property (nonatomic, copy) NSString * __nullable resourceType;

@property (nonatomic, copy) NSString * __nonnull uri;

@property (nonatomic, copy) NSString * __nonnull desc;

@end

@interface BDIOTAIPattern : NSObject

@property (nonatomic, assign) NSNumber* __nullable min;

@property (nonatomic, strong) NSArray<NSString *> * __nullable choice;

@property (nonatomic, copy) NSString * __nullable hint;

@property (nonatomic, assign) NSNumber* __nullable max;

@property (nonatomic, assign) NSNumber* __nullable step;

@property (nonatomic, copy) NSString * __nullable unit;

@end

