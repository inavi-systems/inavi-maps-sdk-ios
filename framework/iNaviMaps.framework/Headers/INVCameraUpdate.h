//
//  INVCameraUpdate.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>

#import "INVFoundation.h"


@class INVCameraUpdateParams;
@class INVCameraPosition;
@class INVLatLng;
@class INVLatLngBounds;

NS_ASSUME_NONNULL_BEGIN

/**
 카메라 이동 애니메이션 타입을 정의하는 열거형
 */
typedef NS_ENUM(NSUInteger, INVCameraUpdateAnimation) {
    /**
     애니메이션 없이 바로 이동합니다.
     */
    INVCameraUpdateAnimationNone,
    
    /**
     시간 경과에 따라, 균일하게 이동하는 애니메이션.
     */
    INVCameraUpdateAnimationLinear,
    
    /**
     시간 경과에 따라, 가감속이 적용되어 이동하는 애니메이션.
     */
    INVCameraUpdateAnimationEaseIn,
    
    /**
     시간 경과에 따라, 감속이 적용되어 이동하는 애니메이션.
     */
    INVCameraUpdateAnimationEaseOut,
    
    /**
     위치, 줌 레벨, 베어링, 기울기의 조합을 변경하여 비행처럼 이동하는 애니메이션.
     */
    INVCameraUpdateAnimationFly,
};

/**
 API 호출로 인한 카메라 이동.
 @see `INVCameraUpdate.reason`
 */
const static NSInteger INV_CAMERA_UPDATE_REASON_NONE = 0;

/**
 사용자 제스처로 인한 카메라 이동.
 @see `INVCameraUpdate.reason`
 */
const static NSInteger INV_CAMERA_UPDATE_REASON_GESTURE = -1;

/**
 지도 컨트롤 조작으로 인한 카메라 이동.
 @see `INVCameraUpdate.reason`
 */
const static NSInteger INV_CAMERA_UPDATE_REASON_CONTROL = -2;

/**
 위치 변경으로 인한 카메라 이동.
 @see `INVCameraUpdate.reason`
 */
const static NSInteger INV_CAMERA_UPDATE_REASON_LOCATION_CHANGED = -3;

/**
 카메라의 이동을 정의하는 클래스.
 
 카메라의 이동은 위치, 애니메이션, 줌, 스크롤로 구성되어 있습니다.
 */
INV_EXPORT
@interface INVCameraUpdate : NSObject


/**
 카메라 이동 시 적용할 애니메이션 타입.
 @see `INVCameraUpdateAnimation`
 */
@property (nonatomic) INVCameraUpdateAnimation animation;

/**
 카메라 이동 시 적용할 애니메이션 지속시간. (초 단위)
 
 기본값은 `0.3`입니다.
  */
@property (nonatomic) NSTimeInterval animationDuration;

/**
 카메라 이동의 원인.
 
 기본값은 `INV_CAMERA_UPDATE_REASON_NONE`입니다.
 */
@property (nonatomic) NSInteger reason;

/**
 `INVCameraUpdateParams`를 이용하여 `INVCameraUpdate` 객체를 생성합니다.
 
 @param params `INVCameraUpdateParams` 객체.
 @return `INVCameraUpdate` 객체.
*/
+ (instancetype)cameraUpdateWithParams:(INVCameraUpdateParams *)params;

/**
 `INVCameraPosition`를 이용하여 `INVCameraUpdate` 객체를 생성합니다.
 
 @param position `INVCameraPosition` 객체.
 @return `INVCameraUpdate` 객체.
 */
+ (instancetype)cameraUpdateWithPosition:(INVCameraPosition *)position;

/**
 현재 지도에 보여지는 `INVCameraPosition`에서 좌표를 변경하는 `INVCameraUpdate` 객체를 생성합니다.
 
 @param target 좌표.
 @return `INVCameraUpdate` 객체.
 */
+ (instancetype)cameraUpdateWithTargetTo:(INVLatLng *)target;

