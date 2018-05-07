#include <vector>
#include <initializer_list>
#include "spatial.h"

namespace AyxCppTest
{

class Polygon : public Area
{
public:
    Polygon(std::initializer_list<Point> points);
    ~Polygon() override;
    bool Contains(const Point &pt) override;

private:
    std::vector<Point> m_Points;
};

}
