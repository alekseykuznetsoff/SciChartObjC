//
//  IPen2D.h
//  SciChart
//
//  Created by Admin on 17.07.15.
//  Copyright (c) 2015 SciChart Ltd. All rights reserved.
//

#import "SCIOpenGLBrush.h"

/**
 @brief Protocol defines SciChart pens which provides stroke color and thickness
 @see SCIOpenGLBrush
 */
@protocol SCIPen2D <NSObject, SCIOpenGLBrush>

/**
 @brief Get stroke thickness of pen
 */
-(float) strokeThickness;

@end
