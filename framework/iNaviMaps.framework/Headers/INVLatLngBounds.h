//
//  INVLatLngBounds.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
//

#import "INVFoundation.h"

@class INVLatLng;

NS_ASSUME_NONNULL_BEGIN

/**
 북동쪽, 남서쪽의 위도, 경도 좌표로 구성된 범위 사각형 영역 클래스.
 */

INV_EXPORT
@interface INVLatLngBounds : NSObject

/**
 남서쪽 좌표.
 */
@property (nonatomic, readonly) INVLatLng *southWest;

/**
 북동쪽 좌표.
 */
@property (nonatomic, readonly) INVLatLng *northEast;

/**
 남동쪽 좌표.
 */
@property (nonatomic, readonly) INVLatLng *southEast;

/**
 북서쪽 좌표.
 */
@property (nonatomic, readonly) INVLatLng *northWest;

/**
 중심점 좌표.
 */
@property (nonatomic, readonly) INVLatLng *center;

/**
 현재 사각형 영역에 특정 좌표가 포함되어 있는지 여부를 반환합니다.
 */
- (BOOL)containsLatLng:(INVLatLng *)latLng;

/**
 현재 사각형 영역에 특정 사각형 영역이 포함되어 있는지 여부를 반환합니다.
 */
- (BOOL)containsBounds:(INVLatLngBounds *)bounds;

/**
남서쪽, 북동쪽 좌표로 `INVLatLngBounds` 객체를 생성합니다.

@param southWest 남서쪽 좌표.
@param northEast 북동쪽 좌표.
@return `INVLatLngBounds`객체.
*/
+ (instancetype)boundsWithSouthWest:(INVLatLng *)southWest northEast:(INVLatLng *)northEast;

/**
 좌표열을 포함하는 최소한의 사각형 영역으로 `INVLatLngBounds` 객체를 생성합니다.
 
 `coords`의 크기는 `2` 이상이어야 합니다.
 
 @param coords 사각형 영역에 포함될 좌표열.
 @return `INVLatLngBounds`객체.
 */
+ (instancetype)boundsWithCoords:(NSArray<INVLatLng *> *)coords;

/**
 남서쪽, 북동쪽 좌표로 `INVLatLngBounds` 객체를 생성합니다.
 
 @param southWest 남서쪽 좌표.
 @param northEast 북동쪽 좌표.
 @return `INVLatLngBounds` 객체.
 */
+ (instancetype)latLngBoundsSouthWest:(INVLatLng *)southWest northEast:(INVLatLng *)northEast INV_DEPRECATED_WITH_TEXT("`boundsWithSouthWest:northEast`로 대체됩니다.");

@end

NS_ASSUME_NONNULL_END
