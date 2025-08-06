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
//---------------------------------------------------------------------------

normal plano::GetNormal()
{
        //TODO: Add your source code here
        return Normal;
}
//---------------------------------------------------------------------------

elemplano plano::GetElemPlano(int i, int j)
{
        //TODO: Add your source code here
        return Plano[i][j];
}
//---------------------------------------------------------------------------

void plano::CargarPlano(voxel *Vox, TProgressBar *Barra, bool Volume, bool MIP, bool Trilinear)
{
        Barra->Position=0;
        Barra->Max=TamY;
        int Rx,Ry,Rz;
        float Rad=sqrt(pow(Vox->getTam(0),2)+pow(Vox->getTam(1),2)+pow(Vox->getTam(2),2));
        float Nx,Ny,Nz,Px,Py,Pz,max=0;
        Nx=Normal.GetCoords(0);
        Ny=Normal.GetCoords(1);
        Nz=Normal.GetCoords(2);
        if(Volume==true)
        {
                //Volumen
                for(int fila=0;fila<TamY;fila++)
                {
                        Barra->Position++;
                        for(int col=0;col<TamX;col++)
                        {
                                Px=Plano[fila][col].GetCoords(0);
                                Py=Plano[fila][col].GetCoords(1);
                                Pz=Plano[fila][col].GetCoords(2);
                                for(int lambda=0;lambda<Rad;lambda++)
                                {
                                        Rx=Nx*lambda+Px;
                                        Ry=Ny*lambda+Py;
                                        Rz=Nz*lambda+Pz;
                                        if(Rx<Vox->getTam(0)&&Ry<Vox->getTam(1)&&Rz<Vox->getTam(2)&&Rx>=0&&Ry>=0&&Rz>=0&&sqrt(pow(Rx,2)+pow(Ry,2)+pow(Rz,2))<Rad&&Vox->getCubo(Rx,Ry,Rz)>40)
                                        {
                                                Plano[fila][col].SetCoords(Rx,Ry,Rz);
                                                Plano[fila][col].SetValue(Vox->getCubo(Rx,Ry,Rz));
                                                break;
                                        }
                                }
                        }
                }
        }
        if(MIP==true)
        {
                //MIP
                for(int fila=0;fila<TamY;fila++)
                {
                        Barra->Position++;
                        for(int col=0;col<TamX;col++)
                        {
                                Px=Plano[fila][col].GetCoords(0);
                                Py=Plano[fila][col].GetCoords(1);
                                Pz=Plano[fila][col].GetCoords(2);
                                max=0;
                                for(int lambda=0;lambda<Rad;lambda++)
                                {
                                        Rx=Nx*lambda+Px;
                                        Ry=Ny*lambda+Py;
                                        Rz=Nz*lambda+Pz;
                                        if(Rx<Vox->getTam(0)&&Ry<Vox->getTam(1)&&Rz<Vox->getTam(2)&&Rx>=0&&Ry>=0&&Rz>=0&&sqrt(pow(Rx,2)+pow(Ry,2)+pow(Rz,2))<Rad&&Vox->getCubo(Rx,Ry,Rz)>max&&max<255)
                                        {
                                                max=Vox->getCubo(Rx,Ry,Rz);
                                                Plano[fila][col].SetCoords(Rx,Ry,Rz);
                                                Plano[fila][col].SetValue(max);
                                        }
                                }
                        }
                }
        }
}
//---------------------------------------------------------------------------

void plano::Trasladar(float x, float y, float z)
{
        float x_=0,y_=0,z_=0;
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
//---------------------------------------------------------------------------

void plano::TrasladarXYZ(float X, float Y, float Z)
{
        float x_,y_,z_,difx,dify,difz;
        x_=Normal.GetPto(0);
        y_=Normal.GetPto(1);
        z_=Normal.GetPto(2);
        difx=X-x_;
        dify=Y-y_;
        difz=Z-z_;
        Normal.SetPto(X,Y,Z);
        for(int j=0;j<TamY;j++)
                for(int i=0;i<TamX;i++)
                {
                        x_=difx+Plano[i][j].GetCoords(0);
                        y_=dify+Plano[i][j].GetCoords(1);
                        z_=difz+Plano[i][j].GetCoords(2);
                        Plano[i][j].SetValue(0);
                        Plano[i][j].SetCoords(x_,y_,z_);
                }
}
//---------------------------------------------------------------------------

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
//---------------------------------------------------------------------------

void plano::Borrar()
{
        //TODO: Add your source code here
        for (int j=0;j<TamY;j++)
                for (int i=0;i<TamX;i++)
                                Plano[i][j].SetValue(0);
}
//---------------------------------------------------------------------------

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
//---------------------------------------------------------------------------

void plano::RotarXYZ(float AngX, float AngY, float AngZ)
{
        float TX,TY,TZ;
        float X,Y,Z,X_,Y_,Z_;
        TX=Normal.GetPto(0);
        TY=Normal.GetPto(1);
        TZ=Normal.GetPto(2);
        Trasladar(-TX,-TY,-TZ);
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
                }
        X=Normal.GetCoords(0);
        Y=Normal.GetCoords(1);
        Z=Normal.GetCoords(2);
        X_=X*cos(2*M_PI/360*AngZ)-Y*sin(2*M_PI/360*AngZ);
        Y_=X*sin(2*M_PI/360*AngZ)+Y*cos(2*M_PI/360*AngZ);
        Z_=Z;
        Normal.SetCoords(X_,Y_,Z_);

        //Vuelvo al lugar original
        Trasladar(TX,TY,TZ);

}
//---------------------------------------------------------------------------

