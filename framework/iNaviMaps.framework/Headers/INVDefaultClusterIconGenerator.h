//
//  INVDefaultClusterIconGenerator.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
//

#import "INVClusterIconGenerator.h"
#import "INVImage.h"

NS_ASSUME_NONNULL_BEGIN

/**
 기본 클러스터 아이콘 이미지 생성기 클래스.
 */
INV_EXPORT
@interface INVDefaultClusterIconGenerator : NSObject<INVClusterIconGenerator>

#pragma mark Creating Instances

/**
 `initWithColors:criteria:` 또는 `initWithImages:criteria:` 생성자를 사용하세요.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 배경 색상을 설정하여 `INVDefaultClusterIconGenerator` 객체를 생성합니다.<br>
 `criteria`의 크기는 `1` 이상이어야 하며, 포함된 원소들의 값은 양수이면서 순차적으로 커져야 합니다.
 @param colors 클러스터 아이콘의 배경 색상 배열.
 @param criteria 클러스터 아이콘의 배경 색상을 구분하는 아이템 개수의 기준.
 @return `INVDefaultClusterIconGenerator` 객체.
*/
- (instancetype)initWithColors:(NSArray<UIColor *> *)colors criteria:(NSArray<NSNumber *> *)criteria;

/**
 배경 이미지를 설정하여 `INVDefaultClusterIconGenerator` 객체를 생성합니다.<br>
 `criteria`의 크기는 `1` 이상이어야 하며, 포함된 원소들의 값은 양수이면서 순차적으로 커져야 합니다.
 @param images 클러스터 아이콘의 배경 이미지 배열.
 @param criteria 클러스터 아이콘의 배경 이미지를 구분하는 아이템 개수의 기준. 
 @return `INVDefaultClusterIconGenerator` 객체.
*/
- (instancetype)initWithImages:(NSArray<UIImage *> *)images criteria:(NSArray<NSNumber *> *)criteria;

#pragma mark Generating Cluster Icon Image

/**
 아이템 개수에 따른 아이콘 이미지를 생성합니다.
 */
- (INVImage *)iconForCount:(NSUInteger)count;

@end

NS_ASSUME_NONNULL_END
