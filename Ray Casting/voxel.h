//---------------------------------------------------------------------------

#if !defined(__VOXEL_H)
#define __VOXEL_H
//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#include <stdio.h>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
//---------------------------------------------------------------------------
class voxel
{
private:	// User declarations
        unsigned char ***Cubo;
        int CantImgs;
        Graphics::TBitmap *BitMap;
        int TamX;
        int TamY;
        BYTE *LinePtr;

public:         // User declarations
        voxel();
        voxel(unsigned int, unsigned int, unsigned int);
        ~voxel();
        voxel* operator=(voxel *);
        void __fastcall Cargar(AnsiString * S, int No);
        void Mostrar(TImage *, int);
        int getCubo(int x, int y, int z);
        int getTam(int index);
};
//---------------------------------------------------------------------------
#endif
