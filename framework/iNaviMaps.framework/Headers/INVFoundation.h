//
//  INVFoundation.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>

#define INV_EXPORT __attribute__((visibility ("default")))

#define INV_DEPRECATED __attribute__((deprecated ("")))

#define INV_DEPRECATED_WITH_TEXT(text) __attribute__((deprecated (text)))
