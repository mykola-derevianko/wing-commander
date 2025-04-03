#include <string>
#include <sstream>

template <typename T>
std::string toString(const T& value)
{
    std::stringstream stream;
    stream << value;
    return stream.str();
}
float toDegree(float radian){
    return 180.f / 3.141592653589793238462643383f * radian;
}

float toRadian(float degree){
    return 3.141592653589793238462643383f / 180.f * degree;
}
