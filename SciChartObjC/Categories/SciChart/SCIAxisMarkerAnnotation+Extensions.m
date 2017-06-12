//
//  SCIAxisMarkerAnnotation+Extensions.m
//  SciChartObjC
//
//  Created by Kuznetsov Aleksey on 12.06.17.
//  Copyright © 2017 Kuznetsov Aleksey. All rights reserved.
//

#import "SCIAxisMarkerAnnotation+Extensions.h"

@implementation SCIAxisMarkerAnnotation (Extensions)

+ (instancetype)customWithPosition:(SCIGenericType)position
{
    SCIAxisMarkerAnnotation *yMarker = [[SCIAxisMarkerAnnotation alloc] init];
    yMarker.coordMode = SCIAnnotationCoord_Absolute;
    yMarker.yAxisId = @"yAxis";
    yMarker.position = position;
    yMarker.style.markerLinePen = [[SCIPenSolid alloc] initWithColorCode:0xFFFFFFFF Width:1];
    yMarker.style.backgroundColor = [UIColor clearColor];
    yMarker.style.textColor = [UIColor clearColor];
    return yMarker;
}


@end
