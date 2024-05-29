#include<windows.h>
#include <GL/glut.h>
#include <math.h>
#include <cmath>
#include<stdio.h>

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);	                    // Set display window colour to white

    glMatrixMode(GL_PROJECTION);	  // Set projection parameters
    gluOrtho2D(0.0, 1980.0, 0.0, 980.0);
}

int bx = 0;
int bx1 = 0;
bool direction = true;
bool direction1 = true;
int tx = 0;

void arrow(int arrow, int x, int y)
{
    switch(arrow)
    {
    case GLUT_KEY_RIGHT:
        tx += 15;
        if(tx>900)
            tx=-80;
        glutPostRedisplay();
        break;

    case GLUT_KEY_LEFT:
        tx -= 15;
        if(tx < -100)
            tx=+900;
        glutPostRedisplay();
        break;
    }
}
void drawCircle(float cx, float cy, float radius)
{
    int numSegments = 100;
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void drawCloudCircleWborder(float cx, float cy, float radius, float borderWidth)
{
    int numSegments = 100;

    // Draw border circle
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for border
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = (radius + borderWidth) * cosf(theta);
        float y = (radius + borderWidth) * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();

    // Draw filled circle
    glColor3f(0.8f, 0.8f, 0.8f); // light gray color for filled circle
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void drawCircleWborder(float cx, float cy, float radius, float borderWidth)
{
    int numSegments = 100;

    // Draw border circle
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for border
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = (radius + borderWidth) * cosf(theta);
        float y = (radius + borderWidth) * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();

    // Draw filled circle
    glColor3f(0.0f, 0.8f, 0.1f); // Green color for filled circle
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void drawRedCircleWborder(float cx, float cy, float radius, float borderWidth)
{
    int numSegments = 100;

    // Draw border circle
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for border
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = (radius + borderWidth) * cosf(theta);
        float y = (radius + borderWidth) * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();

    // Draw filled circle
    glColor4f(0.9f, 0.0f, 0.0f, 0.0f); // Red color for filled circle
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void drawYellowCircleWborder(float cx, float cy, float radius, float borderWidth)
{
    int numSegments = 100;

    // Draw border circle
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for border
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = (radius + borderWidth) * cosf(theta);
        float y = (radius + borderWidth) * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();

    // Draw filled circle
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f); // Yellow color for filled circle
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void drawTreeLeaves_s(float a, float b)
{
    glColor3f(0.0f, 0.8f, 0.1f);
    drawCircleWborder(1225 + a, 600 + b, 25, 0.5);
    drawCircleWborder(1235 + a, 620 + b, 25, 0.5);
    drawCircleWborder(1250 + a, 630 + b, 25, 0.5);
    drawCircleWborder(1250 + a, 630 + b, 25, 0.5);
    drawCircleWborder(1265 + a, 630 + b, 25, 0.5);
    drawCircleWborder(1280 + a, 625 + b, 25, 0.5);
    drawCircleWborder(1290 + a, 615 + b, 25, 0.5);
    drawCircleWborder(1290 + a, 605 + b, 25, 0.5);
    drawCircleWborder(1290 + a, 595 + b, 25, 0.5);
    drawCircleWborder(1280 + a, 585 + b, 25, 0.5);
    drawCircleWborder(1270 + a, 575 + b, 25, 0.5);
    drawCircleWborder(1260 + a, 575 + b, 25, 0.5);
    drawCircleWborder(1250 + a, 575 + b, 25, 0.5);
    drawCircleWborder(1235 + a, 585 + b, 25, 0.5);

    glColor3f(0.0f, 0.8f, 0.1f);
    drawCircle(1260 + a, 600 + b, 45);

}

void drawTreeLeaves_b(float c, float d)
{
    glColor3f(0.0f, 1.0f, 0.0f);
    drawCircleWborder(1160 + c, 700 + d, 20, 0.5);
    drawCircleWborder(1160 + c, 710 + d, 20, 0.5);
    drawCircleWborder(1160 + c, 720 + d, 20, 0.5);
    drawCircleWborder(1165 + c, 730 + d, 20, 0.5);
    drawCircleWborder(1175 + c, 740 + d, 20, 0.5);
    drawCircleWborder(1185 + c, 750 + d, 20, 0.5);
    drawCircleWborder(1195 + c, 750 + d, 20, 0.5);
    drawCircleWborder(1205 + c, 750 + d, 20, 0.5);
    drawCircleWborder(1215 + c, 750 + d, 20, 0.5);
    drawCircleWborder(1225 + c, 745 + d, 20, 0.5);
    drawCircleWborder(1235 + c, 740 + d, 20, 0.5);
    drawCircleWborder(1240 + c, 730 + d, 20, 0.5);
    drawCircleWborder(1245 + c, 720 + d, 20, 0.5);
    drawCircleWborder(1250 + c, 710 + d, 20, 0.5);
    drawCircleWborder(1245 + c, 700 + d, 20, 0.5);
    drawCircleWborder(1240 + c, 690 + d, 20, 0.5);
    drawCircleWborder(1230 + c, 680 + d, 20, 0.5);
    drawCircleWborder(1220 + c, 670 + d, 20, 0.5);
    drawCircleWborder(1210 + c, 670 + d, 20, 0.5);
    drawCircleWborder(1200 + c, 670 + d, 20, 0.5);
    drawCircleWborder(1190 + c, 670 + d, 20, 0.5);
    drawCircleWborder(1180 + c, 680 + d, 20, 0.5);
    drawCircleWborder(1170 + c, 680 + d, 20, 0.5);

    glColor3f(0.0f, 0.8f, 0.1f);
    drawCircle(1200 + c, 710 + d, 55);

}

void drawBananaTree(float x, float y)
{
    glColor3f(0.0f, 1.0f, 0.0f);//Green
    glBegin(GL_QUAD_STRIP);  // tree body
    glVertex2f(1762.6791103184853 + x, 300.0377064782723 + y);
    glVertex2f(1770 + x, 300 + y);
    glVertex2f(1762.7923468079734 + x, 381.2670829475295 + y);
    glVertex2f(1769.2960760317333 + x, 381.3269745636775 + y);
    glVertex2f(1763.9328509390357 + x, 382.9222500072723 + y);
    glVertex2f(1768.2325590693367 + x, 382.8690741591525 + y);

    glVertex2f(1762.702650320295 + x, 360.7365295588521 + y);
    glVertex2f(1762.5913678242064 + x, 365.6911490303415 + y);
    glVertex2f(1750.5015580524114 + x, 360.4815227925409 + y);
    glVertex2f(1748.9572755849788 + x, 366.4199908263956 + y);
    glVertex2f(1742.0832096237946 + x, 358.2396350970207 + y);
    glVertex2f(1737.7261303672872 + x, 363.0085304665216 + y);
    glVertex2f(1737.5288222169552 + x, 354.8143133588348 + y);
    glVertex2f(1731.4086111823356 + x, 357.449113583764 + y);

    glVertex2f(1762.702650320295 + x, 360.7365295588521 + y);
    glVertex2f(1750.5015580524114 + x, 360.4815227925409 + y);
    glVertex2f(1754.811538328355 + x, 353.236100180949 + y);
    glVertex2f(1748.3599506581331 + x, 355.3098247892347 + y);
    glVertex2f(1751.2401237251966 + x, 346.4964952040206 + y);
    glVertex2f(1745.3645706683874 + x, 348.2591611210634 + y);
    glVertex2f(1752.046572183923 + x, 337.7868518492207 + y);
    glVertex2f(1746.0558122044827 + x, 341.4158699137207 + y);

    glVertex2f(1762.5913678242064 + x, 365.6911490303415 + y);
    glVertex2f(1762.5913678242064 + x, 373.0577701842537 + y);
    glVertex2f(1749.8026503202977 + x, 370.7365295588521 + y);
    glVertex2f(1749.5625244635285 + x, 377.66895140465 + y);
    glVertex2f(1739.49290335578 + x, 370.9953577471955 + y);
    glVertex2f(1739.49290335578 + x, 377.8639680148916 + y);
    glVertex2f(1733.3740615954314 + x, 369.3260496514735 + y);
    glVertex2f(1730.4258859757877 + x, 375.5172184527262 + y);
    glVertex2f(1726.7757637800378 + x, 364.1456839198129 + y);
    glVertex2f(1725.5122599430476 + x, 371.09495502326 + y);

    glVertex2f(1762.5913678242064 + x, 373.0577701842537 + y);
    glVertex2f(1762.7923468079734 + x, 381.2670829475295 + y);
    glVertex2f(1754.6087322275107 + x, 378.0709076502702 + y);
    glVertex2f(1753.857494760788 + x, 386.7852622642511 + y);
    glVertex2f(1743.6442951157505 + x, 381.3763525038492 + y);
    glVertex2f(1743.393882626843 + x, 389.3394696511076 + y);
    glVertex2f(1732.8641538114416 + x, 378.6718976236482 + y);
    glVertex2f(1735.002650320302 + x, 385.7365295588521 + y);

    glVertex2f(1769.3592823356444 + x, 373.0205313496484 + y);
    glVertex2f(1769.2960760317333 + x, 381.3269745636775 + y);
    glVertex2f(1776.2838940508616 + x, 378.1460313969424 + y);
    glVertex2f(1774.8648899470525 + x, 386.5598910242343 + y);
    glVertex2f(1786.582214481166 + x, 381.4514762505214 + y);
    glVertex2f(1785.4970936959003 + x, 389.3394696511076 + y);
    glVertex2f(1797.495414126203 + x, 378.2962788902869 + y);
    glVertex2f(1795.3026503202882 + x, 385.7365295588521 + y);

    glVertex2f(1769.4026503202936 + x, 365.7365295588521 + y);
    glVertex2f(1769.3592823356444 + x, 373.0205313496484 + y);
    glVertex2f(1781.202650320292 + x, 370.7365295588521 + y);
    glVertex2f(1780.9924786058382 + x, 378.3840929515732 + y);
    glVertex2f(1790.1384957938737 + x, 370.8751067088785 + y);
    glVertex2f(1789.939845364173 + x, 378.2053075648424 + y);
    glVertex2f(1800.189911263104 + x, 368.6402893747431 + y);
    glVertex2f(1800.3026503202882 + x, 375.7365295588521 + y);
    glVertex2f(1805.4541476501784 + x, 364.0812620131071 + y);
    glVertex2f(1806.3480745838326 + x, 370.5175359354168 + y);

    glVertex2f(1769.4026503202936 + x, 359.9838287914539 + y);
    glVertex2f(1769.4026503202936 + x, 365.7365295588521 + y);
    glVertex2f(1781.202650320292 + x, 359.9838287914539 + y);
    glVertex2f(1781.202650320292 + x, 365.7365295588521 + y);
    glVertex2f(1788.9682304230048 + x, 358.8389678044541 + y);
    glVertex2f(1791.8919556329638 + x, 363.2148185220257 + y);
    glVertex2f(1795.0049709775142 + x, 352.5214486195022 + y);
    glVertex2f(1798.2339252276004 + x, 358.3335662696579 + y);
    glVertex2f(1796.9704213906102 + x, 346.8356813530456 + y);
    glVertex2f(1800.6205435863599 + x, 352.3950982358032 + y);

    glVertex2f(1769.4026503202936 + x, 359.9838287914539 + y);
    glVertex2f(1776.93 + x, 359.9838287914539 + y);
    glVertex2f(1775.3675572530256 + x, 352.4504700039732 + y);
    glVertex2f(1782.4611997721627 + x, 353.4434726417775 + y);
    glVertex2f(1777.6225090194964 + x, 346.1854365127777 + y);
    glVertex2f(1784.650131303131 + x, 346.6001814344348 + y);
    glVertex2f(1775.5390065788124 + x, 339.6112147969212 + y);
    glVertex2f(1782.5764066948452 + x, 340.7937525312349 + y);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(1737.5288222169552 + x, 354.8143133588348 + y);
    glVertex2f(1731.4086111823356 + x, 357.449113583764 + y);
    glVertex2f(1733.9356188563163 + x, 349.7417401781228 + y);
    glVertex2f(1753.857494760788 + x, 386.7852622642511 + y);
    glEnd();
}

void drawCloud (float c, float d)
{
    glColor3f(0.8f, 0.8f, 0.8f); // Light gray
    drawCloudCircleWborder(1405 + c, 850 + d, 15, 0.5);
    drawCloudCircleWborder(1390 + c, 860 + d, 15, 0.5);
    drawCloudCircleWborder(1385 + c, 870 + d, 15, 0.5);
    drawCloudCircleWborder(1390 + c, 880 + d, 15, 0.5);
    drawCloudCircleWborder(1405 + c, 890 + d, 15, 0.5);
    drawCloudCircleWborder(1415 + c, 890 + d, 15, 0.5);
    drawCloudCircleWborder(1415 + c, 850 + d, 15, 0.5);
    drawCloudCircleWborder(1425 + c, 895 + d, 15, 0.5);
    drawCloudCircleWborder(1435 + c, 895 + d, 15, 0.5);
    drawCloudCircleWborder(1435 + c, 850 + d, 15, 0.5);
    drawCloudCircleWborder(1425 + c, 850 + d, 15, 0.5);
    drawCloudCircleWborder(1445 + c, 895 + d, 15, 0.5);
    drawCloudCircleWborder(1445 + c, 850 + d, 15, 0.5);
    drawCloudCircleWborder(1455 + c, 890 + d, 15, 0.5);
    drawCloudCircleWborder(1455 + c, 850 + d, 15, 0.5);
    drawCloudCircleWborder(1465 + c, 890 + d, 15, 0.5);
    drawCloudCircleWborder(1465 + c, 850 + d, 15, 0.5);
    drawCloudCircleWborder(1475 + c, 860 + d, 15, 0.5);
    drawCloudCircleWborder(1480 + c, 870 + d, 15, 0.5);
    drawCloudCircleWborder(1475 + c, 880 + d, 15, 0.5);

    glColor3f(0.8f, 0.8f, 0.8f);
    drawCircle(1450 + c, 870 + d, 30);
    drawCircle(1415 + c, 870 + d, 30);

}

void drawSun(int x, int y, int z)
{
    // Draw the sun circle
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow color for the sun
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // Center of the sun
    for (int i = 0; i <= 360; ++i)
    {
        float angle = i * 3.14159 / 180;
        glVertex2f(x + z * cos(angle), y + z * sin(angle));
    }
    glEnd();


}


void drawBush(float x, float y)
{
    drawCircleWborder(1200 + x, 100 + y, 13, 0.5);

    drawCircleWborder(1180 + x, 100 + y, 13, 0.5);
    drawCircleWborder(1180 + x, 110 + y, 13, 0.5);
    drawCircleWborder(1185 + x, 115 + y, 13, 0.5);
    drawCircleWborder(1190 + x, 120 + y, 13, 0.5);
    drawCircleWborder(1195 + x, 100 + y, 13, 0.5);

    drawCircleWborder(1220 + x, 100 + y, 13, 0.5);
    drawCircleWborder(1220 + x, 110 + y, 13, 0.5);
    drawCircleWborder(1215 + x, 115 + y, 13, 0.5);
    drawCircleWborder(1210 + x, 120 + y, 13, 0.5);
    drawCircleWborder(1205 + x, 100 + y, 13, 0.5);

    drawCircleWborder(1200 + x, 122 + y, 13, 0.5);

    drawCircle(1200 + x, 110 + y, 20);
    drawCircle(1190 + x, 110 + y, 17);
    drawCircle(1190 + x, 100 + y, 17);
    drawCircle(1210 + x, 110 + y, 17);
    drawCircle(1210 + x, 100 + y, 17);
}

void drawTire(float cx, float cy, float radius, float borderWidth)
{
    int numSegments = 100;

    // Draw border circle
    glColor3f(1.0f, 1.0f, 1.0f); // Black color for border
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = (radius + borderWidth) * cosf(theta);
        float y = (radius + borderWidth) * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();

    // Draw filled circle
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f); // Yellow color for filled circle
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}
void DrawCar(int tx)
{
    glColor4f(0.00, 0.05, 0.99, 1.0);      // blue color
    glBegin(GL_QUADS);
    glVertex2i(100 + tx, 260);
    glVertex2i(96.9624689838365 + tx, 249.9035822853638);
    glVertex2i(120 + tx, 250);
    glVertex2i(120 + tx, 260);

    glVertex2i(96.9624689838365 + tx, 249.9035822853638);
    glVertex2i(99.1031751419953 + tx, 238.4722114007973);
    glVertex2i(120 + tx, 238);
    glVertex2i(120 + tx, 250);

    glVertex2i(120 + tx, 238);
    glVertex2i(120 + tx, 250);
    glVertex2i(178 + tx, 249);
    glVertex2i(178 + tx, 238);

    glVertex2i(178 + tx, 249);
    glVertex2i(178 + tx, 238);
    glVertex2i(210.2771816223757 + tx, 238.3437690313077);
    glVertex2i(213.4168839876753 + tx, 249.6466975463847);

    glVertex2i(176.1685968357121 + tx, 260.9220871055456);
    glVertex2i(178.3123271184564 + tx, 249.9305441412842);
    glVertex2i(213.4168839876753 + tx, 249.6466975463847);
    glVertex2i(210 + tx, 260);

    glVertex2i(130 + tx, 270);
    glVertex2i(130 + tx, 260);
    glVertex2i(160 + tx, 260);
    glVertex2i(160 + tx, 270);
    glEnd();

    glColor4f(0.00, 0.0, 0.0, 1.0);      // black color
    glBegin(GL_QUADS);
    glVertex2i(120 + tx, 260);
    glVertex2i(120 + tx, 250);
    glVertex2i(130 + tx, 260);
    glVertex2i(130 + tx, 270);

    glVertex2i(130 + tx, 260);
    glVertex2i(120 + tx, 250);
    glVertex2i(178.3123271184564 + tx, 249.9305441412842);
    glVertex2i(160 + tx, 260);

    glVertex2i(178.3123271184564 + tx, 249.9305441412842);
    glVertex2i(160 + tx, 260);
    glVertex2i(160 + tx, 270);
    glVertex2i(176.1685968357121 + tx, 260.9220871055456);
    glEnd();

// lines in car =====================================================

    glColor4f(0.0, 0.0, 0.0, 1.0);      // black color
    glBegin(GL_LINES);
    glVertex2i(100 + tx, 260);
    glVertex2i(96.9624689838365 + tx, 250);
    glVertex2i(120 + tx, 250);
    glVertex2i(120 + tx, 260);
    glVertex2i(100 + tx, 260);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2i(96.9624689838365 + tx, 250);
    glVertex2i(99.1031751419953 + tx, 238.4722114007973);
    glVertex2i(210.2771816223757 + tx, 238.3437690313077);
    glVertex2i(213.4168839876753 + tx, 249.6466975463847);
    glVertex2i(96.9624689838365 + tx, 250);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2i(130 + tx, 270);
    glVertex2i(130 + tx, 260);
    glVertex2i(160 + tx, 260);
    glVertex2i(160 + tx, 270);
    glVertex2i(130 + tx, 270);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2i(176.1685968357121 + tx, 260.9220871055456);
    glVertex2i(178.3123271184564 + tx, 249.9305441412842);
    glVertex2i(213.4168839876753 + tx, 249.6466975463847);
    glVertex2i(210 + tx, 260);
    glVertex2i(176.1685968357121 + tx, 260.9220871055456);
    glEnd();

    glColor4f(1.0, 1.0, 1.0, 1.0);      // white color
    glBegin(GL_LINES);
    glVertex2i(120 + tx, 260);
    glVertex2i(120 + tx, 250);
    glVertex2i(130 + tx, 260);
    glVertex2i(130 + tx, 270);
    glVertex2i(120 + tx, 260);

    glVertex2i(120 + tx, 250);
    glVertex2i(178.3123271184564 + tx, 249.9305441412842);
    glVertex2i(160 + tx, 260);
    glVertex2i(130 + tx, 260);
    glVertex2i(120 + tx, 250);

    glVertex2i(160 + tx, 260);
    glVertex2i(178.3123271184564 + tx, 249.9305441412842);
    glVertex2i(176.1685968357121 + tx, 260.9220871055456);
    glVertex2i(160 + tx, 270);
    glVertex2i(160 + tx, 260);
    glEnd();

    drawTire(110 + tx, 238, 6, 0.5);
    drawTire(194 + tx, 238, 6, 0.5);

}
void drawShapes(void)
{
    glClear(GL_COLOR_BUFFER_BIT);	// Clear display window


    glColor3f(0.0, 0.0, 0.0);                                //Set colour to black

    glPointSize(10.0);                                         //Adjust the point size



    glColor3f(0.529f, 0.808f, 0.922f); // Sky blue color with full opacity
    glBegin(GL_QUADS);
    glVertex2i(1000, 300);
    glVertex2i(2000, 300);
    glVertex2i(2000, 1100);
    glVertex2i(1000, 1100);
    glEnd();





    glColor3f(0.529f, 0.808f, 0.922f); // Sky blue color with full opacity
    glBegin(GL_QUADS);
    glVertex2i(1000, 300);
    glVertex2i(0, 300);
    glVertex2i(0, 1100);
    glVertex2i(1000, 1100);
    glEnd();




    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_QUADS);
    glVertex2i(1000, 300);
    glVertex2i(0, 300);
    glVertex2i(0, 0);
    glVertex2i(1000, 0);
    glEnd();




    // Draw a couple of points

    //===================================== B U S H ================================================
    glColor3f(0.0f, 0.8f, 0.1f);
    drawCircleWborder(1045, 320, 20, 0.5);
    drawCircleWborder(1065, 330, 20, 0.5);
    drawCircleWborder(1075, 330, 20, 0.5);
    drawCircleWborder(1085, 340, 20, 0.5);
    drawCircleWborder(1105, 345, 20, 0.5);
    drawCircleWborder(1115, 345, 20, 0.5);
    drawCircleWborder(1125, 335, 20, 0.5);
    drawCircleWborder(1135, 325, 20, 0.5);
    drawCircleWborder(1145, 325, 20, 0.5);
    drawCircleWborder(1155, 335, 20, 0.5);
    drawCircleWborder(1165, 345, 20, 0.5);
    drawCircleWborder(1175, 355, 20, 0.5);
    drawCircleWborder(1185, 355, 20, 0.5);
    drawCircleWborder(1195, 365, 20, 0.5);
    drawCircleWborder(1205, 355, 20, 0.5);
    drawCircleWborder(1215, 355, 20, 0.5);
    drawCircleWborder(1225, 365, 20, 0.5);
    drawCircleWborder(1235, 365, 20, 0.5);
    drawCircleWborder(1245, 355, 20, 0.5);
    drawCircleWborder(1255, 355, 20, 0.5);
    drawCircleWborder(1265, 345, 20, 0.5);
    drawCircleWborder(1275, 335, 20, 0.5);
    drawCircleWborder(1285, 325, 20, 0.5);
    drawCircleWborder(1295, 325, 20, 0.5);
    drawCircleWborder(1305, 335, 20, 0.5);
    drawCircleWborder(1315, 345, 20, 0.5);
    drawCircleWborder(1325, 355, 20, 0.5);
    drawCircleWborder(1335, 365, 20, 0.5);
    drawCircleWborder(1345, 375, 20, 0.5);
    drawCircleWborder(1355, 375, 20, 0.5);
    drawCircleWborder(1365, 375, 20, 0.5);
    drawCircleWborder(1375, 365, 20, 0.5);
    drawCircleWborder(1375, 365, 20, 0.5);
    drawCircleWborder(1395, 365, 25, 0.5);
    drawCircleWborder(1415, 360, 25, 0.5);
    drawCircleWborder(1435, 355, 25, 0.5);
    drawCircleWborder(1455, 350, 25, 0.5);
    drawCircleWborder(1465, 340, 25, 0.5);
    drawCircleWborder(1485, 340, 25, 0.5);
    drawCircleWborder(1505, 340, 25, 0.5);
    drawCircleWborder(1525, 350, 25, 0.5);
    drawCircleWborder(1545, 350, 25, 0.5);
    drawCircleWborder(1565, 360, 25, 0.5);
    drawCircleWborder(1585, 365, 25, 0.5);
    drawCircleWborder(1605, 370, 25, 0.5);
    drawCircleWborder(1625, 375, 25, 0.5);
    drawCircleWborder(1645, 375, 25, 0.5);
    drawCircleWborder(1665, 375, 25, 0.5);
    drawCircleWborder(1685, 370, 25, 0.5);
    drawCircleWborder(1705, 365, 25, 0.5);
    drawCircleWborder(1725, 360, 25, 0.5);
    drawCircleWborder(1745, 355, 25, 0.5);
    drawCircleWborder(1765, 345, 25, 0.5);
    drawCircleWborder(1785, 340, 25, 0.5);
    drawCircleWborder(1805, 335, 25, 0.5);
    drawCircleWborder(1825, 330, 25, 0.5);
    drawCircleWborder(1845, 330, 25, 0.5);
    drawCircleWborder(1865, 335, 25, 0.5);
    drawCircleWborder(1885, 340, 25, 0.5);
    drawCircleWborder(1905, 345, 25, 0.5);
    drawCircleWborder(1925, 345, 25, 0.5);
    drawCircleWborder(1945, 350, 25, 0.5);
    drawCircleWborder(1965, 355, 25, 0.5);

    drawCircle(1090, 320, 40);
    drawCircle(1150, 320, 30);
    drawCircle(1190, 330, 40);
    drawCircle(1240, 330, 40);
    drawCircle(1290, 320, 40);
    drawCircle(1340, 335, 40);
    drawCircle(1390, 340, 40);
    drawCircle(1390, 320, 40);
    drawCircle(1440, 330, 40);
    drawCircle(1490, 310, 40);
    drawCircle(1540, 320, 40);
    drawCircle(1590, 335, 40);
    drawCircle(1640, 350, 40);
    drawCircle(1660, 330, 60);
    drawCircle(1690, 345, 40);
    drawCircle(1740, 330, 40);
    drawCircle(1790, 310, 40);
    drawCircle(1840, 310, 40);
    drawCircle(1890, 320, 40);
    drawCircle(1940, 330, 40);
    drawCircle(1990, 330, 40);


    //village ground color
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2i(1000, 300);
    glVertex2i(1000, 0);
    glVertex2i(1980, 0);
    glVertex2i(1980, 300);
    glEnd();



    //city ground color with buildings ================================================================
    glColor3f(0.0f, 0.7f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2i(0, 300);
    glVertex2i(0, 290);
    glVertex2i(1000, 290);
    glVertex2i(1000, 300);
    glEnd();
    //city ground color with buildings ================================================================


    //road -- start ============================================================================
    glColor3f(0.35f, 0.35f, 0.35f); // Dark gray color for highway road
    glBegin(GL_QUADS);
    glVertex2i(0, 290);
    glVertex2i(0, 220);
    glVertex2i(1000, 220);
    glVertex2i(1000, 290);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); // Dark gray color for highway road
    glBegin(GL_QUADS);
    glVertex2i(20, 255);
    glVertex2i(60, 255);
    glVertex2i(60, 260);
    glVertex2i(20, 260);

    glVertex2i(80, 255);
    glVertex2i(120, 255);
    glVertex2i(120, 260);
    glVertex2i(80, 260);

    glVertex2i(140, 255);
    glVertex2i(180, 255);
    glVertex2i(180, 260);
    glVertex2i(140, 260);

    glVertex2i(200, 255);
    glVertex2i(240, 255);
    glVertex2i(240, 260);
    glVertex2i(200, 260);

    glVertex2i(260, 255);
    glVertex2i(300, 255);
    glVertex2i(300, 260);
    glVertex2i(260, 260);

    glVertex2i(320, 255);
    glVertex2i(360, 255);
    glVertex2i(360, 260);
    glVertex2i(320, 260);

    glVertex2i(380, 255);                              //part 4
    glVertex2i(420, 255);
    glVertex2i(420, 260);
    glVertex2i(380, 260);

    glVertex2i(440, 255);                              //part 5
    glVertex2i(480, 255);
    glVertex2i(480, 260);
    glVertex2i(440, 260);

    glVertex2i(500, 255);                              //part 6
    glVertex2i(540, 255);
    glVertex2i(540, 260);
    glVertex2i(500, 260);

    glVertex2i(560, 255);                              //part 7
    glVertex2i(600, 255);
    glVertex2i(600, 260);
    glVertex2i(560, 260);

    glVertex2i(620, 255);                              //part 8
    glVertex2i(660, 255);
    glVertex2i(660, 260);
    glVertex2i(620, 260);


    glVertex2i(680, 255);                              // Part 9
    glVertex2i(720, 255);
    glVertex2i(720, 260);
    glVertex2i(680, 260);

    glVertex2i(740, 255);                              // Part 10
    glVertex2i(780, 255);
    glVertex2i(780, 260);
    glVertex2i(740, 260);

    // Part 11
    glVertex2i(800, 255);
    glVertex2i(840, 255);
    glVertex2i(840, 260);
    glVertex2i(800, 260);

    // Part 12
    glVertex2i(860, 255);
    glVertex2i(900, 255);
    glVertex2i(900, 260);
    glVertex2i(860, 260);

    // Part 13
    glVertex2i(920, 255);
    glVertex2i(960, 255);
    glVertex2i(960, 260);
    glVertex2i(920, 260);

    glEnd();
    //road -- end ==============================================================================
    // ======================================= T  R  E  E  E ========================================

    //================================== T  R  E  E =====================================



    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2i(1000, 0);
    glVertex2i(1000, 2000);
    glEnd();

    drawBananaTree(0, 0);
    drawBananaTree(80, 20);
    drawBananaTree(150, 0);
    drawBananaTree(-100, 20);
    drawBananaTree(-170, 0);

    //===================================== H O U S E - 1 ====================================
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);                            //Brown or wood color

    glBegin(GL_QUADS);                                    //tree middle part
    glVertex2i(1630.34, 336.83);
    glVertex2i(1630.3469113319748, 298.4663866468133);
    glVertex2i(1677.2314735939249, 290.7038954421225);
    glVertex2i(1676.929122760916, 337.0775594258193);

    glVertex2i(1677.1647742925988, 286.6395876893712);
    glVertex2i(1677.2314735939249, 290.7038954421225);
    glVertex2i(1749.5486993470274, 296.4760042866362);
    glVertex2i(1749.6701863835895, 293.3375742933755);

    glVertex2i(1677.2314735939249, 290.7038954421225);
    glVertex2i(1676.929122760916, 337.0775594258193);
    glVertex2i(1749.21, 337.84);
    glVertex2i(1749.5486993470274, 296.4760042866362);

    glVertex2i(1630.3469113319748, 298.4663866468133);
    glVertex2i(1630.4441311982232, 295.1490929056364);
    glVertex2i(1677.1647742925988, 286.6395876893712);
    glVertex2i(1677.2314735939249, 290.7038954421225);
    glEnd();

    glColor3f(0.55f, 0.35f, 0.10f);                            //Brown or wood color

    glBegin(GL_QUADS);                                    //tree middle part
    glVertex2i(1676.929122760916, 337.0775594258193);
    glVertex2i(1757.4402233714532, 337.9296516636617);
    glVertex2i(1730.297229644523, 364.6685199520752);
    glVertex2i(1648.9711768431264, 364.0823780140418);

    glVertex2i(1648.9711768431264, 364.0823780140418);
    glVertex2i(1622.5993155396698, 336.793765713172);
    glVertex2i(1630.34, 336.83);
    glVertex2i(1652.82, 360.36);
    glEnd();

    //DOOR
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2i(1645, 296.1);
    glVertex2i(1645.2882977472784, 322.2437399156744);
    glVertex2i(1650.7, 322.18);
    glVertex2i(1650.034, 295.21);

    glVertex2i(1650.7, 322.18);
    glVertex2i(1650.034, 295.21);
    glVertex2i(1655.62, 294.28);
    glVertex2i(1657, 320);
    glEnd();

    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2i(1645, 296.1);
    glVertex2i(1630.3469113319748, 298.4663866468133);

    glVertex2i(1650.7, 322.18);
    glVertex2i(1650.034, 295.21);

    glVertex2i(1655.62, 294.28);
    glVertex2i(1657, 320);
    glEnd();
    //DOOR END

    //Windows
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2i(1687.7390780804533, 322.6582783376679);
    glVertex2i(1687.741045506573, 308.8140075133853);
    glVertex2i(1700.3083166355257, 308.8064745956596);
    glVertex2i(1700.3083166355257, 322.6266235990075);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2i(1727.4009245791663, 323.5921764674342);
    glVertex2i(1727.402892005286, 309.7479056431516);
    glVertex2i(1740, 309);
    glVertex2i(1740, 323.8201490033479);
    glEnd();
    //Windows

    glColor4f(1.0f, 1.0f, 1.0f, 0.0f); //red
    glBegin(GL_TRIANGLES);
    glVertex2i(1630.34, 336.83);
    glVertex2i(1652.82, 360.36);
    glVertex2i(1676.929122760916, 337.0775594258193);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // Black color for lines
    glBegin(GL_LINE_LOOP);
    glVertex2i(1630.3469113319748, 298.4663866468133);
    glVertex2i(1630.4441311982232, 295.1490929056364);
    glVertex2i(1676.9712549083083, 287.7763032324879);
    glVertex2i(1677.2314735939249, 290.7038954421225);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2i(1676.9712549083083, 287.7763032324879);
    glVertex2i(1677.2314735939249, 290.7038954421225);
    glVertex2i(1749.5486993470274, 296.4760042866362);
    glVertex2i(1749.6701863835895, 293.3375742933755);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(1630.34, 336.83);
    glVertex2i(1630.3469113319748, 298.4663866468133);

    glVertex2i(1630.3469113319748, 298.4663866468133);
    glVertex2i(1677.2314735939249, 290.7038954421225);

    glVertex2i(1677.2314735939249, 290.7038954421225);
    glVertex2i(1676.929122760916, 337.0775594258193);

    glVertex2i(1676.929122760916, 337.0775594258193);
    glVertex2i(1652.82, 360.36);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2i(1677.1647742925988, 286.6395876893712);
    glVertex2i(1677.2314735939249, 290.7038954421225);
    glVertex2i(1749.5486993470274, 296.4760042866362);
    glVertex2i(1749.6701863835895, 293.3375742933755);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2i(1676.929122760916, 337.0775594258193);
    glVertex2i(1757.4402233714532, 337.9296516636617);
    glVertex2i(1730.297229644523, 364.6685199520752);
    glVertex2i(1648.9711768431264, 364.0823780140418);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2i(1677.2314735939249, 290.7038954421225);
    glVertex2i(1676.929122760916, 337.0775594258193);
    glVertex2i(1749.21, 337.84);
    glVertex2i(1749.5486993470274, 296.4760042866362);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2i(1630.3469113319748, 298.4663866468133);
    glVertex2i(1630.4441311982232, 295.1490929056364);
    glVertex2i(1677.1647742925988, 286.6395876893712);
    glVertex2i(1677.2314735939249, 290.7038954421225);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2i(1648.9711768431264, 364.0823780140418);
    glVertex2i(1622.5993155396698, 336.793765713172);
    glVertex2i(1630.34, 336.83);
    glVertex2i(1652.82, 360.36);
    glEnd();
    //==================================== H  O  U  S  E - 1 == E N D =========================================


    //===================================== H O U S E - 2 ====================================
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f); // Brown or wood color

    glBegin(GL_QUADS); // Tree middle part
    glVertex2i(1780.34, 336.83);
    glVertex2i(1780.4969113319748, 298.4663866468133);
    glVertex2i(1827.3814735939249, 290.7038954421225);
    glVertex2i(1827.079122760916, 337.0775594258193);

    glVertex2i(1827.3147742925988, 286.6395876893712);
    glVertex2i(1827.3814735939249, 290.7038954421225);
    glVertex2i(1900.6986993470274, 296.4760042866362);
    glVertex2i(1900.8201863835895, 293.3375742933755);

    glVertex2i(1827.3814735939249, 290.7038954421225);
    glVertex2i(1827.079122760916, 337.0775594258193);
    glVertex2i(1900.36, 337.84);
    glVertex2i(1900.6986993470274, 296.4760042866362);

    glVertex2i(1780.4969113319748, 298.4663866468133);
    glVertex2i(1780.6441311982232, 295.1490929056364);
    glVertex2i(1827.3147742925988, 286.6395876893712);
    glVertex2i(1827.3814735939249, 290.7038954421225);
    glEnd();

    glColor3f(0.55f, 0.35f, 0.10f); // Brown or wood color

    glBegin(GL_QUADS); // Tree middle part
    glVertex2i(1827.079122760916, 337.0775594258193);
    glVertex2i(1907.5902233714532, 337.9296516636617);
    glVertex2i(1880.447229644523, 364.6685199520752);
    glVertex2i(1799.1211768431264, 364.0823780140418);

    glVertex2i(1799.1211768431264, 364.0823780140418);
    glVertex2i(1772.7493155396698, 336.793765713172);
    glVertex2i(1780.49, 336.83);
    glVertex2i(1802.97, 360.36);
    glEnd();

    glColor4f(1.0f, 1.0f, 1.0f, 0.0f); // Red
    glBegin(GL_TRIANGLES);
    glVertex2i(1780.34, 336.83);
    glVertex2i(1802.82, 360.36);
    glVertex2i(1827.079122760916, 337.0775594258193);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // Black color for lines
    glBegin(GL_LINE_LOOP);
    glVertex2i(1780.4969113319748, 298.4663866468133);
    glVertex2i(1780.6441311982232, 295.1490929056364);
    glVertex2i(1827.1712549083083, 287.7763032324879);
    glVertex2i(1827.4314735939249, 290.7038954421225);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2i(1827.1712549083083, 287.7763032324879);
    glVertex2i(1827.4314735939249, 290.7038954421225);
    glVertex2i(1900.7486993470274, 296.4760042866362);
    glVertex2i(1900.8701863835895, 293.3375742933755);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(1780.34, 336.83);
    glVertex2i(1780.4969113319748, 298.4663866468133);

    glVertex2i(1780.4969113319748, 298.4663866468133);
    glVertex2i(1827.3814735939249, 290.7038954421225);

    glVertex2i(1827.3814735939249, 290.7038954421225);
    glVertex2i(1827.079122760916, 337.0775594258193);

    glVertex2i(1827.079122760916, 337.0775594258193);
    glVertex2i(1802.82, 360.36);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2i(1827.3147742925988, 286.6395876893712);
    glVertex2i(1827.3814735939249, 290.7038954421225);
    glVertex2i(1900.7486993470274, 296.4760042866362);
    glVertex2i(1900.8701863835895, 293.3375742933755);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2i(1827.079122760916, 337.0775594258193);
    glVertex2i(1907.5902233714532, 337.9296516636617);
    glVertex2i(1880.447229644523, 364.6685199520752);
    glVertex2i(1799.1211768431264, 364.0823780140418);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2i(1827.3814735939249, 290.7038954421225);
    glVertex2i(1827.079122760916, 337.0775594258193);
    glVertex2i(1900.71, 337.84);
    glVertex2i(1900.7486993470274, 296.4760042866362);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2i(1780.4969113319748, 298.4663866468133);
    glVertex2i(1780.6441311982232, 295.1490929056364);
    glVertex2i(1827.3147742925988, 286.6395876893712);
    glVertex2i(1827.3814735939249, 290.7038954421225);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2i(1799.1211768431264, 364.0823780140418);
    glVertex2i(1772.7493155396698, 336.793765713172);
    glVertex2i(1780.49, 336.83);
    glVertex2i(1802.97, 360.36);
    glEnd();

    //DOOR
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2i(1795, 296.1);
    glVertex2i(1795.2882977472784, 322.2437399156744);
    glVertex2i(1800.7, 322.18);
    glVertex2i(1800.034, 295.21);

    glVertex2i(1800.7, 322.18);
    glVertex2i(1800.034, 295.21);
    glVertex2i(1805.62, 294.28);
    glVertex2i(1807, 320);
    glEnd();

    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2i(1795, 296.1);
    glVertex2i(1780.3469113319748, 298.4663866468133);

    glVertex2i(1800.7, 322.18);
    glVertex2i(1800.034, 295.21);

    glVertex2i(1805.62, 294.28);
    glVertex2i(1807, 320);
    glEnd();
//DOOR END

//Windows
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2i(1837.7390780804533, 322.6582783376679);
    glVertex2i(1837.741045506573, 308.8140075133853);
    glVertex2i(1850.3083166355257, 308.8064745956596);
    glVertex2i(1850.3083166355257, 322.6266235990075);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2i(1877.4009245791663, 323.5921764674342);
    glVertex2i(1877.402892005286, 309.7479056431516);
    glVertex2i(1890, 309);
    glVertex2i(1890, 323.8201490033479);
    glEnd();
//Windows


    //==================================== H  O  U  S  E - 2 == E N D =========================================

    // Righ river
    //Set colour to wood color
    glColor3f(0.55f, 0.35f, 0.10f);
    glBegin(GL_LINE_STRIP);
    glVertex2i(1350, 0);
    glVertex2i(1358.829948312425, 12.8476178777768);
    glVertex2i(1368.7418219960766, 26.526003561215);
    glVertex2i(1380.6360704164588, 39.6096768236342);
    glVertex2i(1393.191110415751, 53.2880625070725);
    glVertex2i(1409.0501083095937, 69.940010295606);
    glVertex2i(1428.213064097987, 84.2131084000633);
    glVertex2i(1451.340769359841, 89.5655201892348);
    glVertex2i(1475.7900577795153, 90.1602326102538);
    glVertex2i(1499.5785546202799, 87.1866705051586);
    glVertex2i(1523.3670514610442, 89.5655201892348);
    glVertex2i(1539.886840933797, 97.8914940835015);
    glVertex2i(1553.7634640909096, 113.948729451016);
    glVertex2i(1567.640087248022, 130.0059648185304);
    glVertex2i(1588.7854177731456, 147.252625028083);
    glVertex2i(1613.2347061928199, 162.1204355535594);
    glVertex2i(1632.397661981213, 174.0146839739404);
    glVertex2i(1653.542992506337, 183.5300827102453);
    glVertex2i(1670.723573558, 193.6401938675692);
    glVertex2i(1693.1904872409439, 203.7503050248932);
    glVertex2i(1723.5868998708092, 214.4551286032361);
    glVertex2i(1750.0185630272138, 223.970527339541);
    glVertex2i(1777.7718093414387, 233.4859260758458);
    glVertex2i(1801.5603061822028, 239.4330502860364);
    glVertex2i(1826.670386180787, 247.1643117592841);
    glVertex2i(1850, 250);
    glVertex2i(1879.5337124935963, 254.3008608115127);
    glVertex2i(1903.823724729105, 256.4790826670508);
    glVertex2i(1928.0984911002124, 259.9902542314428);
    glVertex2i(1954.6737284733033, 261.7153675544318);
    glVertex2i(1980, 261.72);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2i(1370, -10);
    glVertex2i(1378.829948312425, 2.8476178777768);
    glVertex2i(1388.7418219960766, 16.526003561215);
    glVertex2i(1400.6360704164588, 29.6096768236342);
    glVertex2i(1413.191110415751, 43.2880625070725);
    glVertex2i(1429.0501083095937, 59.940010295606);
    glVertex2i(1448.213064097987, 74.2131084000633);
    glVertex2i(1471.340769359841, 79.5655201892348);
    glVertex2i(1495.7900577795153, 80.1602326102538);
    glVertex2i(1519.5785546202799, 77.1866705051586);
    glVertex2i(1543.3670514610442, 79.5655201892348);
    glVertex2i(1559.886840933797, 87.8914940835015);
    glVertex2i(1573.7634640909096, 103.948729451016);
    glVertex2i(1587.640087248022, 120.0059648185304);
    glVertex2i(1608.7854177731456, 137.252625028083);
    glVertex2i(1633.2347061928199, 152.1204355535594);
    glVertex2i(1652.397661981213, 164.0146839739404);
    glVertex2i(1673.542992506337, 173.5300827102453);
    glVertex2i(1690.723573558, 183.6401938675692);
    glVertex2i(1713.1904872409439, 193.7503050248932);
    glVertex2i(1743.5868998708092, 204.4551286032361);
    glVertex2i(1770.0185630272138, 213.970527339541);
    glVertex2i(1797.7718093414387, 223.4859260758458);
    glVertex2i(1821.5603061822028, 229.4330502860364);
    glVertex2i(1846.670386180787, 237.1643117592841);
    glVertex2i(1870, 240);
    glVertex2i(1899.5337124935963, 244.3008608115127);
    glVertex2i(1923.823724729105, 246.4790826670508);
    glVertex2i(1948.0984911002124, 249.9902542314428);
    glVertex2i(1974.6737284733033, 251.7153675544318);
    glVertex2i(2000, 251.72);
    glEnd();
    //Right rver end

    //Village river water -- Start =============================================

    glColor3f(0.55f, 0.35f, 0.10f);
    glBegin(GL_QUAD_STRIP);
    glVertex2i(1350, 0);
    glVertex2i(1370, -10);
    glVertex2i(1358.829948312425, 12.8476178777768);
    glVertex2i(1378.829948312425, 2.8476178777768);
    glVertex2i(1368.7418219960766, 26.526003561215);
    glVertex2i(1388.7418219960766, 16.526003561215);
    glVertex2i(1380.6360704164588, 39.6096768236342);
    glVertex2i(1400.6360704164588, 29.6096768236342);
    glVertex2i(1393.191110415751, 53.2880625070725);
    glVertex2i(1413.191110415751, 43.2880625070725);
    glVertex2i(1409.0501083095937, 69.940010295606);
    glVertex2i(1429.0501083095937, 59.940010295606);
    glVertex2i(1428.213064097987, 84.2131084000633);
    glVertex2i(1448.213064097987, 74.2131084000633);
    glVertex2i(1451.340769359841, 89.5655201892348);
    glVertex2i(1471.340769359841, 79.5655201892348);
    glVertex2i(1475.7900577795153, 90.1602326102538);
    glVertex2i(1495.7900577795153, 80.1602326102538);
    glVertex2i(1499.5785546202799, 87.1866705051586);
    glVertex2i(1519.5785546202799, 77.1866705051586);
    glVertex2i(1523.3670514610442, 89.5655201892348);
    glVertex2i(1543.3670514610442, 79.5655201892348);
    glVertex2i(1539.886840933797, 97.8914940835015);
    glVertex2i(1559.886840933797, 87.8914940835015);
    glVertex2i(1553.7634640909096, 113.948729451016);
    glVertex2i(1573.7634640909096, 103.948729451016);
    glVertex2i(1567.640087248022, 130.0059648185304);
    glVertex2i(1587.640087248022, 120.0059648185304);
    glVertex2i(1588.7854177731456, 147.252625028083);
    glVertex2i(1608.7854177731456, 137.252625028083);
    glVertex2i(1613.2347061928199, 162.1204355535594);
    glVertex2i(1633.2347061928199, 152.1204355535594);
    glVertex2i(1632.397661981213, 174.0146839739404);
    glVertex2i(1652.397661981213, 164.0146839739404);
    glVertex2i(1653.542992506337, 183.5300827102453);
    glVertex2i(1673.542992506337, 173.5300827102453);
    glVertex2i(1670.723573558, 193.6401938675692);
    glVertex2i(1690.723573558, 183.6401938675692);
    glVertex2i(1693.1904872409439, 203.7503050248932);
    glVertex2i(1713.1904872409439, 193.7503050248932);
    glVertex2i(1723.5868998708092, 214.4551286032361);
    glVertex2i(1743.5868998708092, 204.4551286032361);
    glVertex2i(1750.0185630272138, 223.970527339541);
    glVertex2i(1770.0185630272138, 213.970527339541);
    glVertex2i(1777.7718093414387, 233.4859260758458);
    glVertex2i(1797.7718093414387, 223.4859260758458);
    glVertex2i(1801.5603061822028, 239.4330502860364);
    glVertex2i(1821.5603061822028, 229.4330502860364);
    glVertex2i(1826.670386180787, 247.1643117592841);
    glVertex2i(1846.670386180787, 237.1643117592841);
    glVertex2i(1850, 250);
    glVertex2i(1870, 240);
    glVertex2i(1879.5337124935963, 254.3008608115127);
    glVertex2i(1899.5337124935963, 244.3008608115127);
    glVertex2i(1903.823724729105, 256.4790826670508);
    glVertex2i(1923.823724729105, 246.4790826670508);
    glVertex2i(1928.0984911002124, 259.9902542314428);
    glVertex2i(1948.0984911002124, 249.9902542314428);
    glVertex2i(1954.6737284733033, 261.7153675544318);
    glVertex2i(1974.6737284733033, 251.7153675544318);
    glVertex2i(1980, 261.72);
    glVertex2i(2000, 251.72);
    glEnd();


    glColor3f(0.0f, 0.5f, 1.0f); // Light blue color
    glBegin(GL_QUAD_STRIP);
    glVertex2i(1370, -10);
    glVertex2i(1370, -310);
    glVertex2i(1378.829948312425, 2.8476178777768);
    glVertex2i(1378.829948312425, -297.1523821222232);
    glVertex2i(1388.7418219960766, 16.526003561215);
    glVertex2i(1388.7418219960766, -283.473996438785);
    glVertex2i(1400.6360704164588, 29.6096768236342);
    glVertex2i(1400.6360704164588, -270.3903231763658);
    glVertex2i(1413.191110415751, 43.2880625070725);
    glVertex2i(1413.191110415751, -256.7119374929275);
    glVertex2i(1429.0501083095937, 59.940010295606);
    glVertex2i(1429.0501083095937, -240.059989704394);
    glVertex2i(1448.213064097987, 74.2131084000633);
    glVertex2i(1448.213064097987, -225.7868915999367);
    glVertex2i(1471.340769359841, 79.5655201892348);
    glVertex2i(1471.340769359841, -220.4344798107652);
    glVertex2i(1495.7900577795153, 80.1602326102538);
    glVertex2i(1495.7900577795153, -219.8397673897462);
    glVertex2i(1519.5785546202799, 77.1866705051586);
    glVertex2i(1519.5785546202799, -222.8133294948414);
    glVertex2i(1543.3670514610442, 79.5655201892348);
    glVertex2i(1543.3670514610442, -220.4344798107652);
    glVertex2i(1559.886840933797, 87.8914940835015);
    glVertex2i(1559.886840933797, -212.1085059164985);
    glVertex2i(1573.7634640909096, 103.948729451016);
    glVertex2i(1573.7634640909096, -196.051270548984);
    glVertex2i(1587.640087248022, 120.0059648185304);
    glVertex2i(1587.640087248022, -179.9940351814696);
    glVertex2i(1608.7854177731456, 137.252625028083);
    glVertex2i(1608.7854177731456, -162.7473749719169);
    glVertex2i(1633.2347061928199, 152.1204355535594);
    glVertex2i(1633.2347061928199, -147.8795644464406);
    glVertex2i(1652.397661981213, 164.0146839739404);
    glVertex2i(1652.397661981213, -135.9853160260596);
    glVertex2i(1673.542992506337, 173.5300827102453);
    glVertex2i(1673.542992506337, -126.4699172897547);
    glVertex2i(1690.723573558, 183.6401938675692);
    glVertex2i(1690.723573558, -116.3598061324308);
    glVertex2i(1713.1904872409439, 193.7503050248932);
    glVertex2i(1713.1904872409439, -106.2496949751068);
    glVertex2i(1743.5868998708092, 204.4551286032361);
    glVertex2i(1743.5868998708092, -95.5448713967639);
    glVertex2i(1770.0185630272138, 213.970527339541);
    glVertex2i(1770.0185630272138, -86.02947266045904);
    glVertex2i(1797.7718093414387, 223.4859260758458);
    glVertex2i(1797.7718093414387, -76.51407392415425);
    glVertex2i(1821.5603061822028, 229.4330502860364);
    glVertex2i(1821.5603061822028, -70.56694971396364);
    glVertex2i(1846.670386180787, 237.1643117592841);
    glVertex2i(1846.670386180787, -62.8356882407159);
    glVertex2i(1870, 240);
    glVertex2i(1870, -60);
    glVertex2i(1899.5337124935963, 244.3008608115127);
    glVertex2i(1899.5337124935963, -55.69913918848726);
    glVertex2i(1923.823724729105, 246.4790826670508);
    glVertex2i(1923.823724729105, -53.52091733294916);
    glVertex2i(1948.0984911002124, 249.9902542314428);
    glVertex2i(1948.0984911002124, -50.00974576855719);
    glVertex2i(1974.6737284733033, 251.7153675544318);
    glVertex2i(1974.6737284733033, -48.28463244556818);
    glVertex2i(2000, 251.72);
    glVertex2i(2000, -48.28);
    glEnd();

    //Village river water -- End =============================================

    //Sun -- start ===========================================================

    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//sun color
    drawSun(1715, 835, 70);

    //Sun -- end =============================================================
    glPushMatrix();
    glTranslatef(bx, 0, 0);

    drawCloud(0, 0);
    drawCloud(120, -100);
    drawCloud(150, -150);
    drawCloud(400, -140);

    glPopMatrix();

    // Update bx based on direction
    if (direction) {
        bx += 1.5;
        if (bx >= 300) {
            direction = false;
        }
    } else {
        bx -= 1.5;
        if (bx <= 0) {
            direction = true;
        }
    }

    glutPostRedisplay();
    //small bush -- start ====================================================
    drawBush(0, 0);
    drawBush(215, 90);
    drawBush(45, 135);
    //small bush -- end ======================================================

    //Boat -- start ==========================================================

    glColor3f(0.0f, 0.0f, 0.0f);                 // black -- lower part
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2i(1638, 98.8);
    glVertex2i(1650, 80);
    glVertex2i(1652.67, 93.4);
    glVertex2i(1657.0825552484334, 76.2264899836626);
    glVertex2i(1665, 90);
    glVertex2i(1669.6601579109938, 72.904362323878);
    glVertex2i(1673.1, 89.46);
    glVertex2i(1679.913638342429, 71.0278611417516);
    glVertex2i(1679.1572748635608, 89.05925597438);
    glVertex2i(1689.756979556607, 70.9278611417516);
    glVertex2i(1686.1, 89.03);
    glVertex2i(1700.1149530502128, 71.0134858240236);
    glVertex2i(1695, 89);
    glVertex2i(1750.5261605184567, 71.3292697749605);
    glVertex2i(1747.89, 88.91);
    glVertex2i(1750.2622200989795, 88.901408633209);
    glVertex2i(1758.5695017326361, 73.2366456615553);
    glVertex2i(1772.6509481918072, 76.8126897909855);

    glVertex2i(1750.5261605184567, 71.3292697749605);
    glVertex2i(1747.89, 88.91);
    glVertex2i(1758.5695017326361, 73.2366456615553);

    glVertex2i(1775.38520964019, 94.6537457416806);
    glVertex2i(1778.462220098981, 81.2014086332089);
    glVertex2i(1789.758137170986, 100.665429218768);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);                       // white upper part
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2i(1638, 98.8);
    glVertex2i(1652.6677107254905, 93.3792800215468);
    glVertex2i(1653.7215844228233, 96.4613401710933);
    glVertex2i(1665, 90);
    glVertex2i(1666.2434982616176, 95.1440998841554);
    glVertex2i(1673.1, 89.46);
    glVertex2i(1673.561499855718, 94.8513798203914);
    glVertex2i(1679.1572748635608, 89.05925597438);
    glVertex2i(1679.24, 94.91);
    glVertex2i(1686.1, 89.03);
    glVertex2i(1685.96, 94.98);
    glVertex2i(1692.75, 89.01);
    glVertex2i(1692.89, 95.05);

    glVertex2i(1747.6891358168928, 94.9801242873121);
    glVertex2i(1747.89, 88.91);
    glVertex2i(1750, 95.2);
    glVertex2i(1750.26, 88.90);
    glVertex2i(1763.2000000000016, 96.3);
    glVertex2i(1764.4481638466589, 91.331618081896);
    glVertex2i(1775.214581986415, 97.43245880696);
    glVertex2i(1775.38520964019, 94.6537457416806);
    glVertex2i(1789.758137170986, 100.665429218768);
    glEnd();

    glColor3f(0.55f, 0.35f, 0.10f);                       // black upper part
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2i(1673.561499855718, 94.8513798203914);
    glVertex2i(1692.89, 95.05);
    glVertex2i(1673.7241221133647, 103.632981733311);
    glVertex2i(1693.07555906071, 103.0625629879154);
    glVertex2i(1675.5129669474782, 109.3410229767087);
    glVertex2i(1691.9981101397245, 108.6868463554586);
    glVertex2i(1680.2290124192318, 113.1463838056405);
    glVertex2i(1688.3789914381186, 112.5364366728);


    glVertex2i(1680.2290124192318, 113.1463838056405);
    glVertex2i(1688.3789914381186, 112.5364366728);
    glVertex2i(1737.1244630445312, 113.2022328474586);
    glVertex2i(1691.9981101397245, 108.6868463554586);
    glVertex2i(1742.7167064283278, 112.0102020209126);
    glVertex2i(1693.07555906071, 103.0625629879154);
    glVertex2i(1745.8286747083898, 108.92128777232);
    glVertex2i(1692.75, 89.01);
    glVertex2i(1746.5092895197288, 105.1126193975498);
    glVertex2i(1695, 89);
    glVertex2i(1747.2891358168931, 99.9385793412582);
    glVertex2i(1716.97, 88.96);
    glVertex2i(1747.6891358168928, 94.9801242873121);
    glVertex2i(1734.78, 88.93);
    glVertex2i(1747.89, 88.91);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);                       // black upper part
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2i(1775.214581986415, 97.5);
    glVertex2i(1763.2000000000016, 96.4);
    glVertex2i(1747.6891358168928, 94.9801242873121);
    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f);                        //boat white lines
    glBegin(GL_LINE_STRIP);
    glVertex2i(1637.9977144616828, 98.8031006812052);
    glVertex2i(1650, 80);
    glVertex2i(1657.0825552484334, 76.2264899836626);
    glVertex2i(1669.6601579109938, 72.904362323878);
    glVertex2i(1679.913638342429, 71.0278611417516);
    glVertex2i(1689.756979556607, 70.9278611417516);
    glVertex2i(1700.1149530502128, 71.0134858240236);
    glVertex2i(1750.5261605184567, 71.3292697749605);
    glVertex2i(1758.5695017326361, 73.2366456615553);
    glVertex2i(1772.6509481918072, 76.8126897909855);
    glVertex2i(1778.462220098981, 81.2014086332089);
    glVertex2i(1789.758137170986, 100.665429218768);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_STRIP);
    glVertex2i(1695, 89);
    glVertex2i(1750.2622200989795, 88.901408633209);
    glVertex2i(1764.4481638466589, 91.331618081896);
    glVertex2i(1775.38520964019, 94.6537457416806);
    glVertex2i(1789.758137170986, 100.665429218768);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_STRIP);
    glVertex2i(1673.561499855718, 94.8513798203914);
    glVertex2i(1673.7241221133647, 103.632981733311);
    glVertex2i(1675.5129669474782, 109.3410229767087);
    glVertex2i(1680.2290124192318, 113.1463838056405);
    glVertex2i(1688.3789914381186, 112.5364366728);
    glVertex2i(1691.9981101397245, 108.6868463554586);
    glVertex2i(1693.07555906071, 103.0625629879154);
    glVertex2i(1692.75, 89.01);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_STRIP);
    glVertex2i(1680.2290124192318, 113.1463838056405);
    glVertex2i(1737.1244630445312, 113.2022328474586);
    glVertex2i(1742.7167064283278, 112.0102020209126);
    glVertex2i(1745.8286747083898, 108.92128777232);
    glVertex2i(1746.5092895197288, 105.1126193975498);
    glVertex2i(1747.2891358168931, 99.9385793412582);
    glVertex2i(1747.89, 88.91);
    glEnd();

    glColor3f(0.55f, 0.35f, 0.10f);          // boat stand
    glBegin(GL_QUADS);
    glVertex2i(1535, 140);
    glVertex2i(1535, 110);
    glVertex2i(1540, 110);
    glVertex2i(1540, 140);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_STRIP);
    glVertex2i(1540, 140);
    glVertex2i(1637.9977144616828, 98.8031006812052);
    glEnd();
    //Boat -- end ============================================================


    //City side -- start ======================================================
    //============================================================================================
    //City side -- start ======================================================
    //============================================================================================
    //City side -- start ======================================================
    //============================================================================================
    //City side -- start ======================================================
    //============================================================================================

    glColor3f(0.0f, 0.0f, 0.5f); // Dark Blue
    glBegin(GL_QUADS);
    glVertex2i(700, 300);
    glVertex2i(800, 300);
    glVertex2i(800, 400);
    glVertex2i(700, 400);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // Dark Blue
    glBegin(GL_LINES);
    glVertex2i(700, 300);
    glVertex2i(800, 300);
    glVertex2i(800, 400);
    glVertex2i(700, 400);
    glEnd();

    glColor3f(0.55f, 0.35f, 0.10f);  // wood color
    glBegin(GL_QUAD_STRIP);
    glVertex2i(690, 400);
    glVertex2i(810, 400);
    glVertex2i(720, 440);
    glVertex2i(780, 440);
    glVertex2i(720, 445);
    glVertex2i(780, 445);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // Dark Blue
    glBegin(GL_LINES);
    glVertex2i(690, 400);
    glVertex2i(810, 400);
    glVertex2i(720, 440);
    glVertex2i(780, 440);
    glVertex2i(720, 445);
    glVertex2i(780, 445);
    glEnd();

    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2i(710, 380);
    glVertex2i(710, 365);
    glVertex2i(725, 365);
    glVertex2i(725, 380);

    glVertex2i(710, 340);
    glVertex2i(710, 325);
    glVertex2i(725, 325);
    glVertex2i(725, 340);

    glVertex2i(775, 380);
    glVertex2i(775, 365);
    glVertex2i(790, 365);
    glVertex2i(790, 380);

    glVertex2i(775, 340);
    glVertex2i(775, 325);
    glVertex2i(790, 325);
    glVertex2i(790, 340);

    glVertex2i(740, 300);
    glVertex2i(740, 345);
    glVertex2i(760, 345);
    glVertex2i(760, 300);

    glVertex2i(740, 345);
    glVertex2i(760, 345);
    glVertex2i(755, 350);
    glVertex2i(745, 350);

    glVertex2i(742, 387);
    glVertex2i(742, 372);
    glVertex2i(757, 372);
    glVertex2i(757, 387);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // Dark Blue
    glBegin(GL_LINES);
    glVertex2i(710, 380);
    glVertex2i(710, 365);
    glVertex2i(725, 365);
    glVertex2i(725, 380);

    glVertex2i(710, 340);
    glVertex2i(710, 325);
    glVertex2i(725, 325);
    glVertex2i(725, 340);

    glVertex2i(775, 380);
    glVertex2i(775, 365);
    glVertex2i(790, 365);
    glVertex2i(790, 380);

    glVertex2i(775, 340);
    glVertex2i(775, 325);
    glVertex2i(790, 325);
    glVertex2i(790, 340);

    glVertex2i(740, 300);
    glVertex2i(740, 345);
    glVertex2i(760, 345);
    glVertex2i(760, 300);

    glVertex2i(740, 345);
    glVertex2i(760, 345);
    glVertex2i(755, 350);
    glVertex2i(745, 350);

    glVertex2i(742, 387);
    glVertex2i(742, 372);
    glVertex2i(757, 372);
    glVertex2i(757, 387);
    glEnd();

    //building -- start -- ==================================================================
    glColor3f(0.5f, 0.5f, 0.5f); // tan
    glBegin(GL_QUADS);
    glVertex2i(530, 520);
    glVertex2i(530, 300);
    glVertex2i(630, 300);
    glVertex2i(630, 520);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // black
    glBegin(GL_LINES);
    glVertex2i(530, 520);
    glVertex2i(530, 300);
    glVertex2i(630, 300);
    glVertex2i(630, 520);
    glEnd();

    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);   // white color
    glBegin(GL_QUADS);
    glVertex2i(540, 500);
    glVertex2i(540, 480);
    glVertex2i(570, 480);
    glVertex2i(570, 500);

    glVertex2i(540, 460);
    glVertex2i(540, 440);
    glVertex2i(570, 440);
    glVertex2i(570, 460);

    glVertex2i(540, 420);
    glVertex2i(540, 400);
    glVertex2i(570, 400);
    glVertex2i(570, 420);

    glVertex2i(540, 380);
    glVertex2i(540, 360);
    glVertex2i(570, 360);
    glVertex2i(570, 380);

    glVertex2i(540, 340);
    glVertex2i(540, 320);
    glVertex2i(570, 320);
    glVertex2i(570, 340);
    glEnd();

    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);   // black color
    glBegin(GL_LINES);
    glVertex2i(540, 500);
    glVertex2i(540, 480);
    glVertex2i(570, 480);
    glVertex2i(570, 500);

    glVertex2i(540, 460);
    glVertex2i(540, 440);
    glVertex2i(570, 440);
    glVertex2i(570, 460);

    glVertex2i(540, 420);
    glVertex2i(540, 400);
    glVertex2i(570, 400);
    glVertex2i(570, 420);

    glVertex2i(540, 380);
    glVertex2i(540, 360);
    glVertex2i(570, 360);
    glVertex2i(570, 380);

    glVertex2i(540, 340);
    glVertex2i(540, 320);
    glVertex2i(570, 320);
    glVertex2i(570, 340);
    glEnd();

    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);   // white color
    glBegin(GL_QUADS);
    glVertex2i(590, 500); // Increased by 50
    glVertex2i(590, 480); // Increased by 50
    glVertex2i(620, 480); // Increased by 50
    glVertex2i(620, 500); // Increased by 50

    glVertex2i(590, 460); // Increased by 50
    glVertex2i(590, 440); // Increased by 50
    glVertex2i(620, 440); // Increased by 50
    glVertex2i(620, 460); // Increased by 50

    glVertex2i(590, 420); // Increased by 50
    glVertex2i(590, 400); // Increased by 50
    glVertex2i(620, 400); // Increased by 50
    glVertex2i(620, 420); // Increased by 50

    glVertex2i(590, 380); // Increased by 50
    glVertex2i(590, 360); // Increased by 50
    glVertex2i(620, 360); // Increased by 50
    glVertex2i(620, 380); // Increased by 50

    glVertex2i(590, 340); // Increased by 50
    glVertex2i(590, 320); // Increased by 50
    glVertex2i(620, 320); // Increased by 50
    glVertex2i(620, 340); // Increased by 50
    glEnd();

    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);   // black color
    glBegin(GL_LINES);
    glVertex2i(590, 500); // Increased by 50
    glVertex2i(590, 480); // Increased by 50
    glVertex2i(620, 480); // Increased by 50
    glVertex2i(620, 500); // Increased by 50

    glVertex2i(590, 460); // Increased by 50
    glVertex2i(590, 440); // Increased by 50
    glVertex2i(620, 440); // Increased by 50
    glVertex2i(620, 460); // Increased by 50

    glVertex2i(590, 420); // Increased by 50
    glVertex2i(590, 400); // Increased by 50
    glVertex2i(620, 400); // Increased by 50
    glVertex2i(620, 420); // Increased by 50

    glVertex2i(590, 380); // Increased by 50
    glVertex2i(590, 360); // Increased by 50
    glVertex2i(620, 360); // Increased by 50
    glVertex2i(620, 380); // Increased by 50

    glVertex2i(590, 340); // Increased by 50
    glVertex2i(590, 320); // Increased by 50
    glVertex2i(620, 320); // Increased by 50
    glVertex2i(620, 340); // Increased by 50
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(530, 515);
    glVertex2i(630, 515);
    glVertex2i(630, 520);
    glVertex2i(530, 520);
    glEnd();
