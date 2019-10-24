//
//  INVShape.h
//
//  Created by DAECHEOL KIM on 13/06/2019.
//  Copyright © 2019 iNaviMaps. All rights reserved.
//
#import <UIKit/UIKit.h>
#import "INVFoundation.h"
#import "INVLatLng.h"

@class INVShape;
@class InaviMapView;

NS_ASSUME_NONNULL_BEGIN


/**
 오버레이 터치에 대한 이벤트 핸들러 블록 타입 선언.
 
 @return `true`일 경우 이벤트를 소비합니다. 그렇지 않을 경우 `InaviMapView`까지 이벤트가 전달되어 `INVMapViewDelegate`의 `didTapMapView`가 호출됩니다.
 */

typedef BOOL (^INVShapeTouchEvent)(INVShape * __weak);

/**
 연결점의 모양을 정의하는 열거형.
 */
typedef NS_ENUM(NSUInteger, INVLineJoin) {
    /**
     사면.
     */
    INVLineJoinBevel,
    /**
     원형.
     */
    INVLineJoinRound,
    /**
     미터.
     */
    INVLineJoinMiter,
};

/**
 끝 지점의 모양을 정의하는 열거형.
 */
typedef NS_ENUM(NSUInteger, INVLineCap) {
    /**
     평면.
     */
    INVLineCapButt,
    /**
     원형.
     */
    INVLineCapRound,
    /**
     사각형.
     */
    INVLineCapSquare,
};

/**
 아이나비 지도 위에 표출되는 Shape의 속성을 관리하는 클래스.
 지도에 추가되거나 제거 될 수 있습니다.
 */

INV_EXPORT
@interface INVShape : NSObject


#pragma mark Accessing the Shape Attributes

@property (nonatomic, readonly) NSString* identifier;

/**
 shape에 임의 사용자 정보를 저장할 수 있습니다.
 */
@property (nonatomic, strong) NSDictionary *userInfo;

/**
 Shape를 추가할 지도 객체. `nil`을 지정하면 지도에서 제거됩니다.
 */
@property (nonatomic, weak, nullable) InaviMapView *mapView;

/**
 zIndex. 두 shape가 겹쳐진 경우, 높은 값일 수록 앞에 표출됩니다.
 */

@property (nonatomic) NSInteger zIndex;

/**
 Shape의 전역 Z Index를 설정합니다.
 */
@property(nonatomic) NSInteger globalZIndex;

/**
 Shape가 표출되기 위한 최소 줌 레벨.
 
 기본값은 `1`입니다.
 */
@property (nonatomic) double visibleMinZoom;

/**
 Shape가 표출되기 위한 최대 줌 레벨.
 
 기본값은 `20`입니다.
 */
@property (nonatomic) double visibleMaxZoom;


/**
 Shape 표출 여부.

 값이 false이면 Shape 관련 이벤트 Callback을 받을 수 없습니다.

 Shape가 지도 영역 밖에 위치하더라도 해당 값은 변함 없이 유지됩니다.
 */
@property (nonatomic, assign, getter=isVisible) BOOL visible;


/**
 Shape 객체가 지도(InaviMapView)에 등록된 상태를 나타냅니다.
 */
@property (nonatomic, readonly) BOOL isAttached;


/**
 shape 아이템이 터치될 경우 호출되는 이벤트 블록.
 */
@property (nonatomic, nullable) INVShapeTouchEvent touchEvent;

@end

/**
 `Shape`에서 사용하는 이미지 리소스를 생성하는 기본 프로토콜.
 */
@protocol INVImageDataSource <NSObject>
@required
@end

/**
 `Shape`에서 사용하는 이미지 리소스를 `UIView`로 구성하는 프로토콜
 */
@protocol INVImageViewDataSource <INVImageDataSource>
@required

/**
 이미지로 변환할 `UIView`를 구성해야 합니다.
 @param shape 이미지를 사용하는 `INVShape` 객체.
 @return 이미지로 변환할 `UIView` 객체.
 */
- (UIView *)viewWithShape:(INVShape *)shape;

@end


/**
 `Shape`에서 사용하는 이미지 리소스를 `NSString`으로 구성하면 title을 포함해 기본 배경이 있는 이미지로 구성하는 프로토콜
 */
@protocol INVImageTextDataSource <INVImageDataSource>
@required

/**
 이미지로 변환할 `NSString`을 구성해야 합니다.
 @param shape 이미지를 사용하는 `INVShape` 객체.
 @return 기본 이미지로 변환할 `NSString` 객체.
 */
- (NSString *)titleWithShape:(INVShape *)shape;
@end


NS_ASSUME_NONNULL_END
