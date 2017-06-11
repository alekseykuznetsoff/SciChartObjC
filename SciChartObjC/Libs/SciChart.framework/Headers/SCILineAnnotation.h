//
//  LineAnnotation.h
//  SciChart
//
//  Created by Admin on 24.12.15.
//  Copyright © 2015 SciChart Ltd. All rights reserved.
//

/** \addtogroup Annotations
 *  @{
 */

#import <Foundation/Foundation.h>
#import "SCIAnnotationBase.h"

@class SCILineAnnotationStyle;

@interface SCILineAnnotation : SCIAnnotationBase

/**
 * Gets or sets the X start point
 * @code
 let lineAnnotation = SCILineAnnotation()
 lineAnnotation.xAxisId = "xAxis"
 lineAnnotation.yAxisId = "yAxis"
 lineAnnotation.coordMode = .RelativeY
 lineAnnotation.xStart = SCIGeneric(1)
 * @endcode
 * @see SCIAnnotationCoordMode
 */
@property (nonatomic) SCIGenericType xStart;

/**
 * Gets or sets the Y start point
 * @code
 let lineAnnotation = SCILineAnnotation()
 lineAnnotation.xAxisId = "xAxis"
 lineAnnotation.yAxisId = "yAxis"
 lineAnnotation.coordMode = .RelativeY
 lineAnnotation.yStart = SCIGeneric(0.05)
 * @endcode
 * @see SCIAnnotationCoordMode
 */
@property (nonatomic) SCIGenericType yStart;

/**
 * Gets or sets the X end point
 * @code
 let lineAnnotation = SCILineAnnotation()
 lineAnnotation.xAxisId = "xAxis"
 lineAnnotation.yAxisId = "yAxis"
 lineAnnotation.coordMode = .RelativeY
 lineAnnotation.xEnd = SCIGeneric(1)
 * @endcode
 * @see SCIAnnotationCoordMode
 */
@property (nonatomic) SCIGenericType xEnd;

/**
 * Gets or sets the Y end point
 * @code
 let lineAnnotation = SCILineAnnotation()
 lineAnnotation.xAxisId = "xAxis"
 lineAnnotation.yAxisId = "yAxis"
 lineAnnotation.coordMode = .RelativeY
 lineAnnotation.yEnd = SCIGeneric(0.95)
 * @endcode
 * @see SCIAnnotationCoordMode
 */
@property (nonatomic) SCIGenericType yEnd;

/**
 * Gets or sets the LineAnnotation style
 * @discussion The variety of preperties can be set here, e.g. line width, color, point marker
 * @code
 let lineAnnotation = SCILineAnnotation()
 lineAnnotation.style.linePen = SCIPenSolid(colorCode: 0xFFFF0000, width: 2)
 chartSurface.annotation = lineAnnotation
 * @endcode
 * @see SCILineAnnotationStyle
 */
@property (nonatomic, copy) SCILineAnnotationStyle * style;

@end

/** @}*/
