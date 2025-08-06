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
                        Plano[i][j].SetCoords(0,i,j);
                        Plano[i][j].SetValue(0);
                }
        Normal.SetCoords(1,0,0);
        Normal.SetPto(0,TamX/2,TamY/2);
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
                        Plano[i][j].SetCoords(0,i,j);
                        Plano[i][j].SetValue(0);
                }
        Normal.SetCoords(1,0,0);
        Normal.SetPto(0,TamX/2,TamY/2);
}
//---------------------------------------------------------------------------

plano::~plano()
{

}

void plano::Rotar(normal Vect, float Angle)
{
        //Roto a partir de un vector que parte del origen y un angulo.
        float Ux,Uy,Uz,x,y,z,x_,y_,z_,TX=0,TY=0,TZ=0;
        //llevo al 0 el plano
        TX=Normal.GetPto(0);
        TY=Normal.GetPto(1);
        TZ=Normal.GetPto(2);
        Trasladar(-TX,-TY,-TZ);
        Ux=Vect.GetCoords(0);
        Uy=Vect.GetCoords(1);
        Uz=Vect.GetCoords(2);
        for(int j=0;j<TamY;j++)
        {
                for(int i=0;i<TamX;i++)
                {
                        x=Plano[i][j].GetCoords(0);
                        y=Plano[i][j].GetCoords(1);
                        z=Plano[i][j].GetCoords(2);
                        x_=x*(cos(2*M_PI/360*Angle)+Ux*Ux*(1-cos(2*M_PI/360*Angle)))+y*(Ux*Uy*(1-cos(2*M_PI/360*Angle))-Uz*sin(2*M_PI/360*Angle))+z*(Ux*Uz*(1-cos(2*M_PI/360*Angle))+Uy*sin(2*M_PI/360*Angle));
                        y_=x*(Uy*Ux*(1-cos(2*M_PI/360*Angle))+Uz*sin(2*M_PI/360*Angle))+y*(cos(2*M_PI/360*Angle)+Uy*Uy*(1-cos(2*M_PI/360*Angle)))+z*(Uy*Uz*(1-cos(2*M_PI/360*Angle))-Ux*sin(2*M_PI/360*Angle));
                        z_=x*(Uz*Ux*(1-cos(2*M_PI/360*Angle))-Uy*sin(2*M_PI/360*Angle))+y*(Uz*Uy*(1-cos(2*M_PI/360*Angle))+Ux*sin(2*M_PI/360*Angle))+z*(cos(2*M_PI/360*Angle)+Uz*Uz*(1-cos(2*M_PI/360*Angle)));
                        Plano[i][j].SetCoords(x_,y_,z_);
                        //si es el punto medio, guardo el punto de inicio de la normal
                        if(i==TamX/2&&j==TamY/2)
                                Normal.SetPto(x_,y_,z_);
                }
         }
                //calculo la nueva normal
                float nx,ny,nz,nx_,ny_,nz_;
                nx=Normal.GetCoords(0);
                ny=Normal.GetCoords(1);
                nz=Normal.GetCoords(2);
                nx_=nx*(cos(2*M_PI/360*Angle)+Ux*Ux*(1-cos(2*M_PI/360*Angle)))+ny*(Ux*Uy*(1-cos(2*M_PI/360*Angle))-Uz*sin(2*M_PI/360*Angle))+nz*(Ux*Uz*(1-cos(2*M_PI/360*Angle))+Uy*sin(2*M_PI/360*Angle));
                ny_=nx*(Uy*Ux*(1-cos(2*M_PI/360*Angle))+Uz*sin(2*M_PI/360*Angle))+ny*(cos(2*M_PI/360*Angle)+Uy*Uy*(1-cos(2*M_PI/360*Angle)))+nz*(Uy*Uz*(1-cos(2*M_PI/360*Angle))-Ux*sin(2*M_PI/360*Angle));
                nz_=nx*(Uz*Ux*(1-cos(2*M_PI/360*Angle))-Uy*sin(2*M_PI/360*Angle))+ny*(Uz*Uy*(1-cos(2*M_PI/360*Angle))+Ux*sin(2*M_PI/360*Angle))+nz*(cos(2*M_PI/360*Angle)+Uz*Uz*(1-cos(2*M_PI/360*Angle)));
                Normal.SetCoords(nx_,ny_,nz_);
                //El pto inicial de la normal no se deberia tocar

                //Vuelvo a colocar el plano donde corresponde
                Trasladar(TX,TY,TZ);
}

