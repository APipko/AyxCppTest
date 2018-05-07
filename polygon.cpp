#include "polygon.h"

namespace AyxCppTest
{

Polygon::Polygon(std::initializer_list<Point> points) : m_Points(points) {}

Polygon::~Polygon() {}

bool LineIntersection(Point line1Pt1, Point line1Pt2, Point line2Pt1, Point line2Pt2, Point &r_Out)
{
        double s1_x = line1Pt2.m_x - line1Pt1.m_x;
        double s1_y = line1Pt2.m_y - line1Pt1.m_y;
        double s2_x = line2Pt2.m_x - line2Pt1.m_x;
        double s2_y = line2Pt2.m_y - line2Pt1.m_y;

        double s, t;
        s = (-s1_y * (line1Pt1.m_x - line2Pt1.m_x) + s1_x * (line1Pt1.m_y - line2Pt1.m_y)) / (-s2_x * s1_y + s1_x * s2_y);
        t = (s2_x * (line1Pt1.m_y - line2Pt1.m_y) - s2_y * (line1Pt1.m_x - line2Pt1.m_x)) / (-s2_x * s1_y + s1_x * s2_y);

        if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
        {
                // Collision detected
                r_Out.m_x = line1Pt1.m_x + (t * s1_x);
                r_Out.m_y = line1Pt1.m_y + (t * s1_y);
                return true;
        }

        return false; // No collision
}

bool Polygon::Contains(const Point &pt){
    int intersectionCount = 0;
    auto firstPoint = m_Points.begin();
    auto secondPoint = m_Points.begin();
    double xMax = firstPoint->m_y;
    double yMax = firstPoint->m_y;
    for (const auto& point : m_Points){
        xMax = std::max(xMax, point.m_x);
        yMax = std::max(yMax, point.m_y);
    }
    Point rayPoint(xMax + 1, yMax + 1);
    for (auto point = ++m_Points.begin(); point < m_Points.end(); ++point){
        firstPoint = secondPoint;
        secondPoint = point;
        Point intersectionPoint;
        bool intersected = LineIntersection(*firstPoint, *secondPoint, pt, rayPoint, intersectionPoint);
        if (intersected && intersectionPoint != *firstPoint && intersectionPoint != *secondPoint){
            ++intersectionCount;
        }

    }

    return intersectionCount % 2;
}
}
