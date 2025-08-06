//---------------------------------------------------------------------------
#pragma hdrstop
#include "elemplano.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
elemplano::elemplano()
{
        X=0;
        Y=0;
        Z=0;
        valor=0;
}
//---------------------------------------------------------------------------

elemplano::elemplano(float x,float y,float z,int v)
{
        X=x;
        Y=y;
        Z=z;
        valor=v;
}
//---------------------------------------------------------------------------

elemplano::~elemplano()
{

}

void elemplano::SetCoords(float x, float y, float z)
{
        //TODO: Add your source code here
        X=x;
        Y=y;
        Z=z;
}

float elemplano::GetCoords(int index)
{
        //TODO: Add your source code here
        float Coords[3];
        Coords[0]=X;
        Coords[1]=Y;
        Coords[2]=Z;
        return Coords[index];
}

int elemplano::GetValue()
{
        //TODO: Add your source code here
        return valor;
}

void elemplano::SetValue(int v)
{
        //TODO: Add your source code here
        valor=v;
}

