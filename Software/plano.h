//---------------------------------------------------------------------------

#ifndef planoH
#define planoH

#include <ComCtrls.hpp>
#include "normal.h"
#include "voxel.h"
#include "elemplano.h"

//---------------------------------------------------------------------------
class plano
{
private:	// User declarations
        float TamX,TamY;
        normal Normal;

        BYTE *LinePtr;
        int LUT[256];
        int Histo[256];
        float Mascara[9];
public:         // User declarations
        plano();
        plano(float tamx,float tamy);
        ~plano();
        void Rotar(normal Norm, float Angle);
        void Rotar(float azi, float elev, float tilt);
        void Trasladar(float x, float y, float z);
        normal GetNormal();
        elemplano GetElemPlano(int i, int j);
        void CargarPlano(voxel *Vox,TProgressBar *Barra, bool Volume, bool MIP, bool Transparencias, bool Trilinear, int Uinf, int Usup,int Profmax, int Profmin);
        void Mostrar(TImage *Image);
        void Borrar();
        void Restore();
        void RotarXYZ(float AngX, float AngY, float AngZ);
        void VerPlano(voxel *Vox, float Azi, float Elev, float Tilt);
        void TrasladarXYZ(float X, float Y, float Z);
        void Trilinear(voxel * VoxT, float fact_esc);
        void Previa(voxel * Vox,int Uruido);
        void Histograma();
        void LoadLUT(float * Array, int size);
        float GetLUT(int index);
        void ApplyLUT();
        float GetHistograma(int nivel);
        void UmbralFijo(int Umbral);
        float Isodata();
        void Ecualizar();
        int GetSize(int index);
        void IzqDer();
        void BrilloContr(int Brillo, int Contraste);
        plano(plano & original);
        plano & operator=(plano &original);
        void Bilinear(plano &Aux,float FE, int X, int Y);
        elemplano **Plano;
        void SetMask(float *);
        void ApplyMask(plano & Aux);

};
//---------------------------------------------------------------------------
#endif