void plano::Rotar(float azi, float elev, float tilt)
{
        float RotX,RotY,RotZ,AngX,AngY,AngZ;
        normal Vect;

        RotX=sin(2*M_PI/360*elev)*cos(2*M_PI/360*azi);
        RotY=sin(2*M_PI/360*azi)*sin(2*M_PI/360*elev);
        RotZ=cos(2*M_PI/360*elev);

        AngX

       /* RotX=cos(2*M_PI/360*elev);
        RotY=sin(2*M_PI/360*azi);
        RotZ=sin(2*M_PI/360*elev); -*/


        /*       Z^
                  |
                  |
                  |
                  |         X
                  /-------->
                 /
               Y/               */


        Vect.SetCoords(RotX,RotY,RotZ);
        Vect.normalizar();
        //Roto la matriz
        Rotar(Vect,tilt);
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

void plano::Trasladar(float x, float y, float z)
{
        int x_=0,y_=0,z_=0,value=0;
        //Muevo la normal sin tocar la direccion (no cambia)
        Normal.SetPto(Normal.GetPto(0)+x,Normal.GetPto(1)+y,Normal.GetPto(2)+z);

        for(int j=0;j<TamY;j++)
                for(int i=0;i<TamX;i++)
                {
                        x_=Plano[i][j].GetCoords(0);
                        y_=Plano[i][j].GetCoords(1);
                        z_=Plano[i][j].GetCoords(2);
                        Plano[i][j].SetValue(0);
                        Plano[i][j].SetCoords(x_+x,y_+y,z_+z);
                }
}

void plano::Trasladar(normal Norm)
{
        int x_,y_,z_;
        x_=Norm.GetCoords(0);
        y_=Norm.GetCoords(1);
        z_=Norm.GetCoords(2);
        Normal.SetPto(Normal.GetPto(0)+x_,Normal.GetPto(1)+y_,Normal.GetPto(2)+z_);
        for(int j=0;j<TamY;j++)
                for(int i=0;i<TamX;i++)
                {
                        x_=x_+Plano[i][j].GetCoords(0);
                        y_=y_+Plano[i][j].GetCoords(1);
                        z_=z_+Plano[i][j].GetCoords(2);
                        Plano[i][j].SetValue(0);
                        Plano[i][j].SetCoords(x_,y_,z_);
                }

}

void plano::CargarPlano(voxel *Vox)
{
        int Rx,Ry,Rz;
        float Nx,Ny,Nz,Px,Py,Pz,max=0;
        Nx=Normal.GetCoords(0);
        Ny=Normal.GetCoords(1);
        Nz=Normal.GetCoords(2);
        for(int fila=0;fila<TamY;fila++)
        {
                for(int col=0;col<TamX;col++)
                {
                        Px=Plano[fila][col].GetCoords(0);
                        Py=Plano[fila][col].GetCoords(1);
                        Pz=Plano[fila][col].GetCoords(2);
                        max=0;
                        //int lambda=0;
                        for(int lambda=0;lambda<512;lambda++)//512
                        {
                                Rx=Nx*lambda+Px;
                                Ry=Ny*lambda+Py;
                                Rz=Nz*lambda+Pz;
                                if(Rx<Vox->getTam(0)&&Ry<Vox->getTam(1)&&Rz<Vox->getTam(2)&&Rx>0&&Ry>0&&Rz>0)
                                {
                                        if(Vox->getCubo(Rx,Ry,Rz)>70)//>max)
                                        {
                                                max=Vox->getCubo(Rx,Ry,Rz);
                                                //if(Vox->getCubo(Rx,Ry,Rz)>170&&Vox->getCubo(Rx,Ry,Rz)<200)
                                                //{
                                                        Plano[fila][col].SetCoords(Rx,Ry,Rz);
                                                        Plano[fila][col].SetValue(max);
                                                        break;
                                                //}
                                        }
                                }
                        }
                }
        }
}

void plano::Mostrar(TImage *Image)
{
        for (int j=0;j<TamY;j++)
        {
                LinePtr=(BYTE *) Image->Picture->Bitmap->ScanLine[j];
                for (int i=0;i<TamX;i++)
                {
                        LinePtr[i]=Plano[i][j].GetValue();
                }

        }
        Image->Refresh();
}


void plano::Borrar()
{
        //TODO: Add your source code here
        for (int j=0;j<TamY;j++)
                for (int i=0;i<TamX;i++)
                                Plano[i][j].SetValue(0);
}

void plano::Restore()
{
        for (int j=0;j<TamY;j++)
                for (int i=0;i<TamX;i++)
                {
                        Plano[i][j].SetCoords(0,i,j);
                        Plano[i][j].SetValue(0);
                }
        Normal.SetCoords(1,0,0);
        Normal.SetPto(0,TamX/2,TamY/2);
}

void plano::RotarXYZ(float AngX, float AngY, float AngZ)
{
        //TODO: Add your source code here
        float X,Y,Z,X_,Y_,Z_;
        //Rot X
        for (int j=0;j<TamY;j++)
                for (int i=0;i<TamX;i++)
                {
                        X=Plano[i][j].GetCoords(0);
                        Y=Plano[i][j].GetCoords(1);
                        Z=Plano[i][j].GetCoords(2);
                        X_=X;
                        Y_=Y*cos(2*M_PI/360*AngX)-Z*sin(2*M_PI/360*AngX);
                        Z_=Y*sin(2*M_PI/360*AngX)+Z*cos(2*M_PI/360*AngX);
                        Plano[i][j].SetCoords(X_,Y_,Z_);
                        if(j==TamY/2&&i==TamX/2)
                                Normal.SetPto(X_,Y_,Z_);
                }
        X=Normal.GetCoords(0);
        Y=Normal.GetCoords(1);
        Z=Normal.GetCoords(2);
        X_=X;
        Y_=Y*cos(2*M_PI/360*AngX)-Z*sin(2*M_PI/360*AngX);
        Z_=Y*sin(2*M_PI/360*AngX)+Z*cos(2*M_PI/360*AngX);
        Normal.SetCoords(X_,Y_,Z_);
        //Rot Y
        for (int j=0;j<TamY;j++)
                for (int i=0;i<TamX;i++)
                {
                        X=Plano[i][j].GetCoords(0);
                        Y=Plano[i][j].GetCoords(1);
                        Z=Plano[i][j].GetCoords(2);
                        X_=X*cos(2*M_PI/360*AngY)+Z*sin(2*M_PI/360*AngY);
                        Y_=Y;
                        Z_=X*(-sin(2*M_PI/360*AngY))+Z*cos(2*M_PI/360*AngY);
                        Plano[i][j].SetCoords(X_,Y_,Z_);
                        if(j==TamY/2&&i==TamX/2)
                                Normal.SetPto(X_,Y_,Z_);
                }
        X=Normal.GetCoords(0);
        Y=Normal.GetCoords(1);
        Z=Normal.GetCoords(2);
        X_=X*cos(2*M_PI/360*AngY)+Z*sin(2*M_PI/360*AngY);
        Y_=Y;
        Z_=X*(-sin(2*M_PI/360*AngY))+Z*cos(2*M_PI/360*AngY);
        Normal.SetCoords(X_,Y_,Z_);
        //Rot Z
        for (int j=0;j<TamY;j++)
                for (int i=0;i<TamX;i++)
                {
                        X=Plano[i][j].GetCoords(0);
                        Y=Plano[i][j].GetCoords(1);
                        Z=Plano[i][j].GetCoords(2);
                        X_=X*cos(2*M_PI/360*AngZ)-Y*sin(2*M_PI/360*AngZ);
                        Y_=X*sin(2*M_PI/360*AngZ)+Y*cos(2*M_PI/360*AngZ);
                        Z_=Z;
                        Plano[i][j].SetCoords(X_,Y_,Z_);
                        if(j==TamY/2&&i==TamX/2)
                                Normal.SetPto(X_,Y_,Z_);
                }
        X=Normal.GetCoords(0);
        Y=Normal.GetCoords(1);
        Z=Normal.GetCoords(2);
        X_=X*cos(2*M_PI/360*AngZ)-Y*sin(2*M_PI/360*AngZ);
        Y_=X*sin(2*M_PI/360*AngZ)+Y*cos(2*M_PI/360*AngZ);
        Z_=Z;
        Normal.SetCoords(X_,Y_,Z_);

}
