//
//  PointMarkerBase.h
//  SciChart
//
//  Created by Admin on 26.11.15.
//  Copyright © 2015 SciChart Ltd. All rights reserved.
//

/** \addtogroup PointMarkers
 *  @{
 */

#import <Foundation/Foundation.h>
#import "SCIPointMarker.h"
/**
 @brief Provides base functions for point markers
 @see SCIPointMarker
 */
@interface SCIPointMarkerBase : NSObject <SCIPointMarker> {
@protected
    float _width;
    float _height;
}

@end

/** @}*/
