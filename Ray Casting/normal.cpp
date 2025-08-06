//---------------------------------------------------------------------------
#pragma hdrstop
#include "normal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
normal::normal()
{
        X=0;
        Y=0;
        Z=0;
        PX=0;
        PY=0;
        PZ=0;
}
//---------------------------------------------------------------------------

normal::normal(float x,float y,float z,float px,float py,float pz)
{
        X=x;
        Y=y;
        Z=z;
        PX=px;
        PY=py;
        PZ=pz;
}
//---------------------------------------------------------------------------

normal::~normal()
{
}
//---------------------------------------------------------------------------

void normal::SetCoords(float x, float y, float z)
{
        //TODO: Add your source code here
        X=x;
        Y=y;
        Z=z;
}
//---------------------------------------------------------------------------

void normal::SetPto(float px, float py, float pz)
{
        //TODO: Add your source code here
        PX=px;
        PY=py;
        PZ=pz;
}
//---------------------------------------------------------------------------

void normal::SetPto(float *p)
{
        //TODO: Add your source code here
        PX=p[0];
        PY=p[1];
        PZ=p[2];
}
//---------------------------------------------------------------------------

float * normal::GetCoords()
{
        //TODO: Add your source code here
        float Coords[3];
        Coords[0]=X;
        Coords[1]=Y;
        Coords[2]=Z;
        return Coords;
}
//---------------------------------------------------------------------------

float * normal::GetPto()
{
        //TODO: Add your source code here
        float Pto[3];
        Pto[0]=PX;
        Pto[1]=PY;
        Pto[2]=PZ;
        return Pto;
}
//---------------------------------------------------------------------------
