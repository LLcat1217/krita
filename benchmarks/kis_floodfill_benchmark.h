/*
 *  SPDX-FileCopyrightText: 2010 Lukáš Tvrdý <lukast.dev@gmail.com>
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef KIS_FLOODFILL_BENCHMARK_H
#define KIS_FLOODFILL_BENCHMARK_H

#include <KoColor.h>

#include <kis_types.h>
#include <simpletest.h>
#include <kis_paint_device.h>

class KoColor;

class KisFloodFillBenchmark : public QObject
{
    Q_OBJECT
private:
    const KoColorSpace * m_colorSpace;
    KoColor m_color;
    KisPaintDeviceSP m_deviceStandardFloodFill;
    KisPaintDeviceSP m_deviceWithSelectionAsBoundary;
    KisPaintDeviceSP m_deviceWithoutSelectionAsBoundary;
    KisPaintDeviceSP m_existingSelection;
    int m_startX;
    int m_startY;
    
private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    
    void benchmarkFlood();
    void benchmarkFloodWithoutSelectionAsBoundary();
    void benchmarkFloodWithSelectionAsBoundary();

    
    
    
};

#endif
