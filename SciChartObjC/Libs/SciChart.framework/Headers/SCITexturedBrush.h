//
//  SCITexturedBrush.h
//  SciChart
//
//  Created by Admin on 05.02.16.
//  Copyright © 2016 SciChart Ltd. All rights reserved.
//

@class SCITextureOpenGL;

/**
 @brief Protocol defines brush that use texture for drawing. Class should implement SCIBrush2D or SCIPen2D too.
 @see SCIBrush2D
 @see SCIPen2D
 */
@protocol SCITexturedBrush <NSObject>

/**
 @brief Get OpenGl texture assigned to brush
 @see SCITextureOpenGL
 */
@property (nonatomic, strong, readonly) SCITextureOpenGL* texture;

@end
