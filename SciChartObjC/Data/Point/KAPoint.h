//
//  KAPoint.h
//  SciChartObjC
//
//  Created by Kuznetsov Aleksey on 11.06.17.
//  Copyright © 2017 Kuznetsov Aleksey. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KAPoint : NSObject

@property (nonatomic) NSDate *date;
@property (nonatomic) NSNumber *rate;
@property (nonatomic, readonly) double doubleRate;

@end
