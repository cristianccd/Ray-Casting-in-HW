//---------------------------------------------------------------------------
#pragma hdrstop
#include "plano.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
plano::plano()
{
        TamX=512;
        TamY=512;
        Plano=new elemplano *[TamX];
        for (int i=0;i<TamX;i++)
                Plano[i]=new elemplano [TamY];
        for (int j=0;j<TamY;j++)
                for (int i=0;i<TamX;i++)
                {
                        Plano[i][j].SetCoords(i,j,0);
                        Plano[i][j].SetValue(0);
                }
        Normal.SetCoords(0,0,1);
        Normal.SetPto(TamX/2,TamY/2,0);
}
//---------------------------------------------------------------------------

plano::plano(float tamx,float tamy)
{
        TamX=tamx;
        TamY=tamy;
        Plano=new elemplano *[TamX];
        for (int i=0;i<TamX;i++)
                Plano[i]=new elemplano [TamY];
        for (int j=0;j<TamY;j++)
                for (int i=0;i<TamX;i++)
                {
                        Plano[i][j].SetCoords(i,j,0);
                        Plano[i][j].SetValue(0);
                }
        Normal.SetCoords(0,0,1);
        Normal.SetPto(TamX/2,TamY/2,0);
}
//---------------------------------------------------------------------------

plano::~plano()
{

}

void plano::Rotar(normal Vect, float Angle)
{
        //TODO: Add your source code here
        //Roto a partir de un vector que parte del origen y un angulo.
        float Ux,Uy,Uz,x,y,z,x_,y_,z_;
        Ux=Vect.GetCoords()[0];
        Uy=Vect.GetCoords()[1];
        Uz=Vect.GetCoords()[2];
        for(int j=0;j<TamY;j++)
                for(int i=0;i<TamX;i++)
                {
                        x=Plano[i][j].GetCoords()[0];
                        y=Plano[i][j].GetCoords()[1];
                        z=Plano[i][j].GetCoords()[2];
                        x_=x*(cos(2*M_PI/360*Angle)+Ux*Ux*(1-cos(2*M_PI/360*Angle)))+y*(Ux*Uy*(1-cos(2*M_PI/360*Angle))-Uz*sin(2*M_PI/360*Angle))+z*(Ux*Uz*(1-cos(2*M_PI/360*Angle))+Uy*sin(2*M_PI/360*Angle));
                        y_=x*(Uy*Ux*(1-cos(2*M_PI/360*Angle))+Uz*sin(2*M_PI/360*Angle))+y*(cos(2*M_PI/360*Angle)+Uy*Uy*(1-cos(2*M_PI/360*Angle)))+z*(Uy*Uz*(1-cos(2*M_PI/360*Angle))-Ux*sin(2*M_PI/360*Angle));
                        z_=x*(Uz*Ux*(1-cos(2*M_PI/360*Angle))-Uy*sin(2*M_PI/360*Angle))+y*(Uz*Uy*(1-cos(2*M_PI/360*Angle))+Ux*sin(2*M_PI/360*Angle))+z*(cos(2*M_PI/360*Angle)+Uz*Uz*(1-cos(2*M_PI/360*Angle)));
                        Plano[i][j].SetCoords(x_,y_,z_);
                        //si es el punto medio, guardo el punto de inicio de la normal
                        if(i==TamX/2&&j==TamY/2)
                                Normal.SetPto(x_,y_,z_);
                }
                //calculo la nueva normal
                float nx,ny,nz,nx_,ny_,nz_;
                nx=Normal.GetCoords()[0];
                ny=Normal.GetCoords()[1];
                nz=Normal.GetCoords()[2];
                nx_=nx*(cos(2*M_PI/360*Angle)+Ux*Ux*(1-cos(2*M_PI/360*Angle)))+ny*(Ux*Uy*(1-cos(2*M_PI/360*Angle))-Uz*sin(2*M_PI/360*Angle))+nz*(Ux*Uz*(1-cos(2*M_PI/360*Angle))+Uy*sin(2*M_PI/360*Angle));
                ny_=nx*(Uy*Ux*(1-cos(2*M_PI/360*Angle))+Uz*sin(2*M_PI/360*Angle))+ny*(cos(2*M_PI/360*Angle)+Uy*Uy*(1-cos(2*M_PI/360*Angle)))+nz*(Uy*Uz*(1-cos(2*M_PI/360*Angle))-Ux*sin(2*M_PI/360*Angle));
                nz_=nx*(Uz*Ux*(1-cos(2*M_PI/360*Angle))-Uy*sin(2*M_PI/360*Angle))+ny*(Uz*Uy*(1-cos(2*M_PI/360*Angle))+Ux*sin(2*M_PI/360*Angle))+nz*(cos(2*M_PI/360*Angle)+Uz*Uz*(1-cos(2*M_PI/360*Angle)));
                Normal.SetCoords(nx_,ny_,nz_);
}

normal plano::GetNormal()
{
        //TODO: Add your source code here
        return Normal;
}

elemplano plano::GetElemPlano(int i, int j)
{
        //TODO: Add your source code here
        return Plano[i][j];
}