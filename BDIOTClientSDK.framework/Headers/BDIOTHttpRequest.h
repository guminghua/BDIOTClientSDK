//
//  BDIOTHttpRequest.h
//  BDIOTClientSDK
//
//  Created by guminghua on 15/11/10.
//  Copyright © 2015年 baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BDIOTSDKManager.h"


@class BDIOTService;
@class BDIOTServerErrorInfo;
@class BDIOTPagingInfo;
@class BDIOTErrorWrapper;




typedef void (^ResponseHandleBlock)(BDIOTErrorWrapper*, BDIOTPagingInfo*, NSDictionary*);

@interface BDIOTHttpRequest : NSObject
+(NSString*) nonce;
+(NSString*) generateSignature:(NSString*)uri;

+(void) request:(NSString*) method
        serviceName:(NSString*)serviceName
     methodName:(NSString*)methodName
      paramDict:(NSDictionary*)paramDict
       bodyDict:(NSDictionary*)bodyDict
responseHandleBlock:(ResponseHandleBlock)responseHandleBlock;

@end
