//
//  SCISpritePointMarker.h
//  SciChart
//
//  Created by Admin on 28.03.16.
//  Copyright © 2016 SciChart Ltd. All rights reserved.
//

/** \addtogroup PointMarkers
 *  @{
 */

#import <Foundation/Foundation.h>
#import "SCIPointMarkerBase.h"

@protocol SCITexturedBrush;

/**
 @brief Point marker with texture drawing
 @see SCIPointMarker
 */
@interface SCISpritePointMarker : SCIPointMarkerBase

/**
 @brief Defines textured brush for point marker
 @see SCITexturedBrush
 */
@property (nonatomic, strong) id<SCITexturedBrush> brush;

@end

/** @}*/
