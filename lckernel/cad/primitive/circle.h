#pragma once

#include <cad/meta/layer.h>

#include "cad/const.h"
#include "cad/interface/entitydispatch.h"
#include "cad/math/quadratic_math.h"
#include "cad/geometry/geocoordinate.h"
#include "cad/geometry/geocircle.h"
#include "cad/base/cadentity.h"
#include "cad/vo/entitycoordinate.h"
#include "cad/interface/snapable.h"

namespace lc {
    namespace entity {
        class Circle;

        typedef std::shared_ptr<Circle> Circle_SPtr;
        typedef std::shared_ptr<const Circle> Circle_CSPtr;

        class Circle
                : public std::enable_shared_from_this<Circle>, public CADEntity, public geo::Circle, public Snapable {
        public:
            /**
             * @brief Circle, Default Circle Constructor
             * @param geo::Coordinate center, center of Circle
             * @param double radius, radius of circle
             * @param Layer_CSPtr _layer
             */
            Circle(const geo::Coordinate &center, double radius, const Layer_CSPtr _layer);

            /**
             * @brief Circle, Circle Constructor with metatypes
             * @param geo::Coordinate center, center of Circle
             * @param double radius, radius of circle
             * @param Layer_CSPtr _layer
             * @param MetaTypes metaTypes
             */
            Circle(const geo::Coordinate &center, double radius, const Layer_CSPtr layer,
                   const MetaInfo_CSPtr metaInfo);

            Circle(const Circle_CSPtr other, bool sameID = false);

        public:
            virtual std::vector<EntityCoordinate> snapPoints(const geo::Coordinate &coord, double minDistanceToSnap,
                                                             int maxNumberOfSnapPoints) const;

            virtual geo::Coordinate nearestPointOnPath(const geo::Coordinate &coord) const;

        public:

            /**
             * @brief move, moves by an offset
             * @param geo::Coordinate offset
             * @return CADEntity_CSPtr moved entity
             */
            virtual CADEntity_CSPtr move(const geo::Coordinate &offset) const;

            /**
             * @brief copy, copies by an offset
             * @param geo::Coordinate offset
             * @return CADEntity_CSPtr copied entity
             */
            virtual CADEntity_CSPtr copy(const geo::Coordinate &offset) const;

            /**
             * @brief rotate, rotate operation
             * @param geo::Coordinate rotation_center
             * @param double rotation_angle
             * @return CADEntity_CSPtr rotated entity
             */
            virtual CADEntity_CSPtr rotate(const geo::Coordinate &rotation_center, const double rotation_angle) const;

            /**
             * @brief scale, scales the entity
             * @param geo::Coordinate scale_center
             * @param double scale_factor
             * @return
             */
            virtual CADEntity_CSPtr scale(const geo::Coordinate &scale_center,
                                          const geo::Coordinate &scale_factor) const;

            /**
             * @brief boundingBox of the entity
             * @return geo::Area area
             */
            virtual const geo::Area boundingBox() const;

            virtual CADEntity_CSPtr modify(Layer_CSPtr layer, const MetaInfo_CSPtr metaInfo) const;


        public:
            virtual void accept(GeoEntityVisitor &v) const override { v.visit(*this); }

            virtual void dispatch(EntityDispatch &ed) const {
                ed.visit(shared_from_this());
            }

        };
    }
}
// CIRCLE_H
