//
//  INVLatLng.h
//
//  Created by DAECHEOL KIM on 17/06/2019.
//  Copyright © 2019 iNaviMaps. All rights reserved.
//

#import "INVFoundation.h"

NS_ASSUME_NONNULL_BEGIN

/**
 위도, 경도 좌표를 나타내는 클래스.
 */

INV_EXPORT
@interface INVLatLng : NSObject

/**
 위도 (도 단위)
 */
@property (nonatomic) double lat;

/**
 경도 (도 단위)
 */
@property (nonatomic) double lng;

/**
 위도, 경도로  Coordinate 객체를 생성합니다.
 
 @param lat 위도.
 @param lng 경도.
 @return INVLatLng 객체.
 */
+ (nonnull instancetype)latLngWithLat:(double)lat lng:(double)lng;

@end

NS_ASSUME_NONNULL_END
