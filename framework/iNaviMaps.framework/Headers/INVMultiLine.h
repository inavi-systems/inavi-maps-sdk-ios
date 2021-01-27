//
//  INVMultiLine.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
//

#import "INVShape.h"

@class INVLine;

NS_ASSUME_NONNULL_BEGIN

/**
 다중 선형의 기본 전역 Z 인덱스.
 */
const static int INV_MULTI_LINE_DEFAULT_GLOBAL_Z_INDEX = -1000;


/**
지도 위에 다중 선형을 표출하는 셰이프 클래스.
*/
INV_DEPRECATED_WITH_TEXT("`INVRoute`로 대체됩니다.")
INV_EXPORT
@interface INVMultiLine : INVShape

/**
 다중 선형의 두께. (pt 단위)
 
 기본값은 `2.5`입니다.
 */
@property (nonatomic) CGFloat width;

/**
 다중 선형의 끝 지점 모양.
 
 기본값은 `INVLineCapRound`입니다.
 */
@property (nonatomic) INVLineCap capType;

/**
 다중 선형의 연결점 모양.
 
 기본값은 `INVLineJoinRound`입니다.
 */
@property (nonatomic) INVLineJoin joinType;

/**
 다중 선형의 점선 패턴. (pt 단위)
 
 배열 내 홀수 index의 값은 실선의 길이, 짝수 index의 값은 공백의 길이를 의미합니다.<br>
 빈 배열일 경우 실선이 됩니다.
 */
@property (nonatomic, strong) NSArray<NSNumber *> *pattern;

/**
 다중 선형의 라인 배열.
 */
@property (nonatomic, copy) NSArray<INVLine *> *lines;

/**
 라인 배열을 이용하여 다중 선형 객체를 생성합니다.
 
 @param lines 라인 배열.
 @return `INVMultiLine` 객체.
 */
+ (instancetype)multiLineWithLines:(NSArray<INVLine *> *)lines;

@end

NS_ASSUME_NONNULL_END
