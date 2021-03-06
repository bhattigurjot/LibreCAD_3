#include "cad/primitive/dimaligned.h"


using namespace lc;
using namespace entity;

DimAligned::DimAligned(geo::Coordinate const& definitionPoint, geo::Coordinate const& middleOfText, TextConst::AttachmentPoint const& attachmentPoint, double textAngle, double const lineSpacingFactor,
                       TextConst::LineSpacingStyle const& lineSpacingStyle, std::string const& explicitValue,
                       geo::Coordinate const& definitionPoint2, geo::Coordinate const& definitionPoint3, const Layer_CSPtr layer, const MetaInfo_CSPtr metaInfo):
    CADEntity(layer, metaInfo), Dimension(definitionPoint, middleOfText, attachmentPoint, textAngle, lineSpacingFactor, lineSpacingStyle, explicitValue),
    _definitionPoint2(definitionPoint2), _definitionPoint3(definitionPoint3) {

}


DimAligned::DimAligned(const DimAligned_CSPtr other, bool sameID) : CADEntity(other, sameID), Dimension(*other), _definitionPoint2(other->_definitionPoint2), _definitionPoint3(other->_definitionPoint3) {
}

DimAligned_SPtr DimAligned::dimAuto(geo::Coordinate const& p2, geo::Coordinate const& p3, double const textOffset, std::string const& explicitValue, const Layer_CSPtr layer, const MetaInfo_CSPtr metaInfo) {

    geo::Coordinate dir = (p3 - p2).rotate(0.5 * M_PI);
    geo::Coordinate p0 = p3.move(dir, textOffset);
    geo::Coordinate middletext(p2.mid(p3).move(dir, textOffset));


    return std::make_shared<DimAligned>(p0, middletext, TextConst::AttachmentPoint::Top_center , 0., 0., TextConst::LineSpacingStyle::AtLeast, explicitValue, p2, p3, layer, metaInfo);
}



CADEntity_CSPtr DimAligned::move(const geo::Coordinate& offset) const {
    auto newDimAligned = std::make_shared<DimAligned>(this->definitionPoint() + offset, this->middleOfText() + offset, this->attachmentPoint(), this->textAngle(), this->lineSpacingFactor(), this->lineSpacingStyle(), this->explicitValue(),  this->_definitionPoint2 + offset,  this->_definitionPoint3 + offset,  this->layer(), this->metaInfo());
    newDimAligned->setID(this->id());
    return newDimAligned;
}

CADEntity_CSPtr DimAligned::copy(const geo::Coordinate& offset) const {
    auto newDimAligned = std::make_shared<DimAligned>(this->definitionPoint() + offset, this->middleOfText() + offset, this->attachmentPoint(), this->textAngle(), this->lineSpacingFactor(), this->lineSpacingStyle(), this->explicitValue(),  this->_definitionPoint2 + offset, this->_definitionPoint3 + offset,  this->layer(), this->metaInfo());
    return newDimAligned;
}

CADEntity_CSPtr DimAligned::rotate(const geo::Coordinate& rotation_center, const double rotation_angle) const {
    auto newDimAligned = std::make_shared<DimAligned>(this->definitionPoint().rotate(rotation_center, rotation_angle),
                                                      this->middleOfText().rotate(rotation_center, rotation_angle), this->attachmentPoint(), this->textAngle(), this->lineSpacingFactor(), this->lineSpacingStyle(), this->explicitValue(), this->_definitionPoint2.rotate(rotation_center, rotation_angle), this->_definitionPoint3.rotate(rotation_center, rotation_angle),  this->layer(), this->metaInfo());
    return newDimAligned;
}

CADEntity_CSPtr DimAligned::scale(const geo::Coordinate& scale_center, const geo::Coordinate& scale_factor) const {
    auto newDimAligned = std::make_shared<DimAligned>(this->definitionPoint().scale(scale_center, scale_factor),
                                                      this->middleOfText().scale(scale_center, scale_factor), this->attachmentPoint(), this->textAngle(), this->lineSpacingFactor(), this->lineSpacingStyle(), this->explicitValue(), this->_definitionPoint2.scale(scale_center, scale_factor), this->_definitionPoint3.scale(scale_center, scale_factor),  this->layer(), this->metaInfo());
    return newDimAligned;
}

const geo::Area DimAligned::boundingBox() const {
    // TODO create proper bounding box for DimAligned
    return geo::Area(this->middleOfText(), 0., 0.);
}

CADEntity_CSPtr DimAligned::modify(Layer_CSPtr layer, const MetaInfo_CSPtr metaInfo) const {
    auto newDimAligned = std::make_shared<DimAligned>(
                             this->definitionPoint(), this->middleOfText(), this->attachmentPoint(), this->textAngle(), this->lineSpacingFactor(), this->lineSpacingStyle(), this->explicitValue(), this->_definitionPoint2, this->_definitionPoint3,  this->layer(), metaInfo);
    return newDimAligned;
}

const geo::Coordinate& DimAligned::definitionPoint2() const noexcept {
    return _definitionPoint2;
}
const geo::Coordinate& DimAligned::definitionPoint3() const noexcept {
    return _definitionPoint3;
}