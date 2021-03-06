//
//  HitTestBase.h
//  SciChart
//
//  Created by Admin on 03.12.15.
//  Copyright © 2015 SciChart Ltd. All rights reserved.
//

/** \addtogroup HitTest
 *  @{
 */

#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>
#import "SCIHitTestProvider.h"

@class SCIArrayController;

@interface SCIHitTestProviderBase : NSObject <SCIHitTestProvider>

-(int) getClosestPointToCoordX:(double)x Y:(double)y From:(id<SCIRenderPassData>)data;
-(CGPoint) getClosestPointOnSegmentToCoordX:(double)x Y:(double)y From:(id<SCIRenderPassData>)data;

- (int)getClosestIndexWithXValue:(double)xValue
                       andYValue:(double)yValue
                        andXData:(SCIArrayController*)xData
                        andYData:(SCIArrayController*)yData;

@property (nonatomic) SCIHitTestMode hitTestMode;

@end

/** @}*/
