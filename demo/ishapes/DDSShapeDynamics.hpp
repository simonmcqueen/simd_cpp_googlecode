/* 
 * File:   DDSShapeDynamics.hpp
 * Author: corsaro
 *
 * Created on July 13, 2009, 8:44 AM
 */

#ifndef _DDSSHAPEDYNAMICS_HPP
#define	_DDSSHAPEDYNAMICS_HPP

#include <ShapeDynamics.hpp>
#include <QRect>
#include <QtGui>
#include <Shape.hpp>
#include <simd/reader.hpp>

// -- Shaped Include
#include <gen/ccpp_ishape.h>
#include <topic-traits.hpp>

#define CN 8

class DDSShapeDynamics : public ShapeDynamics {
public:
     enum {
        BLUE    = 0,
        RED     = 1,
        GREEN   = 2,
        ORANGE  = 3,
        YELLOW  = 4,
        MAGENTA = 5,
        CYAN    = 6,
        BLACK   = 7
    };
public:
    DDSShapeDynamics(
            int x0, int y0,
            simd::DataReader<ShapeType>& shapeReader,
            const std::string& color,
            int colorIdx
            );

    virtual ~DDSShapeDynamics();

public:

    void setShape(boost::shared_ptr<Shape> shape) {
        shape_ = shape;
    }


    virtual void simulate();
private:
    DDSShapeDynamics(const DDSShapeDynamics& orig);
    boost::shared_ptr<Shape> shape_;
    int x0_;
    int y0_;
    simd::DataReader<ShapeType> & shapeReader_;
    bool attached_;
    std::string color_;
    int colorIdx_;
    QColor  colorList_[CN];
};

#endif	/* _DDSSHAPEDYNAMICS_HPP */

