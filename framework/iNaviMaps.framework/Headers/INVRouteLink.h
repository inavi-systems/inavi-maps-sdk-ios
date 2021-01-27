//
//  INVRouteLink.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "INVFoundation.h"



@class INVLatLng;

NS_ASSUME_NONNULL_BEGIN

INV_EXPORT
/**
 경로를 구성하는 좌표열과 색상 속성을 정의한 클래스.
 
 @see `INVRoute`
 */

@interface INVRouteLink : NSObject

/**
 경로의 선 색상.
 
 기본값은 `UIColor.whiteColor`입니다.
 */
@property (nonatomic, copy)  UIColor* _Nonnull lineColor;

/**
 경로의 테두리 색상.
 
 기본값은 `UIColor.blackColor`입니다.
 */
@property (nonatomic, copy)  UIColor* _Nonnull strokeColor;

/**
 경로의 좌표열.
 
 `coords`의 크기는 `2` 이상이어야 합니다.
 */
@property (nonatomic, copy)  NSArray<INVLatLng*>* _Nonnull coords;

/**
 좌표열을 이용하여 링크 객체를 생성합니다.

 `coords`의 크기는 `2` 이상이어야 합니다.

 @param coords 좌표열.
 @return `INVRouteLink` 객체.
*/
+ (instancetype)linkWithCoords:(NSArray<INVLatLng *> *_Nonnull)coords;

/**
 좌표열과 선 색상을 이용하여 링크 객체를 생성합니다.
 
 `coords`의 크기는 `2` 이상이어야 합니다.
 
  @param coords 좌표열.
  @param lineColor 색상.
  @return `INVRouteLink` 객체.
 */
+ (instancetype)linkWithCoords:(NSArray<INVLatLng *> *_Nonnull)coords
                     lineColor:(UIColor *_Nonnull)lineColor; 

/**
 좌표열과 선 색상, 테두리 색상을 이용하여 링크 객체를 생성합니다.
 
 `coords`의 크기는 `2` 이상이어야 합니다.
 
  @param coords 좌표열.
  @param lineColor 색상.
  @param strokeColor 테두리 색상.
  @return `INVRouteLink` 객체.
 */
+ (instancetype)linkWithCoords:(NSArray<INVLatLng *> *_Nonnull)coords
                     lineColor:(UIColor *_Nonnull)lineColor
                   strokeColor:(UIColor *_Nonnull)strokeColor;

@end
NS_ASSUME_NONNULL_END
