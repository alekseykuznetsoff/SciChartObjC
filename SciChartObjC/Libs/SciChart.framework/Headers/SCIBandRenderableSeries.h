//
//  BandRenderableSeries.h
//  SciChart
//
//  Created by Admin on 16.02.16.
//  Copyright © 2016 SciChart Ltd. All rights reserved.
//

/** \addtogroup RenderableSeries
 *  @{
 */

#import <Foundation/Foundation.h>
#import "SCIRenderableSeriesBase.h"

@class SCIBandSeriesStyle;

/**
 @brief The SCIBandRenderableSeries class.
 @discussion A RenderableSeries type which displays two lines and shaded bands between them, where band-colors depend on wether one line is greater then the other
 @remark Designed to work with SCIXyyDataSeries as data container
 @remark For styling provide or customize SCIBandSeriesStyle
 @see SCIRenderableSeries
 @see SCIRenderableSeriesBase
 @see SCIXyyDataSeries
 @see SCIBandSeriesStyle
 */
@interface SCIBandRenderableSeries : SCIRenderableSeriesBase

/**
 @brief Get or set style for visual customization
 @see SCIBandSeriesStyle
 */
@property (nonatomic, copy) SCIBandSeriesStyle * style;

@end

/** @}*/
