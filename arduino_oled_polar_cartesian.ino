//Include the graphics library.
#include "U8glib.h" 
//Initialize display.
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0);
void setup(void)
{
}
int center_x = 64;
int center_y = 32;
int end_x = center_x;
int end_y = center_y;
int radius = 20;
int theta = 0;

void loop(void)
{
    u8g.firstPage();
    do {
        end_x = radius*cos(radians(theta)) + center_x;
        end_y = -radius*sin(radians(theta)) + center_y;
        u8g.drawLine(center_x, center_y, end_x, end_y);
        theta++;
    } while (u8g.nextPage());
    delay(10);
}
