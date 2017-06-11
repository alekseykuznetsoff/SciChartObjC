//
//  BoxAnnotation.h
//  SciChart
//
//  Created by Admin on 12.01.16.
//  Copyright © 2016 SciChart Ltd. All rights reserved.
//

/** \addtogroup Annotations
 *  @{
 */

#import <Foundation/Foundation.h>
#import "SCIAnnotationBase.h"

@class SCIBoxAnnotationStyle;

@interface SCIBoxAnnotation : SCIAnnotationBase

/**
 * Gets or sets the X start point
 * @code
 let boxAnn = SCIBoxAnnotation()
 boxAnn.xAxisId = "xAxis"
 boxAnn.yAxisId = "yAxis"
 boxAnn.coordMode = .Relative
 boxAnn.xStart = SCIGeneric(0.25)
 * @endcode
 * @see SCIAnnotationCoordMode
 */
@property (nonatomic) SCIGenericType xStart;

/**
 * Gets or sets the Y start point
 * @code
 let boxAnn = SCIBoxAnnotation()
 boxAnn.xAxisId = "xAxis"
 boxAnn.yAxisId = "yAxis"
 boxAnn.coordMode = .Relative
 boxRed.yStart = SCIGeneric(0.25)
 * @endcode
 * @see SCIAnnotationCoordMode
 */
@property (nonatomic) SCIGenericType yStart;

/**
 * Gets or sets the X end point
 * @code
 let boxAnn = SCIBoxAnnotation()
 boxAnn.xAxisId = "xAxis"
 boxAnn.yAxisId = "yAxis"
 boxAnn.coordMode = .Relative
 boxRed.xEnd = SCIGeneric(0.5)
 * @endcode
 * @see SCIAnnotationCoordMode
 */
@property (nonatomic) SCIGenericType xEnd;

/**
 * Gets or sets the Y end point
 * @code
 let boxAnn = SCIBoxAnnotation()
 boxAnn.xAxisId = "xAxis"
 boxAnn.yAxisId = "yAxis"
 boxAnn.coordMode = .Relative
 boxRed.yEnd = SCIGeneric(0.5)
 * @endcode
 * @see SCIAnnotationCoordMode
 */
@property (nonatomic) SCIGenericType yEnd;

/**
 * Gets or sets the BoxAnnotation style
 * @discussion The variety of preperties can be set here, e.g. box fill brush, border pen
 * @code
 let boxAnn = SCIBoxAnnotation()
 boxAnn.xAxisId = "xAxis"
 boxAnn.yAxisId = "yAxis"
 boxAnn.style.fillBrush = SCIBrushSolid(colorCode: 0x301010FF)
 boxAnn.style.borderPen = SCIPenSolid(colorCode: 0xFF0000FF, width: 2)
 chartSurface.annotation = boxAnn
 * @endcode
 * @see SCIBoxAnnotationStyle
 */
@property (nonatomic, copy) SCIBoxAnnotationStyle * style;

@end

/** @}*/
