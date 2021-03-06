//
//  HeatMapHitTest.h
//  SciChart
//
//  Created by Admin on 12.02.16.
//  Copyright © 2016 SciChart Ltd. All rights reserved.
//

/** \addtogroup HitTest
 *  @{
 */

#import <Foundation/Foundation.h>
#import "SCIHitTestProvider.h"

@interface SCIHeatMapHitTestProvider : NSObject <SCIHitTestProvider>

@property (nonatomic) SCIHitTestMode hitTestMode;

@end

/** @}*/