//building -- end -- =========================================================

    //building -- start -- ==================================================================
    glColor3f(0.82f, 0.71f, 0.55f); // tan
    glBegin(GL_QUADS);
    glVertex2i(580, 520);
    glVertex2i(580, 300);
    glVertex2i(680, 300);
    glVertex2i(680, 520);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // black
    glBegin(GL_LINES);
    glVertex2i(580, 520);
    glVertex2i(580, 300);
    glVertex2i(680, 300);
    glVertex2i(680, 520);
    glEnd();

    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);   // white color
    glBegin(GL_QUADS);
    glVertex2i(590, 500);
    glVertex2i(590, 480);
    glVertex2i(620, 480);
    glVertex2i(620, 500);

    glVertex2i(590, 460);
    glVertex2i(590, 440);
    glVertex2i(620, 440);
    glVertex2i(620, 460);

    glVertex2i(590, 420);
    glVertex2i(590, 400);
    glVertex2i(620, 400);
    glVertex2i(620, 420);

    glVertex2i(590, 380);
    glVertex2i(590, 360);
    glVertex2i(620, 360);
    glVertex2i(620, 380);

    glVertex2i(590, 340);
    glVertex2i(590, 320);
    glVertex2i(620, 320);
    glVertex2i(620, 340);
    glEnd();

    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);   // black color
    glBegin(GL_LINES);
    glVertex2i(590, 500);
    glVertex2i(590, 480);
    glVertex2i(620, 480);
    glVertex2i(620, 500);

    glVertex2i(590, 460);
    glVertex2i(590, 440);
    glVertex2i(620, 440);
    glVertex2i(620, 460);

    glVertex2i(590, 420);
    glVertex2i(590, 400);
    glVertex2i(620, 400);
    glVertex2i(620, 420);

    glVertex2i(590, 380);
    glVertex2i(590, 360);
    glVertex2i(620, 360);
    glVertex2i(620, 380);

    glVertex2i(590, 340);
    glVertex2i(590, 320);
    glVertex2i(620, 320);
    glVertex2i(620, 340);
    glEnd();

    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);   // white color
    glBegin(GL_QUADS);
    glVertex2i(640, 500); // Increased by 50
    glVertex2i(640, 480); // Increased by 50
    glVertex2i(670, 480); // Increased by 50
    glVertex2i(670, 500); // Increased by 50

    glVertex2i(640, 460); // Increased by 50
    glVertex2i(640, 440); // Increased by 50
    glVertex2i(670, 440); // Increased by 50
    glVertex2i(670, 460); // Increased by 50

    glVertex2i(640, 420); // Increased by 50
    glVertex2i(640, 400); // Increased by 50
    glVertex2i(670, 400); // Increased by 50
    glVertex2i(670, 420); // Increased by 50

    glVertex2i(640, 380); // Increased by 50
    glVertex2i(640, 360); // Increased by 50
    glVertex2i(670, 360); // Increased by 50
    glVertex2i(670, 380); // Increased by 50

    glVertex2i(640, 340); // Increased by 50
    glVertex2i(640, 320); // Increased by 50
    glVertex2i(670, 320); // Increased by 50
    glVertex2i(670, 340); // Increased by 50
    glEnd();

    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);   // black color
    glBegin(GL_LINES);
    glVertex2i(640, 500); // Increased by 50
    glVertex2i(640, 480); // Increased by 50
    glVertex2i(670, 480); // Increased by 50
    glVertex2i(670, 500); // Increased by 50

    glVertex2i(640, 460); // Increased by 50
    glVertex2i(640, 440); // Increased by 50
    glVertex2i(670, 440); // Increased by 50
    glVertex2i(670, 460); // Increased by 50

    glVertex2i(640, 420); // Increased by 50
    glVertex2i(640, 400); // Increased by 50
    glVertex2i(670, 400); // Increased by 50
    glVertex2i(670, 420); // Increased by 50

    glVertex2i(640, 380); // Increased by 50
    glVertex2i(640, 360); // Increased by 50
    glVertex2i(670, 360); // Increased by 50
    glVertex2i(670, 380); // Increased by 50

    glVertex2i(640, 340); // Increased by 50
    glVertex2i(640, 320); // Increased by 50
    glVertex2i(670, 320); // Increased by 50
    glVertex2i(670, 340); // Increased by 50
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(580, 520);
    glVertex2i(680, 520);
    glVertex2i(680, 525);
    glVertex2i(580, 525);
    glEnd();
    //building -- end -- =========================================================



    //building -- start -- ==================================================================
    glColor3f(0.5f, 0.5f, 0.5f); // tan
    glBegin(GL_QUADS);
    glVertex2i(380, 520);
    glVertex2i(380, 300);
    glVertex2i(480, 300);
    glVertex2i(480, 520);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // black
    glBegin(GL_LINES);
    glVertex2i(380, 520);
    glVertex2i(380, 300);
    glVertex2i(480, 300);
    glVertex2i(480, 520);
    glEnd();

    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);   // white color
    glBegin(GL_QUADS);
    glVertex2i(390, 500);
    glVertex2i(390, 480);
    glVertex2i(420, 480);
    glVertex2i(420, 500);

    glVertex2i(390, 460);
    glVertex2i(390, 440);
    glVertex2i(420, 440);
    glVertex2i(420, 460);

    glVertex2i(390, 420);
    glVertex2i(390, 400);
    glVertex2i(420, 400);
    glVertex2i(420, 420);

    glVertex2i(390, 380);
    glVertex2i(390, 360);
    glVertex2i(420, 360);
    glVertex2i(420, 380);

    glVertex2i(390, 340);
    glVertex2i(390, 320);
    glVertex2i(420, 320);
    glVertex2i(420, 340);
    glEnd();

    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);   // black color
    glBegin(GL_LINES);
    glVertex2i(390, 500);
    glVertex2i(390, 480);
    glVertex2i(420, 480);
    glVertex2i(420, 500);

    glVertex2i(390, 460);
    glVertex2i(390, 440);
    glVertex2i(420, 440);
    glVertex2i(420, 460);

    glVertex2i(390, 420);
    glVertex2i(390, 400);
    glVertex2i(420, 400);
    glVertex2i(420, 420);

    glVertex2i(390, 380);
    glVertex2i(390, 360);
    glVertex2i(420, 360);
    glVertex2i(420, 380);

    glVertex2i(390, 340);
    glVertex2i(390, 320);
    glVertex2i(420, 320);
    glVertex2i(420, 340);
    glEnd();

    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);   // white color
    glBegin(GL_QUADS);
    glVertex2i(440, 500); // Increased by 50
    glVertex2i(440, 480); // Increased by 50
    glVertex2i(470, 480); // Increased by 50
    glVertex2i(470, 500); // Increased by 50

    glVertex2i(440, 460); // Increased by 50
    glVertex2i(440, 440); // Increased by 50
    glVertex2i(470, 440); // Increased by 50
    glVertex2i(470, 460); // Increased by 50

    glVertex2i(440, 420); // Increased by 50
    glVertex2i(440, 400); // Increased by 50
    glVertex2i(470, 400); // Increased by 50
    glVertex2i(470, 420); // Increased by 50

    glVertex2i(440, 380); // Increased by 50
    glVertex2i(440, 360); // Increased by 50
    glVertex2i(470, 360); // Increased by 50
    glVertex2i(470, 380); // Increased by 50

    glVertex2i(440, 340); // Increased by 50
    glVertex2i(440, 320); // Increased by 50
    glVertex2i(470, 320); // Increased by 50
    glVertex2i(470, 340); // Increased by 50
    glEnd();

    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);   // black color
    glBegin(GL_LINES);
    glVertex2i(440, 500); // Increased by 50
    glVertex2i(440, 480); // Increased by 50
    glVertex2i(470, 480); // Increased by 50
    glVertex2i(470, 500); // Increased by 50

    glVertex2i(440, 460); // Increased by 50
    glVertex2i(440, 440); // Increased by 50
    glVertex2i(470, 440); // Increased by 50
    glVertex2i(470, 460); // Increased by 50

    glVertex2i(440, 420); // Increased by 50
    glVertex2i(440, 400); // Increased by 50
    glVertex2i(470, 400); // Increased by 50
    glVertex2i(470, 420); // Increased by 50

    glVertex2i(440, 380); // Increased by 50
    glVertex2i(440, 360); // Increased by 50
    glVertex2i(470, 360); // Increased by 50
    glVertex2i(470, 380); // Increased by 50

    glVertex2i(440, 340); // Increased by 50
    glVertex2i(440, 320); // Increased by 50
    glVertex2i(470, 320); // Increased by 50
    glVertex2i(470, 340); // Increased by 50
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(380, 520);
    glVertex2i(480, 520);
    glVertex2i(480, 525);
    glVertex2i(380, 525);
    glEnd();
