//
//  FastColumnRenderableSeries.h
//  SciChart
//
//  Created by Admin on 01.12.15.
//  Copyright © 2015 SciChart Ltd. All rights reserved.
//

/** \addtogroup RenderableSeries
 *  @{
 */

#import <Foundation/Foundation.h>
#import "SCIRenderableSeriesBase.h"

@class SCIColumnSeriesStyle;

/**
 @brief The SCIFastColumnRenderableSeries class.
 @discussion This renderable series displays data points as columns from zero line to data point coordinates
 @remark Designed to work with SCIXyDataSeries as data container
 @remark For styling provide or customize SCIColumnSeriesStyle
 @see SCIRenderableSeries
 @see SCIRenderableSeriesBase
 @see SCIXyDataSeries
 @see SCIColumnSeriesStyle
 */
@interface SCIFastColumnRenderableSeries : SCIRenderableSeriesBase

/**
 @brief Get or set style for visual customization
 @see SCIColumnSeriesStyle
 */
@property (nonatomic, copy) SCIColumnSeriesStyle * style;

@end

/** @}*/
