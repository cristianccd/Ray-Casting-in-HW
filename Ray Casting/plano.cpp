//---------------------------------------------------------------------------
#pragma hdrstop
#include "plano.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
plano::plano()
{
        PX=0;
        PY=0;
        PZ=0;
        NX=-1;
        NY=-1;
        NZ=-1;
}
//---------------------------------------------------------------------------

plano::plano(float px,float py,float pz,float nx,float ny,float nz)
{
        PX=px;
        PY=py;
        PZ=pz;
        NX=nx;
        NY=ny;
        NZ=nz;
}
//---------------------------------------------------------------------------

plano::~plano()
{

}
//---------------------------------------------------------------------------

void plano::Rotar(int eje,int ang)
{
        //TODO: Add your source code here
        //X fijo
        if (eje==1)
        {
                NX=NX;
                NY=NY*cos(2*M_PI/360*ang)+NZ*sin(2*M_PI/360*ang);
                NZ=-NY*sin(2*M_PI/360*ang)+NZ*cos(2*M_PI/360*ang);
        }
        //Y fijo
        if (eje==2)
        {
                NX=NX*cos(2*M_PI/360*ang)-NZ*sin(2*M_PI/360*ang);
                NY=NY;
                NZ=NX*sin(2*M_PI/360*ang)+NZ*cos(2*M_PI/360*ang);

        }
        //Z fijo
        if (eje==3)
        {
                NX=NX*cos(2*M_PI/360*ang)+NY*sin(2*M_PI/360*ang);
                NY=-NX*sin(2*M_PI/360*ang)+NY*cos(2*M_PI/360*ang);
                NZ=NZ;
        }

        /*   x1=(c-posx)*cos(2*M_PI/360*grad)-(f-posy)*sin(2*M_PI/360*grad);
        	        y1=(c-posx)*sin(2*M_PI/360*grad)+(f-posy)*cos(2*M_PI/360*grad);*/

}
//---------------------------------------------------------------------------

void plano::Graficar(TImage *Image1,TImage *Image2,TImage *Image3)
{
        //TODO: Add your source code here
        Image1->Canvas->MoveTo(64,64);
        Image1->Canvas->LineTo(NY*128,NZ*128);
        Image2->Canvas->MoveTo(64,64);
        Image2->Canvas->LineTo(NX*128,NZ*128);
        Image3->Canvas->MoveTo(64,64);
        Image3->Canvas->LineTo(NX*128,NY*128);
}
//---------------------------------------------------------------------------

void plano::BorrarImages(TImage * Image1, TImage * Image2, TImage * Image3)
{
        //TODO: Add your source code here
}
