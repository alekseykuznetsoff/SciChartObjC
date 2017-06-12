//
//  SCIXyDataSeries+Extensions.m
//  SciChartObjC
//
//  Created by Kuznetsov Aleksey on 12.06.17.
//  Copyright © 2017 Kuznetsov Aleksey. All rights reserved.
//

#import "SCIXyDataSeries+Extensions.h"

@implementation SCIXyDataSeries (Extensions)

+ (instancetype)custom
{
    SCIXyDataSeries * pointsDataSeries = [[SCIXyDataSeries alloc] initWithXType:SCIDataType_DateTime
                                                                          YType:SCIDataType_Double];
    pointsDataSeries.dataDistributionCalculator = [SCIUserDefinedDistributionCalculator new];
    return pointsDataSeries;
}


@end
