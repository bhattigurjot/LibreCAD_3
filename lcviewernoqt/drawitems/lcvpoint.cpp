#include "lcvpoint.h"
#include "../lcpainter.h"
#include "lcdrawoptions.h"
LCVPoint::LCVPoint(const lc::entity::Point_CSPtr Coordinate) : LCVDrawItem(true), lc::entity::Point (Coordinate, true) {
}

void LCVPoint::draw(LcPainter* painter, LcDrawOptions* options, const lc::geo::Area& rect) const {
    bool modified = false;



    painter->point(x(), y(), 3., true);
    painter->stroke();

    if (modified) {
        painter->restore();
    }
}

