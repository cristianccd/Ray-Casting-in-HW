//---------------------------------------------------------------------------
#pragma hdrstop
#include "voxel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------


voxel::voxel()
{
        //TODO: Add your source code here
        BitMap=new Graphics::TBitmap();
        CantImgs=1;
        TamX=512;
        TamY=512;
        Cubo=new unsigned char **[TamX];
        for(int i=0;i<TamX;i++)
                Cubo[i]=new unsigned char *[TamY];
        for(int i=0;i<TamX;i++)
                for(int j=0;j<TamY;j++)
                        Cubo[i][j]=new unsigned char [CantImgs];
        for(int j=0;j<TamY;j++)
                for(int i=0;i<TamX;i++)
                        for(int k=0;k<CantImgs;k++)
                                Cubo[i][j][k]=0;
}

voxel::voxel(unsigned int TX, unsigned int TY, unsigned int CImgs)
{
        //TODO: Add your source code here
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
        for(int j=0;j<TamY;j++)
                for(int i=0;i<TamX;i++)
                        for(int k=0;k<CantImgs;k++)
                                Cubo[i][j][k]=0;
}

voxel* voxel::operator=(voxel *Vxl)
{
       /* char valor;
        for(int j=0;j<TamY;j++)
                for(int i=0;i<TamX;i++)
                        for(int k=0;k<CantImgs;k++)
                        {
                                valor=Vxl->Cubo[i][j][k];
                                Cubo[i][j][k]=valor;
                        }*/

}

voxel::~voxel()
{
        //TODO: Add your source code here
        for (int i = 0; i < TamY; i++)
        {
                for (int j = 0; j < TamX; j++)
                        delete [] Cubo[i][j];
                delete [] Cubo[i];
        }
        delete BitMap;
}

void __fastcall voxel::Cargar(AnsiString * S, int No)
{
        //TODO: Add your source code here
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

void voxel::Borrar(TImage *Image1)
{
        for (int j=0;j<TamY;j++)
        {
                LinePtr=(BYTE *) Image1->Picture->Bitmap->ScanLine[j];
                for (int i=0;i<TamX;i++)
                        LinePtr[i]=0;
        }
        Image1->Refresh();
}
