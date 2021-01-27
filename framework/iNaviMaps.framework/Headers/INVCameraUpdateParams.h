//
//  INVCameraUpdateParams.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import "INVFoundation.h"

NS_ASSUME_NONNULL_BEGIN

@class InaviMapView;
@class INVLatLng;

/**
 카메라를 이동할 지점에 대한 정보를 정의하는 클래스.
 
 `INVCameraUpdate`에 전달하여 `INVCameraPosition`에 상대적인 변화를 줄 수 있습니다.
 
 @see `+[INVCameraUpdate cameraUpdateWithParams:]`
 */

INV_EXPORT
@interface INVCameraUpdateParams : NSObject

/**
 기본 생성자.
 */
+ (instancetype)cameraUpdateParams;


/**
 카메라를 특정 위치로 이동하도록 설정합니다.
 
 @param target 지정할 좌표.
 */
- (void)scrollTo:(INVLatLng *)target INV_DEPRECATED_WITH_TEXT("`targetTo`로 대체됩니다.");


/**
 카메라를 특정 위치로 이동하도록 설정합니다.
 
 @param target 지정할 좌표.
 */
- (void)targetTo:(INVLatLng *)target;

/**
 카메라를 위치를 현위치 기준으로 특정 값 만큼 이동하도록 설정합니다.
 
 @param delta 이동할 거리. (pt 단위)
 */
- (void)scrollBy:(CGPoint)delta INV_DEPRECATED_WITH_TEXT("`targetBy`로 대체됩니다.");

/**
 카메라를 위치를 현위치 기준으로 특정 값 만큼 이동하도록 설정합니다.
 
 @param delta 이동할 거리. (pt 단위)
 */
- (void)targetBy:(CGPoint)delta;

/**
 카메라의 줌 레벨을 특정 값만큼 변경하도록 설정합니다.
 
 @param zoom 지정할 줌 레벨.
 */
- (void)zoomTo:(double)zoom;

/**
 카메라의 줌 레벨을 상대적인 값으로 설정합니다.
 
 @param delta 줌 레벨의 변화량.
 */
- (void)zoomBy:(double)delta;

/**
 카메라의 줌 레벨을 `1`증가하도록 지정합니다.
 */
- (void)zoomIn;

/**
 카메라의 줌 레벨을 `1`감소하도록 지정합니다.
 */
- (void)zoomOut;

/**
 카메라의 기울기 각도를 특정 값으로 변경하도록 설정합니다.
 
 @param tilt 기울기 각도. (도 단위)
 */
- (void)tiltTo:(double)tilt;

/**
 카메라의 기울기 각도를 상대적인 값으로 설정합니다.
 
 @param delta 기울기 각도의 변화량(도 단위)
 */
- (void)tiltBy:(double)delta;

/**
 카메라의 베어링 각도를 특정 값만큼 변경하도록 설정합니다.
 
 @param bearing 베어링 각도(도 단위)
 */
- (void)bearingTo:(double)bearing;

/**
 카메라의 베어링 각도를 상대적인 값으로 설정합니다.
 
 @param delta 베어링 각도의 변화량(도 단위)
 */
- (void)bearingBy:(double)delta;

@end

NS_ASSUME_NONNULL_END
