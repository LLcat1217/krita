/*
 *  SPDX-FileCopyrightText: 2012 Dmitry Kazakov <dimula73@gmail.com>
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#if !defined _MSC_VER
#pragma GCC diagnostic ignored "-Wundef"
#endif

#include "KoOptimizedCompositeOpFactoryPerArch.h"
#include "KoOptimizedCompositeOpAlphaDarken32.h"
#include "KoOptimizedCompositeOpAlphaDarken128.h"
#include "KoOptimizedCompositeOpOver32.h"
#include "KoOptimizedCompositeOpOver128.h"
#include "KoOptimizedCompositeOpCopy128.h"

#include <QString>
#include "DebugPigment.h"

#include <KoCompositeOpRegistry.h>

#if defined(__clang__)
#pragma GCC diagnostic ignored "-Wlocal-type-template-args"
#endif

template<>
template<>
KoOptimizedCompositeOpFactoryPerArch<KoOptimizedCompositeOpAlphaDarkenHard32>::ReturnType
KoOptimizedCompositeOpFactoryPerArch<KoOptimizedCompositeOpAlphaDarkenHard32>::create<Vc::CurrentImplementation::current()>(ParamType param)
{
    return new KoOptimizedCompositeOpAlphaDarkenHard32<Vc::CurrentImplementation::current()>(param);
}


template<>
template<>
KoOptimizedCompositeOpFactoryPerArch<KoOptimizedCompositeOpAlphaDarkenCreamy32>::ReturnType
KoOptimizedCompositeOpFactoryPerArch<KoOptimizedCompositeOpAlphaDarkenCreamy32>::create<Vc::CurrentImplementation::current()>(ParamType param)
{
    return new KoOptimizedCompositeOpAlphaDarkenCreamy32<Vc::CurrentImplementation::current()>(param);
}

template<>
template<>
KoOptimizedCompositeOpFactoryPerArch<KoOptimizedCompositeOpOver32>::ReturnType
KoOptimizedCompositeOpFactoryPerArch<KoOptimizedCompositeOpOver32>::create<Vc::CurrentImplementation::current()>(ParamType param)
{
    return new KoOptimizedCompositeOpOver32<Vc::CurrentImplementation::current()>(param);
}

template<>
template<>
KoOptimizedCompositeOpFactoryPerArch<KoOptimizedCompositeOpAlphaDarkenHard128>::ReturnType
KoOptimizedCompositeOpFactoryPerArch<KoOptimizedCompositeOpAlphaDarkenHard128>::create<Vc::CurrentImplementation::current()>(ParamType param)
{
    return new KoOptimizedCompositeOpAlphaDarkenHard128<Vc::CurrentImplementation::current()>(param);
}

template<>
template<>
KoOptimizedCompositeOpFactoryPerArch<KoOptimizedCompositeOpAlphaDarkenCreamy128>::ReturnType
KoOptimizedCompositeOpFactoryPerArch<KoOptimizedCompositeOpAlphaDarkenCreamy128>::create<Vc::CurrentImplementation::current()>(ParamType param)
{
    return new KoOptimizedCompositeOpAlphaDarkenCreamy128<Vc::CurrentImplementation::current()>(param);
}


template<>
template<>
KoOptimizedCompositeOpFactoryPerArch<KoOptimizedCompositeOpOver128>::ReturnType
KoOptimizedCompositeOpFactoryPerArch<KoOptimizedCompositeOpOver128>::create<Vc::CurrentImplementation::current()>(ParamType param)
{
    return new KoOptimizedCompositeOpOver128<Vc::CurrentImplementation::current()>(param);
}

template<>
template<>
KoOptimizedCompositeOpFactoryPerArch<KoOptimizedCompositeOpOverU64>::ReturnType
KoOptimizedCompositeOpFactoryPerArch<KoOptimizedCompositeOpOverU64>::create<Vc::CurrentImplementation::current()>(ParamType param)
{
    return new KoOptimizedCompositeOpOverU64<Vc::CurrentImplementation::current()>(param);
}

template<>
template<>
KoOptimizedCompositeOpFactoryPerArch<KoOptimizedCompositeOpCopy128>::ReturnType
KoOptimizedCompositeOpFactoryPerArch<KoOptimizedCompositeOpCopy128>::create<Vc::CurrentImplementation::current()>(ParamType param)
{
    return new KoOptimizedCompositeOpCopy128<Vc::CurrentImplementation::current()>(param);
}

template<>
template<>
KoOptimizedCompositeOpFactoryPerArch<KoOptimizedCompositeOpCopyU64>::ReturnType
KoOptimizedCompositeOpFactoryPerArch<KoOptimizedCompositeOpCopyU64>::create<Vc::CurrentImplementation::current()>(ParamType param)
{
    return new KoOptimizedCompositeOpCopyU64<Vc::CurrentImplementation::current()>(param);
}

template<>
template<>
KoOptimizedCompositeOpFactoryPerArch<KoOptimizedCompositeOpCopy32>::ReturnType
KoOptimizedCompositeOpFactoryPerArch<KoOptimizedCompositeOpCopy32>::create<Vc::CurrentImplementation::current()>(ParamType param)
{
    return new KoOptimizedCompositeOpCopy32<Vc::CurrentImplementation::current()>(param);
}

template<>
template<>
KoOptimizedCompositeOpFactoryPerArch<KoOptimizedCompositeOpAlphaDarkenHardU64>::ReturnType
KoOptimizedCompositeOpFactoryPerArch<KoOptimizedCompositeOpAlphaDarkenHardU64>::create<Vc::CurrentImplementation::current()>(ParamType param)
{
    return new KoOptimizedCompositeOpAlphaDarkenHardU64<Vc::CurrentImplementation::current()>(param);
}

template<>
template<>
KoOptimizedCompositeOpFactoryPerArch<KoOptimizedCompositeOpAlphaDarkenCreamyU64>::ReturnType
KoOptimizedCompositeOpFactoryPerArch<KoOptimizedCompositeOpAlphaDarkenCreamyU64>::create<Vc::CurrentImplementation::current()>(ParamType param)
{
    return new KoOptimizedCompositeOpAlphaDarkenCreamyU64<Vc::CurrentImplementation::current()>(param);
}
