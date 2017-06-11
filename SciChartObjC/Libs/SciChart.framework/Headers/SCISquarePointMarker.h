//
//  SquarePointMarker.h
//  SciChart
//
//  Created by Admin on 26.11.15.
//  Copyright © 2015 SciChart Ltd. All rights reserved.
//

/** \addtogroup PointMarkers
 *  @{
 */

#import <Foundation/Foundation.h>
#import "SCIPointMarkerBase.h"

@protocol SCIPen2D;
@protocol SCIBrush2D;

/**
 @brief Point marker with rectangular shape
 @see SCIPointMarker
 */
@interface SCISquarePointMarker : SCIPointMarkerBase

/**
 @brief Defines point marker fill color
 @code
 marker.fillBrush = SCIBrushSolid(colorCode: 0xFF00A0FF)
 @encode
 @see SCIBrush2D
 */
@property (nonatomic, strong) id<SCIBrush2D> fillBrush;
/**
 @brief Defines point marker outline thickness and color
 @code
 style.borderPen = SCIPenSolid(colorCode: 0xFF00A0FF, width: 1)
 @encode
 @see SCIPen2D
 */
@property (nonatomic, strong) id<SCIPen2D> borderPen;

/**
 @brief If true point marker will have borders
 */
@property (nonatomic) BOOL drawBorder;

@end

/** @}*/
