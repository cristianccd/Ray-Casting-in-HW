//---------------------------------------------------------------------------

#ifndef elemplanoH
#define elemplanoH
//---------------------------------------------------------------------------
class elemplano
{
private:	// User declarations
        float X,Y,Z;
        int valor;
public:         // User declarations
        elemplano();
        elemplano(float x,float y,float z,int v);
        ~elemplano();
        void SetCoords(float x, float y, float z);
        float GetCoords(int index);
        int GetValue();
        void SetValue(int v);

};
//---------------------------------------------------------------------------
#endif
