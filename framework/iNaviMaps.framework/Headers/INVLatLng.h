//
//  INVLatLng.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
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
@property (nonatomic, readonly) double lat;

/**
 경도 (도 단위)
 */
@property (nonatomic, readonly) double lng;

/**
 위도, 경도로  `INVLatLng` 객체를 생성합니다.
 
 @param lat 위도.
 @param lng 경도.
 @return `INVLatLng` 객체.
 */
+ (instancetype)latLngWithLat:(double)lat lng:(double)lng;

@end

NS_ASSUME_NONNULL_END
