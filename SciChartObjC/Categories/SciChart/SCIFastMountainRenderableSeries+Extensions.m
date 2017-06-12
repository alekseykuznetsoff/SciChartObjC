//
//  SCIFastMountainRenderableSeries+Extensions.m
//  SciChartObjC
//
//  Created by Kuznetsov Aleksey on 12.06.17.
//  Copyright © 2017 Kuznetsov Aleksey. All rights reserved.
//

#import "SCIFastMountainRenderableSeries+Extensions.h"

@implementation SCIFastMountainRenderableSeries (Extensions)

+ (instancetype)customWithDataSeries:(id<SCIDataSeries>)dataSeries
{
    SCIFastMountainRenderableSeries * mountainSeries = [SCIFastMountainRenderableSeries new];
    id<SCIBrush2D> brush = [[SCIBrushLinearGradient alloc] initWithColorCodeStart:0xbbff0000 Finish:0x88ff0000 Direction:SCILinearGradientDirection_Vertical];
    id<SCIPen2D> pen = [[SCIPenSolid alloc] initWithColorCode:0xFFff0000 Width:0.5];
    mountainSeries.style.areaBrush = brush;
    mountainSeries.style.borderPen = pen;
    mountainSeries.xAxisId = @"xAxis";
    mountainSeries.yAxisId = @"yAxis";
    [mountainSeries setDataSeries:dataSeries];
    return mountainSeries;
}


@end
