//
//  FastOhlcRenderableSeries.h
//  SciChart
//
//  Created by Admin on 25.11.15.
//  Copyright © 2015 SciChart Ltd. All rights reserved.
//

/** \addtogroup RenderableSeries
 *  @{
 */

#import <Foundation/Foundation.h>
#import "SCIRenderableSeriesBase.h"

@class SCIOhlcSeriesStyle;

/**
 @brief The SCIFastOhlcRenderableSeries class.
 @discussion Provides Open-High-Low-Close series rendering where each data point displayed as vertical line from high to low value with marks at open and close values.
 @discussion OHLC series has two color schemes for Up and Down mode. If open value is higher than close, data point is drawn in Down mode, else in Up mode
 @remark Designed to work with SCIOhlcDataSeries as data container
 @remark For styling provide or customize SCIOhlcSeriesStyle
 @see SCIRenderableSeries
 @see SCIRenderableSeriesBase
 @see SCIOhlcDataSeries
 @see SCIOhlcSeriesStyle
 */
@interface SCIFastOhlcRenderableSeries : SCIRenderableSeriesBase

/**
 @brief Get or set style for visual customization
 @see SCIOhlcSeriesStyle
 */
@property (nonatomic, copy) SCIOhlcSeriesStyle * style;

@end

/** @}*/