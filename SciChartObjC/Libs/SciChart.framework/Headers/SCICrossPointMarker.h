//
//  CrossPointMarker.h
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

/**
 @brief Point marker with shape of cross
 @see SCIPointMarker
 */
@interface SCICrossPointMarker : SCIPointMarkerBase

/**
 @brief Defines point marker lines thickness and color
 @code
 style.linePen = SCIPenSolid(colorCode: 0xFF00A0FF, width: 1)
 @encode
 @see SCIPen2D
 */
@property (nonatomic, strong) id<SCIPen2D> linePen;
/**
 @brief If false cross has vertical and horizontal line, otherwise it is rotated for 45 degrees
 */
@property (nonatomic) BOOL drawRotated;

@end

/** @}*/
