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

+(id) sharedManager;

-(void) bootstrap:(NSString *)api_key;

-(void) track:(NSString *)event_name;

-(void) track:(NSString *)event_name
  custom_data:(NSDictionary *)custom_data;

@end