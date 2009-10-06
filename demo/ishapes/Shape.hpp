/* 
 * File:   Shape.hpp
 * Author: corsaro
 *
 * Created on July 12, 2009, 9:50 PM
 */

#ifndef _SHAPE_HPP
#define	_SHAPE_HPP

#include <QRect>
#include <QPen>
#include <QBrush>

class Shape {
public:
    Shape(const QRect& bounds, const QPen& pen, const QBrush& brush);
    virtual ~Shape();
public:
    virtual void update() = 0;
    virtual void paint(QPainter& painter) = 0;

public:
    virtual void setPen(const QPen& pen);
    virtual void setBrush(const QBrush& brush);
    virtual void setBounds(const QRect& bounds);
    
private:
    Shape(const Shape&);
    Shape& operator=(const Shape&);

protected:
    QRect bounds_;
    QPen pen_;
    QBrush brush_;
};

#endif	/* _SHAPE_HPP */

