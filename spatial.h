namespace AyxCppTest
{
	struct Point
	{
		double m_x;
		double m_y;
        Point();
		Point(double x, double y);
		Point(const Point &pt);
        Point& operator=(const Point& pt);
        bool operator ==(const Point& pt) const;
        bool operator !=(const Point& pt) const;
		~Point();

        static bool DbgHasLeaks();
	};

	class Area
	{
	public:
		// returns true if point is inside
		// false if outside or on the line
		virtual bool Contains(const Point &pt) = 0;
        virtual ~Area() {}
	};

	class Circle : public Area
	{
		Point m_pt;
		double m_radius;
	public:
		Circle(Point pt, double radius);
        ~Circle() override;
		bool Contains(const Point &pt) override;
	};

	class Rectangle : public Area
	{
		Point m_TopLeft;
		Point m_BottomRight;
	public:
		Rectangle(Point topLeft, Point bottomRight);
        ~Rectangle() override;
		bool Contains(const Point &pt) override;
		double Size();
	};
}
