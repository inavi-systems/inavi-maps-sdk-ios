
#import <UIKit/UIKit.h>

#import "INVFoundation.h"

NS_ASSUME_NONNULL_BEGIN

@class INVMapCamera;

@class INVImage;
@class INVCameraPosition;
@class INVCameraUpdate;
@class INVProjection;
@class INVLatLngBounds;
@class INVMapOptions;

@protocol INVMapViewDelegate;

/**
 위치 추적 모드를 나타내는 열거형.
 */
typedef NS_ENUM(NSUInteger, INVUserTrackingMode) {
    
    /**
     사용자 위치 표시 및 추적을 사용하지 않는 모드.
     */
    INVUserTrackingModeNone = 0,
    
    /**
     사용자 위치는 표시하지만 카메라를 추적하지 않는 모드.
     */
    INVUserTrackingModeNoTracking,
    
    /**
     사용자 위치 표시와 카메라의 위치를 추적하는 모드.
     */
    INVUserTrackingModeTracking,
    
    /**
     사용자 위치 표시와 카메라의 좌표와 베어링을 추적하는 모드.
     */
    INVUserTrackingModeTrackingCompass,
};

/**
 아이나비 지도 객체를 정의하는 클래스
 해당 클래스를 이용하여 아이나비 인증 및 아이나비 지도를 사용할 수 있습니다.
 */

INV_EXPORT
IB_DESIGNABLE
@interface InaviMapView : UIView

#pragma mark Creating Instances

/**
 지정된 프레임 크기로 지도 뷰의 인스턴스를 생성합니다.

 @param frame 사용자 지정 프레임 크기.
 @return `InaviMapView` 인스턴스.
 */
- (instancetype)initWithFrame:(CGRect)frame;


/**
 지정된 프레임 크기와 지도의 기본 옵션을 지정하여 지도 뷰의 인스턴스를 생성합니다.
 
 @param frame 사용자 지정 프레임 크기.
 @param options 지도의 기본 옵션.
 @return `InaviMapView` 인스턴스.
 */
- (instancetype)initWithFrame:(CGRect)frame options:(INVMapOptions *)options;


#pragma mark Accessing the Delegate

/**
 `InaviMapView`의 delegate.
 
 지도 뷰의 delegate를 이용해 지도의 표출이나, 화면 갱신 여부 등의 메시지를 전달합니다.
 */

@property(nonatomic, weak, nullable) IBOutlet id<INVMapViewDelegate> delegate;

#pragma mark Configuring the Map’s Appearance

/**
 지도의 최소 줌 레벨.
 
 기본값은 `1`입니다.
 */
@property (nonatomic) double minimumZoomLevel;

/**
 지도의 최대 줌 레벨.
 
 기본값은 `20`입니다.
 */
@property (nonatomic) double maximumZoomLevel;

/**
 지도 영역 중심에 대한 카메라 위치.
 */
@property (nonatomic) INVCameraPosition *cameraPosition;

/**
 이 지도에 대한 `INVProjection` 객체.
 */
@property (nonatomic, readonly) INVProjection *projection;

/**
 지도의 패딩. 패딩에 해당하는 부분은 지도의 콘텐츠 영역에서 제외됩니다.
 */
@property (nonatomic, assign) UIEdgeInsets contentInset;

/**
 지도 영역에 대한 `INVLatLngBounds`.
 */
@property (nonatomic, readonly, copy) INVLatLngBounds *contentBounds;

/**
 축척 바 표출 여부.
 
 기본값은 `TRUE`입니다.
 */
@property (nonatomic, assign) IBInspectable BOOL showScaleBar;

/**
 나침반 표출 여부.

 기본값은 `TRUE`입니다.
 */
@property(nonatomic, assign) IBInspectable BOOL showCompass;

/**
 줌 컨트롤 표출 여부.
 
 기본값은 `FALSE`입니다.
 */
@property (nonatomic) IBInspectable BOOL showZoomControl;

/**
 현위치 버튼 표출 여부.
 
 기본값은 `FALSE`입니다.
 */
@property (nonatomic) IBInspectable BOOL showLocationButton;

#pragma mark Displaying the User’s Location

/**
 위치 추적 모드.
 
 @see `INVUserTrackingMode`
 */
@property (nonatomic, assign) INVUserTrackingMode userTrackingMode;

#pragma mark Configuring How the User Interacts with the Map

/**
 지도 줌 제스처 사용 여부를 나타내는 속성.
 
 기본값은 `TRUE`입니다.
 */
@property(nonatomic, getter=isZoomGesturesEnabled) BOOL zoomGesturesEnabled;

/**
 지도 스크롤 제스처 사용 여부를 나타내는 속성.
 
 기본값은 `TRUE`입니다.
 */
@property(nonatomic, getter=isScrollGesturesEnabled) BOOL scrollGesturesEnabled;

/**
 지도 회전 제스처 사용 여부를 나타내는 속성.
 
 기본값은 'TRUE'입니다.
 */
@property(nonatomic, getter=isRotateGesturesEnabled) BOOL rotateGesturesEnabled;

/**
 지도 기울기 제스처 사용 여부를 나타내는 속성.
 
 기본값은 `TRUE`입니다.
 */
@property(nonatomic, getter=isTiltGesturesEnabled) BOOL tiltGesturesEnabled;

/**
 지도 애니메이션 마찰 계수 입니다.
 값의 범위는 0~1이며, 계수가 클수록 마찰이 강해집니다.
 
 기본값은 UIScrollViewDecelerationRate의 `UIScrollViewDecelerationRateNormal`입니다.
 */
@property(nonatomic) CGFloat decelerationRate;
#pragma mark Manipulating the Viewpoint

/**
 카메라를 이동합니다.
 
 @param cameraUpdate `INVCameraUpdate` 객체.
 */
- (void)moveCamera:(INVCameraUpdate *)cameraUpdate;

/**
 카메라를 이동합니다.
 카메라 이동이 완료되거나 취소되었을 경우 `completion` 블록이 호출됩니다.
 
 @param cameraUpdate `INVCameraUpdate` 객체.
 @param completion   카메라 이동이 완료되었을 때 호출되는 콜백 블록. (완료 전에 다른 지도 조작으로 취소 여부를 isCancelled로 전달합니다.)
 */
- (void)moveCamera:(INVCameraUpdate *)cameraUpdate completion:(nullable void (^)(BOOL isCancelled))completion;

/**
 현재 진행 중인 지도 이동 애니메이션을 취소합니다.
 */
- (void)cancelTransitions;


@end

NS_ASSUME_NONNULL_END
