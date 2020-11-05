#include "TXLib.h"
#include <iostream>
#include <math.h>

class Sphere
{
    public:

        float x = 1;
        float y = 1;
        float R = 1;
        float Vx = 1;
        float Vy = 1;

        void draw()
        {
            COLORREF OldFillColor = txGetFillColor();
            COLORREF OldColor = txGetColor();
            txSetColor(TX_BLUE);
            txSetFillColor(TX_BLUE);
            txCircle(x, y , R);
            txSetFillColor(OldFillColor);
            txSetColor(OldColor);
        }

        void movement()
        {
            x = x + Vx;
            y = y + Vy;
        }

        void collisionWithWalls()
        {
            if (x + R > 1500)
            {
                Vx = -Vx;
            }
            if ( x - R < 0)
            {
                Vx = -Vx;
            }
            if (y + R > 800)
            {
                Vy = -Vy;
            }
            if ( y - R < 0)
            {
                Vy = -Vy;
            }
        }

        bool checkCollisionSpheres(Sphere sphere)
        {
            return (x - sphere.x) * (x - sphere.x) + (y - sphere.y) * (y - sphere.y) < (R + sphere.R) * (R + sphere.R);
        }
        void collisionSpheres(Sphere* sphere)
        {
            if (!checkCollisionSpheres(*sphere))
            {
                return;
            }

            float Bufer = 0;
            Bufer = Vx;
            Vx = sphere->Vx;
            sphere->Vx = Bufer;

            Bufer = Vy;
            Vy = sphere->Vy;
            sphere->Vy = Bufer;
        }
};

void drowAtoms(Sphere* atoms, int number)
{
    for (int i = 0; i < number; i++)
    {
        atoms[i].draw();
    }
}

void moveAtoms(Sphere* atoms, int number)
{
    for (int i = 0; i < number; i++)
    {
        for (int j = i + 1; j < number; j++)
        {
            atoms[i].collisionSpheres(&atoms[j]);
        }
    }

    for (int i = 0; i < number; i++)
    {
        atoms[i].collisionWithWalls();
    }

    for (int i = 0; i < number; i++)
    {
        atoms[i].movement();
    }
}

int main()
{
    int number = 500;
    Sphere* atoms = new Sphere[number];
    int a = 1500;
    int b = 800;

    txCreateWindow(a, b);
    txSetFillColor (TX_BLACK);


    for (int i = 0; i < number; i++)
    {
        atoms[i].x = 20 + rand()%(1481);
        atoms[i].y = 20 + rand()%(781);
        atoms[i].R = 5;
        atoms[i].Vx = -10 + rand()%(10+10+1);
        atoms[i].Vy = -10 + rand()%(10+10+1);
    }

    while (true)
    {
        txBegin();
        txClear();

        drowAtoms(atoms, number);

        moveAtoms(atoms, number);

        txEnd();
    }

    delete[] atoms;
    return 0;
}






