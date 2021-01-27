//
//  INVImage.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "INVFoundation.h"

NS_ASSUME_NONNULL_BEGIN

/**
 셰이프에서 사용하는 비트맵 이미지를 정의한 클래스.
 */
INV_EXPORT
@interface INVImage : NSObject <NSSecureCoding>

#pragma mark Initializing and Preparing the Image Object

/**
 `UIImage`로부터 `INVImage` 객체를 생성합니다.
 재사용 식별자는 자동으로 지정됩니다.
 
 @param image 생성할 이미지 객체.
 @return `INVImage` 객체.
 */
+ (instancetype)imageWithImage:(nonnull UIImage *)image;

/**
 `UIImage`로부터 `INVImage` 객체를 생성합니다.
 재사용 식별자는 `reuseIdentifier`로 지정됩니다.
 
 @param image 생성할 이미지 객체.
 @param reuseIdentifier 재사용 식별자.
 @return `INVImage` 객체.
 */
+ (instancetype)imageWithImage:(nonnull UIImage *)image reuseIdentifier:(nullable NSString *)reuseIdentifier;

/**
 앱의 `Asset`으로부터 `INVImage` 객체를 생성합니다.
 재사용 식별자는 자동으로 지정됩니다.
 
 @param name 생성할 이미지 Asset 이름.
 @return `INVImage` 객체.
 */
+ (instancetype)imageWithName:(nonnull NSString *)name;

/**
 앱의 `Asset`으로부터 `INVImage` 객체를 생성합니다.
 재사용 식별자는 `reuseIdentifier`로 지정됩니다.
 
 @param name 생성할 이미지 Asset 이름.
 @param reuseIdentifier 재사용 식별자.
 @return `INVImage` 객체.
 */
+ (instancetype)imageWithName:(nonnull NSString *)name reuseIdentifier:(nullable NSString *)reuseIdentifier;

/**
 지정한 `Bundle`의 `Asset`으로부터 `INVImage` 객체를 생성합니다.
 재사용 식별자는 자동으로 지정됩니다.
 
 @param name 생성할 이미지 Asset 이름.
 @param bundle Asset이 포함된 번들.
 @return `INVImage` 객체.
 */
+ (instancetype)imageWithName:(nonnull NSString *)name inBundle:(nullable NSBundle *)bundle;

/**
 지정한 `Bundle`의 `Asset`으로부터 `INVImage` 객체를 생성합니다.
 재사용 식별자는 `reuseIdentifier`로 지정됩니다.
 
 @param name 생성할 이미지 Asset 이름.
 @param bundle Asset이 포함된 번들.
 @param reuseIdentifier 재사용 식별자.
 @return `INVImage` 객체.
 */
+ (instancetype)imageWithName:(nonnull NSString *)name inBundle:(nullable NSBundle *)bundle reuseIdentifier:(nullable NSString *)reuseIdentifier;

#pragma mark Getting and Setting Attributes

/**
이미지 객체.
*/
@property (nonatomic, readonly) UIImage *image;

/**
 재사용 식별자.
 */
@property (nonatomic, readonly, copy) NSString *reuseIdentifier;

@end

NS_ASSUME_NONNULL_END
