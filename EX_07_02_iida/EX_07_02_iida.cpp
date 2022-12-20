#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

/// <summary>
/// 物体の定義
/// </summary>
class Solid {
public:
    virtual double GetVolume() = 0;
    virtual double GetSurface() = 0;
};

/// <summary>
/// 箱型
/// </summary>
class Box :Solid {
private:
    double width;
    double height;
    double depth;

public:
    Box(
        double width,   //幅
        double height,  //高さ
        double depth) {//奥行
        this->width = width;
        this->height = height;
        this->depth = depth;
    }

    double GetWidth()
    {
        return width;
    }

    double GetHeight()
    {
        return height;
    }

    double GetDepth()
    {
        return depth;
    }

    double GetVolume() {
        return width * height * depth;
    }
    double GetSurface() {
        return (width * height + height * depth + depth * width) * 2;
    }
};

/// <summary>
/// 円柱
/// </summary>
class Cylinder : Solid
{
private:
    double radius;
    double height;
public:
    Cylinder(
        double radius,
        double height)
    {
        this->radius = radius;
        this->height = height;
    }
    double GetRadius()
    {
        return radius;
    }

    double GetHeight()
    {
        return height;
    }

    double GetVolume()
    {
        return radius * radius * M_PI * height;
    }

    double GetSurface()
    {
        return radius * 2 * M_PI * height + radius * radius * M_PI * 2;
    }
};

/// <summary>
/// 円錐
/// </summary>
class Cone : Solid
{
private:
    double radius;
    double height;
public:
    Cone(
        double radius,
        double height)
    {
        this->radius = radius;
        this->height = height;
    }
    double GetRadius()
    {
        return radius;
    }

    double GetHeight()
    {
        return height;
    }

    double GetVolume()
    {
        return radius * radius * M_PI * height / 3;
    }

    double GetSurface()
    {
        return radius * radius * M_PI + sqrt(radius * radius + height * height) * radius * M_PI;
    }
};

/// <summary>
/// 球
/// </summary>
class Sphere : Solid
{
private:
    double radius;
public:
    Sphere(
        double radius)
    {
        this->radius = radius;
    }
    double GetRadius()
    {
        return radius;
    }

    double GetVolume()
    {
        return radius * radius * M_PI * 4;
    }

    double GetSurface()
    {
        return radius * radius * M_PI * radius * (4.0f / 3.0f);
    }
};

int main()
{
    Box box{ 3,5,2 };
    Cylinder cylinder{ 8,4 };
    Cone cone{ 6,8 };
    Sphere sphere{ 7 };
    cout << "Boxの体積=" << box.GetVolume() << endl;
    cout << "Boxの表面積=" << box.GetSurface() << endl;
    cout << "\nCylinderの体積=" << cylinder.GetVolume() << endl;
    cout << "Cylinderの表面積=" << cylinder.GetSurface() << endl;
    cout << "\nConeの体積=" << cone.GetVolume() << endl;
    cout << "Coneの表面積=" << cone.GetSurface() << endl;
    cout << "\nSphereの体積=" << sphere.GetVolume() << endl;
    cout << "Sphereの表面積=" << sphere.GetSurface() << endl;
}