//building -- end -- =========================================================





    //building -- start ==========================================================
    glColor3f(0.0f, 0.5f, 0.25f); // green paint
    glBegin(GL_QUADS);
    glVertex2i(460, 630); // Decreased by 120
    glVertex2i(460, 300); // Decreased by 120
    glVertex2i(560, 300); // Decreased by 120
    glVertex2i(560, 630); // Decreased by 120
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // black
    glBegin(GL_LINES);
    glVertex2i(460, 630); // Decreased by 120
    glVertex2i(460, 300); // Decreased by 120
    glVertex2i(560, 300); // Decreased by 120
    glVertex2i(560, 630); // Decreased by 120
    glEnd();

    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);   // white color
    glBegin(GL_QUADS);
    glVertex2i(470, 620); // Decreased by 120
    glVertex2i(470, 600); // Decreased by 120
    glVertex2i(500, 600); // Decreased by 120
    glVertex2i(500, 620); // Decreased by 120

    glVertex2i(470, 580); // Decreased by 120
    glVertex2i(470, 560); // Decreased by 120
    glVertex2i(500, 560); // Decreased by 120
    glVertex2i(500, 580); // Decreased by 120

    glVertex2i(470, 540); // Decreased by 120
    glVertex2i(470, 520); // Decreased by 120
    glVertex2i(500, 520); // Decreased by 120
    glVertex2i(500, 540); // Decreased by 120

    glVertex2i(470, 500); // Decreased by 120
    glVertex2i(470, 480); // Decreased by 120
    glVertex2i(500, 480); // Decreased by 120
    glVertex2i(500, 500); // Decreased by 120

    glVertex2i(470, 460); // Decreased by 120
    glVertex2i(470, 440); // Decreased by 120
    glVertex2i(500, 440); // Decreased by 120
    glVertex2i(500, 460); // Decreased by 120

    glVertex2i(470, 420); // Decreased by 120
    glVertex2i(470, 400); // Decreased by 120
    glVertex2i(500, 400); // Decreased by 120
    glVertex2i(500, 420); // Decreased by 120

    glVertex2i(470, 380); // Decreased by 120
    glVertex2i(470, 360); // Decreased by 120
    glVertex2i(500, 360); // Decreased by 120
    glVertex2i(500, 380); // Decreased by 120

    glVertex2i(470, 340); // Decreased by 120
    glVertex2i(470, 320); // Decreased by 120
    glVertex2i(500, 320); // Decreased by 120
    glVertex2i(500, 340); // Decreased by 120
    glEnd();

    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);   // black color
    glBegin(GL_LINES);
    glVertex2i(470, 620); // Decreased by 120
    glVertex2i(470, 600); // Decreased by 120
    glVertex2i(500, 600); // Decreased by 120
    glVertex2i(500, 620); // Decreased by 120

    glVertex2i(470, 580); // Decreased by 120
    glVertex2i(470, 560); // Decreased by 120
    glVertex2i(500, 560); // Decreased by 120
    glVertex2i(500, 580); // Decreased by 120

    glVertex2i(470, 540); // Decreased by 120
    glVertex2i(470, 520); // Decreased by 120
    glVertex2i(500, 520); // Decreased by 120
    glVertex2i(500, 540); // Decreased by 120

    glVertex2i(470, 500); // Decreased by 120
    glVertex2i(470, 480); // Decreased by 120
    glVertex2i(500, 480); // Decreased by 120
    glVertex2i(500, 500); // Decreased by 120

    glVertex2i(470, 460); // Decreased by 120
    glVertex2i(470, 440); // Decreased by 120
    glVertex2i(500, 440); // Decreased by 120
    glVertex2i(500, 460); // Decreased by 120

    glVertex2i(470, 420); // Decreased by 120
    glVertex2i(470, 400); // Decreased by 120
    glVertex2i(500, 400); // Decreased by 120
    glVertex2i(500, 420); // Decreased by 120

    glVertex2i(470, 380); // Decreased by 120
    glVertex2i(470, 360); // Decreased by 120
    glVertex2i(500, 360); // Decreased by 120
    glVertex2i(500, 380); // Decreased by 120

    glVertex2i(470, 340); // Decreased by 120
    glVertex2i(470, 320); // Decreased by 120
    glVertex2i(500, 320); // Decreased by 120
    glVertex2i(500, 340); // Decreased by 120
    glEnd();

    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);   // white color
    glBegin(GL_QUADS);
    glVertex2i(520, 620); // Decreased by 120
    glVertex2i(520, 600); // Decreased by 120
    glVertex2i(550, 600); // Decreased by 120
    glVertex2i(550, 620); // Decreased by 120

    glVertex2i(520, 580); // Decreased by 120
    glVertex2i(520, 560); // Decreased by 120
    glVertex2i(550, 560); // Decreased by 120
    glVertex2i(550, 580); // Decreased by 120

    glVertex2i(520, 540); // Decreased by 120
    glVertex2i(520, 520); // Decreased by 120
    glVertex2i(550, 520); // Decreased by 120
    glVertex2i(550, 540); // Decreased by 120

    glVertex2i(520, 500); // Decreased by 120
    glVertex2i(520, 480); // Decreased by 120
    glVertex2i(550, 480); // Decreased by 120
    glVertex2i(550, 500); // Decreased by 120

    glVertex2i(520, 460); // Decreased by 120
    glVertex2i(520, 440); // Decreased by 120
    glVertex2i(550, 440); // Decreased by 120
    glVertex2i(550, 460); // Decreased by 120

    glVertex2i(520, 420); // Decreased by 120
    glVertex2i(520, 400); // Decreased by 120
    glVertex2i(550, 400); // Decreased by 120
    glVertex2i(550, 420); // Decreased by 120

    glVertex2i(520, 380); // Decreased by 120
    glVertex2i(520, 360); // Decreased by 120
    glVertex2i(550, 360); // Decreased by 120
    glVertex2i(550, 380); // Decreased by 120

    glVertex2i(520, 340); // Decreased by 120
    glVertex2i(520, 320); // Decreased by 120
    glVertex2i(550, 320); // Decreased by 120
    glVertex2i(550, 340); // Decreased by 120
    glEnd();

    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);   // black color
    glBegin(GL_LINES);
    glVertex2i(520, 620); // Decreased by 120
    glVertex2i(520, 600); // Decreased by 120
    glVertex2i(550, 600); // Decreased by 120
    glVertex2i(550, 620); // Decreased by 120

    glVertex2i(520, 580); // Decreased by 120
    glVertex2i(520, 560); // Decreased by 120
    glVertex2i(550, 560); // Decreased by 120
    glVertex2i(550, 580); // Decreased by 120

    glVertex2i(520, 540); // Decreased by 120
    glVertex2i(520, 520); // Decreased by 120
    glVertex2i(550, 520); // Decreased by 120
    glVertex2i(550, 540); // Decreased by 120

    glVertex2i(520, 500); // Decreased by 120
    glVertex2i(520, 480); // Decreased by 120
    glVertex2i(550, 480); // Decreased by 120
    glVertex2i(550, 500); // Decreased by 120

    glVertex2i(520, 460); // Decreased by 120
    glVertex2i(520, 440); // Decreased by 120
    glVertex2i(550, 440); // Decreased by 120
    glVertex2i(550, 460); // Decreased by 120

    glVertex2i(520, 420); // Decreased by 120
    glVertex2i(520, 400); // Decreased by 120
    glVertex2i(550, 400); // Decreased by 120
    glVertex2i(550, 420); // Decreased by 120

    glVertex2i(520, 380); // Decreased by 120
    glVertex2i(520, 360); // Decreased by 120
    glVertex2i(550, 360); // Decreased by 120
    glVertex2i(550, 380); // Decreased by 120

    glVertex2i(520, 340); // Decreased by 120
    glVertex2i(520, 320); // Decreased by 120
    glVertex2i(550, 320); // Decreased by 120
    glVertex2i(550, 340); // Decreased by 120
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);     // black color
    glBegin(GL_TRIANGLES);
    glVertex2i(440, 630);
    glVertex2i(578, 630);
    glVertex2i(510, 730);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);     // black color
    glBegin(GL_QUADS);
    glVertex2i(440, 625);
    glVertex2i(578, 625);
    glVertex2i(578, 630);
    glVertex2i(440, 630);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);     // white color
    glBegin(GL_LINE_STRIP);
    glVertex2i(440, 630);
    glVertex2i(578, 630);
    glVertex2i(510, 730);
    glVertex2i(440, 630);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);     // white color
    glBegin(GL_LINE_STRIP);
    glVertex2i(440, 625);
    glVertex2i(578, 625);
    glVertex2i(578, 630);
    glVertex2i(440, 630);
    glEnd();
    //building -- end ============================================================


    //building -- start ==========================================================
    glColor3f(0.8f, 0.0f, 0.0f);     // red color
    glBegin(GL_QUADS);
    glVertex2i(320, 300);
    glVertex2i(435, 300);
    glVertex2i(435, 450);
    glVertex2i(320, 450);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);     // black color
    glBegin(GL_QUADS);
    glVertex2i(310, 450);
    glVertex2i(445, 450);
    glVertex2i(435, 460);
    glVertex2i(320, 460);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);     // white color
    glBegin(GL_QUADS);
    glVertex2i(335, 435);
    glVertex2i(335, 410);
    glVertex2i(360, 410);
    glVertex2i(360, 435);

    glVertex2i(335, 400);
    glVertex2i(335, 375);
    glVertex2i(360, 375);
    glVertex2i(360, 400);

    glVertex2i(335, 365);
    glVertex2i(335, 340);
    glVertex2i(360, 340);
    glVertex2i(360, 365);

    glVertex2i(335, 330);
    glVertex2i(335, 310);
    glVertex2i(360, 310);
    glVertex2i(360, 330);

    glVertex2i(395, 435);
    glVertex2i(395, 410);
    glVertex2i(420, 410);
    glVertex2i(420, 435);

    glVertex2i(395, 400);
    glVertex2i(395, 375);
    glVertex2i(420, 375);
    glVertex2i(420, 400);

    glVertex2i(395, 365);
    glVertex2i(395, 340);
    glVertex2i(420, 340);
    glVertex2i(420, 365);

    glVertex2i(395, 330);
    glVertex2i(395, 310);
    glVertex2i(420, 310);
    glVertex2i(420, 330);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);     // black color
    glBegin(GL_LINES);
    glVertex2i(320, 300);
    glVertex2i(435, 300);
    glVertex2i(435, 450);
    glVertex2i(320, 450);

    glVertex2i(310, 450);
    glVertex2i(445, 450);
    glVertex2i(435, 460);
    glVertex2i(320, 460);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);     // white color
    glBegin(GL_LINES);
    glVertex2i(335, 435);
    glVertex2i(335, 410);
    glVertex2i(360, 410);
    glVertex2i(360, 435);

    glVertex2i(335, 400);
    glVertex2i(335, 375);
    glVertex2i(360, 375);
    glVertex2i(360, 400);

    glVertex2i(335, 365);
    glVertex2i(335, 340);
    glVertex2i(360, 340);
    glVertex2i(360, 365);

    glVertex2i(335, 330);
    glVertex2i(335, 310);
    glVertex2i(360, 310);
    glVertex2i(360, 330);

    glVertex2i(395, 435);
    glVertex2i(395, 410);
    glVertex2i(420, 410);
    glVertex2i(420, 435);

    glVertex2i(395, 400);
    glVertex2i(395, 375);
    glVertex2i(420, 375);
    glVertex2i(420, 400);

    glVertex2i(395, 365);
    glVertex2i(395, 340);
    glVertex2i(420, 340);
    glVertex2i(420, 365);

    glVertex2i(395, 330);
    glVertex2i(395, 310);
    glVertex2i(420, 310);
    glVertex2i(420, 330);
    glEnd();
    //building -- end ============================================================

    //factory -- start ===========================================================
    glColor3f(0.4f, 0.4f, 0.4f); // Dark ash color
    glBegin(GL_QUADS);                //body
    glVertex2i(205, 300);
    glVertex2i(300, 300);
    glVertex2i(300, 440);
    glVertex2i(205, 490);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);     //white color
    glBegin(GL_QUADS);                   // rooftop
    glVertex2i(205, 490);
    glVertex2i(300, 440);
    glVertex2i(300, 430);
    glVertex2i(205, 480);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);         //body and rooftop lines
    glVertex2i(205, 300);
    glVertex2i(300, 300);
    glVertex2i(300, 440);
    glVertex2i(205, 490);

    glVertex2i(205, 490);
    glVertex2i(300, 440);
    glVertex2i(300, 430);
    glVertex2i(205, 480);
    glEnd();

    glColor3f(0.4f, 0.4f, 0.4f); // Dark ash color
    glBegin(GL_QUAD_STRIP);                //cloud pipe
    glVertex2i(266.63, 457.56);
    glVertex2i(294.59, 442.85);
    glVertex2i(267.9699779082307, 487.6119314027288);
    glVertex2i(293.8975533554554, 488.2692502168837);
    glVertex2i(271.9869262169556, 512.9187057476928);
    glVertex2i(290.2457821657054, 513.2473651547703);
    glVertex2i(273.4128118118305, 531.6522919511078);
    glVertex2i(289.1806050467303, 531.4809513581852);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);    //pipe head
    glBegin(GL_QUADS);
    glVertex2i(273.4128118118305, 531.6522919511078);
    glVertex2i(289.1806050467303, 531.4809513581852);
    glVertex2i(289.1806050467303, 536.4809513581852);
    glVertex2i(273.4128118118305, 536.6522919511078);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);         //cloud pipe and head lines
    glVertex2i(266.63, 457.56);
    glVertex2i(267.9699779082307, 487.6119314027288);
    glVertex2i(271.9869262169556, 512.9187057476928);
    glVertex2i(273.4128118118305, 531.6522919511078);
    glVertex2i(289.1806050467303, 531.4809513581852);
    glVertex2i(290.2457821657054, 513.2473651547703);
    glVertex2i(293.8975533554554, 488.2692502168837);
    glVertex2i(294.59, 442.85);

    glVertex2i(273.4128118118305, 531.6522919511078);
    glVertex2i(289.1806050467303, 531.4809513581852);
    glVertex2i(289.1806050467303, 536.4809513581852);
    glVertex2i(273.4128118118305, 536.6522919511078);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);                               //danger sign black
    glVertex2i(252.9667051673276, 418.0418142299319);
    glVertex2i(262.3042493359834, 431.5285965785966);
    glVertex2i(243.8021657261577, 431.5285965785966);

    glVertex2i(252.9667051673276, 418.0418142299319);
    glVertex2i(261.8086578107202, 404.1719443840718);
    glVertex2i(270.2337137401944, 416.8095282782816);

    glVertex2i(252.9667051673276, 418.0418142299319);
    glVertex2i(243.3065742008945, 404.1719443840717);
    glVertex2i(235.0467154465081, 417.2555606510184);
    glEnd();

    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);                               //danger sign yellow
    glVertex2i(252.9667051673276, 418.0418142299319);
    glVertex2i(262.3042493359834, 431.5285965785966);
    glVertex2i(270.2337137401944, 416.8095282782816);

    glVertex2i(252.9667051673276, 418.0418142299319);
    glVertex2i(243.3065742008945, 404.1719443840717);
    glVertex2i(261.8086578107202, 404.1719443840718);

    glVertex2i(252.9667051673276, 418.0418142299319);
    glVertex2i(243.8021657261577, 431.5285965785966);
    glVertex2i(235.0467154465081, 417.2555606510184);
    glEnd();

    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);          //factory door
    glBegin(GL_QUADS);
    glVertex2i(228, 300);
    glVertex2i(272, 300);
    glVertex2i(272.5221929529424, 347.7860439592682);
    glVertex2i(228.6328725374823, 347.7860439592682);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);    //factory door top
    glBegin(GL_QUADS);
    glVertex2i(228.4990572094937, 352.1903819111639);
    glVertex2i(272.7556467849395, 352.1903819111639);
    glVertex2i(272.7556467849395, 359.4903819111646);
    glVertex2i(228.4990572094937, 359.4903819111646);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);    //factory door and top lines
    glBegin(GL_LINES);
    glVertex2i(228, 300);
    glVertex2i(272, 300);
    glVertex2i(272.5221929529424, 347.7860439592682);
    glVertex2i(228.6328725374823, 347.7860439592682);

    glVertex2i(228.4990572094937, 352.1903819111639);
    glVertex2i(272.7556467849395, 352.1903819111639);
    glVertex2i(272.7556467849395, 359.4903819111646);
    glVertex2i(228.4990572094937, 359.4903819111646);
    glEnd();
    //factory -- end =============================================================

    glColor3f(0.4f, 0.4f, 0.4f); // Dark ash color
    glBegin(GL_QUADS);                //body
    glVertex2i(105, 300);
    glVertex2i(200, 300);
    glVertex2i(200, 440);
    glVertex2i(105, 490);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);     //white color
    glBegin(GL_QUADS);                   // rooftop
    glVertex2i(105, 490);
    glVertex2i(200, 440);
    glVertex2i(200, 430);
    glVertex2i(105, 480);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);         //body and rooftop lines
    glVertex2i(105, 300);
    glVertex2i(200, 300);
    glVertex2i(200, 440);
    glVertex2i(105, 490);

    glVertex2i(105, 490);
    glVertex2i(200, 440);
    glVertex2i(200, 430);
    glVertex2i(105, 480);
    glEnd();

    glColor3f(0.4f, 0.4f, 0.4f); // Dark ash color
    glBegin(GL_QUAD_STRIP);                //cloud pipe
    glVertex2i(166.63, 457.56);
    glVertex2i(194.59, 442.85);
    glVertex2i(167.9699779082307, 487.6119314027288);
    glVertex2i(193.8975533554554, 488.2692502168837);
    glVertex2i(171.9869262169556, 512.9187057476928);
    glVertex2i(190.2457821657054, 513.2473651547703);
    glVertex2i(173.4128118118305, 531.6522919511078);
    glVertex2i(189.1806050467303, 531.4809513581852);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);    //pipe head
    glBegin(GL_QUADS);
    glVertex2i(173.4128118118305, 531.6522919511078);
    glVertex2i(189.1806050467303, 531.4809513581852);
    glVertex2i(189.1806050467303, 536.4809513581852);
    glVertex2i(173.4128118118305, 536.6522919511078);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);         //cloud pipe and head lines
    glVertex2i(166.63, 457.56);
    glVertex2i(167.9699779082307, 487.6119314027288);
    glVertex2i(171.9869262169556, 512.9187057476928);
    glVertex2i(173.4128118118305, 531.6522919511078);
    glVertex2i(189.1806050467303, 531.4809513581852);
    glVertex2i(190.2457821657054, 513.2473651547703);
    glVertex2i(193.8975533554554, 488.2692502168837);
    glVertex2i(194.59, 442.85);

    glVertex2i(173.4128118118305, 531.6522919511078);
    glVertex2i(189.1806050467303, 531.4809513581852);
    glVertex2i(189.1806050467303, 536.4809513581852);
    glVertex2i(173.4128118118305, 536.6522919511078);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);                               //danger sign black
    glVertex2i(152.9667051673276, 418.0418142299319);
    glVertex2i(162.3042493359834, 431.5285965785966);
    glVertex2i(143.8021657261577, 431.5285965785966);

    glVertex2i(152.9667051673276, 418.0418142299319);
    glVertex2i(161.8086578107202, 404.1719443840718);
    glVertex2i(170.2337137401944, 416.8095282782816);

    glVertex2i(152.9667051673276, 418.0418142299319);
    glVertex2i(143.3065742008945, 404.1719443840717);
    glVertex2i(135.0467154465081, 417.2555606510184);
    glEnd();

    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);                               //danger sign yellow
    glVertex2i(152.9667051673276, 418.0418142299319);
    glVertex2i(162.3042493359834, 431.5285965785966);
    glVertex2i(170.2337137401944, 416.8095282782816);

    glVertex2i(152.9667051673276, 418.0418142299319);
    glVertex2i(143.3065742008945, 404.1719443840717);
    glVertex2i(161.8086578107202, 404.1719443840718);

    glVertex2i(152.9667051673276, 418.0418142299319);
    glVertex2i(143.8021657261577, 431.5285965785966);
    glVertex2i(135.0467154465081, 417.2555606510184);
    glEnd();

    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);          //factory door
    glBegin(GL_QUADS);
    glVertex2i(128, 300);
    glVertex2i(172, 300);
    glVertex2i(172.5221929529424, 347.7860439592682);
    glVertex2i(128.6328725374823, 347.7860439592682);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);    //factory door top
    glBegin(GL_QUADS);
    glVertex2i(128.4990572094937, 352.1903819111639);
    glVertex2i(172.7556467849395, 352.1903819111639);
    glVertex2i(172.7556467849395, 359.4903819111646);
    glVertex2i(128.4990572094937, 359.4903819111646);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);    //factory door and top lines
    glBegin(GL_LINES);
    glVertex2i(128, 300);
    glVertex2i(172, 300);
    glVertex2i(172.5221929529424, 347.7860439592682);
    glVertex2i(128.6328725374823, 347.7860439592682);

    glVertex2i(128.4990572094937, 352.1903819111639);
    glVertex2i(172.7556467849395, 352.1903819111639);
    glVertex2i(172.7556467849395, 359.4903819111646);
    glVertex2i(128.4990572094937, 359.4903819111646);
    glEnd();

    // factory end ========================================================================

    glColor3f(0.4f, 0.4f, 0.4f); // Dark ash color
    glBegin(GL_QUADS);                //body
    glVertex2i(5, 300);
    glVertex2i(100, 300);
    glVertex2i(100, 440);
    glVertex2i(5, 490);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);     //white color
    glBegin(GL_QUADS);                   // rooftop
    glVertex2i(5, 490);
    glVertex2i(100, 440);
    glVertex2i(100, 430);
    glVertex2i(5, 480);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);         //body and rooftop lines
    glVertex2i(5, 300);
    glVertex2i(100, 300);
    glVertex2i(100, 440);
    glVertex2i(5, 490);

    glVertex2i(5, 490);
    glVertex2i(100, 440);
    glVertex2i(100, 430);
    glVertex2i(5, 480);
    glEnd();

    glColor3f(0.4f, 0.4f, 0.4f); // Dark ash color
    glBegin(GL_QUAD_STRIP);                //cloud pipe
    glVertex2i(66.63, 457.56);
    glVertex2i(94.59, 442.85);
    glVertex2i(67.9699779082307, 487.6119314027288);
    glVertex2i(93.8975533554554, 488.2692502168837);
    glVertex2i(71.9869262169556, 512.9187057476928);
    glVertex2i(90.2457821657054, 513.2473651547703);
    glVertex2i(73.4128118118305, 531.6522919511078);
    glVertex2i(89.1806050467303, 531.4809513581852);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);    //pipe head
    glBegin(GL_QUADS);
    glVertex2i(73.4128118118305, 531.6522919511078);
    glVertex2i(89.1806050467303, 531.4809513581852);
    glVertex2i(89.1806050467303, 536.4809513581852);
    glVertex2i(73.4128118118305, 536.6522919511078);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);         //cloud pipe and head lines
    glVertex2i(66.63, 457.56);
    glVertex2i(67.9699779082307, 487.6119314027288);
    glVertex2i(71.9869262169556, 512.9187057476928);
    glVertex2i(73.4128118118305, 531.6522919511078);
    glVertex2i(89.1806050467303, 531.4809513581852);
    glVertex2i(90.2457821657054, 513.2473651547703);
    glVertex2i(93.8975533554554, 488.2692502168837);
    glVertex2i(94.59, 442.85);

    glVertex2i(73.4128118118305, 531.6522919511078);
    glVertex2i(89.1806050467303, 531.4809513581852);
    glVertex2i(89.1806050467303, 536.4809513581852);
    glVertex2i(73.4128118118305, 536.6522919511078);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);                               //danger sign black
    glVertex2i(52.9667051673276, 418.0418142299319);
    glVertex2i(62.3042493359834, 431.5285965785966);
    glVertex2i(43.8021657261577, 431.5285965785966);

    glVertex2i(52.9667051673276, 418.0418142299319);
    glVertex2i(61.8086578107202, 404.1719443840718);
    glVertex2i(70.2337137401944, 416.8095282782816);

    glVertex2i(52.9667051673276, 418.0418142299319);
    glVertex2i(43.3065742008945, 404.1719443840717);
    glVertex2i(35.0467154465081, 417.2555606510184);
    glEnd();

    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);                               //danger sign yellow
    glVertex2i(52.9667051673276, 418.0418142299319);
    glVertex2i(62.3042493359834, 431.5285965785966);
    glVertex2i(70.2337137401944, 416.8095282782816);

    glVertex2i(52.9667051673276, 418.0418142299319);
    glVertex2i(43.3065742008945, 404.1719443840717);
    glVertex2i(61.8086578107202, 404.1719443840718);

    glVertex2i(52.9667051673276, 418.0418142299319);
    glVertex2i(43.8021657261577, 431.5285965785966);
    glVertex2i(35.0467154465081, 417.2555606510184);
    glEnd();

    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);          //factory door
    glBegin(GL_QUADS);
    glVertex2i(28, 300);
    glVertex2i(72, 300);
    glVertex2i(72.5221929529424, 347.7860439592682);
    glVertex2i(28.6328725374823, 347.7860439592682);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);    //factory door top
    glBegin(GL_QUADS);
    glVertex2i(28.4990572094937, 352.1903819111639);
    glVertex2i(72.7556467849395, 352.1903819111639);
    glVertex2i(72.7556467849395, 359.4903819111646);
    glVertex2i(28.4990572094937, 359.4903819111646);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);    //factory door and top lines
    glBegin(GL_LINES);
    glVertex2i(28, 300);
    glVertex2i(72, 300);
    glVertex2i(72.5221929529424, 347.7860439592682);
    glVertex2i(28.6328725374823, 347.7860439592682);

    glVertex2i(28.4990572094937, 352.1903819111639);
    glVertex2i(72.7556467849395, 352.1903819111639);
    glVertex2i(72.7556467849395, 359.4903819111646);
    glVertex2i(28.4990572094937, 359.4903819111646);
    glEnd();




    // Bangladesh flag -- start ===========================================================================================
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);                       //flag stand
    glVertex2i(811, 294);
    glVertex2i(855, 294);
    glVertex2i(855, 302.5);
    glVertex2i(811, 302.5);

    glVertex2i(818, 302.5);
    glVertex2i(848, 302.5);
    glVertex2i(848, 309);
    glVertex2i(818, 309);

    glVertex2i(823, 309);
    glVertex2i(843, 309);
    glVertex2i(843, 314);
    glVertex2i(823, 314);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);                              //flag stand lines
    glVertex2i(811, 294);
    glVertex2i(855, 294);
    glVertex2i(855, 302.5);
    glVertex2i(811, 302.5);

    glVertex2i(818, 302.5);
    glVertex2i(848, 302.5);
    glVertex2i(848, 309);
    glVertex2i(818, 309);

    glVertex2i(823, 309);
    glVertex2i(843, 309);
    glVertex2i(843, 314);
    glVertex2i(823, 314);
    glEnd();

    glColor3f(0.5f, 0.5f, 0.5f); // Gray color for steel stand
    glBegin(GL_QUADS);
    glVertex2i(831.5, 314);
    glVertex2i(836.4, 314);
    glVertex2i(836.4, 419);
    glVertex2i(831.5, 419);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2i(831.5, 314);
    glVertex2i(836.4, 314);
    glVertex2i(836.4, 419);
    glVertex2i(831.5, 419);
    glEnd();

    glColor3f(0.0f, 1.0f, 0.0f); // Green color for flag
    glBegin(GL_QUADS);
    glVertex2i(836, 414);
    glVertex2i(836, 388);
    glVertex2i(876, 388);
    glVertex2i(876, 414);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2i(836, 414);
    glVertex2i(836, 388);
    glVertex2i(876, 388);
    glVertex2i(876, 414);
    glEnd();

    drawRedCircleWborder(856, 401, 5, 0.1);
    //Bangladesh flag -- End ===========================================================================================

    // Palestine flag -- start ===========================================================================================
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);                       //flag stand
    glVertex2i(881, 294);
    glVertex2i(925, 294);
    glVertex2i(925, 302.5);
    glVertex2i(881, 302.5);

    glVertex2i(888, 302.5);
    glVertex2i(918, 302.5);
    glVertex2i(918, 309);
    glVertex2i(888, 309);

    glVertex2i(893, 309);
    glVertex2i(913, 309);
    glVertex2i(913, 314);
    glVertex2i(893, 314);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);                              //flag stand lines
    glVertex2i(881, 294);
    glVertex2i(925, 294);
    glVertex2i(925, 302.5);
    glVertex2i(881, 302.5);

    glVertex2i(888, 302.5);
    glVertex2i(918, 302.5);
    glVertex2i(918, 309);
    glVertex2i(888, 309);

    glVertex2i(893, 309);
    glVertex2i(913, 309);
    glVertex2i(913, 314);
    glVertex2i(893, 314);
    glEnd();

    glColor3f(0.5f, 0.5f, 0.5f); // Gray color for steel stand
    glBegin(GL_QUADS);
    glVertex2i(901.5, 314);
    glVertex2i(906.4, 314);
    glVertex2i(906.4, 419);
    glVertex2i(901.5, 419);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2i(901.5, 314);
    glVertex2i(906.4, 314);
    glVertex2i(906.4, 419);
    glVertex2i(901.5, 419);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // Black color for flag
    glBegin(GL_QUADS);
    glVertex2i(906, 414);
    glVertex2i(906, 406);
    glVertex2i(946, 388);
    glVertex2i(946, 414);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); // white color for flag
    glBegin(GL_QUADS);
    glVertex2i(906, 406);
    glVertex2i(906, 388);
    glVertex2i(946, 388);
    glVertex2i(946, 406);
    glEnd();

    glColor3f(0.0f, 1.0f, 0.0f); // Green color for flag
    glBegin(GL_QUADS);
    glVertex2i(906, 397);
    glVertex2i(906, 388);
    glVertex2i(946, 388);
    glVertex2i(946, 397);
    glEnd();

    glColor4f(1.0f, 0.0f, 0.0f, 0.0f); // Red color for flag
    glBegin(GL_TRIANGLES);
    glVertex2i(926, 401);
    glVertex2i(906, 388);
    glVertex2i(906, 414);
    glEnd();
    //Palestine Flag -- end ====================================================================

    //Small -- tree ============================================================================
    glColor3f(0.55f, 0.35f, 0.10f); // Wood color for small tree
    glBegin(GL_QUAD_STRIP);
    glVertex2i(443.664822871523, 292.2449477023016);
    glVertex2i(450.0700190087021, 292.2047528471575);
    glVertex2i(443.9317060439055, 355.8563894603661);
    glVertex2i(450.0700190087021, 355.8563894603661);
    glVertex2i(443.4312980220944, 362.2547838560964);
    glVertex2i(450.5112247389537, 361.4901517706758);
    glVertex2i(443.7144950907688, 370.5382981148208);
    glVertex2i(450, 370);
    glVertex2i(443.2896994877572, 380.2236378634831);
    glVertex2i(450, 380);

    glVertex2i(443.9317060439055, 355.8563894603661);
    glVertex2i(443.4312980220944, 362.2547838560964);
    glVertex2i(430.987900480976, 355.2378479916416);
    glVertex2i(432.9502731074609, 361.713677659041);
    glVertex2i(419.8677889308947, 361.713677659041);
    glVertex2i(424.9372515493141, 365.8346601746588);

    glVertex2i(450.0700190087021, 355.8563894603661);
    glVertex2i(450.5112247389537, 361.4901517706758);
    glVertex2i(463.367048817977, 355.3850259386279);
    glVertex2i(462.3858625047346, 361.4193217650683);
    glVertex2i(476.7765950989573, 361.2721438180819);
    glVertex2i(471.3800703761237, 365.3931263336997);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(476.7765950989573, 361.2721438180819);
    glVertex2i(471.3800703761237, 365.3931263336997);
    glVertex2i(479.0660298298564, 371.8689560010992);

    glVertex2i(419.8677889308947, 361.713677659041);
    glVertex2i(424.9372515493141, 365.8346601746588);
    glVertex2i(416.4336368345461, 373.487913417949);
    glEnd();

    drawBush(-752, 275);



    //===========================================================================================
    glColor3f(0.55f, 0.35f, 0.10f); // Wood color for small tree
    glBegin(GL_QUAD_STRIP);
    glVertex2i(563.664822871523, 292.2449477023016);
    glVertex2i(570.0700190087021, 292.2047528471575);
    glVertex2i(563.9317060439055, 355.8563894603661);
    glVertex2i(570.0700190087021, 355.8563894603661);
    glVertex2i(563.4312980220944, 362.2547838560964);
    glVertex2i(570.5112247389537, 361.4901517706758);
    glVertex2i(563.7144950907688, 370.5382981148208);
    glVertex2i(570, 370);
    glVertex2i(563.2896994877572, 380.2236378634831);
    glVertex2i(570, 380);

    glVertex2i(563.9317060439055, 355.8563894603661);
    glVertex2i(563.4312980220944, 362.2547838560964);
    glVertex2i(550.987900480976, 355.2378479916416);
    glVertex2i(552.9502731074609, 361.713677659041);
    glVertex2i(539.8677889308947, 361.713677659041);
    glVertex2i(544.9372515493141, 365.8346601746588);

    glVertex2i(570.0700190087021, 355.8563894603661);
    glVertex2i(570.5112247389537, 361.4901517706758);
    glVertex2i(583.367048817977, 355.3850259386279);
    glVertex2i(582.3858625047346, 361.4193217650683);
    glVertex2i(596.7765950989573, 361.2721438180819);
    glVertex2i(591.3800703761237, 365.3931263336997);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(596.7765950989573, 361.2721438180819);
    glVertex2i(591.3800703761237, 365.3931263336997);
    glVertex2i(599.0660298298564, 371.8689560010992);

    glVertex2i(539.8677889308947, 361.713677659041);
    glVertex2i(544.9372515493141, 365.8346601746588);
    glVertex2i(536.4336368345461, 373.487913417949);
    glEnd();

    drawBush(-632, 270);
    //===========================================================================================

    //===========================================================================================
    glColor3f(0.55f, 0.35f, 0.10f); // Wood color for small tree
    glBegin(GL_QUAD_STRIP);
    glVertex2i(683.664822871523, 292.2449477023016);
    glVertex2i(690.0700190087021, 292.2047528471575);
    glVertex2i(683.9317060439055, 355.8563894603661);
    glVertex2i(690.0700190087021, 355.8563894603661);
    glVertex2i(683.4312980220944, 362.2547838560964);
    glVertex2i(690.5112247389537, 361.4901517706758);
    glVertex2i(683.7144950907688, 370.5382981148208);
    glVertex2i(690, 370);
    glVertex2i(683.2896994877572, 380.2236378634831);
    glVertex2i(690, 380);

    glVertex2i(683.9317060439055, 355.8563894603661);
    glVertex2i(683.4312980220944, 362.2547838560964);
    glVertex2i(670.987900480976, 355.2378479916416);
    glVertex2i(672.9502731074609, 361.713677659041);
    glVertex2i(659.8677889308947, 361.713677659041);
    glVertex2i(664.9372515493141, 365.8346601746588);

    glVertex2i(690.0700190087021, 355.8563894603661);
    glVertex2i(690.5112247389537, 361.4901517706758);
    glVertex2i(703.367048817977, 355.3850259386279);
    glVertex2i(702.3858625047346, 361.4193217650683);
    glVertex2i(716.7765950989573, 361.2721438180819);
    glVertex2i(711.3800703761237, 365.3931263336997);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(716.7765950989573, 361.2721438180819);
    glVertex2i(711.3800703761237, 365.3931263336997);
    glVertex2i(719.0660298298564, 371.8689560010992);

    glVertex2i(659.8677889308947, 361.713677659041);
    glVertex2i(664.9372515493141, 365.8346601746588);
    glVertex2i(656.4336368345461, 373.487913417949);
    glEnd();

    drawBush(-512, 270);
    //===========================================================================================

    //===========================================================================================
    glColor3f(0.55f, 0.35f, 0.10f); // Wood color for small tree
    glBegin(GL_QUAD_STRIP);
    glVertex2i(308.664822871523, 292.2449477023016);
    glVertex2i(315.0700190087021, 292.2047528471575);
    glVertex2i(308.9317060439055, 355.8563894603661);
    glVertex2i(315.0700190087021, 355.8563894603661);
    glVertex2i(308.4312980220944, 362.2547838560964);
    glVertex2i(315.5112247389537, 361.4901517706758);
    glVertex2i(308.7144950907688, 370.5382981148208);
    glVertex2i(315, 370);
    glVertex2i(308.2896994877572, 380.2236378634831);
    glVertex2i(315, 380);

    glVertex2i(308.9317060439055, 355.8563894603661);
    glVertex2i(308.4312980220944, 362.2547838560964);
    glVertex2i(295.987900480976, 355.2378479916416);
    glVertex2i(297.9502731074609, 361.713677659041);
    glVertex2i(282.8677889308947, 361.713677659041);
    glVertex2i(287.9372515493141, 365.8346601746588);

    glVertex2i(315.0700190087021, 355.8563894603661);
    glVertex2i(315.5112247389537, 361.4901517706758);
    glVertex2i(328.367048817977, 355.3850259386279);
    glVertex2i(327.3858625047346, 361.4193217650683);
    glVertex2i(341.7765950989573, 361.2721438180819);
    glVertex2i(336.3800703761237, 365.3931263336997);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(341.7765950989573, 361.2721438180819);
    glVertex2i(336.3800703761237, 365.3931263336997);
    glVertex2i(344.0660298298564, 371.8689560010992);

    glVertex2i(282.8677889308947, 361.713677659041);
    glVertex2i(287.9372515493141, 365.8346601746588);
    glVertex2i(279.4336368345461, 373.487913417949);
    glEnd();

    drawBush(-887, 275);
    //===========================================================================================

    //Small -- tree ============================================================================

    // city clouds and sun ============================================================================
    drawSun(200, 835, 70);

    glPushMatrix();
    glTranslatef(bx1, 0, 0);

    drawCloud(-1000, -50);
    drawCloud(-1400, 50);

    glPopMatrix();
    bx1 += 1.0;
    if (bx1 > 300)
        bx1 = -100;
    glutPostRedisplay();
    // city clouds and sun ============================================================================

    //city river ===============================================================================
    glColor3f(0.35f, 0.35f, 0.35f); // Dark gray color
    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(650, 0);
    glVertex2i(650, 175);
    glVertex2i(0, 175);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(650, 175);
    glVertex2i(650, 0);
    glVertex2i(665.293994173004, 174.395425999948);

    glVertex2i(650, 0);
    glVertex2i(665.293994173004, 174.395425999948);
    glVertex2i(676.4328993275798, 165.7374588116197);

    glVertex2i(650, 0);
    glVertex2i(676.4328993275798, 165.7374588116197);
    glVertex2i(683.5212935168553, 155.2567616889066);

    glVertex2i(650, 0);
    glVertex2i(683.5212935168553, 155.2567616889066);
    glVertex2i(688.078118352818, 145.2317470497898);

    glVertex2i(650, 0);
    glVertex2i(688.078118352818, 145.2317470497898);
    glVertex2i(688.5844322234806, 134.7510499270767);

    glVertex2i(650, 0);
    glVertex2i(688.5844322234806, 134.7510499270767);
    glVertex2i(690, 0);
    glEnd();


    glColor3f(0.0f, 0.6f, 0.8f);      // water color
    glBegin(GL_QUADS);
    glVertex2i(-10, -10);
    glVertex2i(640, -10);
    glVertex2i(640, 165);
    glVertex2i(-10, 165);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(640, 165);
    glVertex2i(640, -10);
    glVertex2i(655.293994173004, 164.395425999948);

    glVertex2i(640, -10);
    glVertex2i(655.293994173004, 164.395425999948);
    glVertex2i(666.4328993275798, 155.7374588116197);

    glVertex2i(640, -10);
    glVertex2i(666.4328993275798, 155.7374588116197);
    glVertex2i(673.5212935168553, 145.2567616889066);

    glVertex2i(640, -10);
    glVertex2i(673.5212935168553, 145.2567616889066);
    glVertex2i(678.078118352818, 135.2317470497898);

    glVertex2i(640, -10);
    glVertex2i(678.078118352818, 135.2317470497898);
    glVertex2i(678.5844322234806, 124.7510499270767);

    glVertex2i(640, -10);
    glVertex2i(678.5844322234806, 124.7510499270767);
    glVertex2i(680, -10);
    glEnd();

    //city river ===============================================================================
    //part 1 ===============================================================================
    glColor3f(1.0f, 1.0f, 1.0f);      // white color
    glBegin(GL_QUADS);
    glVertex2i(20, 190);
    glVertex2i(20, 175);
    glVertex2i(25, 175);
    glVertex2i(25, 190);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);      // black color
    glBegin(GL_LINES);
    glVertex2i(20, 190);
    glVertex2i(20, 175);
    glVertex2i(25, 175);
    glVertex2i(25, 190);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);      // white color
    glBegin(GL_QUADS);
    glVertex2i(120, 190);
    glVertex2i(120, 175);
    glVertex2i(125, 175);
    glVertex2i(125, 190);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);      // black color
    glBegin(GL_LINES);
    glVertex2i(120, 190);
    glVertex2i(120, 175);
    glVertex2i(125, 175);
    glVertex2i(125, 190);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); // white color
    glBegin(GL_QUADS);
    glVertex2i(220, 190);
    glVertex2i(220, 175);
    glVertex2i(225, 175);
    glVertex2i(225, 190);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);      // black color
    glBegin(GL_LINES);
    glVertex2i(220, 190);
    glVertex2i(220, 175);
    glVertex2i(225, 175);
    glVertex2i(225, 190);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); // white color
    glBegin(GL_QUADS);
    glVertex2i(320, 190);
    glVertex2i(320, 175);
    glVertex2i(325, 175);
    glVertex2i(325, 190);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);      // black color
    glBegin(GL_LINES);
    glVertex2i(320, 190);
    glVertex2i(320, 175);
    glVertex2i(325, 175);
    glVertex2i(325, 190);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); // white color
    glBegin(GL_QUADS);
    glVertex2i(420, 190);
    glVertex2i(420, 175);
    glVertex2i(425, 175);
    glVertex2i(425, 190);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);      // black color
    glBegin(GL_LINES);
    glVertex2i(420, 190);
    glVertex2i(420, 175);
    glVertex2i(425, 175);
    glVertex2i(425, 190);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); // white color
    glBegin(GL_QUADS);
    glVertex2i(520, 190);
    glVertex2i(520, 175);
    glVertex2i(525, 175);
    glVertex2i(525, 190);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);      // black color
    glBegin(GL_LINES);
    glVertex2i(520, 190);
    glVertex2i(520, 175);
    glVertex2i(525, 175);
    glVertex2i(525, 190);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); // white color
    glBegin(GL_QUADS);
    glVertex2i(620, 190);
    glVertex2i(620, 175);
    glVertex2i(625, 175);
    glVertex2i(625, 190);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);      // black color
    glBegin(GL_LINES);
    glVertex2i(620, 190);
    glVertex2i(620, 175);
    glVertex2i(625, 175);
    glVertex2i(625, 190);
    glEnd();

    //part 1
    glColor3f(1.0f, 1.0f, 1.0f); // white color
    glBegin(GL_QUADS);
    glVertex2i(695, 175);
    glVertex2i(695, 160);
    glVertex2i(700, 160);
    glVertex2i(700, 175);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);      // black color
    glBegin(GL_LINES);
    glVertex2i(695, 175);
    glVertex2i(695, 160);
    glVertex2i(700, 160);
    glVertex2i(700, 175);
    glEnd();

    //part 2
    glColor3f(1.0f, 1.0f, 1.0f); // white color
    glBegin(GL_QUADS);
    glVertex2i(695, 125);
    glVertex2i(695, 105);
    glVertex2i(700, 105);
    glVertex2i(700, 125);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);      // black color
    glBegin(GL_LINES);
    glVertex2i(695, 125);
    glVertex2i(695, 105);
    glVertex2i(700, 105);
    glVertex2i(700, 125);
    glEnd();

    //part 3
    glColor3f(1.0f, 1.0f, 1.0f); // white color
    glBegin(GL_QUADS);
    glVertex2i(695, 80);
    glVertex2i(695, 60);
    glVertex2i(700, 60);
    glVertex2i(700, 80);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);      // black color
    glBegin(GL_LINES);
    glVertex2i(695, 80);
    glVertex2i(695, 60);
    glVertex2i(700, 60);
    glVertex2i(700, 80);
    glEnd();

    //part 4
    glColor3f(1.0f, 1.0f, 1.0f); // white color
    glBegin(GL_QUADS);
    glVertex2i(695, 40);
    glVertex2i(695, 20);
    glVertex2i(700, 20);
    glVertex2i(700, 40);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);      // black color
    glBegin(GL_LINES);
    glVertex2i(695, 40);
    glVertex2i(695, 20);
    glVertex2i(700, 20);
    glVertex2i(700, 40);
    glEnd();

    //part 5
    glColor3f(1.0f, 1.0f, 1.0f); // white color
    glBegin(GL_QUADS);
    glVertex2i(695, 0);
    glVertex2i(695, -20);
    glVertex2i(700, -20);
    glVertex2i(700, 0);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);      // black color
    glBegin(GL_LINES);
    glVertex2i(695, 0);
    glVertex2i(695, -20);
    glVertex2i(700, -20);
    glVertex2i(700, 0);
    glEnd();
    //part 2 ===============================================================================
    //city river stands ===============================================================================

    //city river stands ===============================================================================

    DrawCar(tx);

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2i(1000, 300);
    glVertex2i(1000, 210);
    glVertex2i(1200, 210);
    glVertex2i(1200, 300);
    glEnd();
    // tree ===========================================================================================
    drawTreeLeaves_s(-200, -20);             //cross line tree leaves
    drawTreeLeaves_s(-220, 40);             //cross line tree leaves

    drawTreeLeaves_s(-320, 250);
    drawTreeLeaves_b(-320, 100);
    drawTreeLeaves_b(-250, 80);
    drawTreeLeaves_b(-280, 40);
    drawTreeLeaves_b(-320, 0);
    drawTreeLeaves_b(-420, -50);

    drawTreeLeaves_b(-200, 0);
    drawTreeLeaves_b(-85, -20);
    drawTreeLeaves_b(-140, 160);
    drawTreeLeaves_b(-80, 140);
    drawTreeLeaves_b(0, 100);

    drawTreeLeaves_b(-500, -120);
    drawTreeLeaves_b(-360, -100);
    drawTreeLeaves_b(-400, -50);

    drawTreeLeaves_s(-320, -50);
    drawTreeLeaves_s(-320, 20);
    drawTreeLeaves_s(-320, 100);
    drawTreeLeaves_b(-50, -100);


    //Set colour to wood color
    glColor3f(0.55f, 0.35f, 0.10f);                            //Brown or wood color

    // Draw a filled triangle
    glBegin(GL_QUAD_STRIP);                                    //tree middle part
    glVertex2i(950, 500);
    glVertex2i(1000, 490);
    glVertex2i(960, 455);
    glVertex2i(1000, 450);
    glVertex2i(965, 400);
    glVertex2i(1000, 400);
    glVertex2i(963, 350);
    glVertex2i(1000, 350);
    glVertex2i(960, 280);
    glVertex2i(1000, 280);
    glVertex2i(958, 245);
    glVertex2i(1000, 245);
    glVertex2i(950, 200);
    glVertex2i(1000, 200);


    glVertex2i(1000, 490);
    glVertex2i(1050, 500);
    glVertex2i(1000, 450);
    glVertex2i(1040, 455);
    glVertex2i(1000, 400);
    glVertex2i(1035, 400);
    glVertex2i(1000, 350);
    glVertex2i(1037, 350);
    glVertex2i(1000, 280);
    glVertex2i(1040, 280);
    glVertex2i(1000, 245);
    glVertex2i(1042, 245);
    glVertex2i(1000, 200);
    glVertex2i(1050, 200);
    glEnd();





    glColor3f(0.55f, 0.35f, 0.10f);

    glBegin(GL_QUAD_STRIP);                                    //tree middle part

    glVertex2i(950, 500);
    glVertex2i(963.85, 539.97);
    glVertex2i(912.72, 526.09);
    glVertex2i(935.42, 549.13);
    glVertex2i(878.79, 535.79);
    glVertex2i(909.45, 551.88);
    glVertex2i(878.7863323445118, 535.7892161293773);
    glVertex2i(886.21, 557.80);
    glVertex2i(850.3051188946838, 556.9986304005242);
    glVertex2i(868.4381226318774, 571.4700249512673);
    glVertex2i(838.763, 566.51);
    glVertex2i(848.3901914017788, 585.594703772472);


    glVertex2i(827.8837380937555, 572.7541952876619);
    glVertex2i(833.3542429792057, 587.417242975208);
    glVertex2i(795.7666250545877, 579.4200112014508);
    glVertex2i(811.9394073470548, 592.8848605834163);
    glVertex2i(744.8640308038314, 568.5123124334325);
    glVertex2i(789.1576673128518, 594.2517649854684);
    glVertex2i(768.4973781345398, 576.9960781418912);
    glVertex2i(763.6495120154201, 592.1456597641389);


    glVertex2i(768.4973781345398, 576.9960781418912);
    glVertex2i(763.6495120154201, 592.1456597641389);
    glVertex2i(744.8640308038314, 568.5123124334325);
    glVertex2i(738.1982148900419, 581.8439442610105);
    glEnd();


    glColor3f(0.55f, 0.35f, 0.10f);

    glBegin(GL_TRIANGLES);
    glVertex2i(744.8640308038314, 568.5123124334325);
    glVertex2i(738.1982148900419, 581.8439442610105);
    glVertex2i(716.3828173540035, 557.6046136654141);
    glEnd();


    glColor3f(0.55f, 0.35f, 0.10f);

    glBegin(GL_QUAD_STRIP);
    glVertex2i(768.4973781345398, 576.9960781418912);
    glVertex2i(795.7666250545877, 579.4200112014508);
    glVertex2i(763.6495120154201, 592.1456597641389);
    glVertex2i(789.1576673128518, 594.2517649854684);
    glVertex2i(757.5896793665205, 612.143107505506);
    glVertex2i(776.9811438429991, 609.1131911810564);
    glVertex2i(748.4999303931712, 627.2926891277538);
    glVertex2i(769.1033613994297, 624.8687560681941);
    glVertex2i(744.19, 634.69);
    glVertex2i(760, 640);
    glVertex2i(740.0161646847117, 641.8362874851116);
    glVertex2i(756.2, 649.19);
    glVertex2i(735.17, 652.33);
    glVertex2i(752.58, 657.92);
    glVertex2i(732.7443655060323, 657.5918523722493);
    glVertex2i(749.711896922951, 664.8636515509282);
    glEnd();


    glColor3f(0.55f, 0.35f, 0.10f);

    glBegin(GL_TRIANGLES);
    glVertex2i(732.7443655060323, 657.5918523722493);
    glVertex2i(749.711896922951, 664.8636515509282);
    glVertex2i(727.8964993869126, 679.4072499082861);
    glEnd();

    glColor3f(0.55f, 0.35f, 0.10f);                            //Brown or wood color

    // Draw a filled triangle
    glBegin(GL_QUAD_STRIP);                                    //tree middle part
    glVertex2i(963.8514564469309, 539.9698883763499);
    glVertex2i(1030.1592569586526, 539.580912991536);
    glVertex2i(969.3514534635943, 566.7823738325819);
    glVertex2i(1024.8869482827452, 567.6998925963734);
    glVertex2i(970.0389530906773, 599.094856305477);
    glVertex2i(1028.7533079784107, 598.9822574067558);
    glVertex2i(966.30, 623.55);
    glVertex2i(1029.1047952234712, 621.1259538455658);
    glEnd();


    glColor3f(0.55f, 0.35f, 0.10f);                            //Brown or wood color

    // Draw a filled triangle
    glBegin(GL_QUAD_STRIP);                                    //tree middle part
    glVertex2i(1010.475971235264, 634.130981912806);
    glVertex2i(1029.1047952234712, 621.1259538455658);
    glVertex2i(1023.4809993025027, 643.6211375294389);
    glVertex2i(1038.9464380851655, 634.8339564029245);
    glVertex2i(1037.1890018598624, 659.0865763121);
    glVertex2i(1052.6544406425253, 643.269650284376);
    glVertex2i(1048.788080946859, 666.4678084583701);
    glVertex2i(1063.550545239401, 655.9231911065531);
    glVertex2i(1060, 680);
    glVertex2i(1073.3921881010951, 668.9282191737908);
    glVertex2i(1068.119879425187, 701.616532964418);
    glVertex2i(1080, 680);
    glVertex2i(1088.8726374462892, 704.7026723298401);
    glVertex2i(1088.857626883757, 689.3144793873012);
    glVertex2i(1096.840884886002, 705.8409933926562);
    glVertex2i(1101.8626549509956, 694.5867880632084);
    glVertex2i(1109.3624165769793, 705.0821126841121);
    glVertex2i(1127.9549939363094, 702.80547055848);
    glVertex2i(1143.6896371131959, 692.4778645928454);
    glVertex2i(1144.6503695242793, 703.1849109127521);
    glVertex2i(1148.295052951759, 693.2688473481822);
    glEnd();

    glColor3f(0.55f, 0.35f, 0.10f);                            //Brown or wood color

    // Draw a filled triangle
    glBegin(GL_QUAD_STRIP);
    glVertex2i(1068.119879425187, 701.616532964418);
    glVertex2i(1088.8726374462892, 704.7026723298401);
    glVertex2i(1068.9326374462892, 710.4567232984061);
    glVertex2i(1087.354876029201, 712.2914794152804);
    glVertex2i(1069.9006197326871, 721.0186075635366);
    glVertex2i(1086.2165549663848, 722.1569286263526);
    glVertex2i(1070.5802901406105, 735.0078212451633);
    glVertex2i(1084.6987935492966, 734.299019963057);
    glVertex2i(1070.931777385671, 745.5524385969777);
    glVertex2i(1080.0704457572442, 746.9583875772197);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glVertex2i(963.8514564469309, 539.9698883763499);
    glVertex2i(949, 498);
    glVertex2i(1030.1592569586526, 539.580912991536);
    glVertex2i(1050, 499.8);


    glVertex2i(963.8514564469309, 539.9698883763499);
    glVertex2i(960.02, 455);
    glVertex2i(1030.1592569586526, 539.580912991536);
    glVertex2i(1040, 454.8);
    glEnd();


    glBegin(GL_QUAD_STRIP);
    glVertex2i(1030.1592569586526, 539.580912991536);
    glVertex2i(1050, 499.8);
    glVertex2i(1048.8714708422062, 547.6842100540115);
    glVertex2i(1064.52, 507.3);
    glVertex2i(1063.2964760459367, 550.1929066111818);
    glVertex2i(1078.4, 514.7);
    glVertex2i(1087.7562674783492, 551.4472548897669);
    glVertex2i(1078.3874279579409, 514.4683580999003);
    glVertex2i(1115.351929607225, 559.2869316309242);
    glVertex2i(1122.250845139444, 530.1233341538192);
    glVertex2i(1131.97204429848, 572.7711756257147);
    glVertex2i(1147.3378107111494, 546.11627470578);
    glVertex2i(1149.005164213204, 586.1444402528135);
    glVertex2i(1171.9712065273532, 568.9925858662984);
    glVertex2i(1157.1450273118899, 600.679910071894);
    glVertex2i(1176.4784166251445, 578.5249068290643);


    glVertex2i(1172.4019318085373, 591.8029968704406);
    glVertex2i(1176.4784166251445, 578.5249068290643);
    glVertex2i(1185.1053561988767, 593.0733393094744);
    glVertex2i(1186.414848365625, 580.5631492373678);
    glVertex2i(1198.232228068894, 596.4609191468979);
    glVertex2i(1200.172984621675, 582.6013916456714);
    glVertex2i(1213.421560275649, 595.3404066975684);
    glVertex2i(1214.6954617808387, 580.5631492373678);


    glVertex2i(1157.1450273118899, 600.679910071894);
    glVertex2i(1172.4019318085373, 591.8029968704406);
    glVertex2i(1164.3564296946556, 617.6332931307951);
    glVertex2i(1176.636406605317, 605.7767636998127);
    glVertex2i(1163.84, 624.66);
    glVertex2i(1180, 620);
    glVertex2i(1163.0860872556216, 634.9946397975908);
    glVertex2i(1177.906749044351, 635.4180872772688);
    glEnd();


    glBegin(GL_QUAD_STRIP);
    glVertex2i(833.3542429792057, 587.417242975208);
    glVertex2i(848.3901914017788, 585.594703772472);
    glVertex2i(827.2777548288655, 613.9610573001758);
    glVertex2i(843.0333197160044, 612.7490907703959);
    glVertex2i(828.4897213586454, 633.9585050415428);
    glVertex2i(846.6692193053441, 633.9585050415428);
    glVertex2i(837.4399561945386, 649.8041797579403);
    glVertex2i(849.73, 641.24);
    glVertex2i(844.4283777047385, 660.4532030115776);
    glVertex2i(854.7446189817003, 653.131999524702);
    glVertex2i(849.4201073548813, 677.4250838220618);
    glVertex2i(860.0691306085193, 664.1138047550153);
    glVertex2i(848.4217614248528, 692.0674907958129);
    glVertex2i(860.7346945618717, 686.7429791689943);
    glVertex2i(852.7479271216432, 705.7115518395356);
    glVertex2i(860, 700);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(852.7479271216432, 705.7115518395356);
    glVertex2i(860, 700);
    glVertex2i(858.7380027018146, 714.696665209792);

    glVertex2i(982.2987044457645, 769.1277539622928);
    glVertex2i(987.9575762100989, 768.2137781103223);
    glVertex2i(987.3741873684158, 779.2981661022981);

    glVertex2i(826.3885311240131, 739.269122908757);
    glVertex2i(822.1442876927334, 751.3955327124121);
    glVertex2i(791.8282631835933, 742.9070458498536);

    glVertex2i(892.6080690956403, 850.1827178551476);
    glVertex2i(902.9386420044748, 842.2000024255944);
    glVertex2i(903.4082135003308, 854.4088613178524);

    glVertex2i(892.6080690956403, 850.1827178551476);
    glVertex2i(903.4082135003308, 854.4088613178524);
    glVertex2i(896.3646410624892, 872.252578160383);


    glVertex2i(938.4139702448624, 722.1572895533117);
    glVertex2i(956.6295954117137, 716.506080442492);
    glVertex2i(940, 760);

    glVertex2i(954.6967402970517, 762.9323829549445);
    glVertex2i(946.1392196232368, 774.5817070223203);
    glVertex2i(957.3664249645174, 769.9879781475317);

    glVertex2i(982.9191210674027, 840.3532383114426);
    glVertex2i(978.9145940662042, 846.264682932259);
    glVertex2i(983.8725798772118, 847.40883350403);

    glVertex2i(978.9145940662042, 846.264682932259);
    glVertex2i(983.8725798772118, 847.40883350403);
    glVertex2i(981.393586971708, 855.0365039825027);
    glEnd();


    glBegin(GL_QUAD_STRIP);
    glVertex2i(966.30, 623.55);
    glVertex2i(988.6094843574725, 633.7049053174317);
    glVertex2i(962.476457192765, 648.5948294554441);
    glVertex2i(976.9968860626369, 656.5672082103872);
    glVertex2i(952.56, 689.44);
    glVertex2i(969.5493566197483, 692.272047077292);


    glVertex2i(952.56, 689.44);
    glVertex2i(969.5493566197483, 692.272047077292);
    glVertex2i(960.6938710087717, 704.0993444093682);
    glVertex2i(970, 700);
    glVertex2i(967.3250575092349, 709.4470754581284);
    glVertex2i(975.8500455914856, 709.0382872224382);
    glVertex2i(972.458879316045, 715.8643527166407);
    glVertex2i(980.0149077931463, 715.6593502096943);
    glVertex2i(976.0953364292022, 723.1372669429547);
    glVertex2i(982.9015395821797, 722.1260596173704);
    glVertex2i(975.4536087033509, 733.1910013146239);
    glVertex2i(982.3181507404967, 732.4325958204356);
    glVertex2i(976.5231549131031, 742.603007960442);
    glVertex2i(982.70, 741.71);
    glVertex2i(976.0953364292022, 750.945468396508);
    glVertex2i(982.3181507404967, 750.323186965379);
    glVertex2i(980, 760);
    glVertex2i(985.8184837905945, 759.6574084323059);
    glVertex2i(982.2987044457645, 769.1277539622928);
    glVertex2i(987.9575762100989, 768.2137781103223);

    glVertex2i(952.56, 689.44);
    glVertex2i(969.5493566197483, 692.272047077292);
    glVertex2i(950, 700);
    glVertex2i(960.6938710087717, 704.0993444093682);
    glVertex2i(938.4139702448624, 722.1572895533117);
    glVertex2i(952.1375013307548, 727.4154517819629);
    glVertex2i(915.0389829240427, 738.6572806033006);
    glVertex2i(936.8086467144025, 744.5899882958197);
    glVertex2i(893.7264944844718, 755.1572716532895);
    glVertex2i(909.5126429464602, 767.0685630886233);
    glVertex2i(875.94, 755.41);
    glVertex2i(894.4139941115548, 774.40726121161);


    glVertex2i(875.94, 755.41);
    glVertex2i(894.4139941115548, 774.40726121161);
    glVertex2i(859.7361580840673, 755.6397761436913);
    glVertex2i(854.8855941626048, 772.6167498688084);
    glVertex2i(826.3885311240131, 739.269122908757);
    glVertex2i(822.1442876927334, 751.3955327124121);


    glVertex2i(894.4139941115548, 774.40726121161);
    glVertex2i(909.5126429464602, 767.0685630886233);
    glVertex2i(887.5389978407254, 792.2822515157648);
    glVertex2i(904.8169279878991, 782.0948509560175);
    glVertex2i(884.1014997053107, 813.5947399553338);
    glVertex2i(900, 800);
    glVertex2i(887.5389978407238, 833.5322291407371);
    glVertex2i(896.8342125583454, 814.0257126742302);
    glVertex2i(892.6080690956403, 850.1827178551476);
    glVertex2i(902.9386420044748, 842.2000024255944);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glVertex2i(946.6876862946549, 741.9562891391444);
    glVertex2i(935.8086467144025, 743.5899882958197);
    glVertex2i(949.5480627240823, 754.3512536666626);
    glVertex2i(940, 760);
    glVertex2i(954.6967402970517, 762.9323829549445);
    glVertex2i(946.1392196232368, 774.5817070223203);


    glVertex2i(957.3664249645174, 769.9879781475317);
    glVertex2i(946.1392196232368, 774.5817070223203);
    glVertex2i(955.6501991068609, 780.0946415315082);
    glVertex2i(940.9739331688197, 787.7297089062903);
    glVertex2i(954.6967402970517, 788.6757708197897);
    glVertex2i(947.641145104464, 794.5872154406061);
    glVertex2i(958.891959060212, 801.4521188712315);
    glVertex2i(951.073596819777, 802.7869612049643);
    glVertex2i(963.0871778233724, 813.4656998748261);
    glVertex2i(956.60365791667, 818.8050692097571);
    glVertex2i(967.6637801104563, 820.7119868293753);
    glVertex2i(961.5616437276777, 826.4327396882298);
    glVertex2i(973.7659164932348, 827.9582737839244);
    glVertex2i(968.2358553963418, 831.9628007851226);
    glVertex2i(979.4866693520897, 832.9162595949317);
    glVertex2i(975.4821423508913, 838.6370124537863);
    glVertex2i(982.9191210674027, 840.3532383114426);
    glVertex2i(978.9145940662042, 846.264682932259);
    glEnd();


    glColor3f(0.55f, 0.35f, 0.10f);

    glBegin(GL_QUAD_STRIP);
    glVertex2i(940.9739331688197, 787.7297089062903);
    glVertex2i(947.641145104464, 794.5872154406061);
    glVertex2i(932.5216462434097, 800.8777107902603);
    glVertex2i(943.1603901417624, 801.1872134859061);
    glVertex2i(917.3484054668987, 818.3662715940499);
    glVertex2i(936.43, 810.93);
    glVertex2i(926.22, 808.15);
    glVertex2i(927.0106971364137, 820.084012335297);
    glVertex2i(917.3484054668987, 818.3662715940499);
    glVertex2i(925.2929563951666, 830.3904567827794);
    glVertex2i(915.6306647256516, 833.8259382652736);
    glVertex2i(925.5076739878225, 839.8380308596385);
    glVertex2i(918.2072758375224, 847.5678641952503);
    glVertex2i(926.581261951102, 850.3591928997769);


    glVertex2i(970.0389530906773, 599.094856305477);
    glVertex2i(988.6094843574725, 633.7049053174317);
    glVertex2i(969.3514534635943, 566.7823738325819);
    glVertex2i(1000, 629.72);


    glVertex2i(1000, 629.72);
    glVertex2i(1028.7533079784107, 598.9822574067558);
    glVertex2i(1010.475971235264, 634.130981912806);
    glVertex2i(1029.11, 621.130981912806);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(918.2072758375224, 847.5678641952503);
    glVertex2i(926.581261951102, 850.3591928997769);
    glVertex2i(923.3604980612637, 856.1565679014857);

    glVertex2i(918.2072758375224, 847.5678641952503);
    glVertex2i(923.3604980612637, 856.1565679014857);
    glVertex2i(914.1276415770604, 865.6041419783447);

    glVertex2i(946.2665636152317, 145.6794863056759);
    glVertex2i(956.9941759815997, 133.9741055207706);
    glVertex2i(920.4690713644417, 135.1259667485345);

    glVertex2i(1041.0137169726786, 155.8108650805316);
    glVertex2i(1029.650729452395, 139.1701773748464);
    glVertex2i(1055.9999726601127, 138.3921897176732);

    glVertex2i(1093.6011163557132, 171.8913904646633);
    glVertex2i(1094.7405449525497, 155.1417900911683);
    glVertex2i(1104.2357832595194, 164.0293331464922);

    glVertex2i(1094.7405449525497, 155.1417900911683);
    glVertex2i(1104.2357832595194, 164.0293331464922);
    glVertex2i(1116.3896882924407, 152.06533287971);
    glEnd();


    glColor3f(0.55f, 0.35f, 0.10f); // Set color for lines
    glBegin(GL_QUAD_STRIP);
    glVertex2i(950, 200);
    glVertex2i(1000, 200);
    glVertex2i(939.6134200468648, 183.3916438220976);
    glVertex2i(961.7293412163266, 165.4135401617609);
    glVertex2i(910.7200391641808, 167.3397655539398);
    glVertex2i(939.6134200468648, 154.1772253740504);
    glVertex2i(881.8266582814967, 157.0665634623188);
    glVertex2i(912.8602895999352, 151.9299624165083);

    glVertex2i(1000, 200);
    glVertex2i(1038.1994450907741, 168.8972293313869);
    glVertex2i(961.7293412163266, 165.4135401617609);
    glVertex2i(987.1968956737041, 149.7893478322721);
    glVertex2i(946.2665636152317, 145.6794863056759);
    glVertex2i(956.9941759815997, 133.9741055207706);

    glVertex2i(1000, 200);
    glVertex2i(987.1968956737041, 149.7893478322721);
    glVertex2i(1050, 200);
    glVertex2i(1000.4108391246398, 145.1561716845368);
    glVertex2i(1038.1994450907741, 168.8972293313869);
    glVertex2i(1012.4019528399841, 149.9008941285324);
    glVertex2i(1041.0137169726786, 155.8108650805316);
    glVertex2i(1029.650729452395, 139.1701773748464);


    glVertex2i(1050, 200);
    glVertex2i(1012.4019528399841, 149.9008941285324);
    glVertex2i(1041.0137169726786, 155.8108650805316);
    glVertex2i(1029.650729452395, 139.1701773748464);


    glVertex2i(1050, 200);
    glVertex2i(1041.0137169726786, 155.8108650805316);
    glVertex2i(1064.51460470683, 190.5151572950144);
    glVertex2i(1064.51460470683, 149.1539234704346);
    glVertex2i(1076.5096874031676, 177.0188191504271);
    glVertex2i(1078.4087350645616, 151.0398471425573);
    glVertex2i(1093.6011163557132, 171.8913904646633);
    glVertex2i(1094.7405449525497, 155.1417900911683);
    glEnd();



    drawTreeLeaves_b(0, 0);
    drawTreeLeaves_b(50, 50);
    drawTreeLeaves_b(-30, 100);
    drawTreeLeaves_b(-80, 90);
    drawTreeLeaves_b(-140, 110);
    drawTreeLeaves_b(-100, 110);
    drawTreeLeaves_b(-130, 80);


    drawTreeLeaves_s(0, 0);
    drawTreeLeaves_s(-35, 40);
    drawTreeLeaves_s(35, 80);

    // tree adding leaves =============================================================================
    drawTreeLeaves_s(-570, -20);
    drawTreeLeaves_s(-570, 30);
    drawTreeLeaves_s(-600, 50);
    drawTreeLeaves_s(-550, 100);
    drawTreeLeaves_s(-400, 100);
    drawTreeLeaves_s(-520, 180);
    drawTreeLeaves_s(-480, 160);
    drawTreeLeaves_b(-400, 120);
    drawTreeLeaves_s(-380, 260);
    drawTreeLeaves_s(-320, 280);
    // tree adding leaves =============================================================================
    // tree ===========================================================================================

    glFlush();
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);						// Initalise GLUT
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);	// Set display mode

    glutInitWindowPosition(100, 100);				// Set window position
    glutInitWindowSize(1980, 980);					// Set window size
    glutCreateWindow("An Example OpenGL Program");	// Create display window

    init();							// Execute initialisation procedure
    glutDisplayFunc(drawShapes);		// Send graphics to display window
    glutSpecialFunc(arrow);
    glutMainLoop();					// Display everything and wait

    return 0;
}
