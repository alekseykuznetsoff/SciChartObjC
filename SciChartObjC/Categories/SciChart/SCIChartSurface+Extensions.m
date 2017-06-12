//
//  SCIChartSurface+Extensions.m
//  SciChartObjC
//
//  Created by Kuznetsov Aleksey on 12.06.17.
//  Copyright © 2017 Kuznetsov Aleksey. All rights reserved.
//

#import "SCIChartSurface+Extensions.h"

@implementation SCIChartSurface (Extensions)

+ (instancetype)customWithView:(SCIChartSurfaceViewBase *)view
{
    SCIChartSurface *surface = [[SCIChartSurface alloc] initWithView:view];
    
    SCIPenSolid  *majorPen = [[SCIPenSolid alloc] initWithColor:[UIColor darkGrayColor] Width:1.0];
    SCITextFormattingStyle *  textFormatting= [[SCITextFormattingStyle alloc] init];
    textFormatting.fontSize = 14.0;
    textFormatting.color = [UIColor darkGrayColor];
    
    SCIAxisStyle * axisStyle = [[SCIAxisStyle alloc]init];
    axisStyle.drawMinorTicks = NO;
    axisStyle.majorTickBrush = majorPen;
    axisStyle.majorGridLineBrush = majorPen;
    axisStyle.labelStyle = textFormatting;
    
    SCIDateTimeAxis *xAxis = [[SCIDateTimeAxis alloc] init];
    xAxis.axisId = @"xAxis";
    xAxis.subDayTextFormatting = @"mm:ss";
    xAxis.growBy = [[SCIDoubleRange alloc]initWithMin:SCIGeneric(0.0) Max:SCIGeneric(0.1)];
    xAxis.style = axisStyle;
    [surface attachAxis:xAxis IsXAxis:YES];
    
    SCINumericAxis *yAxis = [[SCINumericAxis alloc] init];
    
    yAxis.axisId = @"yAxis";
    yAxis.growBy = [[SCIDoubleRange alloc]initWithMin:SCIGeneric(0.1) Max:SCIGeneric(0.1)];
    yAxis.visibleRangeLimit = [[SCIDoubleRange alloc]initWithMin:SCIGeneric(760) Max:SCIGeneric(790)];
    yAxis.style = axisStyle;
    [surface attachAxis:yAxis IsXAxis:NO];
    
    return surface;
}


@end
