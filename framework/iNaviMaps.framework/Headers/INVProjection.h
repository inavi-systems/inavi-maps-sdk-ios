//
//  INVProjection.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "INVFoundation.h"

@class INVLatLng;
@class INVLatLngBounds;
@class InaviMapView;

NS_ASSUME_NONNULL_BEGIN

/**
 단말 화면 상의 좌표와 지도 상의 좌표 간 변환을 담당하는 클래스.
 */

INV_EXPORT
@interface INVProjection : NSObject

+ (instancetype)projection:(InaviMapView *)mapView;

/**
 단말 화면 상의 좌표를 지도 상의 좌표(위도, 경도)로 변환합니다.
 
 @param point 화면 좌표.
 @return INVLatLng 객체.
 */
- (INVLatLng *)latlngFromPoint:(CGPoint)point;

/**
 지도 상의 좌표를 단말 화면 상의 좌표(x, y)로 변환합니다.
 
 @param coord 위경도 좌표.
 @return 화면 좌표. `coord`가 유효하지 않으면 CGPointZero 좌표가 반환됩니다.
 */
- (CGPoint)pointFromLatLng:(INVLatLng *)coord;

/**
 단말 화면 상의 영역을 위경도 영역으로 변환합니다.
 
 @param viewBounds 화면 영역.
 @return 위경도 영역.
 */
- (INVLatLngBounds *)latlngBoundsFromViewBounds:(CGRect)viewBounds;

/**
 위경도 영역을 단말 화면 상의 영역으로 변환합니다.
 
 @param latlngBounds 위경도 영역.
 @return 화면 영역.
 */
- (CGRect)viewBoundsFromLatLngBounds:(INVLatLngBounds *)latlngBounds;

/**
 카메라의 위도에 따른 축척을 미터/픽셀 단위로 반환합니다.
 
 @return 축척. (미터/픽셀 단위)
 */
- (double)metersPerPixel;

/**
 카메라의 위도, 줌 레벨에 따른 축척을 미터/픽셀 단위로 반환합니다.
 
 @param latitude 카메라의 위도.
 @param zoom 줌 레벨.
 @return 축척. (미터/픽셀 단위)
 */
- (double)metersPerPixelAtLatitude:(double)latitude zoom:(double)zoom;

@end

NS_ASSUME_NONNULL_END
