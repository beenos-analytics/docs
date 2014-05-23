//
//  BeenosAnalytics.h
//  BeenosAnalytics
//
//  Created by Hiroyuki Kato on 2/17/14.
//  Copyright (c) 2014 Hiroyuki Kato. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface BeenosAnalytics : NSObject

+ (id)sharedManager;

- (void)bootstrap:(NSString *)apiKey;

- (void)track:(NSString *)eventName;

- (void)track:(NSString *)eventName withCustomData:(NSDictionary *)customData;

@end