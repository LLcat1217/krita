/*
 *  kis_tool_brush.h - part of Krita
 *
 *  Copyright (c) 2003-2004 Boudewijn Rempt <boud@valdyas.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef KIS_TOOL_FREEHAND_H_
#define KIS_TOOL_FREEHAND_H_

#include "kis_types.h"
#include "kis_tool_paint.h"
#include "kis_point.h"
#include "koffice_export.h"

class QWidget;
class KisPainter;
class KisBrush;
class KisEvent;
class KisPaintLayer;


class KRITACORE_EXPORT KisToolFreehand : public KisToolPaint {
    Q_OBJECT
    typedef KisToolPaint super;

public:
    KisToolFreehand(const QString transactionText);
    virtual ~KisToolFreehand();

    virtual void update(KisCanvasSubject *subject);

    virtual void buttonPress(KisButtonPressEvent *e);
    virtual void move(KisMoveEvent *e);
    virtual void buttonRelease(KisButtonReleaseEvent *e);

    virtual enumToolType toolType() { return TOOL_FREEHAND; }

protected:
    virtual void paintAt(const KisPoint &pos,
                 const double pressure,
                 const double xTilt,
                 const double yTilt);

    virtual void paintLine(const KisPoint & pos1,
                   const double pressure1,
                   const double xtilt1,
                   const double ytilt1,
                   const KisPoint & pos2,
                   const double pressure2,
                   const double xtilt2,
                   const double ytilt2);

    // XXX: why not make this a protected member attribute for the
    // use of subclasses? BSAR.
    inline KisPainter * painter() { return m_painter; };
    virtual void initPaint(KisEvent *e);
    virtual void endPaint();

    KisImageSP currentImage();

    void paintOutline(const KisPoint& point);

    /**
     * Use a temporary drawing layer (true), or draw directly on the paint device (false).
     * To be set before KisToolFreehand::initPaint is called.
     **/
    void setUseTempLayer(bool u);

protected:
    KisPoint m_prevPos;
    double m_prevPressure;
    double m_prevXTilt;
    double m_prevYTilt;
    double m_dragDist;

    bool m_useTempLayer;
    KisPaintDeviceImplSP m_target;
    KisPaintLayer *m_tempLayer;
    KisPaintDeviceImplSP m_source;

    QString m_transactionText;
    enumBrushMode m_mode;
    KisPainter *m_painter;

    KisImageSP m_currentImage;
private:
    bool m_paintedOutline;
};



#endif // KIS_TOOL_FREEHAND_H_

