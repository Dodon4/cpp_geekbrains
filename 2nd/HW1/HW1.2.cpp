#include <iostream>

using namespace std;

class RGBA
{
private:
    uint8_t m_red;
    uint8_t m_green;
    uint8_t m_blue;
    uint8_t m_alpha;    
    
public:
    RGBA(uint8_t red = 0, uint8_t green = 0,uint8_t blue = 0, uint8_t alpha = 255)
    : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) {}
    void print()
    {
        cout << "red:" << unsigned(m_red) << endl;
        cout << "green:" << unsigned(m_green) << endl;
        cout << "blue:" << unsigned(m_blue) << endl;
        cout << "alpha:" << unsigned(m_alpha) << endl;
        
    }
};
int main()
{
    RGBA a(2,3);

    a.print();

    return 0;

}