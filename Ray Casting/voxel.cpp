//---------------------------------------------------------------------------
#pragma hdrstop
#include "voxel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------

voxel::voxel()
{
        BitMap=new Graphics::TBitmap();
        CantImgs=0;
        TamX=512;
        TamY=512;
        Cubo=new unsigned char **[TamX];
        for(int i=0;i<TamX;i++)
                Cubo[i]=new unsigned char *[TamY];
        for(int i=0;i<TamX;i++)
                for(int j=0;j<TamY;j++)
                        Cubo[i][j]=new unsigned char [CantImgs];
        /*for(int j=0;j<TamY;j++)
                for(int i=0;i<TamX;i++)
                        for(int k=0;k<CantImgs;k++)
                                Cubo[i][j][k]=0;*/
}
//---------------------------------------------------------------------------

voxel::voxel(unsigned int TX, unsigned int TY, unsigned int CImgs)
{
        BitMap=new Graphics::TBitmap();
        CantImgs=CImgs;
        TamX=TX;
        TamY=TY;
        Cubo=new unsigned char **[TamX];
        for(int i=0;i<TamX;i++)
                Cubo[i]=new unsigned char *[TamY];
        for(int i=0;i<TamX;i++)
                for(int j=0;j<TamY;j++)
                        Cubo[i][j]=new unsigned char [CantImgs];
        /*for(int j=0;j<TamY;j++)
                for(int i=0;i<TamX;i++)
                        for(int k=0;k<CantImgs;k++)
                                Cubo[i][j][k]=0;*/
}
//---------------------------------------------------------------------------

voxel::~voxel()
{
        for (int i = 0; i < TamY; i++)
        {
                for (int j = 0; j < TamX; j++)
                        delete [] Cubo[i][j];
                delete [] Cubo[i];
        }
        delete BitMap;
}
//---------------------------------------------------------------------------

void __fastcall voxel::Cargar(AnsiString * S, int No)
{
        CantImgs=No;
        BitMap=new Graphics::TBitmap();
        for(int k=0;k<No;k++)
        {
                BitMap->LoadFromFile(S[k]);
                for(int i=0;i<BitMap->Height;i++)//Y
                {
                        LinePtr = (Byte *)BitMap->ScanLine[i];
                        for(int j=0;j<BitMap->Width;j++)//X
                        {
                                Cubo[j][i][k]=LinePtr[j];
                        }
                }
        }
}
//---------------------------------------------------------------------------

void voxel::Mostrar(TImage *Image1, int index)
{
        //Cargo paleta..
        for (int j=0;j<TamY;j++)
        {
                LinePtr=(BYTE *) Image1->Picture->Bitmap->ScanLine[j];
                for (int i=0;i<TamX;i++)
                        LinePtr[i]=Cubo[i][j][index];
        }
        Image1->Refresh();
}
//---------------------------------------------------------------------------

void voxel::setCubo(int X, int Y, int Z, float value)
{
        Cubo[X][Y][Z]=value;
}
//---------------------------------------------------------------------------

int voxel::getCubo(int x, int y, int z)
{
        return Cubo[x][y][z];
}
//---------------------------------------------------------------------------

int voxel::getTam(int index)
{
        int Tamanos[3];
        Tamanos[0]=TamX;
        Tamanos[1]=TamY;
        Tamanos[2]=CantImgs;
        return Tamanos[index];
}
//---------------------------------------------------------------------------

voxel::voxel(voxel *VoxC)
{
        BitMap=new Graphics::TBitmap();
        CantImgs=VoxC->getTam(2);
        TamX=VoxC->getTam(0);
        TamY=VoxC->getTam(1);
        Cubo=new unsigned char **[TamX];
        for(int i=0;i<TamX;i++)
                Cubo[i]=new unsigned char *[TamY];
        for(int i=0;i<TamX;i++)
                for(int j=0;j<TamY;j++)
                {
                        Cubo[i][j]=new unsigned char [CantImgs];
                        for(int k=0;k<CantImgs;k++)
                                Cubo[i][j][k]=VoxC->getCubo(i,j,k);
                }
}
