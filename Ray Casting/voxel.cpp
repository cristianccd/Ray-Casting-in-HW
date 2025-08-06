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

voxel::voxel(voxel &Vxl)
{
        //TODO: Add your source code here
        BitMap=new Graphics::TBitmap();
        BitMap=Vxl.BitMap;
        CantImgs=Vxl.CantImgs;
        TamX=Vxl.TamX;
        TamY=Vxl.TamY;
        Cubo=new unsigned char **[TamX];
        for(int i=0;i<TamX;i++)
                Cubo[i]=new unsigned char *[TamY];
        for(int i=0;i<TamX;i++)
                for(int j=0;j<TamY;j++)
                        Cubo[i][j]=new unsigned char [CantImgs];
        for(int j=0;j<TamY;j++)
                for(int i=0;i<TamX;i++)
                        for(int k=0;k<CantImgs;k++)
                                Cubo[i][j][k]=Vxl.Cubo[i][j][k];
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
                        ptr = (Byte *)BitMap->ScanLine[i];
                        for(int j=0;j<BitMap->Width;j++)//X
                        {
                                Cubo[j][i][k]=ptr[j];
                        }
                }
        }
}

void voxel::Mostrar(TImage *Image1, int index)
{
        BYTE *LinePtr;
        typedef struct
        {
        TLogPalette lpal;
        TPaletteEntry dummy[256];
        } LogPal;
        Image1->Picture->Bitmap->PixelFormat=pf8bit;
        Image1->Picture->Bitmap->Width=TamX;
        Image1->Picture->Bitmap->Height=TamY;
        LogPal SysPal;
        SysPal.lpal.palVersion = 0x300;
        SysPal.lpal.palNumEntries = 256;
        for (int i=0;i<SysPal.lpal.palNumEntries;i++)
        {
                SysPal.lpal.palPalEntry[i].peRed = i;
                SysPal.lpal.palPalEntry[i].peGreen = i;
                SysPal.lpal.palPalEntry[i].peBlue = i;
                SysPal.lpal.palPalEntry[i].peFlags = 0;
        }
        Image1->Picture->Bitmap->Palette = CreatePalette(&SysPal.lpal);
        for (int j=0;j<TamY;j++)
        {
                LinePtr=(BYTE *) Image1->Picture->Bitmap->ScanLine[j];
                for (int i=0;i<TamX;i++)
                        LinePtr[i]=Cubo[i][j][index];
        }
        Image1->Refresh();
}

void voxel::Vista(TImage *Image1, int angulox, int anguloy)
{
        int *max=new int [TamX];
        BYTE *LinePtr;
        for(int j=0;j<TamY;j++)
        {
                LinePtr=(BYTE *) Image1->Picture->Bitmap->ScanLine[j];
                for(int i=0;i<TamX;i++)
                {
                        for(int k=0;k<CantImgs;k++)
                        {

                                if(Cubo[i][j][k]>max[i])
                                        max[i]=Cubo[i][j][k];
                                        //LinePtr[i]=255;//Cubo[i][j][k];
                                //else
                                        //LinePtr[i]=0;
                                        //max[i]=Cubo[i][j][k];
                        }
                        LinePtr[i]=max[i];

                 }
        }
        Image1->Refresh();
        delete max;
}
