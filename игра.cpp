#include "TXLib.h"
#include <ctime>
#include "math.h"
struct Sphere
{

    double x;
    double y;
    double R;

    double Red;
    double Green;
    double Blue;

    double Quality;
    double Vx;
    double Vy;

};

struct Screen
{
    double a;
    double b;
};

void DrowSph(Sphere Sph){
    COLORREF OldFillColor = txGetFillColor();
    COLORREF OldColor = txGetColor();
    for (double i = 0; i <= Sph.Quality; i++)
    {
        txSetFillColor(RGB((Sph.Red * i) / Sph.Quality, (Sph.Green * i) / Sph.Quality, (Sph.Blue * i) / Sph.Quality));
        txSetColor(RGB((Sph.Red * i) / Sph.Quality, (Sph.Green * i) / Sph.Quality, (Sph.Blue * i) / Sph.Quality));
        txCircle(Sph.x, Sph.y , Sph.R - (Sph.R * i) / Sph.Quality);
    }
    txSetFillColor(OldFillColor);
    txSetColor(OldColor);
}

void MoveSph(Sphere* Sph){
        Sph->x += Sph->Vx;
        Sph->y += Sph->Vy;
}

void CheckCollisionWall(Sphere* Sph, Screen ab){
    if (Sph->x >= ab.a - Sph->R   or Sph->x <= Sph->R  ) {
            Sph->Vx = -Sph->Vx;
    }
    if (Sph->y >= ab.b - Sph->R   or Sph->y <= Sph->R  ) {
            Sph->Vy = -Sph->Vy;
    }
}

void CollisionResult (Sphere* Sph1, Sphere* Sph2){
        double Bufer = 0;
        Bufer = Sph1->Vx;
        Sph1->Vx = Sph2->Vx;
        Sph2->Vx = Bufer;

        Bufer = Sph1->Vy;
        Sph1->Vy = Sph2->Vy;
        Sph2->Vy = Bufer;
     }
bool CheckCollisionBall(Sphere Sph1, Sphere Sph2){
    if ((pow((Sph1.x - Sph2.x),2)) + (pow((Sph1.y - Sph2.y),2)) <= (Sph2.R + Sph1.R) * (Sph2.R + Sph1.R)){
        return true;
    }
    else{
        return false;
    }
}

bool LoseCondition(Sphere Sph1, Sphere Sph2, Sphere Sph3){
    if(CheckCollisionBall(Sph1, Sph3) or CheckCollisionBall(Sph2, Sph3)){
        return false;
    }
    else{
    return true;
    }
}
bool ImmortalTimer(){
    if (clock() <= 3000){
        return true;
    }
    else
        return false;
}

int main()
{
    Screen ab;
    ab = {1500, 800};
    txCreateWindow(ab.a, ab.b);
    txSetFillColor (TX_BLACK);

    Sphere Sph1;
    Sph1 = {400, 500, 100, 0, 100, 250, 100, 7, 7};
    Sphere Sph2;
    Sph2 = {300, 200, 100, 0, 100, 250, 100, 5, 5};
    Sphere Sph3;


    while (LoseCondition(Sph1, Sph2, Sph3) or ImmortalTimer()) {
        txBegin();
        txClear();

        if(ImmortalTimer()){
            Sph3 = {txMouseX(), txMouseY(), 100, 0, 100, 250, 100, 0, 0};
            DrowSph(Sph3);
        }
        else{
            Sph3 = {txMouseX(), txMouseY(), 100, 250, 250, 0, 100, 0, 0};
            DrowSph(Sph3);
        }

        if (CheckCollisionBall(Sph1, Sph2)){
            CollisionResult (&Sph1, &Sph2);
        }

        MoveSph(&Sph1);
        MoveSph(&Sph2);


        DrowSph(Sph1);
        DrowSph(Sph2);

        CheckCollisionWall(&Sph1, ab);
        CheckCollisionWall(&Sph2, ab);

        txEnd();
        }
    return 0;
}
