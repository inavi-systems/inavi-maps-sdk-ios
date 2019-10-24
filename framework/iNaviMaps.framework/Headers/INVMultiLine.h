//
//  INVMultiLine.h
//
//  Created by DAECHEOL KIM on 14/08/2019.
//  Copyright © 2019 iNaviMaps. All rights reserved.
//

#import "INVShape.h"

@class INVLine;

NS_ASSUME_NONNULL_BEGIN

/**
 다중 선형의 기본 전역 Z 인덱스
 */
const static int INV_MULTI_LINE_DEFAULT_GLOBAL_Z_INDEX = -1000;

/**
 지도 위에 다중 선형을 표출하는 Shape 클래스
 */
INV_EXPORT
@interface INVMultiLine : INVShape

/**
 다중 선형의 두께를 설정합니다.(pt 단위)
 
 기본값은 `2.5`입니다.
 */
@property (nonatomic) CGFloat width;

/**
 다중 선형의 끝 지점 모양을 설정합니다.
 
 기본값은 `INVLineCapRound`입니다.
 */
@property (nonatomic) INVLineCap capType;

/**
 다중 선형의 연결점 모양을 설정합니다.
 
 기본값은 `INVLineJoinRound`입니다.
 */
@property (nonatomic) INVLineJoin joinType;

/**
 다중 선형의 점선 패턴을 설정합니다. (pt 단위)
 배열 내 홀수 index의 값은 실선의 길이, 짝수 index의 값은 공백의 길이를 의미합니다.
 빈 배열일 경우 실선이 됩니다.
 */
@property (nonatomic, strong) NSArray<NSNumber *> *pattern;

/**
 다중 선형의 라인을 설정합니다.
 */
@property (nonatomic, copy) NSArray<INVLine *> *lines;

/**
 라인을 설정하여 다중 선형을 생성합니다.
 */
+ (instancetype)multiLineWithLines:(NSArray<INVLine *> *)lines;

@end

NS_ASSUME_NONNULL_END
