//---------------------------------------------------------------------------

#if !defined(__MATRIZ_H)
#define __MATRIZ_H
//---------------------------------------------------------------------------
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
        Byte *ptr;

public:         // User declarations
        voxel();
        voxel(unsigned int, unsigned int, unsigned int);
        ~voxel();
        voxel(voxel &);
        void __fastcall Cargar(AnsiString * S, int No);

};
//---------------------------------------------------------------------------
#endif
