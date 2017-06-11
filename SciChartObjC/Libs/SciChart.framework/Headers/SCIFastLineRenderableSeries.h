//
//  FastLineRenderableSeries.h
//  SciChart
//
//  Created by Admin on 28.08.15.
//  Copyright (c) 2015 SciChart Ltd. All rights reserved.
//

/** \addtogroup RenderableSeries
 *  @{
 */

#import <Foundation/Foundation.h>
#import "SCIRenderableSeriesBase.h"

@class SCILineSeriesStyle;

/**
 @brief The SCIFastLineRenderableSeries class.
 @discussion This renderable series displays line connecting all data points and as option point markers at data points coordinates
 @remark Designed to work with SCIXyDataSeries as data container
 @remark For styling provide or customize SCILineSeriesStyle
 @see SCIRenderableSeries
 @see SCIRenderableSeriesBase
 @see SCIXyDataSeries
 @see SCILineSeriesStyle
 */
@interface SCIFastLineRenderableSeries : SCIRenderableSeriesBase

/**
 @brief Get or set style for visual customization
 @see SCILineSeriesStyle
 */
@property (nonatomic, copy) SCILineSeriesStyle * style;

@end

/** @}*/