void plano::VerPlano(voxel *Vox,float Azi, float Elev, float Tilt)
{
        Restore();
        float diametro=sqrt(pow(TamX,2)+pow(TamY,2)+pow(Vox->getTam(2),2));
        float radio=diametro/2;
        float centroX=TamX/2;
        float centroY=TamY/2;
        float centroZ=Vox->getTam(2)/2;

        float RotX,RotY,RotZ;
        RotX=sin(2*M_PI/360*Elev)*cos(2*M_PI/360*Azi);
        RotY=sin(2*M_PI/360*Azi)*sin(2*M_PI/360*Elev);
        RotZ=cos(2*M_PI/360*Elev);

        normal Vision;
        //El punto inicial es el cruce con la esfera
        Vision.SetCoords(RotX,RotY,RotZ);
        Vision.normalizar();
        RotX=Vision.GetCoords(0);
        RotY=Vision.GetCoords(1);
        RotZ=Vision.GetCoords(2);
        //La dir de vision es la opuesta, asi mira dentro de la esfera
        Vision.SetCoords(-RotX,-RotY,-RotZ);
        //Tengo las coordenadas normalizadas, ahora multiplico por el radio
        //Traslado el plano al centro de la esfera
        RotX=RotX*radio+centroX;
        RotY=RotY*radio+centroY;
        RotZ=RotZ*radio+centroZ;
        //Ese es el punto de inicio de mi vector normal
        Vision.SetPto(RotX,RotY,RotZ);
        //Ya seteado el destino, ahora tengo que calcular la rotacion del plano
        //Veo cuanto hay q rotar y en que direccion
        Normal.SetCoords(-Normal.GetCoords(0),-Normal.GetCoords(1),-Normal.GetCoords(2));
        float DirX,DirY,DirZ,O_Azi,O_Elev,O_Tilt;
        DirX=Normal.GetCoords(0);
        DirY=Normal.GetCoords(1);
        DirZ=Normal.GetCoords(2);
        //Calculo los angulos originales
        O_Azi=atan(DirY/DirX)/(2*M_PI)*360;
        O_Elev=acos(DirZ)/(2*M_PI)*360;
        //Calculo la rotacion necesaria (rotacion con respecto al origen!)
        float DifRotY=0,DifRotZ=0;
        DifRotY=Elev-O_Elev;
        DifRotZ=Azi-O_Azi;
        //Roto el plano
        RotarXYZ(Tilt,DifRotY,DifRotZ);
        TrasladarXYZ(RotX,RotY,RotZ);
        
}
//---------------------------------------------------------------------------






/*if(Trilinear==true)
                                        {
                                                float x1=0,x2=0,x3=0,x4=0,x5=0,x6=0,x7=0,x8=0;
                                                float a=0,b=0,g=0,X=0,Y=0,Z=0,value=0;
                                                voxel VoxT;

                                                X=Rx;
                                                Y=Ry;
                                                Z=Rz;
                                                a=X-(int)X;
                                                b=Y-(int)Y;
                                                g=Z-(int)Z;
                                                x1=Vox->getCubo(X,Y,Z);
                                                x2=Vox->getCubo(X+1,Y,Z);
                                                x3=Vox->getCubo(X,Y+1,Z);
                                                x4=Vox->getCubo(X+1,Y+1,Z);
                                                x5=Vox->getCubo(X,Y,Z+1);
                                                x6=Vox->getCubo(X+1,Y,Z+1);
                                                x7=Vox->getCubo(X,Y+1,Z+1);
                                                x8=Vox->getCubo(X+1,Y+1,Z+1);
                                                value=((1-g)*(1-b)*(1-a)*x1+(1-g)*(1-b)*(1+a)*x2+(1-g)*(1+b)*(1-a)*x3+
                                                      (1-g)*(1+b)*(1+a)*x4+(1+g)*(1-b)*(1-a)*x5+(1+g)*(1-b)*(1+a)*x6+
                                                      (1+g)*(1+b)*(1-a)*x7+(1+g)*(1+b)*(1+a)*x8)/8;
                                                Vox->setCubo(X,Y,Z,value);//se debe aplicar sobre un nuevo cubo
                                                Rx=X;
                                                Ry=Y;
                                                Rz=Z;
                                                //Fin trilinear
                                        }*/
