//
//  INVMapViewDelegate.h
//
//  Created by DAECHEOL KIM on 04/07/2019.
//  Copyright © 2019 iNaviMaps. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "iNaviMaps.h"

NS_ASSUME_NONNULL_BEGIN

@class InaviMapView;
@class INVLatLng;

/**
`InaviMapView`에 관련된 업데이트 및 비동기 작업의 결과를 알려주는 콜백 메서드가 정의된 프로토콜.
*/
@protocol INVMapViewDelegate <NSObject>

@optional

#pragma mark Responding to Map Position Changes


/**
 지도가 표시하는 영역이 변경될 때 호출되는 콜백 메서드.

 @param mapView 영역이 변경될 `InaviMapView` 객체.
 @param animated 애니메이션 효과가 적용돼 움직일 경우 `true`, 그렇지 않을 경우 `false`.
 @param reason 카메라 변경 이유.
 */
- (void)mapView:(InaviMapView *)mapView regionWillChangeAnimated:(BOOL)animated reason:(NSInteger)reason;

/**
 지도가 표시하고 있는 영역이 변경되고 있을 때 호출되는 콜백 메서드.

 @param mapView 영역이 변경되고 있는 `InaviMapView` 객체.
 @param reason 카메라 변경 이유.
 */
- (void)mapView:(InaviMapView *)mapView regionIsChangingWithReason:(NSInteger)reason;

/**
 지도가 표시하고 있는 영역이 변경되었을 때 호출되는 콜백 메서드.

 @param mapView 영역이 변경된 `INaviMapView` 객체.
 @param animated 애니메이션 효과가 적용돼 움직인 경우 `true`, 그렇지 않은 경우 `false`.
 @param reason 카메라 변경 이유.
 */
- (void)mapView:(InaviMapView *)mapView regionDidChangeAnimated:(BOOL)animated reason:(NSInteger)reason;


/**
 지도가 표시하고 있는 영역이 변경된 후 진행 중인 터치 이벤트가 없을 때 호출되는 콜백 메서드.

 @param mapView 영역이 변경된 `INaviMapView` 객체.
 */
- (void)mapViewDidBecomeIdle:(InaviMapView *)mapView;

#pragma mark Responding to Map Event

/**
 사용자가 지도를 탭하면 호출됩니다.

 @param point 탭한 화면 좌표.
 @param latlng 탭한 위경도 좌표.
 */
- (void)didTapMapView:(CGPoint)point LatLng:(INVLatLng*)latlng;

/**
 사용자가 지도를 더블 탭하면 호출됩니다.

 @param point 더블 탭한 화면 좌표.
 @param latlng 더블 탭한 위경도 좌표.
 @return `true`일 경우 이벤트를 소비합니다. 그렇지 않을 경우 `InaviMapView`까지 이벤트가 전달됩니다.
 */
- (BOOL)didDoubleTapMapView:(CGPoint)point LatLng:(INVLatLng*)latlng;

/**
 사용자가 지도를 롱 탭하면 호출됩니다.
 
 @param point 롱 탭한 화면 좌표.
 @param latlng 롱 탭한 위경도 좌표.
 */
- (void)didLongTapMapView:(CGPoint)point LatLng:(INVLatLng*)latlng;

#pragma mark Tracking User Location

/**
 위치 추적 모드가 변경될 때 호출되는 콜백 메서드.

 @param mapView 위치 추적 모드가 적용된 `InaviMapView` 객체.
 @param mode 위치 추적 모드.
 @param animated 애니메이션 효과가 적용돼 움직인 경우 `true`, 그렇지 않은 경우 `false`.
 */
- (void)mapView:(InaviMapView *)mapView didChangeUserTrackingMode:(INVUserTrackingMode)mode animated:(BOOL)animated;

/**
 위치가 업데이트 되면 호출되는 콜백 메서드.

@param mapView 위치 추적 모드가 적용된 `InaviMapView` 객체.
@param userLocation 업데이트 된 위치
*/
- (void)mapView:(InaviMapView *)mapView didUpdateUserLocation:(nullable CLLocation *)userLocation;
@end
NS_ASSUME_NONNULL_END