/**
 현재 지도에 보여지는 `INVCameraPosition`에서 좌표와 줌 레벨을 변경하는 `INVCameraUpdate` 객체를 생성합니다.
 
 @param target 좌표.
 @param zoom 줌 레벨.
 @return `INVCameraUpdate` 객체.
 */
+ (instancetype)cameraUpdateWithTargetTo:(INVLatLng *)target zoomTo:(double)zoom;

/**
 현재 지도에 보여지는 `INVCameraPosition`에서 좌표의 변화량을 적용하는 `INVCameraUpdate` 객체를 생성합니다.
 
 @param delta 줌 레벨 변화량.
 @return `INVCameraUpdate` 객체.
 */
//+ (instancetype)cameraUpdateWithTargetBy:(CGPoint)delta;

/**
 현재 지도에 보여지는 `INVCameraPosition`에서 줌 레벨을 한 단계 증가하는 `INVCameraUpdate` 객체를 생성합니다.
 
 @return `INVCameraUpdate` 객체.
 */
+ (instancetype)cameraUpdateWithZoomIn;

/**
 현재 지도에 보여지는 `INVCameraPosition`에서 줌 레벨을 한 단계 감소하는 `INVCameraUpdate` 객체를 생성합니다.
 
 @return `INVCameraUpdate` 객체.
 */
+ (instancetype)cameraUpdateWithZoomOut;

/**
 현재 지도에 보여지는 `INVCameraPosition`에서 줌 레벨을 변경하는 `INVCameraUpdate` 객체를 생성합니다.
 
 @param zoom 줌 레벨.
 @return `INVCameraUpdate` 객체.
 */
+ (instancetype)cameraUpdateWithZoomTo:(double)zoom;

/**
 현재 지도에 보여지는 `INVCameraPosition`에서 줌 레벨의 변화량을 적용하는 `INVCameraUpdate` 객체를 생성합니다.
 
 @param delta 줌 레벨 변화량.
 @return `INVCameraUpdate` 객체.
 */
+ (instancetype)cameraUpdateWithZoomBy:(double)delta;

/**
 현재 지도에 보여지는 `INVCameraPosition`에서 기울기를 변경하는 `INVCameraUpdate` 객체를 생성합니다.
 
 @param tilt 기울기.
 @return `INVCameraUpdate` 객체.
 */
+ (instancetype)cameraUpdateWithTiltTo:(double)tilt;

/**
 현재 지도에 보여지는 `INVCameraPosition`에서 베어링을 변경하는 `INVCameraUpdate` 객체를 생성합니다.
 
 @param bearing 베어링 값.
 @return `INVCameraUpdate` 객체.
 */
+ (instancetype)cameraUpdateWithBearingTo:(double)bearing;

/**
 새로운 `INVLatLngBounds` 범위로 위치와 줌 레벨을 변경하는 `INVCameraUpdate` 객체를 생성합니다.
 
 @param bounds `INVLatLngBounds` 객체.
 @return `INVCameraUpdate` 객체.
 */
+ (instancetype)cameraUpdateWithFitBounds:(INVLatLngBounds *)bounds;

/**
 새로운 `INVLatLngBounds` 범위로 위치와 줌 레벨을 변경하는 `INVCameraUpdate` 객체를 생성합니다.
 
 @param bounds `INVLatLngBounds` 객체.
 @param padding 패딩 값. (pt 단위)
 @return `INVCameraUpdate` 객체.
 */
+ (instancetype)cameraUpdateWithFitBounds:(INVLatLngBounds *)bounds padding:(CGFloat)padding;

/**
 새로운 `INVLatLngBounds` 범위로 위치와 줌 레벨을 변경하는 `INVCameraUpdate` 객체를 생성합니다.
 
 @param bounds `INVLatLngBounds` 객체.
 @param paddingInsets 패딩 값. (pt 단위)
 @return `INVCameraUpdate` 객체.
 */
+ (instancetype)cameraUpdateWithFitBounds:(INVLatLngBounds *)bounds paddingInsets:(UIEdgeInsets)paddingInsets;

@end

NS_ASSUME_NONNULL_END
